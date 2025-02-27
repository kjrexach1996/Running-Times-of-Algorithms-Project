// Running Times of Algorithms Project.cpp (Part 1) - This program uses 3 different search algorithms
// to look through a vector of sorted integers and determines whether a target value chosen by the user
// is present or absent in the vector. All targets not found in vector will result in each search algorithm
// returning -1.

#include <iostream>
#include <algorithm> // Included to sort vector
#include <vector>

using namespace std;

// Preconditions: Vector must be accessible and nonempty; target, low, and high must be integers;
// at first, low must be 0 and high must be the last index in the vector; low and high must update
// with the correct parameters as the vector halves during every recursive call.
// Postconditions: original function call will return a -1 if target value was not found or
// a value representing the index where the target was found; vector must stay the same.
int recursiveSearch(const vector<int>& vec, int value, int low, int high);

// Preconditions: Vector must be accessible and nonempty; target must be an integer;
// Postconditions: function will return a -1 if target value was not found or
// a value representing the index where the target was found; vector must stay the same.
int iterativeSearch(const vector<int>& vec, int value);

// Preconditions: Vector must be accessible and nonempty; target must be an integer;
// Postconditions: function will have gone through every index in vector until target value
// was found. If not found, returns -1.
int sequentialSearch(const vector<int>& vec, int value);

int main()
{
	//Creating the vector to search for elements
	vector<int> myVector = { 5, 9, 7, 4, 8, 3, 1, 2, 6, 10 };

	//Vector before sorting
	cout << "Unsorted vector: ";
	for (int i = 0; i < myVector.size(); ++i)
	{
		cout << myVector[i] << " ";
	}
	cout << endl;

	//Sort the elements of the vector in ascending order
	sort(myVector.begin(), myVector.end());

	//Vector after sorting
	cout << "Sorted vector: ";
	for (int i = 0; i < myVector.size(); ++i)
	{
		cout << myVector[i] << " ";
	}
	cout << endl << endl;

	//*** RECURSIVE SEARCHES ***//
	cout << "Recursive Binary Search" << endl;

	//Searching for PRESENT element using recursive binary search
	int target = 7;
	int result = recursiveSearch(myVector, target, 0, (myVector.size() - 1));

	//Checking if element is in vector
	if (result != -1)
		cout << "Element " << target << " was found at index " << result << "." << endl;
	else
		cout << "Element " << target << " was not found." << endl;

	//Resetting target for ABSENT element using recursive binary search
	target = 11;
	result = recursiveSearch(myVector, target, 0, (myVector.size() - 1));

	//Checking if element is in vector
	if (result != -1)
		cout << "Element " << target << " was found at index " << result << "." << endl;
	else
		cout << "Element " << target << " was not found." << endl;

	cout << endl;

	//***ITERATIVE SEARCHES***//
	cout << "Iterative Binary Search" << endl;

	//Searching for PRESENT element using iterative binary search
	target = 3;
	result = iterativeSearch(myVector, target);

	//Checking if element is in vector
	if (result != -1)
		cout << "Element " << target << " was found at index " << result << "." << endl;
	else
		cout << "Element " << target << " was not found." << endl;

	//Resetting target for ABSENT element using iterative binary search
	target = 23;
	result = iterativeSearch(myVector, target);

	//Checking if element is in vector
	if (result != -1)
		cout << "Element " << target << " was found at index " << result << "." << endl;
	else
		cout << "Element " << target << " was not found." << endl;

	cout << endl;

	//***SEQUENTIAL SEARCHES***//
	cout << "Sequential Search" << endl;

	//Searching for PRESENT element using sequential search
	target = 9;
	result = sequentialSearch(myVector, target);

	//Checking if element is in vector
	if (result != -1)
		cout << "Element " << target << " was found at index " << result << "." << endl;
	else
		cout << "Element " << target << " was not found." << endl;

	//Resetting target for ABSENT element using sequential search
	target = -13;
	result = sequentialSearch(myVector, target);

	//Checking if element is in vector
	if (result != -1)
		cout << "Element " << target << " was found at index " << result << "." << endl;
	else
		cout << "Element " << target << " was not found." << endl;

	cout << endl;
}

int recursiveSearch(const vector<int>& vec, int value, int low, int high)
{
	//If false, target was not found; returns -1
	if (low <= high)
	{
		//Halves the vector in two
		int mid = low + ((high - low) / 2);

		if (vec[mid] == value)
			return mid; //Returns the index where target was found
		else if (vec[mid] < value)
			return recursiveSearch(vec, value, mid + 1, high); //Function call searches back half of vector
		else
			return recursiveSearch(vec, value, low, mid - 1); //Function call searches front half of vector
	}
	else
		return -1;
}

int iterativeSearch(const vector<int>& vec, int value)
{
	//Initiates beginning and end indexes of vector
	int low = 0;
	int high = vec.size() - 1;

	//If false, target was not found; returns -1
	while (low <= high)
	{
		//Halves the vector in two
		int mid = low + ((high - low) / 2);

		if (vec[mid] == value)
			return mid; //Returns the index where target was found
		else if (vec[mid] < value)
			low = mid + 1; //New beginning index
		else
			high = mid - 1; //New end index
	}
	return -1;
}

int sequentialSearch(const vector<int>& vec, int value)
{
	//Searches through every index of vector until target is found/not found
	for (int i = 0; i < vec.size(); ++i)
	{
		if (vec[i] == value)
			return i;
	}
	return -1;
}

	
		
	


