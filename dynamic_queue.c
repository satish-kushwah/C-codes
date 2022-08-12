//dynamic q which doubles when overflow
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
  {if((1+q->rear)<(q->size))
   {q->rear++;
    q->data[q->rear]=*t;
   }
  else {q->size=2*q->size; 
        q->data=(int*)realloc(q->data,q->size*sizeof(int));
       q->rear++;
       q->data[q->rear]=*t;
       }
  }  
//dq
void dq(struct queue *q)
  {if((q->rear - q->front)>0)
    {q->front++; 
    printf("dqd: %d\n",q->data[q->front]); }
  else printf("empty\n");
  }
//main
main()
{int n,i,t;
q.rear=(-1); 
q.front=(-1); 
q.size=5;
q.data=(int*)malloc(q.size*sizeof(int));
do
  {printf("1 to enq\n");
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

for(i=q.front+1;i<=q.rear;i++)
printf("%d\n",q.data[i]);
}                   