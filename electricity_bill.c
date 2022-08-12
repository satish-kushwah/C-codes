#include "stdio.h"
#include "string.h"

int main() {
    int units;
    float bill;
    char id[50],name[100],consumer_type[2];
    printf("Enter Subscriber ID: ");
    scanf("%s",id);
    printf("Enter Subscriber Name: ");
    getchar();//to consume \n from previous input
    gets(name);
    printf("Enter monthly consuption: ");
    scanf("%d",&units);
    while(1){
        printf("Enter consumer type R for residential, C for Commercial, I for industrial: ");
        scanf("%s",consumer_type);
        if(strcmp(consumer_type,"R")==0 || strcmp(consumer_type,"C")==0 || strcmp(consumer_type,"I")==0)
            break;
        else
            printf("Enter correct consumer type\n");            
    }
    if(strcmp(consumer_type,"R")==0){
        if(units>500)
            bill=50+(units-500)*0.45;
        else
            bill=50;
    }else if(strcmp(consumer_type,"C")==0){
        if(units>1000)
            bill=100+(units-1000)*0.45;
        else
            bill=100;
    }else{
        if(units>1000)
            bill=180+(units-1000)*0.75;
        else
            bill=180;
    }
    printf("\nSubscriber ID: %s\n", id);
    printf("Subscriber Name: %s\n",name );
    printf("Monthly consuption: %d\n", units);
    printf("Consumer type: %s\n", consumer_type);
    printf("--------------------------------\n");
    printf("Total bill for month: %.2f pesos\n",bill );

    return 0;
}