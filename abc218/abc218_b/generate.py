#!/usr/bin/env python3
# usage: $ oj generate-input 'python3 generate.py'
# usage: $ oj generate-input --hack-actual=./a.out --hack-expected=./naive 'python3 generate.py'
import random


# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    P = [None for _ in range(26)]
    for i in range(26):
        P[i] = random.randint(1, 10**9)  # TODO: edit here
    print(*[P[i] for i in range(26)])


if __name__ == "__main__":
    main()