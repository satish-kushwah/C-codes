#include "stdio.h"

#define SIZE 8
int main() {
    int intensities[SIZE],n;
    for(int i=0; i<SIZE; ++i) {
        intensities[i]=0;    
    }
    printf("enter intensity values seperated by space: ");
    for(int i=0; i<17; ++i) {
        scanf("%d",&n);
        intensities[n]=intensities[n]+1;
    }
    
    printf("\n%-12s %-12s %-12s\n","Intensity","Frequency","Histogram");    
    for(int i=0; i<SIZE; ++i) {
        printf("%-12d %-12d ",i,intensities[i]);
        for(int j=0; j<intensities[i]; ++j) {
                printf("%c",'*');    
            } 
        printf("\n");   
    }
  
    return 0;
}