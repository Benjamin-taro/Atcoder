#!/usr/bin/env python3
# usage: $ oj generate-input 'python3 generate.py'
# usage: $ oj generate-input --hack-actual=./a.out --hack-expected=./naive 'python3 generate.py'
import random


# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    X = random.randint(1, 10**9)  # TODO: edit here
    Y = random.randint(1, 10**9)  # TODO: edit here
    A = random.randint(1, 10**9)  # TODO: edit here
    B = random.randint(1, 10**9)  # TODO: edit here
    print(X, Y, A, B)


if __name__ == "__main__":
    main()
