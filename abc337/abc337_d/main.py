#!/usr/bin/env python3
# from typing import *



# def solve(H: int, W: int, K: int, S: List[str]) -> int:
def solve(H, W, K, S):
    output = 10**18
    for i in range(H):
        temp = S[i]
        #print(temp)
        for c1 in range(len(temp) - K + 1):
            #print(c1)
            check = temp[c1:c1+K]
            #print(check)
            #print(check.count("o"))
            if "x" not in check and K-check.count("o") < output:
                output = K-check.count("o")
            #print(output)



    S = [list(word) for word in S]
    S = [list(row) for row in zip(*S[::-1])]

    #print(S)
    for j in range(W):
        temp = S[j]
        #print(temp)
        for c2 in range(len(temp) - K + 1):
            check = temp[c2:c2+K]
            if "x" not in check and K-check.count("o") < output:
                output = K-check.count("o")
            #print(output)

    if output == 10**18:
        output = -1

    return output

# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    H, W, K = map(int, input().split())
    S = [None for _ in range(H)]
    for i in range(H):
        S[i] = input()
    a = solve(H, W, K, S)
    print(a)

if __name__ == '__main__':
    main()
