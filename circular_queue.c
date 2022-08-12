//circular queue
#include<stdio.h>
#include<stdlib.h>
//q struct
struct queue {int size;
              int rear;
              int front;
              int *data;} ;
struct queue q;
//enq
void enq(struct queue *q, int *t)
{
 if(q->front < q->rear && q->rear < q->size)
 	{q->data[q->rear]=*t; q->rear++;}
 else if(q->front > q->rear && q->rear < q->size)
 	{q->data[q->rear]=*t; q->rear++;}
 else if(q->rear == q->size  &&  q->front > 0)
 	{q->rear=0; q->data[q->rear]=*t;; q->rear++;}
 else printf("\nfull\n");
}
//dq
void dq(struct queue *q)
{
 if((1+q->front) < q->rear  &&  q->front < (q->size-1))
 	{q->front++; printf("dqd %d",q->data[q->front]);}
 else if((1+q->front) > q->rear  &&  q->front < (q->size-1))
	{q->front++; printf("dqd %d",q->data[q->front]);}
 else if(q->front == (q->size-1)  &&  q->rear > 0  &&  q->rear != q->size)
 	{q->front=0; printf("dqd %d",q->data[q->front]);}
 else printf("\nempty\n");
}
//main
main()
{int n,i,t;
q.rear=0; q.front=(-1); q.size=10;
q.data=(int*)malloc(q.size*sizeof(int));
do
	{printf("\n1 to enq\n");
	printf("2 to dq\n");
	printf("0 to exit\n");
	scanf("%d",&n);
	switch(n)
	 {case 1: printf("add int: ");
	         scanf("%d",&t);
	         enq(&q,&t); break;
	  case 2: dq(&q); break;
	  case 0: break;
	 }
	}
while(n!=0);
} 
                      
