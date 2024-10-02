# Toy-RSA-Alforithm
This is a toy implementation of the RSA encryption algorithm written in C. The user will provide the program with two prime integers, p and q, and a message to encrypt. The program will return the values of E and D, along with the encoded and decoded messages. It can accept prime integers up to four digits, but none larger. The encryption uses ASCII values from 0 to 127.

**Note: This program uses the GMP library to handle the larger integers. You may have to install it first.**

# How to compile
### Compiling with makefile:
You can use the included makefile to compile. Simply enter the command: `make` in the terminal. 

To remove the generated files, enter the command: `make clean`.

### Compiling with gcc:
Alternatively, you could compile with the gcc compiler by using the command: 

    gcc RSA.c RSA_helper.c -lgmp -o RSA

# How to run:

The command to run the program is structured in the following format: `./RSA p q m`,
Where p and q are two different prime integers less than four digits long, and m is the message you wan to encrypt.

    ./RSA 17 13 Hello World!



If the message is multi-line it may be best to include it inside of `" "`.

```
./RSA 8641 13 "In the heart of the bustling city, 
where the cacophony of honking cars and chattering pedestrians 
creates a vibrant symphony, a small café sits tucked away on a 
quiet street corner. With its charming exterior adorned with 
blooming flowers and warm, inviting lights, the café serves as 
a serene oasis for those seeking a moment of respite."
```







