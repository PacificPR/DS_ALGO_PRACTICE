// A character is stored as its ASCII Code value in the memory location
// While printing we use %c to get the character
// If we use %d , we get the integer value (ASCII code) of that character
// Hence we can initialize characters as ASCII codes as well, i.e 65 for 'A'


#include<stdio.h>

void main() {
    char a='A';
    char b=97;
    int d = 'b'-95;
    printf("Character in  a = %c\n",a);
    printf("ASCII Code of a = %d\n",a);
 
    printf("Integer Operation on a Character 'b'-95 = %d\n\n",d);
    printf("Character in  b = %c\n",b);
    printf("ASCII Code of b = %d\n",b);
}
