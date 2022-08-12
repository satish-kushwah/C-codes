//good when one queue required
//works for int, returns pointer to data, NULL when empty
#include<stdio.h>
#include<stdlib.h>
//q node struct
typedef struct node {int data; struct node *next;} node;
node *rear,*front;
//enque
void enq(int enqData){
    node *newRear; newRear=(node*)malloc(sizeof(node));
    rear->data=enqData; newRear->next=NULL; rear->next=newRear; 
    rear=newRear;
    return;
}
//dequeue
int* dq(){
    node *newFront; 
    static int dqData;
    if(front->next==NULL)
        return NULL;
    dqData=front->data;
    newFront=front->next; free(front); 
    front=newFront;
    return(&dqData);
}
//main
int main()
{   int choice,enqData,*dqData;
    //initialising queue
    rear=front=(node*)malloc(sizeof(node)); 
    front->next=NULL;
    do
    {   printf("\n1 to enq-\t2 to dq-\t0 to exit\nchoice: ");    
        scanf("%d",&choice);
        switch(choice)
        {   case 0 : break;
            case 1 : printf("enter int to enq: ");
                     scanf("%d",&enqData); enq(enqData); 
                     break;
            case 2 : dqData=dq();
                     if(dqData==NULL) printf("queue is empty\n"); 
                     else printf("dequed int: %d\n",*dqData);
                     break;
            default : printf("wrong key\n");
        }
    } while(choice!=0);
    return 0;
}            
