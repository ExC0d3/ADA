#include <stdio.h>
#include <stdlib.h>

void task(int a[], int d[], int p[], int x){
	
	int m = d[0],i,total=0,sum=0,cur=1;

	for(i=1;i<x;i++){
		total += p[i];

		if(d[i] > m)
			m = d[i];

		if( cur <= m){
			cur += 1;
			printf("T%d ",a[i]);
			sum += p[i];
		}
	}

	printf("\nTotal penalty:%d",(total-sum));
}

int main(int argc, char const *argv[])
{
	int x, a[20], i,j, temp, d[20], p[20];
	fflush(stdin);
	printf("\nNo. of tasks:");
	scanf("%d",&x);
	

	for(i=0;i<x;i++)
		a[i] = i+1;

	printf("\nEnter deadlines:");

	for(i=0;i<x;i++)
		scanf("%d",&d[i]);

	printf("\nEnter penalties:");

	for(i=0;i<x;i++)
		scanf("%d",&p[i]);

	printf("\n");
	for(i=0;i<x;i++)
		printf("%d ",p[i]);


	//sort in descending order of penalties

	for(i=0;i<x;i++){
		for(j=0;j<x-1;j++){
			if(p[j] < p[j+1]){
				temp = p[j];p[j] = p[j+1]; p[j+1] = temp;

				temp = d[j];d[j] = d[j+1]; d[j+1] = temp;

				temp = a[j];a[j] = a[j+1]; a[j+1] = temp;
			}
		}
	}
	printf("\n");
	for(i=0;i<x;i++)
		printf("%d ",p[i]);
	printf("\n");
	task(a,d,p,x);
	return 0;
}