#!/usr/bin/env python3
# usage: $ oj generate-input 'python3 generate.py'
# usage: $ oj generate-input --hack-actual=./a.out --hack-expected=./naive 'python3 generate.py'
import random


# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    H = random.randint(1, 10)  # TODO: edit here
    W = random.randint(1, 10)  # TODO: edit here
    A = [[None for _ in range(H + W + 4)] for _ in range(H + W + 4)]
    for j in range(H + 4):
        for i in range(W):
            A[i + j][i + j] = random.randint(1, 10)  # TODO: edit here
    N = random.randint(1, 10)  # TODO: edit here
    R = [None for _ in range(N)]
    C = [None for _ in range(N)]
    E = [None for _ in range(N)]
    for i in range(N):
        R[i] = random.randint(1, 10)  # TODO: edit here
        C[i] = random.randint(1, 10)  # TODO: edit here
        E[i] = random.randint(1, 10)  # TODO: edit here
    print(H, W)
    for j in range(H + 4):
        print(*[A[i + j][i + j] for i in range(W)])
    print(N)
    for i in range(N):
        print(R[i], C[i], E[i])


if __name__ == "__main__":
    main()