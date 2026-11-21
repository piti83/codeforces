# codeforces

My solutions to [Codeforces](https://codeforces.com) problems, written in C++.

Each file in `solutions/` starts with a link to the problem and a link to my accepted submission.

## Runner

`runner.py` compiles a solution and runs it in one step:

```
./runner.py 4A                   # compile solutions/4A.cpp and run it, input from the terminal
./runner.py 4A -i testcase.txt   # input from a file, prints run time
./runner.py 4A -i t.txt -t 1     # same, with a 1 s time limit
./runner.py 4A -f                # force recompilation
```

Binaries go to `build/`. A solution is only recompiled when its source changed.

## Problems

`[x]` solved, `[ ]` to do.

| Status | Problem | Name | Solution | Submission |
|--------|---------|------|----------|------------|
| [x] | [4A](https://codeforces.com/contest/4/problem/A)        | Watermelon            | [4A.cpp](solutions/4A.cpp)        | [399208055](https://codeforces.com/contest/4/submission/399208055)    |
| [x] | [71A](https://codeforces.com/contest/71/problem/A)      | Way Too Long Words    | [71A.cpp](solutions/71A.cpp)      | [399213290](https://codeforces.com/contest/71/submission.399213290)   |
| [x] | [158A](https://codeforces.com/contest/158/problem/A)    | Next Round            | [158A.cpp](solutions/158A.cpp)    | [399224933](https://codeforces.com/contest/158/submission/399224933)  |
| [x] | [231A](https://codeforces.com/contest/231/problem/A)    | Team                  | [231A.cpp](solutions/231A.cpp)    | [399219042](https://codeforces.com/contest/231/submission/399219042)  |
| [x] | [282A](https://codeforces.com/contest/282/problem/A)    | Bit++                 | [282A.cpp](solutions/282A.cpp)    | [399219751](https://codeforces.com/contest/282/submission/399219751)  |
| [x] | [1901A](https://codeforces.com/contest/1901/problem/A)  | Line Trip             | [1901A.cpp](solutions/1901A.cpp)  | [399253929](https://codeforces.com/contest/1901/submission/399253929) |
