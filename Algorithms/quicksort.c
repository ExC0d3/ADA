#include <stdio.h>
#include <stdlib.h>

int *arr,n;

int partition(int *arr,int l,int piv,int r);

void quicksort(int *arr,int l, int r){
	if(l<r){
		int pivot = (l+r)/2;
		pivot = partition(arr,l,pivot,r);
		quicksort(arr,l,pivot-1);
		quicksort(arr,pivot+1,r);
	}
}

int partition(int *arr,int l,int piv, int r){
	int val = *(arr+piv),i=l-1,j=r+1,temp;

	while(1){
		while(i<=r && *(arr+i) <= val)
			i++;
		while(j>=0 && *(arr+j) > val)
			j--;

		if(i<j){
			temp = *(arr+i);
			*(arr+i) = *(arr+j);
			*(arr+j) = temp;
		}
		else{
			break;
		}
	}

	return i;
}

int main(int argc, char const *argv[]){
	int a;//0 -1 3 10 2 6 7 4 5 11
	printf("\n n: ");
	scanf("%d",&n);

	arr = (int *)malloc(sizeof(int)*n);

	for(a=0;a<n;a++)
		scanf("%d",(arr+a));

	quicksort(arr,0,n-1);

	for(a=0;a<n;a++)
		printf("%d", *(arr+a));

	return 0;
}