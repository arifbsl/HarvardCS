# Converted staff solution since I did not have my own implementation
from cs50 import get_float
from sys import argv

def main():
    # Request user input for total change
    dollars = get_float("Change: ")

    # Error-checking for positive number
    while True:
        if dollars < 0:
            dollars = get_float("Change: ")
        else:
            break

    # Initialize cents and coins
    cents = round(dollars * 100)
    coins = 0

    # Calculate number of quarters
    coins += cents // 25
    cents = cents % 25

    # Then dimes
    coins += cents // 10
    cents = cents % 10

    # Then Pennies
    coins += cents // 5
    coins += cents % 5

    # Since coins was incrementing for each, print total number of coins
    print(coins)

if __name__ == "__main__":
    main()