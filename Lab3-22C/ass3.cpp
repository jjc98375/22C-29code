/*
	Name: Joshua Cho
	Professor: Manish Goel
	Class: CIS22C
	Project: Lab3
	Description:
		This program is purposedly made to practice mergesort. By utilizing the codes from Lab1, now 
		the program can sort the USD and C2D classe by using mergesort. It first asks how many classes
		that user want to input and retrieve all the data. Then, the program shows how original unsorted
		array looks, dynamically shows how the array being sorted, and shows the new sorted array.

*/

#include <iostream>
#include <string>
#include "USD.h"
#include "C2D.h"
#include <cmath>

using namespace std;

const int SORT_MAX_SIZE = 16; //maximum size of main array

void MergeSortRec(USD** arr, int begin, int end);
bool compareUandC(USD* a, USD* b);
void Merge(USD** arr, int begin, int mid, int end);


/*
pseudocode:
	create double pointer array of USD with SORT_MAX_SIZE.
	Ask user how any currency that they want to input.
	user input the size and it stored to the size variable
	loop:
		asks exactly 'size' time to users.
		ask user what currency that they want to input
		enter the amount
		create dynamically USD or C2D by the result of the input
	After creating the array, print the array
	MergeSort the array
	re-print the array
	delete the array

*/

int main() {

	USD** arr = new USD*[SORT_MAX_SIZE];
	
	int size;
	string cur;
	double amount;
	int wh;
	int de;


	cout << "How many currency do you want to enter? (put it less than 16) ";
	cin >> size;
	for(int i = 0; i < size; i++) {
		//ask the type of currency
		cin.clear();
		cout << "What type of currency you want to build?: ";
		//getline(cin, cur);
		cin >> cur;

		//ask the amount of the currency
		cout << "Enter the amount: ";
		cin >> amount;

		//calculate the amount to ready for the input
		wh = (int)floor(amount);
		amount -= wh;
		de = (int)round(amount * 100);

		//if cur = USD, put USD into the array, else, put C2D
		if (cur == "USD") {
			arr[i] = new USD("USD", de, wh);
		}
		else {
			arr[i] = new C2D("C2D", de, wh, 1.36);
		}
	}

	//print the original
	cout << "\nYou have your money in this order" << endl;
	for (int f = 0; f < size; f++) {		
		arr[f]->print();
	}

	cout << endl;
	cout << endl;

	//Now merge sort
	MergeSortRec(arr, 0, size - 1);

	cout << endl;

	//print the new sorted array
	cout << "\nJust completed the sorting!" << endl;
	cout << "Now you have your money in ascending order." << endl;
	for (int f = 0; f < size; f++) {
		arr[f]->print();
	}

	//delete the dynamically allocated main array
	for (int i = 0; i < size; i++) {
		delete arr[i];
	}
	delete[] arr;
	  
	system("pause");
	return 0;
}




/*
Algorithm compareUandC(USD* a, USD* b)

	This algorithm basically compares the USD object to see which one is smaller. Although, some of
	objects are C2D, so the program excerpt those class and cast it back to USD to compare.
	Pre: Retrieve two pointer of USD class; a and b. All the pointer should be valid USD pointer
	Post: It will return true if dereferenced value of a is smaller than or equal to dereferenced value of b
			Else, it will return false.

	Pseudocode:
		if(a or b is CAD) {
			downcast a to as CAD pointer 
			use C2U function to return converted value of a as USD object, which called temp
		}
		compare a and b
		return the corresponding results

*/
bool compareUandC(USD* a, USD* b) {
	if ((*a).getName() == "CAD") {
		C2D* c = dynamic_cast<C2D*>(a);
		USD temp = c->C2U();
		a = new USD(temp);
	}
	else if ((*b).getName() == "CAD") {
		C2D* c = dynamic_cast<C2D*>(b);
		USD temp = c->C2U();
		b = new USD(temp);
	}
	if ((*a) <= (*b)) {
		return true;
	}
	else {
		return false;
	}
}


/*
void Merge(USD** arr, int begin, int mid, int end)

	This algorithm called when the MergeSort function needs to merge back the array in to the main array.
	Pre: Receive the USD double pointer array, three integers that necessary for partitioning.
	Post: No returns but after the merge success the leftPos pass mid and rightPos pass end.

	Pseudocode:
		initialize mergeSize which indicates the size of merged partition
		initialize leftPos, rightPos and mergePos to track the position of arrays
		Create temporary array that will contain the merged array which will again be recopied back to the main array
		leftPos iterates from the very beginning
		rightPos iterates from the middle
		unless they reach to their delimiter, compare each elements that referenced by the each index.
		merge back with the very smallest one
		if there is left over put it all to the mergedArr.
		print the mergedArr so that user can see the updates
		copy the mergedArr back to the main array
		delete the mergedArr

*/
void Merge(USD** arr, int begin, int mid, int end) {
	int mergedSize = end - begin + 1;                // Size of merged partition
	int mergePos = 0;                          // Position to insert merged number
	int leftPos = 0;                           // Position of elements in left partition
	int rightPos = 0;                          // Position of elements in right partition
	USD** mergedArr = new USD*[mergedSize];   // Dynamically allocates temporary array

	leftPos = begin;                     
	rightPos = mid + 1;                      

	while (leftPos <= mid && rightPos <= end) {
		if (compareUandC(arr[leftPos], arr[rightPos])) {
			mergedArr[mergePos] = arr[leftPos];
			++leftPos;
		}
		else {
			mergedArr[mergePos] = arr[rightPos];
			++rightPos;
		}
		++mergePos;
	}

	while (leftPos <= mid) {
		mergedArr[mergePos] = arr[leftPos];
		++leftPos;
		++mergePos;
	}

	while (rightPos <= end) {
		mergedArr[mergePos] = arr[rightPos];
		++rightPos;
		++mergePos;
	}

	for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
		arr[begin + mergePos] = mergedArr[mergePos];
	}

	//print everytime it gets merged
	cout << "sorting is in progress" << endl;
	for (int f = 0; f < mergedSize; f++) {
		mergedArr[f]->print();
	}
	cout << endl;
	
	delete[] mergedArr;

}

/*
Algorithm MergeSortRec(USD** arr, int begin, int end)

	This algorithm initialize the MergeSort the array with the helper method "Merge". It is recursive
	function. 
	Pre: It passes in the main array, two index which indicates the beginning and the end.
	Post: No returns exist, but it is recursive function. After all recursions done, the main array will 
		have their data in ascending order. 


	pseudocode:
		if(begin is still less than end) {
			mid = begin + end / 2
			mergesort the bottom half
			mergesort the upper half
			merge
		}

*/
void MergeSortRec(USD** arr, int begin, int end) {
	int mid = 0;

	if (begin < end) {
		mid = (begin + end) / 2; 

		MergeSortRec(arr, begin, mid);
		MergeSortRec(arr, mid + 1, end);
		Merge(arr, begin, mid, end);
	}
}
