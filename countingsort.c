//IMPLEMENTATION OF COUNTING SORT
//A LINEAR TIME SORTING ALGORITHM THAT REQUIRES A LIMITING ELEMENT(k)
//IT HAS A TIME COMPLEXITY OF O(n+k) IN ANY CASE
//BUT THIS ALGORITHM WORKS ONLY FOR POSITIVE NUMBERS(SINCE INDEX CANNOT BE NEGATIVE)
#include<stdio.h>
#define SIZE 100
int arri[100];
int arro[100];
//FUNCTION TO SORT THE ARRAY
int countingSort(size,k)
int size;
int k;
{
	int c[k+1],i;
	//INITIALIZES EACH ELEMENT COUNT AS 0
	for(i=0;i<=k;i++)
	c[i]=0;
	//COUNTS THE FREQUENCY OF EACH ELEMENT AND STORES IN THE INDEX EQUAL TO THE ELEMENT
	for(i=0;i<size;i++)
	c[arri[i]]=c[arri[i]]+1;
	//CALCULATES THE NO. OF EEMENTS SMALLER THAN OR EQUAL TO AN ELEMENT
	for(i=1;i<=k;i++)
	c[i]=c[i]+c[i-1];
	//THE OUTPUT ARRAY IS UPDATED ACCORDINGLY BY CONSIDERING THE NO. OF ELEMENTS ABOVE ONE ELEMENT
	for(i=size-1;i>=0;i--)
	{
		arro[c[arri[i]]-1]=arri[i];
		c[arri[i]]=c[arri[i]]-1;//THE COUNT IS DECREASED BY ONE SINCE TE ELEMENT ENTERS TO THE OUTPUT ARRAY
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
	printf("%d\t",arro[i]);
	printf("\n");
	return 0;
}
//main FUNCTION TO SEND THE SIZE OF ARRAY AND CALL THE PRINTING FUNCTION
int main()
{
	int n,i,k;
	printf("Enter the no. of elements of the array:");
	scanf("%d",&n);
	printf("Enter the limiting element:");
	scanf("%d",&k);
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
	scanf("%d",&arri[i]);
	countingSort(n,k);
	print_arr(n);
	return 0;
}
//END OF PROGRAM
