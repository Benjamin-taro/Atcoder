#!/usr/bin/env python3
# from typing import *



# def solve(N: int, Q: List[int], A: List[int], B: List[int]) -> int:
def solve(N, Q, A, B):
    INF = 10**18
    output = 0

    for x in range(max(Q) + 1):
        #print(x)
        y = INF
        for i in range(N):
            #print(i)
            if Q[i] < A[i] * x:
                y = -INF
            elif B[i] > 0:
                y = min(y, (Q[i] - A[i] * x) // B[i])
            #print(y)
            #print(output)
        output = max(output, x + y)

    return output

# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():

    N = int(input())
    Q = list(map(int, input().split()))
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    ans = solve(N, Q, A, B)

    print(ans)






if __name__ == '__main__':
    main()
