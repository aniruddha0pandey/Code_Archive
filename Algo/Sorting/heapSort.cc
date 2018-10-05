// Binary-Search Tree : Data of all the nodes in the left sub-tree of the root node should be ≤ the data of the root.
//                      The data of all the nodes in the right sub-tree of the root node should be > the data of the root.
// Binary-Heap   Tree : Data of the root node is > or < the data of two children node.

#include <iostream>

bool childLarger(int arr[], int n, int i, int child) { return (child < n) && (arr[child] > arr[i]); }

// bottom-up approach
void heapify (int arr[], int n, int i) {
	int heap;
	int l = (i << 1) + 1;
	int r = (i << 1) + 2;

	if ( childLarger(arr, n, i, l) ) heap = l;
	if ( childLarger(arr, n, i, r) ) heap = r;
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
		heapify(arr, n, i);
	}
}

void heapSort (int arr[], int n) {
	buildHeap(arr, n);
	extractHeap(arr, n);
}

char print(int arr[], int n) {
	for (int i = 0; i < n; ++i)
		std::cout << arr[i] << std::endl;
	return puts("");
}

int main (void) {
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int n = *(&arr + 1) - arr;
	heapSort(arr, n);
	print(arr, n);
	return 0;
}
