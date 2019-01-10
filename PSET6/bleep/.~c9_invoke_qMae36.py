from cs50 import get_string
from sys import argv

words = set()

def main():

    # Error checking for correct number of cla
    if len(argv) != 2:
        print("Usage: python bleep.py dictionary")
        exit(1)
    else:
        Input = get_string("What message would you like to censor? ")

    # Load words from file into set
    infile = argv[1]

    file = open(infile, "r")
    for line in file:
    file = o
    file.close()
    return True

    if word in words:
        word = ("*")
        return True
        print(word)

if __name__ == "__main__":
    main()
