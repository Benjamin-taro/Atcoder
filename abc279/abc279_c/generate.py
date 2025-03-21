#!/usr/bin/env python3
# usage: $ oj generate-input 'python3 generate.py'
# usage: $ oj generate-input --hack-actual=./a.out --hack-expected=./naive 'python3 generate.py'
import random


# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    H = random.randint(1, 1000)  # TODO: edit here
    S = [None for _ in range(H)]
    T = [None for _ in range(H)]
    W = random.randint(1, 10**9)  # TODO: edit here
    for i in range(H):
        S[i] = ''.join([random.choice('abcde') for _ in range(random.randint(1, 100))])  # TODO: edit here
    for i in range(H):
        T[i] = ''.join([random.choice('abcde') for _ in range(random.randint(1, 100))])  # TODO: edit here
    print(H, W)
    for i in range(H):
        print(S[i])
    for i in range(H):
        print(T[i])


if __name__ == "__main__":
    main()
