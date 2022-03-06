#include <iostream>
#include <string.h>

using namespace std;

int * sieve(int n, int* numPrime){
    int * A;
    
    // ten jeden navic (n+1) je kvuli tomu zakoncovacimu intu?
    // jestli jo, vis ze potom nepotrebujes numPrime?
    // jestli je to jen kvuli indexovani poli, tak se spis vyplati udelat n++, jednorazove
    // a i je to castejsi... ale to uz je na tobe
    A = (int *) malloc((n+1) * sizeof(int));
    // btw. kdyz tu formuli mas dvakrat, mozna by bylo lepsi to mit v promenne
    memset(A,0, (n+1) * sizeof(int));
    
    for (int p = 2; p<= n; p++){
        A[p] = p;
    }

    //
    for (int p = 2; p*p <= n; p++){
        if (A[p] != 0 ){
            int j;
            j = p*p;
            while (j <= n){
                A[j] = 0;
                j += p; 
            }
        }
    }

    // Spocita prvky
    for (int p = 2; p<= n; p++){
        if (A[p] != 0) (*numPrime)++;
    }

    
    // Uz jen kopirovani; L = resuLt
    int * L;
    // snad to mam spravne.. ale melo by to fungovat i kdyz das misto size_t int
    size_t Ls = (*numPrime) * sizeof(int);
    L = (int *) malloc(Ls);
    memset(L,0, Ls);

    // klidne se vsadim ze to bude fungovat takto, bez toho while
    int j = 0;
    for (int p = 2; p <= n; p++){
        if (A[p] != 0) {
            assert (j < (*numPrime));
            L[j] = A[p];
            j++;
        }
    }
   
    free(A);
    return L;
}

void printPrime(int* L, int n) {
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

    L = sieve(n, &numPrime);
    printPrime(L, numPrime);

    free(L);
    return 0;
}
