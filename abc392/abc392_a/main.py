#!/usr/bin/env python3

YES = 'Yes'
NO = 'No'

def solve(a, b, c):
    if a * b == c:
        return YES
    if a * c == b:
        return YES
    if b * c == a:
        return YES
    return NO

def main():
    a, b, c = map(int, input().split())
    ans = solve(a, b, c)
    print(ans)

if __name__ == '__main__':
    main()
