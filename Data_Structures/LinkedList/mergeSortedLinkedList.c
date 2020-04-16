//WE ARE CHANGING THE LINKS AS PER THE VALUES IN TWO LINKEDLISTS 
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
} *first=NULL;
struct node *second=NULL,*third=NULL;

struct node* create(int A[],int n){
    int i;
    struct node *f,*t, *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=A[0];
    p->next=NULL;
    f=p;
    for(i=1;i<n;i++) {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=NULL;
        p->next=t;
        p=p->next;
    }
    return f;
}

void disp(struct node *f) {
    struct node *p;
    p=f;
    while(p!=NULL){
        printf("%d\t",p->data);
        p=p->next;
    }
}

struct node* merge(struct node *f,struct node *s) {
    struct node *third,*last;
    //third will be our new linkedlist created by altering the links between
    //the two linked lists
    //For first Node,we set the third and last pointer on smallest value
    //the last pointer denotes the last pointer in the third list
    if(f->data<s->data) {
       third=last=f;
       f=f->next;
       last->next=NULL;
    }
    else {
        third=last=s;
        s=s->next;
        last->next=NULL;
    }
    //After setting the first node,we change links depending on values
    while(f&&s) {
        if(f->data<s->data) {
            last->next=f;
            last=f;
            f=f->next;
            last->next=NULL;
        }
        else {
            last->next=s;
            last=s;
            s=s->next;
            last->next=NULL;
        }
        if(f)
            last->next=f;
        else
            last->next=s;
    }
    return third;
}

void main() {
    int A[]={11,32,73,77,80,82,84,95};
    int B[]={1,31,53,94,99};
    first=create(A,8);
    second=create(B,5);
    third=merge(first,second);
    disp(third);
}


