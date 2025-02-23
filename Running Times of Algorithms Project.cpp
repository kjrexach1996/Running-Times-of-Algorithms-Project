// Running Times of Algorithms Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int recursiveSearch(const vector<int>& vec, int value, int low, int high);
int iterativeSearch(const vector<int>& vec, int value);
int sequentialSearch(const vector<int>& vec, int value);

int main()
{
	//Creating the vector to search for elements
	vector<int> myVector = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	//*** RECURSIVE SEARCHES ***//
	//Searching for PRESENT element using recursive binary search
	int target = 7;
	int result = recursiveSearch(myVector, target, 0, (myVector.size() - 1));

	//Checking if element is in vector
	if (result != -1)
		cout << "Element " << target << " was found at index " << result << "." << endl;
	else
		cout << "Element " << target << " was not found." << endl;

	//Searching for ABSENT element using recursive binary search
	target = 11;
	result = recursiveSearch(myVector, target, 0, (myVector.size() - 1));

	//Checking if element is in vector
	if (result != -1)
		cout << "Element " << target << " was found at index " << result << "." << endl;
	else
		cout << "Element " << target << " was not found." << endl;

	//***ITERATIVE SEARCHES***//
	//Searching for PRESENT element using iterative binary search
	target = 3;
	result = iterativeSearch(myVector, target);

	//Checking if element is in vector
	if (result != -1)
		cout << "Element " << target << " was found at index " << result << "." << endl;
	else
		cout << "Element " << target << " was not found." << endl;

	//Searching for ABSENT element using iterative binary search
	target = 23;
	result = iterativeSearch(myVector, target);

	//Checking if element is in vector
	if (result != -1)
		cout << "Element " << target << " was found at index " << result << "." << endl;
	else
		cout << "Element " << target << " was not found." << endl;

	//***SEQUENTIAL SEARCHES***//
	//Searching for PRESENT element using sequential search
	target = 9;
	result = sequentialSearch(myVector, target);

	//Checking if element is in vector
	if (result != -1)
		cout << "Element " << target << " was found at index " << result << "." << endl;
	else
		cout << "Element " << target << " was not found." << endl;

	//Searching for ABSENT element using sequential search
	target = -13;
	result = sequentialSearch(myVector, target);

	//Checking if element is in vector
	if (result != -1)
		cout << "Element " << target << " was found at index " << result << "." << endl;
	else
		cout << "Element " << target << " was not found." << endl;
}

int recursiveSearch(const vector<int>& vec, int value, int low, int high)
{
	if (low <= high)
	{
		int mid = low + ((high - low) / 2);

		if (vec[mid] == value)
			return mid;
		else if (vec[mid] < value)
			return recursiveSearch(vec, value, mid + 1, high);
		else
			return recursiveSearch(vec, value, low, mid - 1);
	}
	else
		return -1;
}

int iterativeSearch(const vector<int>& vec, int value)
{
	int low = 0;
	int high = vec.size() - 1;

	while (low <= high)
	{
		int mid = low + ((high - low) / 2);

		if (vec[mid] == value)
			return mid;
		else if (vec[mid] < value)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}

int sequentialSearch(const vector<int>& vec, int value)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		if (vec[i] == value)
			return i;
	}
	return -1;
}

	
		
	


