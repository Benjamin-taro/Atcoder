#!/usr/bin/env python3
# usage: $ oj generate-input 'python3 generate.py'
# usage: $ oj generate-input --hack-actual=./a.out --hack-expected=./naive 'python3 generate.py'
import random
import string

# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    # Generate a random length for the string between 3 and 100
    length = random.randint(3, 100)
    
    # Select two different lowercase letters
    letters = random.sample(string.ascii_lowercase, 2)
    
    # Create a string with all characters the same except one
    s = letters[0] * (length - 1) + letters[1]
    
    # Shuffle the string so that the different character is randomly placed
    s_list = list(s)
    random.shuffle(s_list)
    s_shuffled = ''.join(s_list)

    print(s_shuffled)

if __name__ == "__main__":
    main()
