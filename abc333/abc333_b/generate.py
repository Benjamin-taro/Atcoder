#!/usr/bin/env python3
# usage: $ oj generate-input 'python3 generate.py'
# usage: $ oj generate-input --hack-actual=./a.out --hack-expected=./naive 'python3 generate.py'
import random

def validate_input(S1, S2, T1, T2):
    if S1 in "ABCDE" and S2 in "ABCDE" and T1 in "ABCDE" and T2 in "ABCDE":
        if S1 != S2 and T1 != T2:
            return True
    return False



# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    # failed to analyze input format
    n = random.randint(1, 10 ** 9)  # TODO: edit here
    a = [random.randint(1, 10 ** 9) for _ in range(n)]  # TODO: edit here
    print(n)  # TODO: edit here
    print(*a)  # TODO: edit here

if __name__ == "__main__":
    main()