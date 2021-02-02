#include <ctime>
#pragma once
class SortingAlgorithms{



public:
	void displayTime(time_t start, time_t end);

	void Merge(int A[], int low, int mid, int high);

	void MergeSort(int A[], int low, int high);

	int partition(int A[], int low, int high);

	void QuickSort(int A[], int low, int high);



	void selectionSort(int arr[], int size);
	void bubbleSort(int arr[], int size);


	void insertionSort(int arr[], int size);

	void bucketSort(int arr[], int size);

	void shellSort(int arr[], int size);


	void heapify(int arr[], int n, int i);

	void heapSort(int arr[], int n);

	void CountSort(int arr[], int size);

	void radixSort(int arr[], int size);

	void swap(int &a, int &b);


};