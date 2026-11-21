#!/usr/bin/env python3
"""Compile and run a Codeforces solution in one step.

Usage:
    ./runner 4A                     # compile solutions/4A.cpp and run it (stdin from terminal)
    ./runner 4A -i testcase.txt     # read input from file and measure run time
    ./runner 4A -i t.txt -t 1       # additionally enforce a 1 s time limit
    ./runner 4A -f                  # force recompilation
"""

import argparse
import os
import shutil
import subprocess
import sys
import threading
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SOLUTIONS = ROOT / "solutions"
BUILD = ROOT / "build"

CXX = os.environ.get("CXX") or shutil.which("g++") or shutil.which("clang++")
CXXFLAGS = ["-std=c++20", "-O3", "-Wall", "-Wextra", "-DLOCAL"]

if sys.stderr.isatty():
    DIM, GREEN, RED, YELLOW, BOLD, RESET = (
        "\033[2m",
        "\033[32m",
        "\033[31m",
        "\033[33m",
        "\033[1m",
        "\033[0m",
    )
else:
    DIM = GREEN = RED = YELLOW = BOLD = RESET = ""


def info(msg: str) -> None:
    print(msg, file=sys.stderr, flush=True)


def ensure_line_start() -> None:
    """Move the cursor to the start of a fresh line if the program's output
    did not end with a newline (same trick zsh uses for its '%' mark).

    Printing (columns - 1) spaces followed by '\\r' wraps to the next line only
    when the cursor is not already in column 0; otherwise it stays put.
    """
    sys.stdout.flush()
    if not sys.stderr.isatty():
        sys.stderr.write("\n")
        sys.stderr.flush()
        return
    columns = shutil.get_terminal_size().columns
    sys.stderr.write(" " * (columns - 1) + "\r")
    sys.stderr.flush()


def find_source(problem: str) -> Path:
    for candidate in (
        SOLUTIONS / f"{problem}.cpp",
        SOLUTIONS / f"{problem.upper()}.cpp",
    ):
        if candidate.is_file():
            return candidate
    for candidate in SOLUTIONS.glob("*.cpp"):
        if candidate.stem.lower() == problem.lower():
            return candidate
    info(f"{RED}Solution not found: {SOLUTIONS / (problem + '.cpp')}{RESET}")
    sys.exit(1)


def compile_source(src: Path, force: bool) -> Path:
    if CXX is None:
        info(f"{RED}No C++ compiler found (g++/clang++).{RESET}")
        sys.exit(1)

    BUILD.mkdir(exist_ok=True)
    binary = BUILD / src.stem

    if not force and binary.exists() and binary.stat().st_mtime >= src.stat().st_mtime:
        info(f"{DIM}[build] {src.name} is up to date, skipping compilation{RESET}")
        return binary

    cmd = [CXX, *CXXFLAGS, str(src), "-o", str(binary)]
    info(f"{DIM}[build] {' '.join(cmd)}{RESET}")
    t0 = time.perf_counter()
    result = subprocess.run(cmd)
    dt = time.perf_counter() - t0
    if result.returncode != 0:
        info(f"{RED}{BOLD}Compilation failed.{RESET}")
        sys.exit(result.returncode)
    info(f"{DIM}[build] OK ({dt:.2f} s){RESET}")
    return binary


def run(binary: Path, input_file: Path | None, time_limit: float | None) -> int:
    if input_file is None:
        info(f"{DIM}[run] {binary.name} — waiting for input (Ctrl+D to finish){RESET}")
        try:
            code = subprocess.run([str(binary)]).returncode
        except KeyboardInterrupt:
            code = 130
        ensure_line_start()
        return code

    if not input_file.is_file():
        info(f"{RED}Input file does not exist: {input_file}{RESET}")
        sys.exit(1)

    info(f"{DIM}[run] {binary.name} < {input_file}{RESET}")
    info(f"{DIM}{'─' * 40}{RESET}")

    timed_out = threading.Event()
    with open(input_file, "rb") as fin:
        t0 = time.perf_counter()
        proc = subprocess.Popen([str(binary)], stdin=fin)
        killer = None
        if time_limit is not None:

            def kill() -> None:
                timed_out.set()
                proc.kill()

            killer = threading.Timer(time_limit, kill)
            killer.start()
        _, status_raw, usage = os.wait4(proc.pid, 0)
        wall = time.perf_counter() - t0
        if killer:
            killer.cancel()
        proc.returncode = os.waitstatus_to_exitcode(status_raw)

    cpu = usage.ru_utime + usage.ru_stime

    ensure_line_start()
    info(f"{DIM}{'─' * 40}{RESET}")

    code = proc.returncode
    if timed_out.is_set():
        status = f"{RED}{BOLD}TLE{RESET} (killed after {time_limit:g} s)"
    elif code != 0:
        status = f"{RED}{BOLD}RE{RESET} (exit code {code})"
    elif time_limit is not None and cpu > time_limit:
        status = f"{YELLOW}{BOLD}TLE{RESET} (CPU {cpu:.3f} s > {time_limit:g} s)"
    else:
        status = f"{GREEN}{BOLD}OK{RESET}"

    info(f"status: {status}")
    info(
        f"time:   {BOLD}{wall * 1000:.1f} ms{RESET} {DIM}(wall){RESET}, {cpu * 1000:.1f} ms {DIM}(CPU){RESET}"
    )
    return 124 if timed_out.is_set() else code


def main() -> None:
    parser = argparse.ArgumentParser(
        description="Compile and run a Codeforces solution."
    )
    parser.add_argument("problem", help="problem id, e.g. 4A (file solutions/4A.cpp)")
    parser.add_argument(
        "-i", "--input", type=Path, help="input file; enables time measurement"
    )
    parser.add_argument(
        "-t",
        "--time-limit",
        type=float,
        metavar="SEC",
        help="time limit in seconds (with -i)",
    )
    parser.add_argument(
        "-f", "--force", action="store_true", help="force recompilation"
    )
    args = parser.parse_args()

    src = find_source(args.problem)
    binary = compile_source(src, args.force)
    sys.exit(run(binary, args.input, args.time_limit))


if __name__ == "__main__":
    main()
