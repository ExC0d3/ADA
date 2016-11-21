import java.util.*;

class MCM{

	void printMCM(int s[][],int i, int j){
		if(i==j){
			System.out.print("A"+i);
		}
		else{
			System.out.print(" ( ");
			printMCM(s, i, s[i][j]);
			printMCM(s, s[i][j]+1,j);
			System.out.print(" ) ");
		}
	}

	public static void main(String args[]){
		int arr[] = {1,2,1,2,1};

		int s[][] = new int[5][5];
		int m[][] = new int[5][5];

		for(int a=1;a<5;a++){
			m[a][a] = 0;
		}

		for(int l=2;l<5;l++){
			for(int i=1;i<5-l+1;i++){
				int j=i+l-1;
				m[i][j] = Integer.MAX_VALUE;
				for(int k=i;k<j;k++){
					int t = m[i][k] + m[k+1][j] + (arr[i-1]*arr[j]*arr[k]);
					if(t < m[i][j]){
						m[i][j] = t;
						s[i][j] = k;
					}
				}
			}
		}

		new MCM().printMCM(s,1,4);
	}
}