#include <stdlib.h>
#include <stdio.h>

int main(){
	int r,c,i,j;
	scanf("%d%d", &r,&c);
	int **M;
	M=(int **)malloc(r*sizeof(int *));
	for(i=0;i<r;i++)
		M[i] = (int *)malloc(c*sizeof(int));
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			scanf("%d",&M[i][j]);
    printf("REVERSE MATRIX : \n");
	for(i=0;i<c;i++){
		for(j=0;j<r;j++){
			printf("%d ",M[j][i]);
		}
		printf("\n");
	}  
}

