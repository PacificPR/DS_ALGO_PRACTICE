
// C program to demonstrate the use of calloc() and malloc() 

//After successful allocation in malloc() and calloc(), a pointer to the block of memory is returned 
//otherwise NULL value is returned which indicates the failure of allocation. 

//###  ABOUT MALLOC  ###
//malloc() allocates memory block of given size (in bytes) and returns a
//pointer to the beginning of the block. malloc() doesn’t initialize the
//allocated memory. If we try to access the content of memory block(before
//initializing) then we’ll get segmentation fault error(or maybe garbage
//values). 

//###  ABOUT CALLOC  ###
//calloc() allocates the memory and also initializes the allocated memory
//block to zero. If we try to access the content of these blocks then we’ll get 0. 

//“free” method in C is used to dynamically de-allocate the memory.
//The memory allocated using functions malloc() and calloc() is not
//de-allocated on their own. Hence the free() method is used[201~
// “realloc” or “re-allocation” method in C is used to dynamically change
// the memory allocation of a previously allocated memory

#include <stdio.h> 
#include <stdlib.h> 
  
int main() 
{ 
    int* arr; 
  
    // malloc() allocate the memory for 5 integers 
    // containing garbage values 
    arr = (int*)malloc(5 * sizeof(int)); // 5*4bytes = 20 bytes 
  
    // Deallocates memory previously allocated by malloc() function 
    free(arr); 
  
    // calloc() allocate the memory for 5 integers and 
    // set 0 to all of them 
    arr = (int*)calloc(5, sizeof(int)); 
  
    // Deallocates memory previously allocated by calloc() function 
    free(arr); 
  
    return (0); 
} 

