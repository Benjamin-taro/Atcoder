#!/usr/bin/env python3
# from typing import *



# def solve(n: int, a: List[int], b: List[int]) -> Tuple[int, int]:
def solve(n, a, b):
    A = list()
    output = list()
    for num in range(n):
        if a[num] == 1:
            A.append(b[num])
        elif a[num] == 2:
            output.append(A[-b[num]])
    return output


    pass  # TODO: edit here

# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    n = int(input())
    a = [None for _ in range(n)]
    b = [None for _ in range(n)]
    for i in range(n):
        a[i], b[i] = map(int, input().split())
    output = solve(n, a, b)
    
    print('\n'.join(map(str, output)))
    #print(a)
    #print(b)
    #print(e)
    #print(f)

if __name__ == '__main__':
    main()
