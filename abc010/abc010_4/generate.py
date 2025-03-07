#!/usr/bin/env python3
# usage: $ oj generate-input 'python3 generate.py'
# usage: $ oj generate-input --hack-actual=./a.out --hack-expected=./naive 'python3 generate.py'
import random


# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    N = random.randint(1, 10**9)  # TODO: edit here
    G = random.randint(1, 1000)  # TODO: edit here
    p = [None for _ in range(G)]
    E = random.randint(1, 1000)  # TODO: edit here
    a = [None for _ in range(E)]
    b = [None for _ in range(E)]
    for i in range(G):
        p[i] = random.randint(1, 10**9)  # TODO: edit here
    for i in range(E):
        a[i] = random.randint(1, 10**9)  # TODO: edit here
        b[i] = random.randint(1, 10**9)  # TODO: edit here
    print(N, G, E)
    print(*[p[i] for i in range(G)])
    for i in range(E):
        print(a[i], b[i])


if __name__ == "__main__":
    main()
