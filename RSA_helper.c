#include "RSA_helper.h"

void Encrypt(char* mesg, mpz_t E, mpz_t n, mpz_t* C, mpz_t* m, int size){

    //Function to encrypt the message

    for (int i = 0; i < size; i++) {
        mpz_init_set_ui(m[i], mesg[i]);

        //C = m^E mod n
        mpz_powm(C[i], m[i], E, n); 
    } 

}

void Decrypt(mpz_t* m, mpz_t* C, mpz_t D, mpz_t n, int size) {
    
    //Function to decrypt the message

    for(int i = 0; i < size; i++){
        //m = C^D mod n
        mpz_powm(m[i], C[i], D, n); 
    }
    
}

int FindValueForED(int e, int* d, int p, int q){

    //Finds values for e and d

    if(p != e && q != e){

        int phiN = (p-1)*(q-1);
        int y;
        
        //e is determined recursivly, d is the x calculated by extended GCD
        if(ExtendedGCD(e, phiN, d, &y) == 1){
            return e;
        }

    }
    

    e++;
    return FindValueForED(e, d, p, q);

    
}

int ExtendedGCD(int a, int b, int* x, int* y) 
{ 

    /*This function calculates the GCD of a and b.
    It also finds the coefficents.*/
    
    if (a == 0) 
    { 
        *x = 0; 
        *y = 1; 
        return b; 
    } 
 
    int x1, y1; 
    int gcd = ExtendedGCD(b%a, a, &x1, &y1); 
 
    
    *x = y1 - (b/a) * x1; 
    *y = x1; 
 
    return gcd; 
} 

void initMPZ(mpz_t* m, mpz_t* C, mpz_t E, mpz_t D, mpz_t n, mpz_t phi, int e, int d, int p, int q, int size){

    //This function initalizes mpz values
    for (int i = 0; i < size; i++) {
        mpz_init(m[i]);
        mpz_init(C[i]);
        
    }

    mpz_init_set_ui(phi,((p-1)*(q-1)));
    mpz_init_set_ui(E, e);
    mpz_init_set_ui(D, d);
    mpz_init_set_ui(n, (p * q));

}

void ClearMpz(mpz_t* m, mpz_t* C, mpz_t E, mpz_t D, mpz_t n, mpz_t phi, int size){

    //This function clears mpz values

    for (int i = 0; i < size; i++) {
        mpz_clear(m[i]);
        mpz_clear(C[i]);
    }

    mpz_clear(E);
    mpz_clear(n);
    mpz_clear(D);
    mpz_clear(phi);


}

void PrintMpzArr(mpz_t* arr, int size, int isEncrypted){

    //Function to display either the encoded or decoded message.
 
    
    for (int i = 0; i < size; i++) {
        long int val = mpz_get_ui(arr[i]);

        printf("%c", (char)val);


    }

    printf("\n");

}

char* ReadCommandArgs(int* p, int* q, int argc, char* argv[]){

    /*This function reads in arguments from the command line.
    It also ensures that p and q are both prime, not the same number, within the ASCII character space,
    and are no greater than 4 digits.*/

    *p = atoi(argv[1]);
    *q = atoi(argv[2]);

    if (argc < 4) {
        fprintf(stderr, "\nError: Three arguments were not entered. please enter p, q, and message.\n");
        exit(EXIT_FAILURE);

    }else if (*p == *q){
        fprintf(stderr, "\nError: p and q must be two different prime numbers.\n");
        exit(EXIT_FAILURE);

    }else if(!IsPrime(*p) || !IsPrime(*q)){
        fprintf(stderr, "\nError: p and q must both be prime.\n");
        exit(EXIT_FAILURE);

    }else if ((*p) * (*q) < 128){
        fprintf(stderr, "\nError: n must be at least as big as the ASCII character space (128). Please choose a bigger p and q.\n");
        exit(EXIT_FAILURE);

    }else if(*p > 9973 || *q > 9973){
        fprintf(stderr, "\nError: p and q can't be larger than 4 digits.\n");
        exit(EXIT_FAILURE);

    }else{
        

        int total_length = 0;
        for (int i = 3; i < argc; i++) {
            total_length += strlen(argv[i]);
        }
        
        char *mesg = (char*)malloc(total_length + 1);
        if (mesg == NULL) {
            fprintf(stderr, "Failed to allocate memory.\n");
            exit(EXIT_FAILURE);
        }
        
        strcpy(mesg, "");
        for (int i = 3; i < argc; i++) {
            strcat(mesg, argv[i]);
            
            if (i < argc - 1) {
                strcat(mesg, " ");
            }
        }
        return mesg;
    }



}

int IsPrime(int n) {

    //Checks if a number is prime

    if (n <= 1) {
        return 0; 
    }
    if (n <= 3) {
        return 1; 
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return 0; 
    }
    int i;
    for (i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0; 
        }
    }
    return 1; 
}


