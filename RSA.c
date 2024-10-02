/*Filename: RSA.c*/

#include "RSA_helper.h"

int main(int argc, char *argv[]) {


    int p;
    int q;
    char* mesg = ReadCommandArgs(&p, &q, argc, argv); //Intalizes p, q and mesg
    int size = strlen(mesg);
    int e;
    int d;
    
    //Find value for e and d
    e = 2;
    e = FindValueForED(e, &d, p, q);
    
    //Check that d is positive
    if(d < 0){
        d += (p-1)*(q-1);
    }

    
    mpz_t n;
    mpz_t E;
    mpz_t D;
    mpz_t phi;
    mpz_t m[size]; 
    mpz_t C[size];

    //Initalize mpz ints
    initMPZ(m, C, E, D, n, phi, e, d, p, q, size);


    gmp_printf("\nThe E value is: %Zd\n",E);
    gmp_printf("\nThe D value is: %Zd\n", D);
    printf("\nThe message is: %s\n", mesg);
    
    //Encrypt and display the message
    printf("\nThe encoded message is: ");
    Encrypt(mesg, E, n, C, m ,size);
    PrintMpzArr(C, size, 1);

    //Decrypt and display the message
    printf("\nThe decoded message is: ");
    Decrypt(m, C, D, n, size);
    PrintMpzArr(m, size, 0);

    free(mesg);
    //Clear mpz values from memory
    ClearMpz(m, C, E, D, n, phi, size);


   return 0;
}

