#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <dos.h>
#include <stdlib.h>
#include <math.h>


void smg(int a[], int low, int mid, int high){
	int i, j, k, c[10000];
	j = mid + 1;
	i= low;
	k = low;
	while(i<=mid && j<=high){
		if(a[i]<a[j]){
			c[k] = a[i];
			i++; k++;
		}
		else{
			c[k] = a[j];
			j++; k++;
		}
	}
	while (i<=mid){
		c[k] = a[i];
		i++; k++;
	}
	while(j<=high){
		c[k] = a[j];
		j++; k++;
	}
	for(i=low;i<=high; i++)
		a[i] = c[i];

}

void ms(int a[], int low, int high){
	int mid;
	if (low<high){
		mid = (low+high)/2;
		ms(a, low, mid);
		ms(a, mid+1, high);
		smg(a, low, mid, high);
		delay(1);
	}
}


void main(){
	int a[30000], n, i;
	float res;
	clock_t start, end;
	clrscr();
    for(n=1000;n<=10000;n+=1000){
       /*
	printf("Enter the size of the array\n");
	scanf("%d", &n);
	*/
	for(i=0;i<n;i++)
		a[i] = rand();
	/*
	printf("Unsorted array is \n");
	for(i=0;i<n;i++)
		printf("%d\n", a[i]);
	*/

	start = clock();
	ms(a,0,n-1);
	end= clock();
	res =(float)((end-start)/CLK_TCK);
      //	printf("The sorted array is \n");
       //	for(i=0;i<n;i++)
	 //	printf("%d\n",a[i]);
	printf("***Info*** start=%ld end=%ld **=%d\n",start, end, CLK_TCK);
	printf("Time needed to sort %d elements is %f\n",n, res);
  }
	getch();

}