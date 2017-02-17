//IMPLEMENTATION OF MERGESORT
//A SORTING METHOD WITH A TIME COMPLEXITY OF O(n*lg n)
//ADVANTAGE OF THIS SORTING ALGORITHM IS THAT IT HAS THE SAME TIME COMPLEXITY IN ANY CASE
//DISADVANTAGE IS THAT IT HAS A LOT OF COMPARISONS!!!!
#include<stdio.h>
#define SIZE 100
int arr[SIZE];
int merge(l,m,u)
int l;//THE LOWER BOUND
int m;//THE MID POSITION
int u;//THE UPPER BOUND
{
	int i,j,k;
	int n1=m-l+1;//SIZE OF 1ST ARRAY
	int n2=u-m;//SIZE OF 2ND ARRAY
	int a[n1],b[n2];
	//THE ELEMENT ON EITHER SIDES OF MID ARE PARTITIONED BETWEEN THE TWO ARRAY
	for(i=0;i<n1;i++)
	a[i]=arr[l+i];
	for(j=0;j<n2;j++)
	b[j]=arr[m+1+j];
	i=0;
	j=0;
	//THE MERGING OF ELEMENTS ACCORDING TO THE COMPARISONS TAKE PLACE
	for(k=l;i<n1 && j<n2;k++)
	{
		if(a[i]<=b[j])
		arr[k]=a[i++];
		else
		arr[k]=b[j++];
	}
	//THE REMAINING ELEMENTS IN a[] and b[] ARE PUSHED INTO RESULTANT ACCORDINGLY
	while(i<n1)
	arr[k++]=a[i++];
	while(j<n2)
	arr[k++]=b[j++];
	return 0;
}
//THE RECURSIVE FUNCTION TO DIVIDE THE ARRAY INTO SUBARRAYS
int mergesort(l,u)
int l;
int u;
{
	int m;
	if(l<u)
	{
		m=l+(u-l)/2;
		mergesort(l,m);
		mergesort(m+1,u);
		merge(l,m,u);
	}
	return 0;
}
//FUNCTION TO PRINT THE SORTED ARRAY
int print_arr(size)
int size;
{
	int i;
	printf("The sorted array is:\n");
	for(i=0;i<size;i++)
	printf("%d\t",arr[i]);
	printf("\n");
	return 0;
}
//main FUNCTION TO SEND THE SIZE OF ARRAY AND CALL THE PRINTING FUNCTION
int main()
{
	int n,i;
	printf("Enter the no. of elements of the array:");
	scanf("%d",&n);
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	mergesort(0,n-1);
	print_arr(n);
	return 0;
}
//END OF PROGRAM
