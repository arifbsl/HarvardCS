import nltk
from nltk.tokenize import sent_tokenize


def lines(a, b):
    """Return lines in both a and b"""

    # Take in string inputs a,b and split each string into lines
    file1 = []
    with open("file1", "r") as file:
        for line in file.readlines():
            file1.append(line.rstrip())

    file2 = []
    with open("file2", "r") as file:
        for line in file.readlines():
            file2.append(line.rstrip())

    # Compute a list of all lines that appear in both a and b
    f1l = set(file1)
    f2l = set(file2)
    line_comp = (f1l & f2l)
    lines = list(line_comp)

    # Return the list that contains all lines present in both a and b
    return [lines]


def sentences(a, b):
    """Return sentences in both a and b"""

    file1 = []
    with open("file1", "r") as file:
        for line in file.readlines():
            sentences = nltk.sent_tokenize(line)

    file2 = []
    with open("file1", "r") as file:
        for line in file.readlines():
            sentences = nltk.sent_tokenize(line)

    f1s = set(file1)
    f2s = set(file2)
    sent_comp = (f1s & f2s)
    sentences = list(sent_comp)

    return [sentences]


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    # Take in string inputs a, b, and substring length n
    # Split ea8ch string into all substrings of length n
    # Compute list of all substrings appearing both a and b
    # Return the list

    return []
