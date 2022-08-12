#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void main(){
    int *x,j,i,n;
    printf("check prime upto: ");
    scanf("%d",&n); 
    x=(int*)malloc(n*sizeof(int));
    for(i=0;i<=(n-2);i++)
        *(x+i)=i+2;
    for(i=0;i<=pow(n,0.5);i++){
        if(*(x+i)==0) 
            continue;
        for(j=2;j<=n/(2+i);j++)
            *(x+(i+2)*j-2)=0;
    }
    printf("primes are\n");
    for(i=0;i<n;i++)
        if(*(x+i)!=0)
            printf("%d\n",*(x+i));

    printf("\n");
    system("pause");
}
