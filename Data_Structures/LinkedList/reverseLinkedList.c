//REVERSING LINKED LISTS USING SLIDING POINTERS
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

struct node* reverseLinkedList(struct node* f) {
    struct node *p,*q,*r; //q will be the current node whose links will be changed, r would be previous and p would be after q
    //So, r , q , p  will be the order of pointers 
    r=NULL;
    q=r;
    p=f;
    while(p!=NULL) {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    f=q;
    return f;
}

int main() {
    int A[]={4,5,6,7,8};
    create(A,5);
    printf("Reversed Linked list=\n");
    display(reverseLinkedList(first));
}

