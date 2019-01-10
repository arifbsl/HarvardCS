# Questions

## What's `stdint.h`?

`stdint.h` introduces a several new int-related datatypes that are more versatile based on the specificity of memory that they allocate/use

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

Since these all specify a specific number of bits, they would be useful to implement because you can allocate the exact amount of bits required for an input into memory.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE is 1 byte.
DWORD is 4 bytes.
LONG is 4 bytes.
WORD is 2 bytes.


## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

The first two bytes are the letter "B" and the letter "M":

0x42 0x4D

## What's the difference between `bfSize` and `biSize`?

`bfSize` is the size of the entire BMP (in bytes).

`biSize` includes only the size of the info header in the BMP.

## What does it mean if `biHeight` is negative?

If `biHeight` is negative, the BMP is a top-down arrangement. This indicates that the first first byte of memory begins at the top-left of the BMP.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

`biBitCount`

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

Lines 24 and 32 of copy.c involve command line arguments. These arguments are stored in variables that are used on lines 24 and 32. It would return NULL if nothing is stored at the memory address for the char* values inputted by the command line arguments; NULL if the files contain nothing.

## Why is the third argument to `fread` always `1` in our code? (For example, see lines 40, 44, and 75.)

The '1' value corresponds to `nmemb` variable in `fread`. By indicating a value of 1, this is telling the `fread` function that we only have one element. This is true on lines 40, 44, and 75.

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

1

## What does `fseek` do?

`fseek` is used to change the position of the pointer forward or backwards within a file.

## What is `SEEK_CUR`?

`SEEK_CUR` is a constant defined in the 'whence' variable of `fseek`. It passes to `fseek` to move the pointer to an exact given location in the file.