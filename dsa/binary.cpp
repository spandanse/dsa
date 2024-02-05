#include<stdio.h>
#define max 5

void sort(int arr[])
{
	int i,j,t=0;
	for(i=0; i<max; i++)
	{
		for(j=i+1; j<max; j++)
		{
			if(arr[j]<arr[i])
			{
				t=arr[i];
				arr[i]=arr[j];
				arr[j]=t;
				
			}
		}
	}
	printf("Array after sorting :");
	for(i=0; i<max; i++)
	{
		printf("%d ", arr[i]);
	}
}

void binary(int ar[], int x)
{
	int l=0, r=max, m;
	while(l<=r)
	{
		m=(l+r)/2;
		if(ar[m]==x)
		{
			printf("Element: %d is found at: %d ",x,m+1);
			break;
		}
		else if(ar[m]<x)
		{
			l=m+1;
		}
		else
		{
			r=m-1;
		}
	}
	if(l>r)
	{
		printf("Element not found");
	}
}

int main()
{
	int a[max],i,x;
	printf("Enter the elements");
	for(i=0; i<max; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a);
	printf("\nEnter element to search");
	scanf("%d", &x);
	binary(a,x);
}
