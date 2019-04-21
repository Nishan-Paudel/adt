#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <dos.h>

void bubble(int a[], int n){
	int temp, i, j;
	for(j=0;j<n-1;j++){
		for(i=0;i<n-1-j;i++){
			if(a[i]>a[i+1]){
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;

			}
		}
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
	bubble(a,n);
	end= clock();
	res = (end-start)/CLK_TCK;
      //	printf("The sorted array is \n");
       //	for(i=0;i<n;i++)
	 //	printf("%d\n",a[i]);
	printf("***Info*** start=%f end=%f **=%d\n",start, end, CLK_TCK);
	printf("Time needed to sort %d elements is %f\n",n, res);
  }
	getch();

}