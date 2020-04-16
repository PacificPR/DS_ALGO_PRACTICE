// ####limits.h  The limits.h header determines various properties of the various variable types. 
// The macros defined in this header, limits the values of various variable types like char, int and long.
//These limits specify that a variable cannot store any value beyond these limits,
// EXAMPLE MACROS -> INT_MIN,INT_MAX,LONG_MIN,LONG_MAX,CHAR_MIN,CHAR_MAX,  UINT_MAX,
// SHRT_MAX,SHRT MIN, SCHAR_MIN,SCHAR_MAX #####

#include<limits.h>
#include<stdlib.h>
#include<stdio.h>

struct snode{
    int data;
    struct snode *next;
}*top=NULL;

void push(int x){
        struct snode *t=(struct snode*)malloc(sizeof(struct snode));
        if(t==NULL)
            printf("Stack OVerflow\n");
        else{
            t->data=x;
            t->next=top;
            top=t;
            printf("Element Pushed in Stack : %d \n",x);
        }
}

int pop(){
    int x=INT_MIN;
    struct snode *t;
    if(top==NULL)
        printf("Stack is Empty\n");
    else{
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

void peek(int pos){
    struct snode *p;
    p=top;
    int i;
    for(i=1;i<pos&&p;i++){
        p=p->next;
    }
    if(p)
        printf("Element at %d is %d\n",pos,p->data);
    else
        printf("Invalid position\n");
}

int stackTop(){
    if(top)
        return top->data;
    else
        return INT_MIN;
}
    
int isEmpty(){
    if(top)
        return 0;
    else
        return 1;
}

int isFull(){
    struct snode *t;
    return t?0:1;
}

void display(struct snode* p) {
    printf("LINKED LIST IN NORMAL ORDER IS : ");
    struct snode *t=p;
    while(t!=0) {
        printf("%d\t",t->data);
        t=t->next;
    }   
    printf("\n");
}

void main(){
    printf("Popped no = %d\n",pop());
    push(1);
    push(2);
    push(3);
    printf("Popped no = %d\n",pop());
    push(4);
    display(top);
    printf("Popped no = %d\n",pop());
    display(top);
    printf("Stack TOP = %d\n",stackTop());
    peek(2);
}

