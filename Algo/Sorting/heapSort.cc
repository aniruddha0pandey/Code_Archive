// Binary-Search Tree : Data of all the nodes in the left sub-tree of the root node should be ≤ the data of the root.
//                      The data of all the nodes in the right sub-tree of the root node should be > the data of the root.
// Binary-Heap   Tree : Data of the root node is > or < the data of two children node.

#include <iostream>

// bottom-up approach
void heapify (int arr[], int n, int i) {
	int heap = i;
	int l = (i << 1) + 1;
	int r = (i << 1) + 2;
	if ( (l < n) && (arr[l] > arr[heap]) ) heap = l;
	if ( (r < n) && (arr[r] > arr[heap]) ) heap = r;
	if (heap != i) {
		std::swap(arr[i], arr[heap]);
		heapify(arr, n, heap);
	}
}

void buildHeap (int arr[], int n) {
	for (int i = (n >> 1) - 1; i >= 0; --i)
		heapify(arr, n, i);
}

void extractHeap(int arr[], int n) {
	for (int i = n - 1; i >= 0; --i) {
		std::swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

void heapSort (int arr[], int n) {
	buildHeap(arr, n);
	extractHeap(arr, n);
}

char print(int arr[], int n) {
	for (int i = 0; i < n; ++i)
		std::cout << arr[i] << " ";
	return puts("");
}

int main (void) {
	int arr[] = {12, 11, 13, 5, 6, 7};
	int n = *(&arr + 1) - arr;
	heapSort(arr, n);
	print(arr, n);
	return 0;
}
