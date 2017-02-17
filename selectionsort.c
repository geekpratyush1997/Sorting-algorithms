//IMPLEMENTATION OF SELECTION SORT
//A LINEAR TIME SORTING ALGORITHM WITH A TIME COMPLEXITY OF O(n^2)
#include<stdio.h>
#define SIZE 100
int arr[SIZE];
//FUNCTION TO SORT THE ARRAY
int selectionSort(size)
int size;
{
	int i,j,s,pos,f;
	for(i=0;i<size;i++)
	{
		s=arr[i];
		for(j=i;j<size;j++)
		{
			if(arr[j]<s)
			{//THE POSITION  OF THE SMALLEST ELEMENT BETWEEN THE RANGE OF INDEX IS STORED
				pos=j;
				s=arr[j];
				f=1;//TO MAKESURE THAT A SMALLER ELEMENT HAS BEEN FOUND
			}
		}
		if(f==1)
		{//SWAPPING OF POSITIONS
			arr[pos]=arr[i];
			arr[i]=s;
		}
		f=0;
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
	selectionSort(n);
	print_arr(n);
	return 0;
}
//END OF PROGRAM
