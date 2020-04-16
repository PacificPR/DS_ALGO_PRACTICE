#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
}*first=NULL;

void create(int A[],int n) {
    int i;
    struct node *t,*last;
    first=(struct node*)malloc(sizeof(struct node)); //Creating the first node 
    first->data=A[0];
    first->next=NULL;
    last=first;     //The last points to the current last node of the linked list

    for(i=1;i<n;i++) {
        t=(struct node*)malloc(sizeof(struct node));//A new node is created 
        t->data=A[i];
        t->next=NULL; //Currently it's the last node
        last->next=t; //last is currently the previous node,so it should point to the new last node currently i.e t
        last=t;     //last will point to the current last node which is t
    }   
}

void display(struct node* p) {
    printf("LINKED LIST IN NORMAL ORDER IS : ");
    while(p!=0) {
        printf("%d\t",p->data);
        p=p->next;
    }   
}

void Rdisplay(struct node* p) {

    if(p!=NULL) {
        Rdisplay(p->next);
        printf("%d\t",p->data);
    }   
}

void sortedInsert(struct node *f,int n) {
    struct node *temp,*p,*q;
    p=f;
    q=NULL;
       while(p&&p->data<n) {
        q=p;
        p=p->next;
    }
    if(p) {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=n;
        temp->next=p;
        q->next=temp;
    }
}

int main() {
    int A[]={40,50,60,70,80};
    create(A,5);
    sortedInsert(first,65);
    display(first);
}

