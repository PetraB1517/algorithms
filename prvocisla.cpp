#include <iostream>
#include <string.h>

using namespace std;

int * sieve(int n, int &numPrime){
    int * A;
    int * L;
    

    A =(int *) malloc((n+1)*sizeof(int));
    memset(A,0,(n+1)*sizeof(int));
    
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
    memset(L,0,numPrime*sizeof(int));

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

void printPrime(int* L, int &n) {
    int j = 0;
    while (j < n){
        cout << L[j] << " ";
        j++;
    }
    cout << endl;
}

int main()
{
    int n = 20;
    int * L;
    int numPrime = 0;

    L = sieve(n, numPrime);
    printPrime(L, numPrime);

    free(L);
    return 0;
}