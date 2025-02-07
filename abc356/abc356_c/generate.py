#!/usr/bin/env python3
# usage: $ oj generate-input 'python3 generate.py'
# usage: $ oj generate-input --hack-actual=./a.out --hack-expected=./naive 'python3 generate.py'
import random


# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    a = random.randint(1, 10**9)  # TODO: edit here
    b = random.randint(1, 1000)  # TODO: edit here
    d = [None for _ in range(b)]
    e = [[None for _ in range(d_i)] for _ in range(b)]
    f = [None for _ in range(b)]
    c = random.randint(1, 10**9)  # TODO: edit here
    for i in range(b):
        d[i] = random.randint(1, 10**9)  # TODO: edit here
        for j in range(d_i):
            e[i][j] = random.randint(1, 10**9)  # TODO: edit here
        f[i] = random.choice('abcde')  # TODO: edit here
    print(a, b, c)
    for i in range(b):
        print(d[i], *[e[i][j] for j in range(d_i)], f[i])


if __name__ == "__main__":
    main()
