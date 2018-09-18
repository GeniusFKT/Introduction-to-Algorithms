#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <ctime>

using namespace std;

LARGE_INTEGER nFreq;
LARGE_INTEGER t1;
LARGE_INTEGER t2;

double dt;	// 4 parameters used for detecting the running time of functions 

void insertionSort(int a[], int size);

void mergeSort(int a[], int size);
void mergeSortRecursive(int a[], int left, int right);


int main()
{
	int size = 10000;
	int array[10000] = {0};
	
	srand((unsigned)time(NULL));			// the numbers in the array will be 
											// generated randomly
	for (int j = 0; j < size; ++j)	
	{
		array[j] = (rand() - 16384);		// interval is [-16384, 16383]
		cout << array[j] << "  ";
	}
	cout << endl << endl;
	
	insertionSort(array, size);
	
	for (int i = 0; i < size; ++i)
		cout << array[i] << "  ";
	
	cout << endl << endl;
	return 0;
	
}



void insertionSort(int a[], int size)
{	
	if (size == 1)
		return;
	else
	{
		for (int i = 1; i < size; ++i)
		{
			int key = a[i];
			int j = i - 1;
			while (j >= 0 && key < a[j])
			{
				a[j+1] = a[j];
				j--;
			}
			
			a[j+1] = key;
		}
	}
}

void mergeSort(int a[], int size)
{
	mergeSortRecursive(a, 0, size-1);
}

void mergeSortRecursive(int a[], int left, int right)
{
	if (left == right)
		return;
	
	int center = (left + right) / 2;
	
	mergeSortRecursive(a, left, center);
	mergeSortRecursive(a, center+1, right);
	
	int *l = new int [center-left+2];
	int *r = new int [right-center+1];
	
	l[center-left+1] = 99999;
	r[right-center] = 99999;
	
	for (int i = left; i <= center; ++i)
		l[i-left] = a[i];
	for (int i = center + 1; i <= right; ++i)
		r[i-center-1] = a[i];
	
	int counter1 = 0, counter2 = 0;
	
	for (int i = left; i <= right; ++i)
	{
		if (l[counter1] > r[counter2])
		{
			a[i] = r[counter2];
			counter2++;
		}
		else
		{
			a[i] = l[counter1];
			counter1++;
		}
	}	
		
	delete [] l;
	delete [] r;
	
}