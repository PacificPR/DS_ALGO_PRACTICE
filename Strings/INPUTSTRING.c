#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void main(){
    char *s; 
    int size;
    printf("Enter size of String \n");
    scanf("%d",&size);
    while(getchar()!='\n'); //To remove \n from screen left on the screen
    //after the call to scanf() a newline character is left in the input stream. 
    //This newline character is read by the subsequent fgets() and gets terminated instantly. So we have to clear the input stream after the scanf():
    s=(char*)malloc(size*sizeof(char));

    printf("Enter the expression :  ");
    fgets(s,size*sizeof(char),stdin);
    printf("A char =%c\n",s[19]);
    puts(s);
}



