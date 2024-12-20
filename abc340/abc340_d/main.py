#!/usr/bin/env python3
# from typing import *

import heapq

# def solve(N: int, A: List[int], B: List[int], X: List[int]) -> int:
    
'''
def solve(N, A, B, X):
  
    temp = [0]*N
    while 0 in temp:
        n = 0
        if temp[n+1] == None or temp[n+1] > temp[n] + A[n]:
                temp[n+1] = temp[n] + A[n]
        if X[n] > n + 1:
            if temp[X[n]-1] == None or temp[X[n]-1] > temp[n]+B[n]:
                temp[X[n]-1] = temp[n]+B[n]
        print(temp)
        n = temp.index(min_greater_than_zero(temp))
        print(n)
    
    return temp 
   ''' 
# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    '''
    N = int(input())
    A = [None for _ in range(N - 1)]
    B = [None for _ in range(N - 1)]
    X = [None for _ in range(N - 1)]
    for i in range(N - 1):
        A[i], B[i], X[i] = map(int, input().split())
    a = solve(N, A, B, X)
    print(a)
'''
    N = int(input())
    g = [[] for _ in range(N + 1)]
    for i in range(1, N):
        A, B, X = map(int, input().split())
        g[i].append((i + 1, A))
        g[i].append((X, B))
    INF = 10 ** 18
    d = [INF] * (N + 1)
    d[1] = 0
    q = [(0, 1)]
    while q:
        c, v = heapq.heappop(q)
        if d[v] < c:
            continue
        for u, w in g[v]:
            if d[u] > c + w:
                d[u] = c + w
                heapq.heappush(q, (d[u], u))
        #print(str(c)+" "+str(v))
        #print(q)
        #print(g)
        #print(d)

    print(d[N] if d[N] < INF else -1)        
        
if __name__ == '__main__':
    main()
