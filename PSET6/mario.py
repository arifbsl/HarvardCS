from cs50 import get_int

# Error checking for user-input
while True:
    height = get_int("Height: ")
    if height > 0 and height < 9:
        break

# Generating the pyramid of blocks + spaces
for i in range(height):
    print(" " * (height - i - 1) + "#" * (i+1), end="")
    print()