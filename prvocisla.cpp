#include <iostream>
#include <string.h>

using namespace std;

int * sieve(int n){
    int * A;
    int * L;
    
    int numPrime;
    
    A =(int *) malloc(n*sizeof(int));
    memset(A,0,8);
    
    for (int p = 2; p<= n; p++){
        A[p]=p;
    }

    for (int p = 2; p*p <= n; p++){
        if (A[p] != 0 ){
            int j;
            j = p*p;
            while (j <= n){
                A[j] = 0;
                j = j + p; 
            }
        }
    }

    for (int p = 2; p<= n; p++){
        if (A[p] != 0) numPrime++;
    
    }

    L = (int *) malloc(numPrime*sizeof(int));

    int j = 0;
    
    while (j < numPrime) {
        for (int p = 2; p<= n; p++){
    
            if (A[p] != 0) {
                L[j] = A[p];
                j++;
            }
        }
    }
   
    free(A);
    return L;
}

void printPrime(int* L, int n) {
    int j = 0;

    while (L[j] <= n){
        cout << L[j] << " ";
        j++;
    }

    cout << endl;
}

int main()
{
    int n = 200;

    int * L;

    L = sieve(n);
    
    printPrime(L,n);

    free(L);

    return 0;
}
