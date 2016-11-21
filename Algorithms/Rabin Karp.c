#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>
#define d 256 //number of characters in input


void search(char txt[], char pat[], int q){

	int M = strlen(pat);
	int N = strlen(txt);
	int p=0,t=0,h=1,a,i,j;
	//h = pow(d,m-1)%q
	h = pow(d,M-1);
	h = h%q;
	//calculate initial hash for txt and pattern

	for(i=0;i<M;i++){
		
		p = (d*p + pat[i])%q;
		t = (d*t + txt[i])%q;
	}
	printf("\nInitial hashes:%d %d",p,t);

	for(i=0;i<=N-M;i++){
		if(p==t){
			printf("\nMatched hashes");
			for(j=0;j<M;j++){
				if(txt[i+j] != pat[j])
					break;
			}
			if(j >= M)
				printf("\nPos:%d",i);
			else
				printf("\nNot:%d",i);

		}

		if( i < N-M){
			t = (d*(t-txt[i]*h) + txt[i+M])%q;

			if(t<0){
				t += q;
			}
		}
		printf("\nNew hash:%d",t);
	}
}

int main(int argc, char const *argv[])
{
	char txt[] = "324156";
	char pat[] = "24";
	
	search(txt,pat,101);
	return 0;
}