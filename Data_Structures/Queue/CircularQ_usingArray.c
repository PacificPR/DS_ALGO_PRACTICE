#include<stdio.h>
#include<stdlib.h>

struct queue{
    int f;
    int r;
    int size;
    int *a; 
};

void enqueue(struct queue *q,int x){ 
    if((q->r+1)%(q->size)==q->f)
        printf("Queue Full\n");
    else{ 
        q->r=(q->r+1)%(q->size);
        q->a[q->r]=x;
    }   
}

void dequeue(struct queue *q){
    if(q->f==q->r)
        printf("Queue is empty\n");
    else{
        q->f=(q->f+1)%q->size;
        printf("Deleted element = %d \n",q->a[q->f]);
    }   
}

void isEmpty(struct queue *q){
    if(q->f==q->r)
        printf("Queue is empty\n");
    else
        printf("Queue is not empty\n");
}

void isFull(struct queue *q){
    if(q->r==q->size-1)
        printf("Queue is Full\n");
    else
        printf("Queue is Not Full\n");
}

void first(struct queue *q){
    if(q->f==q->r)
        printf("Queue Empty\n");
    else
        printf("First element = %d \n",q->a[q->f+1]);
}

void last(struct queue *q){
    if(q->f==q->r)
        printf("Queue Empty\n");
    else
        printf("Last element = %d \n",q->a[q->r]);
}

void main(){
    struct queue q;
    printf("Enter size of the Queue\n");
    scanf("%d",&q.size);
    q.a=(int *)malloc(q.size*sizeof(int));
    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);
    first(&q);
    last(&q);
    dequeue(&q);
    enqueue(&q,4);
    enqueue(&q,5);
    enqueue(&q,6);
    dequeue(&q);
    enqueue(&q,7);
    first(&q);
    last(&q);
}
