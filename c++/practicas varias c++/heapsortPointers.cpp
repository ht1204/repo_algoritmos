#include <iostream> 
using namespace std; 

// A function to swap two values
void swapValues(int *p,int *q) 
{ 
   int temp = *p; 
   *p  = *q; 
   *q = temp; 
} 

// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void heapify(int *arr, int n, int i) 
{ 
	int largest = i; // Initialize largest as root 
	int left = 2*i + 1; // left = 2*i + 1 
	int right = 2*i + 2; // right = 2*i + 2 

	// If left child is larger than root 
	if (left < n && *(arr+left) > *(arr+largest)) 
		largest = left; 

	// If right child is larger than largest so far 
	if (right < n && *(arr+right) > *(arr+largest)) 
		largest = right; 

	// If largest is not root 
	if (largest != i) 
	{ 
		swapValues(arr+i, arr+largest); 

		// Recursively heapify the affected sub-tree 
		heapify(arr, n, largest); 
	} 
} 


// Main function to do heap sort 
void heapSort(int *arr, int n) 
{ 
	// Build heap (rearrange array) 
	for (int i = n / 2 - 1; i >= 0; i--) 
		heapify(arr, n, i); 

	// One by one extract an element from heap 
	for (int i=n-1; i>0; i--) 
	{ 
		// Move current root to end 
		swapValues(arr, arr+i); 

		// call max heapify on the reduced heap 
		heapify(arr, i, 0); 
	} 
} 


/* A utility function to print array of size n */
void printArray(int *dataArray, int n) 
{ 
	for (int i=0; i<n; i++){
		cout << *dataArray << " "; 
		dataArray++;
	}
	cout << "\n"; 
} 


//Main Function
int main() 
{ 
	int arr[] = {12, 11, 13, 5, 6, 7}; 
	//int arr[] = {12, 11, 13, 5, 6, 7,-154,580,1000,-10000}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	
	//Show the original array
	cout << "Original array is \n"; 
	printArray(&arr[0], n); 
	
	//Calling heapsort
	heapSort(arr, n); 
	cout << "\n\n"; 
	
	//Show the sorted array
	cout << "Sorted array is \n"; 
	printArray(&arr[0], n); 
}
