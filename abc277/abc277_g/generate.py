#!/usr/bin/env python3
# usage: $ oj generate-input 'python3 generate.py'
# usage: $ oj generate-input --hack-actual=./a.out --hack-expected=./naive 'python3 generate.py'
import random


# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    N = random.randint(1, 1000)  # TODO: edit here
    C = [None for _ in range(N)]
    M = random.randint(1, 1000)  # TODO: edit here
    u = [None for _ in range(M)]
    v = [None for _ in range(M)]
    K = random.randint(1, 10**9)  # TODO: edit here
    for i in range(M):
        u[i] = random.randint(1, 10**9)  # TODO: edit here
        v[i] = random.randint(1, 10**9)  # TODO: edit here
    for i in range(N):
        C[i] = random.randint(1, 10**9)  # TODO: edit here
    print(N, M, K)
    for i in range(M):
        print(u[i], v[i])
    print(*[C[i] for i in range(N)])


if __name__ == "__main__":
    main()
