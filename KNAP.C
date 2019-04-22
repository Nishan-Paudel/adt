#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int maxe(int a, int b){
	return (a>b)?a:b;
}

void optimal_solution(int v[10][10], int n, int m, int p[10], int w[10]){
	int i,j;
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++)
			v[i][j] =0;
	}
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			if(i==0 || j==0)
				v[i][j]=0;
			else if (j<w[i])
				v[i][j] = v[i-1][j];
			else
				v[i][j]=maxe(v[i-1][j], v[i-1][j-w[i]]+p[i]);
		}
	}
	printf("The resultant matrix is\n");
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++)
			printf("%d\t", v[i][j]);
		printf("\n");
	}
	printf("The optimal solution is %d\n", v[n][m]);

}


void main(){
	int i,j, n, m, w[10], p[10], v[10][10];
	clrscr();
	printf("Enter the number of object\n");
	scanf("%d", &n);
	printf("Enter the weight of the object \n");
	for(i=1;i<=n;i++)
		scanf("%d", &w[i]);
	printf("Enter the profits of objects\n");
	for(i=1;i<=n;i++)
		scanf("%d", &p[i]);
	printf("Enter the capacity of knapsack\n");
	scanf("%d", &n);
	optimal_solution(v,n,m, p, w);
	getch();

}

