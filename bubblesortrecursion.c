//IMPLEMENTATION OF BUBBLESORT USING RECURSION
//THIS HELPS TO REDUCE THE UNNECCESSARY COMPARISONS
//IT ALSO HAS A TIME COMPLEXITY OF O(n^2)
#include<stdio.h>
#define SIZE 100
int arr[SIZE];
//FUNCTION TO SORT THE ARRAY
int bubbleSort(size)
int size;
{
	int i,t;
	if(size==0)//BASE CASE
	return 0;
	for(i=0;i<size-1;i++)
	{
		if(arr[i]>arr[i+1])
		{//SWAPPING OF POSITIONS
			t=arr[i];
			arr[i]=arr[i+1];
			arr[i+1]=t;
		}
	}
	bubbleSort(size-1);//RECURSIVE CALL TAKES PLACE
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
	bubbleSort(n);
	print_arr(n);
	return 0;
}
//END OF PROGRAM
