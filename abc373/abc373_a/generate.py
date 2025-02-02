#!/usr/bin/env python3
# usage: $ oj generate-input 'python3 generate.py'
# usage: $ oj generate-input --hack-actual=./a.out --hack-expected=./naive 'python3 generate.py'
import random


# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    S = [None for _ in range(12)]
    for i in range(12):
        S[i] = ''.join([random.choice('abcde') for _ in range(random.randint(1, 100))])  # TODO: edit here
    for i in range(12):
        print(S[i])


if __name__ == "__main__":
    main()
