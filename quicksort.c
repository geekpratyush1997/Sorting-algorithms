//IMPLEMENTATION OF QUICKSORT
//THE BEST SORTING ALGORITHM WITH A TIME COMPLEXITY OF O(n*lg n)
//THE ADVANTAGES OF THIS ALGORITHM LIES IN THE FACT THAT IT RELATIVELY DOES VERY LESS COMPARISONS AND THERE IS NO SPACE WASTAGE
//NOTE:IT IS BY FAR THE THE BEST SORTING ALGORITHM BUT AT TIMES DUE TO BAD SELECTION OF PIVOT THE COMPLEXITY MAY BECOME O(n^2) AT THAT TIME HEAP SORT BECOMES A BETTER CHOICE
//NOTE:BUT A COMBINATION OF THE TWO IS MORE PREFERABLE AND THAT IS CALLED THE INTROSORT!!
#include<stdio.h>
#define SIZE 100
int arr[SIZE];
//FUNCTION TO DO THE SWAPING OF ELEMENTS
int swap(x,y)//IT TAKES THE POSITION OF ELEMENTS TO BE SWAPPED
int x;
int y;
{
	int t;
	t=arr[x];
	arr[x]=arr[y];
	arr[y]=t;
	return 0;
}
//FUNCTION THAT BRING ALL THE ELEMENTS SMALLER THAN THE PIVOT TO THE LEFT AND GREATER ONES TO THE RIGHT
int partition(l,u)
int l;//THE LOWER BOUND
int u;//THE UPPER BOUND
{
	int i,j,pivot;
	pivot=arr[u];//THE LAST ELEMENT IS SELECTED AS THE PIVOT
	i=l;
	for(j=l;j<u;j++)
	if(arr[j]<=pivot)
	{
		swap(i,j);//THIS SWAP HELPS IN SWAPPING A LARGE ELEMENT WITH A SMALLER ONE(RELATIVE TO THE PIVOT)
		i++;
	}
	swap(i,u);//THIS SWAP BRINGS THE PIVOT TO ITS POSITION
	return i;//THE POSITION OF PIVOT IS RETURNED
}
//FUNCTION TO DIVIDE THE ARRAY AND SEND THE POSTIONS
int quickSort(l,u)
int l;//THE LOWER BOUND
int u;//THE UPPER BOUND
{
	int p;
	if(l<u)
	{
		p=partition(l,u);
		quickSort(l,p-1);
		quickSort(p+1,u);
	}
	return 0;
}
//FUNCTION TO PRINT THE ARRAY
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
	quickSort(0,n-1);
	print_arr(n);
	return 0;
}
//END OF PROGRAM
