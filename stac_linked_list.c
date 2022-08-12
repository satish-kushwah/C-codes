//good when only one stac required
//wrorks for int, return pointer to data NULL when empty
#include<stdio.h>
#include<stdlib.h>
//stac struct
typedef struct node {int data; struct node *next;} node;
node *top; 
//push
void push(int pushData){
    node *newTop;
    newTop=(node*)malloc(sizeof(node)); 
    newTop->data=pushData; newTop->next=top; top=newTop;
}
//pop
int* pop(){
    static int returnData;
    node *temp; 
    if(top==NULL){
        return NULL;
    }
    else{
        returnData=top->data; temp=top->next; free(top); 
        top=temp; 
        return &returnData;
    }
}
//main
int main(){
    int choice,pushData,*popedData;
    do{
        printf("\n1 to push\t2 to pop\t0 to exit\nchoice: ");    
        scanf("%d",&choice);
        switch(choice){
            case 0 :break;
            case 1 :printf("enter int to push: ");
                    scanf("%d",&pushData); push(pushData); 
                    break;
            case 2 :popedData=pop();
                    if(popedData==NULL)
                        printf("Stac is empty\n");
                    else
                        printf("poped int %d\n",*popedData); 
                    break;
            default:printf("wrong key\n");
        }
    } while(choice!=0);
    return 0;
}
