// ####limits.h  The limits.h header determines various properties of the various variable types. 
// The macros defined in this header, limits the values of various variable types like char, int and long.
//These limits specify that a variable cannot store any value beyond these limits,
// EXAMPLE MACROS -> INT_MIN,INT_MAX,LONG_MIN,LONG_MAX,CHAR_MIN,CHAR_MAX,  UINT_MAX,
// SHRT_MAX,SHRT MIN, SCHAR_MIN,SCHAR_MAX #####

#include<limits.h>
#include<stdio.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;
    int *a;
};

void create(struct stack *st){
    printf("Enter Size of the stack    ");
    scanf("%d",&st->size);
    st->top=-1;
    st->a=(int *)malloc(st->size*sizeof(int));
}

void push(struct stack *st,int x){
    if(st->top>=st->size-1)
        printf("Stack Overflow\n");
    else{
        st->top+=1;
        printf("TOP POSITION : %d \n",st->top);
        st->a[st->top]=x;
        printf("%d pushed on Stack\n",x);
    }
}

int pop(struct stack *st){
    int x;
    if(st->top==-1){
        return INT_MIN;
    }
    else{
        printf("TOP POSITION FOR POP : %d\n",st->a[st->top]);
        x=st->a[st->top]; 
        st->top-=1;
        return x;
    }
}

int peek(struct stack *st,int pos){
    if(st->top-pos+1<0){
        return INT_MIN;
    }
    else
        return st->a[st->top-pos+1];
}

int isEmpty(struct stack *st){
    if(st->top==-1)
        return 1;
    else
        return 0;
}

int isFull(struct stack *st){
    if(st->top==st->size-1)
        return 1;
    else
        return 0;
}

int stackTop(struct stack *st){
    if(st->top==-1)
        printf("Stack Empty\n");
    else
        return st->a[st->top];
}

void main(){
    struct stack s;
    int i,popnum;
    create(&s);
    //printf("%d",pop(&s));
    push(&s,1);
    push(&s,2);
    push(&s,3);
    popnum=pop(&s);
    if(popnum==INT_MIN)
        printf("STACK UNDERFLOW\n");
    else
        printf("Popped Element = %d \n",popnum);
    push(&s,4);
    push(&s,5);
    push(&s,6);
    for(i=1;i<7;i++){
        if(peek(&s,i)==INT_MIN)
            printf("INVALID POSITION\n");
        else
            printf("Element at position %d is %d \n",i,peek(&s,i));
        }
}



