//IMPLEMENTATION OF BUBBLESORT
//A LINEAR TIME STABLE SORTING ALGORITHM
//TIME COMPLEXITY OF O(n^2)
#include<stdio.h>
#define SIZE 100
int arr[SIZE];
//THIS FUNCTION SORTS THE INPUT ARRAY
int bubbleSort(size)
int size;
{
	int i,j,t;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size-1;j++)
		{
			if(arr[j]>arr[j+1])
			{//SWAPPING TAKES PLACE
				t=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=t;
			}
		}
	}
	return 0;
}
//THIS FUNCTION PRINTS THE SORTED ARRAY
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
	bubbleSort(n);
	print_arr(n);
	return 0;
}
//END OF PROGRAM
