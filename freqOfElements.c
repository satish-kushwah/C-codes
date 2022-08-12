#include "stdio.h"

int main() {
    long A[100000],freq[100000],n; //freq array stores frq of all elements
    int found,t;
    scanf("%d",&t); //scan no of test case
    for(int i=0; i<t; ++i) {
        scanf("%ld",&n); //scan no of elements in array
        for(int j=0; j<100000; ++j)
            freq[j]=0; //initialising freq of all elements to 0
        for(int j=0; j<n; ++j) {
            scanf("%ld",&A[j]) ; //scaning array elemnts
            freq[A[j]]=freq[A[j]]+1;//calculating freq of elements as they appear
            }
            
        for(int k=0; k<n; ++k) {
            found=0; //assuming element not found of higher freq
            for(int l=k+1; l<n; ++l) {
                if(A[k]!=A[l] && freq[A[l]]>freq[A[k]]){ //checking if element found of higher freq
                    printf("%ld ",A[l]); //printing elemnt if found
                    found=1; //setting found to 1
                    break; //break inner loop
                }
            }
            if(found!=1)//if element not found of higher freq print -1
                printf("-1 ");      
        }
    printf("\n"); //print new line after each test case
    }
    return 0;
}