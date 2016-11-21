#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(int argc, char const *argv[])
{
	int i,j;
	char *p = "is";
	char *t = "this is my istring";
	int n = strlen(t);
	int m = strlen(p);
	printf("\n%d %d",n,m);
	for(i=0;i<n-m;i++){
		for(j=0;j<m;j++){
			if(t[i+j]!=p[j])
				break;
		}
		if(j==m)
			printf("\nPos:%d",i);
	}

	return 0;
}