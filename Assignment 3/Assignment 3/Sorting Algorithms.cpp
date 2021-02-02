#include "Sorting Algorithms.h"
#include <iostream>
#include <iomanip>
#include <list>
#include <ctime>

using namespace std;

void SortingAlgorithms::displayTime(time_t start, time_t end)
{
	double time_taken = double(end - start);
	cout << "Time taken by program is : " << fixed
		<< time_taken << setprecision(5)<< " sec " << endl;
}

void SortingAlgorithms::Merge(int A[], int low, int mid, int high)
{
	// split the array to left and right part
	int LH = mid - low + 1;
	int  RH = high - mid;
	int *left = new int[LH];
	int *right = new int[RH];
	// move elements into left array
	for (int i = 0; i < LH; i++)
		left[i] = A[low + i];
	// move elements into right array
	for (int j = 0; j < RH; j++)
		right[j] = A[j + mid + 1];

	// Merging part
	int s = 0, j = 0, k = low;
	// s is for left array index pointing
	// j is for right array index pointing
	// k is for original array index pointing
	while (s < LH&&j < RH)
	{
		// sorting is performed
		if (left[s] < right[j])
			A[k++] = left[s++];
		else
			A[k++] = right[j++];
	}
	// only one of the below two loops will run
	// move remaining elements into the original array
	while (s < LH)
		A[k++] = left[s++];
	// move remaining element into the original array
	while (j < RH)
		A[k++] = right[j++];
	// delete left and right arrays
	delete[]left;
	delete[]right;
}

void SortingAlgorithms::MergeSort(int A[], int low, int high)
{
	time_t start, end;
	time(&start);
	int mid = (low + high) / 2;
	if (low < high)
	{
		MergeSort(A, low, mid);
		MergeSort(A, mid + 1, high);
		Merge(A, low, mid, high);
	}
	time(&end);
	displayTime(start, end);
}

int SortingAlgorithms::partition(int A[], int low, int high)
{
	int i = low;
	for (int j = low; j < high; j++)
	{
		if (A[j] < A[high])
		{
			swap(A[i], A[j]);
			i++;
		}
	}
	swap(A[i], A[high]);
	//i++;
	return i;
}

void SortingAlgorithms::QuickSort(int A[], int low, int high)
{
	time_t start, end;
	time(&start);
	if (low < high)
	{
		int index = partition(A, low, high);
		QuickSort(A, low, index - 1);
		QuickSort(A, index + 1, high);

	}
	time(&end);
	displayTime(start, end);
}

void SortingAlgorithms::selectionSort(int arr[], int size)
{
	time_t start, end;
	time(&start);
	for (int i = 0; i < size; i++)
	{
		int min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[min])
				min = j;
		}
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
	time(&end);
	displayTime(start, end);
}

void SortingAlgorithms::bubbleSort(int arr[], int size)
{
	time_t start, end;
	time(&start);
	bool NoMoreSwaps = false;
	for (int i = 0; i < size&&!NoMoreSwaps; i++)
	{
		NoMoreSwaps = true;
		for (int j = 0; j < size - 1; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				NoMoreSwaps = false;
			}
		}
	}
	time(&end);
	displayTime(start, end);
}


void SortingAlgorithms::insertionSort(int arr[], int size)
{
	time_t start, end;
	time(&start);
	for (int i = 1; i < size; i++)
	{
		int num = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > num)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = num;
	}
	time(&end);
	displayTime(start, end);
}


void SortingAlgorithms::heapify(int arr[], int size, int i) {

	// take indexes of current, it's left and it's right child nodes
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	

	// compare the current max element with the right child. 
	// If right is greater than current max. Then assign the max the index of right
	if (right < size && arr[right] > arr[max])
		max = right;

	// compare the current max element with the left child. 
	// If left is greater than current max. Then assign the max the index of left
	if (left < size && arr[left] > arr[max])
		max = left;


	// if the max element index, then perform swapping
	if (max != i) {
		swap(arr[i], arr[max]);
		heapify(arr, size, max);
	}
}

void SortingAlgorithms::heapSort(int arr[], int size) {
	time_t start, end;
	time(&start);
	// change the original array into max heap
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(arr, size, i);

	// apply heap sort on the given array
	for (int i = size - 1; i >= 0; i--) {
		// swap and perform percolate down
		// move last index to the first index and then perform heapify operation on it
		swap(arr[0], arr[i]);

		heapify(arr, i, 0);
	}

	time(&end);

	displayTime(start, end);
}


void SortingAlgorithms::CountSort(int arr[], int size) {
	time_t start, end;
	time(&start);
	int max = arr[0];

	// traverse and find the maximum element from the array
	for (int i = 1; i < size; i++) {
		if (arr[i] > max)
			max = arr[i];
	}

	int *count = new int[max];
	// intialize array with 0
	for (int i = 0; i <= max; ++i) {
		count[i] = 0;
	}

	// Store the count of each element of original array in count array
	for (int i = 0; i < size; i++) {
		count[arr[i]]++;
	}

	// Store the commulative count at each index in the count array
	for (int i = 1; i <= max; i++) {
		count[i] += count[i - 1];
	}
	int *B = new int[max];
	// get the element of count array corresponding to the element of original array. And then place the original array element on that index
	for (int i = size - 1; i >= 0; i--) {
		B[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}

	// Copy the sorted elements into original array
	for (int i = 0; i < size; i++) {
		arr[i] = B[i];
	}

	time(&end);
	displayTime(start, end);
	/*delete[] B;
	delete[] count;*/
	
}

void SortingAlgorithms::radixSort(int arr[], int size)
{
	time_t start, end;
	time(&start);
	int max = arr[0], pos = 1;
	int *tempArr = new int[size];
	max = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}

	int *count = new int[size];
	while (max / pos > 0)
	{


		for (int i = 0; i < size; i++)
			count[i] = 0;


		for (int i = 0; i < size; i++)
			count[arr[i] / pos % 10]++;

		for (int i = 1; i < 10; i++)
			count[i] += count[i - 1];

		for (int i = size - 1; i >= 0; i--)
			tempArr[--count[arr[i] / pos % 10]] = arr[i];

		for (int i = 0; i < size; i++)
			arr[i] = tempArr[i];
		pos = pos * 10;
	}
	delete[]count;
	delete[]tempArr;
	
	time(&end);
	displayTime(start, end);
}


void SortingAlgorithms::bucketSort(int arr[], int size)
{
	// Logic: First we have to read all the elements one by one. Then if they are integers divide them by 10
	// After dividing we will get the bucket index. Place this element at this bucket index. Similarly do this for complete array
	// After this sort each bucket seperately. And then append each bucket into the array

	// buckets creation equal to size
	time_t start, end;
	time(&start);
	list<int> *buckets = new list<int>[size];

	// dividing each element with size to get bucket index and then place each array element into their respective bucket
	for (int i = 0; i < size; i++)
	{
		int index = floor(size / arr[i]);
		buckets[index].push_back(arr[i]);
	}
2
	// Sorting individual Buckets
	for (int i = 0; i < size; i++)
	{
		buckets[i].sort();
	}

	// reading elements from each buckets and adding it into the array
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		for (int num : buckets[i])
		{
			arr[index++] = num;
		}
	}
	time(&end);
	displayTime(start, end);
}

void SortingAlgorithms::swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}