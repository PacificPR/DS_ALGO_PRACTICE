#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack {
    int size;
    int top;
    char *exp;
};

int isMatchingPair(char character1, char character2) 
{ 
   if (character1 == '(' && character2 == ')') 
     return 1; 
   else if (character1 == '{' && character2 == '}') 
     return 1; 
   else if (character1 == '[' && character2 == ']') 
     return 1; 
   else
     return 0; 
} 
void push(struct stack *st,char x){ 
    st->top+=1;
    st->exp[st->top]=x;
    }   


void pop(struct stack *st){
    //char p=st->exp[st->top];
    st->top=st->top-1;
    //return p;
}

int isEmpty(struct stack *st){
    if(st->top==-1)
        return 1;
    else
        return 0;
}

char peek(struct stack *st){
    return st->exp[st->top];
}

int isBalanced(char *s){
    struct stack *st;
    int slen=strlen(s);
    st=(struct stack*)malloc(sizeof(struct stack));
    st->top=-1;
    st->size=strlen(s);
    st->exp=(char*)malloc(2*slen*sizeof(char));
    //printf("\n String length : %d  \n",strlen(s));
    int i=0;
    while(s[i]!='\0'){
        if(s[i]=='('||s[i]=='{'||s[i]=='[')  
            push(st,s[i]);
        else if(s[i]==')'||s[i]=='}'||s[i]==']')
        {
            if(isEmpty(st))
                return 0;
            else if(isMatchingPair(peek(st),s[i])){
                pop(st);
            }
        }
        i++;
    }   
    if(isEmpty(st))
        return 1;
    else
        return 0;
    
}

void main(){
    //struct stack st;
    char *s; 
    s=(char*)malloc(20*sizeof(char));
    printf("Enter the expression :  ");
    fgets(s,20*sizeof(char),stdin);
    //puts(s);
    if(isBalanced(s))
        printf("\nBALANANCED\n");
    else
        printf("\nNOT BALANANCE\n");
}

