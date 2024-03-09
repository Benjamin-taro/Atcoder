#!/usr/bin/env python3

def main():
    A, B, W = map(int, input().split())
    W *= 1000  # Convert kilograms to grams
    min_count = W // B if W % B == 0 else W // B + 1
    max_count = W // A
    satisfied = False
    
    for n in range(min_count, max_count + 1):
        if A * n <= W <= B * n:
            satisfied = True
            min_count = min(min_count, n)
            max_count = max(max_count, n)
    
    if not satisfied:
        print("UNSATISFIABLE")
    else:
        print(min_count, max_count)

if __name__ == '__main__':
    main()
