#ifndef RSA_HELPER_H
#define RSA_HELPER_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

//Function Prototypes
char* ReadCommandArgs(int*, int*, int, char*[]);
int ExtendedGCD(int, int, int*, int*);
int FindValueForED(int, int*, int, int);
int IsPrime(int);
void initMPZ(mpz_t*, mpz_t*, mpz_t, mpz_t, mpz_t, mpz_t, int, int, int, int, int);
void PrintMpzArr(mpz_t*, int, int);
void Encrypt(char*, mpz_t, mpz_t, mpz_t*, mpz_t*, int);
void Decrypt(mpz_t*, mpz_t*, mpz_t, mpz_t, int size);
void ClearMpz(mpz_t*, mpz_t*, mpz_t, mpz_t, mpz_t, mpz_t, int size);

#endif 
