//IMPLEMENTATION OF INSERTION SORT
//A LINEAR TIME SORTING ALGORITHM WITH A TIME COMPLEXITY OF O(n^2)
//THIS IS A GOOD METHOD FOR SORTING NEARLY SORTED ARRAYS(BUT THE BEST METHOD IS THE  DIJKSTRA'S SMOOTHSORT)
#include<stdio.h>
#define SIZE 100
int arr[SIZE];
//FUNCTION TO SORT THE ARRAY
int insertionSort(size)
int size;
{
	int i,j,s;
	for(i=1;i<size;i++)
	{
		s=arr[i];
		j=i-1;
		//EACH ELEMENT ENTERS INTO SOMEWHAT A SORTED ARRAY AND IS PLACED AT PROPER INDEX
		while(j>=0 && arr[j]>s)
		{//ELEMENTS ARE MOVED ONE INDEX AHEAD TO MAKE A GAP FOR THE INCOMING ELEMENT
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=s;
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
	insertionSort(n);
	print_arr(n);
	return 0;
}
//END OF PRORAM
