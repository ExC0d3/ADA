#include <stdio.h>
#include <stdlib.h>


char *a;

int *s,*f;


void sort(int n){
	int x,b;
	for(x=0;x<n;x++){
		for(b=0;b<n-1;b++){
			if(f[b] > f[b+1]){
				int temp = f[b];
				f[b] = f[b+1];
				f[b+1] = temp;

				temp = s[b];
				s[b] = s[b+1];
				s[b+1] = temp;

				char c = a[b];
				a[b] = a[b+1];
				a[b+1] = c;
			}
		}
	}
}

void print(int n){
	int x,count=0;
	int temp = f[0];
	printf("%c ",a[0]);
	for(x=1;x<n;x++){
		count +=1;
		if(s[x] >= temp){
			temp = f[x];
			printf("%c ", a[x]);
		}
	}
	printf("\n%d",count);
}

int main(int argc, char const *argv[])
{
	int n=5,x;
	/*printf("\nn:");
	scanf("%d",&n);
	*/a = (char *)malloc(sizeof(char)*n);
	s = (int *)malloc(sizeof(int)*n);
	f = (int *)malloc(sizeof(int)*n);
	
	
	for(x=0;x<n;x++){
		scanf("%c",&a[x]);
		//printf("%c ",a[x]);
		scanf("%d%d",&s[x],&f[x]);
	}
	

	/*for(x=0;x<n;x++){
		printf("%c",a[x]);
	}
	printf("\n");
	*/
	sort(n);
	
	print(n);
	return 0;
}