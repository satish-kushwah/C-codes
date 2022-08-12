//declare as many stac as needed
//stac returns pointer to data, NULL when empty, store int values, size doubles automatically when overflows
#include<stdio.h>
#include<stdlib.h>
//stack struct
typedef struct stack {int size; int top; int *data;} stack;
stack stack1; //name of stac
//stack initialisation
void stackInitialse(stack *stackObj){
    stackObj->top=(-1); stackObj->size=32; //size doubles automatically when stac overflows
    stackObj->data=(int*)malloc(stackObj->size*sizeof(int));
}
//push
void push(stack *stackObj, int pushData){
    if((1+stackObj->top)<(stackObj->size)){
        stackObj->top++;
        stackObj->data[stackObj->top]=pushData; 
    }
    else{
        stackObj->size=stackObj->size*2; 
        stackObj->data=(int*)realloc(stackObj->data,stackObj->size*sizeof(int));
        stackObj->top++;
        stackObj->data[stackObj->top]=pushData;  
    }
}
//pop
int* pop(stack *stackObj){
    if(stackObj->top>=0){
        stackObj->top--;
        return &(stackObj->data[stackObj->top+1]);
    }
    else 
        return NULL; //when stac is empty
}

//main
int main(){
    stackInitialse(&stack1); //initialse stack
    int choice,pushData,*popData;
    do{
        printf("\n1 to push\n");    
        printf("2 to pop\n"); 
        printf("0 to exit\n: "); 
        scanf("%d",&choice);
        switch(choice){
            case 0 : break;
            case 1 : printf("enter int to push: ");
                     scanf("%d",&pushData); 
                     push(&stack1,pushData); 
                     break;
            case 2 : popData=pop(&stack1);
                     if(popData==NULL)
                        printf("Stac is empty");
                     else
                        printf("popping %d",*popData);
                     break;
        }
    } while(choice!=0);
    return 0;
}            
