#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x){
    struct node *t;
    t=(struct node*)malloc(sizeof(struct node));
    if(t==NULL)
        printf("Queue is Full\n");
    else{
        t->data=x;
        t->next=NULL;
        if(front==NULL){
            front=t;
            rear=t;
        }
        else{
            rear->next=t;
            rear=t;
        }
    }
}

void dequeue(){
    struct node *t;
    if(front==NULL)
        printf("Queue is Empty\n");
    else{
        t=front;
        front=front->next;
        free(t);
    }
}

void isEmpty(){
    if(front==NULL)
        printf("Queue is empty\n");
    else
        printf("Queue is not empty\n");
}

void isFull(){
    struct node *p;
    if(p==NULL)
        printf("Queue is Full\n");
    else
        printf("Queue is Not Full\n");
}

void first(){
    if(front==NULL)
        printf("Queue Empty\n");
    else
        printf("First element = %d \n",front->data);
}

void last(){
    if(front==NULL)
        printf("Queue Empty\n");
    else
        printf("Last element = %d \n",rear->data);
}

void main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    first();
    last();
    dequeue();
    dequeue();
    first();
    last();
}
