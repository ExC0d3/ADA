#include <stdio.h>
#include <stdlib.h>

void printLCS(int **b, char *x, int i, int j){
	if(i==0 || j==0){
		return;
	}
	else{
		if(b[i][j] == 2){
			printLCS(b,x,i-1,j-1);
			printf("%c ",x[i-1]);
		}
		else if(b[i][j] == 1){
			printLCS(b,x,i-1,j);
		}
		else{
			printLCS(b,x,i,j-1);
		}
	}
}


int main(int argc, char const *argv[])
{
	
	char *x = "ABCBDAB";
	char *y = "BDCABA";
	int a,i,j;
	int m = strlen(x); int n = strlen(y);
	printf("%d %d\n", m,n);
	int **b = (int **)malloc(sizeof(int)*(m+1));
	int **c = (int **)malloc(sizeof(int)*(m+1));

	for(a=0;a<m+1;a++){
		b[a] = (int *)malloc(sizeof(int)*(n+1));
		c[a] = (int *)malloc(sizeof(int)*(n+1));
	}

	for(a=0;a<m+1;a++){
		c[a][0] = 0;
	}

	for(a=0;a<n+1;a++){
		c[0][a] = 0;
	}

	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(x[i-1] == y[j-1]){
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = 2;
			}
			else if( c[i-1][j] >= c[i][j-1])
				b[i][j] = 1;
			else
				b[i][j] = 0;
		}
	}

	printLCS(b,x,m,n);

	return 0;
}