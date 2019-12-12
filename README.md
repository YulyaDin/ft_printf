# ft_printf
ft_printf recodes (but not fully) the libc’s printf function. This ft_printf deals with the following parameters:
1. types char, string and pointer - %c, %s, %p
2. types int, int in octal system, unsigned int, int in hexadecimal system (upper and lower case) - %d, %i, %o, %u, %x, %X, - and also %D (long and long long int), %O (long and long long int in octimal system), %U (unsigned long and long long int) with the modifiers h (short or unsigned short), hh (char or unsigned char), l (long int or unsigned long int) and ll(long long or unsigned long long)
3. types float, double and long double with the modifier L - %f, %lf, %Lf
4. it works with %%, with the precision, width and * instead of precision and width
5. flags #0-+ and space
+ the bonus - it works with $
***
# Usage
Run the following commands:

* To compile write:

make
* To remove objects:

make clean
* To remove objects and binary file (program):

make fclean
* To re-compile:

make re
* Executing

To test the library, first write and compile main.c with the library:
gcc -o test main.c libftprintf.a
./test
