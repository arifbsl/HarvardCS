from cs50 import get_string
from sys import argv

# Assign words as a set type
words = set()

# Re-assign cla to variable
infile = argv[1]

# Open file, remove trailing space, populate words, close file
file = open(infile, "r")
for line in file:
    words.add(line.rstrip("\n"))
file.close()


def main():
    # Error checking for correct number of cla
    if len(argv) != 2:
        print("Usage: python bleep.py dictionary")
        exit(1)
    else:
        # Prompt user for input
        Input = get_string("What message would you like to censor? ")

        # Split into individual strings
        split = Input.split()

        # Censor words on banned list by replacing each bad word with *s
        for item in split:
            if item.lower() in words:
                print("*" * len(item), end=" ")
            # Print words not on banned list as uncensored
            else:
                print(item, end=" ")
        print()


if __name__ == "__main__":
    main()
