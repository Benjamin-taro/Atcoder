#!/usr/bin/env python3
# usage: $ oj generate-input 'python3 generate.py'
# usage: $ oj generate-input --hack-actual=./a.out --hack-expected=./naive 'python3 generate.py'
import random


# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    N = random.randint(1, 1000)  # TODO: edit here
    A = [None for _ in range(N)]
    B = [None for _ in range(N)]
    for i in range(N):
        A[i] = random.randint(1, 10**9)  # TODO: edit here
    for i in range(N):
        B[i] = random.randint(1, 10**9)  # TODO: edit here
    K = random.randint(1, 1000)  # TODO: edit here
    X = [None for _ in range(K)]
    Y = [None for _ in range(K)]
    for i in range(K):
        X[i] = random.randint(1, 10**9)  # TODO: edit here
        Y[i] = random.randint(1, 10**9)  # TODO: edit here
    print(N)
    print(*[A[i] for i in range(N)])
    print(*[B[i] for i in range(N)])
    print(K)
    for i in range(K):
        print(X[i], Y[i])


if __name__ == "__main__":
    main()
