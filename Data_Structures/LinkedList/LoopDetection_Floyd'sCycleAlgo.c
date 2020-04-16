//FLOYD'S CYCLE ALGORITHM 
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
}*first=NULL;

void createLoopedLL(int A[],int n) {
    int i;
    struct node *t,*last,*loopnode;
    first=(struct node*)malloc(sizeof(struct node)); //Creating the first node 
    first->data=A[0];
    first->next=NULL;
    last=first;     //The last points to the current last node of the linked list

    for(i=1;i<n;i++) {
        t=(struct node*)malloc(sizeof(struct node));//A new node is created 
        t->data=A[i];
        t->next=NULL; //Currently it's the last node
        if(i==2)
            loopnode=t;
        last->next=t; //last is currently the previous node,so it should point to the new last node currently i.e t
        last=t;     //last will point to the current last node which is t
    }   
    last->next=loopnode;
}

void detectLoop(struct node* f) {
    struct node *p,*q;
    p=q=f;
    while(p&&q&&q->next){  // Checking if both the pointers are NOT NULL
        p=p->next;
        q=q->next->next;
        if(p==q) {
            printf("LinkedList has a loop\n");
            exit(0);
        }
    }
    printf("DOESN'T HAVE LOOP");
}

void disp(struct node* f) {
    struct node *p;
    while(p!=NULL) {
        printf("%d",p->data);
        p=p->next;
    }
}

int main() {
    int A[]={4,5,6,7,8};
    createLoopedLL(A,5);
    //disp(first); TO TEST IF LINKEDLIST IS LOOPED by displaying it's element
    detectLoop(first);
    
}

