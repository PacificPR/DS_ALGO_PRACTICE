#include<stdio.h>

struct node {
    int data;
    struct node* next;
};

void displayINorder(struct node* p) {  //For printing linked list recursively in normal order
    
    while(p!=)) {
        printf("%d",p->data);
        display(p->next);
    }
}

void displayReverseOrder(struct node* p) {   //For printing linked list recursively in reverse order
    
    while(p!=)) {
        display(p->next);
        printf("%d",p->data);
    }
}

void main() {
    //Creat linked list first and fill it with elements
    struct node* first;
    displayINorder(first);
    //LINKED LIST IN REVERSE ORDER
    displayReverseOrder(first);
}
