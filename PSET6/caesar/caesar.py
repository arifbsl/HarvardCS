import sys
from sys import argv
from cs50 import get_string

# Error checking for correct number of arguments
if len(argv) != 2:
    print("Usage: python caesar.py k")
    sys.exit(1)

# Error checking for User-input type (.isdigit python syntax from @ https://www.tutorialspoint.com/python/string_isdigit.htm)
if argv[1].isdigit() != True:
    print("Usage: python caesar.py k")
    sys.exit(1)
else:
    # Prompt for text that will be encrypted
    plaintext = get_string("plaintext: ")

    key = int(argv[1])

    CT = ("ciphertext: ")
    # Text encryption process
    for i in plaintext:

        # ord() implementation and syntax from https://docs.python.org/3/library/functions.html#ord
        if i.isalpha() == True or i.isdigit() == True:
            PT = ord(i)

            # chr() implementation and syntax from https://docs.python.org/2/library/functions.html#chr
            # Case-sensitive plaintext encryption
            if PT >= 97 and PT <= 122:
                CT += chr(((PT - 97 + key) % 26) + 97)
            else:
                CT += chr(((PT - 65 + key) % 26) + 65)
        # For non-alphanumeric text
        else:
            CT += i
    print(CT)

