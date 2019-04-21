#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <dos.h>
#include <stdlib.h>
#include <math.h>

int partition(int a[], int low, int high){
       int temp, key, i,j;
       key = a[low];
       i = low;
       j = high+ 1;
       while(i<=j){
	   do i++; while(key>=a[i]);
	   do j++; while(key<a[j]);
       }
       if(i<j){
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
       }
       temp = a[low];
       a[low] = a[j];
       a[j] = temp;
       return j;
}


void q(int a[], int low, int high){
	int k;
	if (low<high){
		k = partition(a, low, high);
		q(a, low, k-1);
		q(a, k+1, high);
	}
	delay(1);

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
	q(a,0,n-1);
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