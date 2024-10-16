#!/usr/bin/env python3
# usage: $ oj generate-input 'python3 generate.py'
# usage: $ oj generate-input --hack-actual=./a.out --hack-expected=./naive 'python3 generate.py'
import random


# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    N = random.randint(1, 10)  # TODO: edit here
    A = [None for _ in range(N)]
    B = [None for _ in range(N)]
    for i in range(N):
        A[i] = random.randint(1, 10)  # TODO: edit here
    for i in range(N):
        B[i] = random.randint(1, 10)  # TODO: edit here
    Q = random.randint(1, 10)  # TODO: edit here
    query = [None for _ in range(Q)]
    for i in range(Q):
        query[i] = random.randint(1, 10)  # TODO: edit here
    print(N)
    print(*[A[i] for i in range(N)])
    print(*[B[i] for i in range(N)])
    print(Q)
    for i in range(Q):
        print(query[i])


if __name__ == "__main__":
    main()
