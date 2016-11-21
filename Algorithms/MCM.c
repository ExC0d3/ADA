#include <stdio.h>
#include <stdlib.h>
int n,**m,*arr,**s,a,l,i,j,k,t;
/*
	n := number of arrays
	m := table to store the cost of muliplying arrays
	s := stores the optimal position for parentheses, i.e value of k
  	Ex
  	p = <p0,p1,p2,p3,p4>
  	m(i,j) = m(i,k) + m(k,j) + p(i-1)*p(k)*p(j)
  	s(i,j) = min(m) for all possible values of k  
*/

void printMCM(int **s, int i, int j){
	if(i==j){
		printf("A%d",i);
	}
	else{
		printf("(");
		printMCM(s,i,*(*(s+i)+j));
		printMCM(s,*(*(s+i)+j)+1, j);
		printf(")");
	}

}

int main(){
	printf("\nNumber of elements: ");
	scanf("%d",&n);
	printf("\nEnter elements: ");
	
	arr = (int *)malloc(n*sizeof(int));
	m = (int **)malloc(n*sizeof(int));
	s = (int **)malloc(n*sizeof(int));

	for(a=0;a<n;a++){
		m[a] = (int *)malloc(n*sizeof(int));
		s[a] = (int *)malloc(n*sizeof(int));
	}

	for(a=0;a<n;a++){
		scanf("%d ",arr+a);
	}

	for(a=1;a<n;a++){
		*(*(m+a)+a) = 0;
	}

	for(l=2;l<n;l++){
		for(i=1;i<n-l+1;i++){
			j =i+l-1;
			*(*(m+i)+j) = 21476876;
			for(k=i;k<j;k++){
				t = *(*(m+i)+k) + *(*(m+k+1)+j) + *(arr+i-1)*(*(arr+k))*(*(arr+j));
				printf("%d ",t);
				if(t < *(*(m+i)+j)){
					*(*(m+i)+j) = t;
					*(*(s+i)+j) = k;
				} 
			}
		}
	}

	printMCM(s,1,n-1);
	return 0;
}
