//IMPLEMENTATION OF HEAP SORT
//A SORTING ALGORITHM WITH A TIME COMPLEXITY OF O(n*lg n)
//THE ONLY SORTING ALGORITHM THAT GIVES COMPETITION TO QUICK SORT SINCE ITS AVERAGE TIME COMPLEXITY IS O(n*lg n)
//BUT IN QUICKSORT THE WORST CASE IS O(n^2)
#include<stdio.h>
#include<limits.h>
#define SIZE 100
int h[SIZE];
int size=0;
//FUNCTION TO SWAP ELEMENTS BY POSITIONS
int swap(x,y)
int x;
int y;
{
	int t;
	t=h[x];
	h[x]=h[y];
	h[y]=t;
	return 0;
}
//FUNCTION THAT RETURNS INDEX OF THE PARENT
int parent(i)
int i;
{
	return (i-1)/2;
}
//FUNCTION THAT RETURNS INDEX OF THE LEFT CHILD
int leftchild(i)
int i;
{
	return 2*i+1;
}
//FUNCTION THAT RETURNS INDEX OF THE RIGHT CHILD
int rightchild(i)
int i;
{
	return 2*(i+1);
}
//FUNCTION TO MOVE AN ELEMENT DOWNWARDS TO ITS APPROPRIATE POSITION
int shiftDown(i)
int i;
{
	int r,l,maxIndex=i;
	r=rightchild(i);
	if(r<size && h[r]>h[maxIndex])//TO CHECK IF IT SHOULD BE MOVED DOWNWARDS
	maxIndex=r;
	l=leftchild(i);
	if(l<size && h[l]>h[maxIndex])//TO CHECK IF IT SHOULD BE MOVED DOWNWARDS LEFT RATHER THAN RIGHT
	maxIndex=l;
	if(i!=maxIndex)//TO CHECK IF THE ELEMENT HAS EACHED ITS PROPER POSITON
	{
		swap(i,maxIndex);
		shiftDown(maxIndex);
	}
	return 0;
}
//FUNCTION TO BUILD A HEAP FROM THE GIVEN ARRAY OF ELEMENTS
int buildHeap(n)
int n;
{
	int i=(n-2)/2;//IF WE OVSERVE CAREFULLY WE JUST NEED TO SHIFT DOWN THE NON-LEAFS IN ORDER TO BUIL IT
	for(;i>=0;i--)
	shiftDown(i);
	return 0;
}
//FUNCTION THAT SORTS THE HEAP IN AN ORDER
int heapSort(n)
int n;
{
	buildHeap(n);//CALLING TO BUILD A HEAP FROM ARRAY
	int m=n-1;
	while(m--)
	{
		swap(0,size-1);//SWAPPING OF THE LAST ELEMENT TO GET THE ELEMENT AT SIZE AS THE LARGEST ELEMENT
		size--;//THE LAST ELEMENT PRESENT IS OUT OF HEAD AND STORED AS SINGLE NODE
		shiftDown(0);
	}
	return 0;
}
//FUNCTION TO PRINT THE SORTED HEAP
int print_arr(size)
int size;
{
	int i;
	printf("The sorted array is:\n");
	for(i=0;i<size;i++)
	printf("%d\t",h[i]);
	printf("\n");
	return 0;
}
//main FUNCTION TO SEND THE SIZE OF ARRAY AND CALL THE PRINTING FUNCTION
int main()
{
	int n,i;
	printf("Enter the no. of elements of the array:");
	scanf("%d",&n);
	size=n;
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
	scanf("%d",&h[i]);
	heapSort(n);
	print_arr(n);
	return 0;
}
//END OF PROGRAM
