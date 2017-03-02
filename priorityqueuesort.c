//IMPLEMENTATION OF PRIORITY QUEUE SORT
//IT ACTUALLY USES THE CONCEPT OF HEAP FORMATION AND HAS A TIME COMPLEXITY OF O(n*lg n)
#include<stdio.h>
#include<limits.h>
#define SIZE 100
int h[SIZE];
int arr[SIZE];
int asort[SIZE];
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
//FUNCTION TO MOVE AN ELEMENT UPWARDS TO ITS APPROPRIATE POSITION
int shiftUp(i)
int i;
{
	if(i>0 && h[parent(i)]<h[i])//TO CHECK IF IT IS AT ITS CORRECT POSITION
	{
		swap(i,parent(i));
		shiftUp(parent(i));
	}
	return 0;
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
//FUNCTION TO INSERT A NEW ELEMENT INTO THE HEAP
int insert(k)
int k;
{
	if(size==SIZE)//TO CHECK IF ANY SPACE IS LEFT OR NOT
	{
		printf("ERROR\n");
		return 0;
	}
	h[size]=k;
	shiftUp(size);//THE ELEMENT IS GIVEN THE END POSITION THEN MOVED UPWARDS TO REACH ITS APPROPRIATE POSITION
	size++;
	return 0;
}
//FUNCTION THAT RETURNS THE LARGEST ELEMENT IN THE HEAP
int extractMax()
{
	int result=h[0];
	h[0]=h[size-1];//THE LARGEST ELEMENT IS SWAPPED WITH THE LAST ELEMENT
	size--;
	shiftDown(0);
	return result;
}
//FUNCTION THAT INSERTS THE ARRAY ELEMENTS INTO THE HEAP AND THEN EXTRACTS THE MAXIMUM VALUE ONE AFTER OTHER
int prioritySort(n)
int n;
{
	int i;
	//INSERTION
	for(i=0;i<n;i++)
	insert(arr[i]);
	//EXTRACTION
	for(i=n-1;i>=0;i--)
	asort[i]=extractMax();
	return 0;
}
//FUNCTION TO PRINT THE SORTED ARRAY
int print_arr(size)
int size;
{
	int i;
	printf("The sorted array is:\n");
	for(i=0;i<size;i++)
	printf("%d\t",asort[i]);
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
	prioritySort(n);
	print_arr(n);
	return 0;
}
//END OF PROGRAM
