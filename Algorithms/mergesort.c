#include <stdio.h>
#include <stdlib.h>

int *temp,*arr,n;

void merge(int *, int, int, int);


void mergesort(int *arr,int l,int r){
	if(l<r){
		int mid = (l+r)/2;
		mergesort(arr,l,mid);
		mergesort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}

void merge(int *arr,int l,int mid,int r){
	int i,k,j;

	for(i=l;i<=r;i++)
		*(temp+i) = *(arr+i);

	i=l,j=mid+1,k=l;

	while(i <= mid && j<=r){
		if(*(temp+i) <= *(temp+j)){
			*(arr+k) = *(temp+i);
			i++;
		}
		else {
			*(arr+k) = *(temp+j);
			j++;
		}
		k++;
	}

	while(i<=mid){
		*(arr+k) = *(temp+i);
		i++; k++;
	}

	while(j<=r){
		*(arr+k) = *(temp+j);
		j++;
		k++;
	}
}

int main(){
	int a;
	printf("\n n: ");
	scanf("%d",&n);
	arr = (int *)malloc(sizeof(int)*n);
	temp = (int *)malloc(sizeof(int)*n);

	for(a=0;a<n;a++)
		scanf("%d",(arr+a));

	mergesort(arr,0,n-1);

	for(a=0;a<n;a++)
		printf("%d ",*(arr+a));
	return 0;
}