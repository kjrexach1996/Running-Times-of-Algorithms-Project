// Running Times of Algorithms Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <random>
#include <vector>

using namespace std;

int recursiveSearch(const vector<int>& vec, int value, int low, int high);
int iterativeSearch(const vector<int>& vec, int value);
int sequentialSearch(const vector<int>& vec, int value);

int main()
{
	//Initializing a vector
	vector<int> myVector;

	//Creating a random number generator (rng)
	mt19937 rng(random_device{}());

	//Setting the range of random integers for distribution
	uniform_int_distribution<int> distributor(1, 100);

	//Filling the vector with 10 random integers
	for (int i = 0; i < 10; ++i)
	{
		myVector.push_back(distributor(rng));
	}

	//Printing out contents of vector BEFORE sorting
	for (int i = 0; i < myVector.size(); ++i)
	{
		cout << "Index " << i << ": " << myVector[i] << endl;
	}
	cout << endl;

	//Sort the elements of the vector in ascending order
	sort(myVector.begin(), myVector.end());

	//Printing out contents of vector AFTER sorting
	for (int i = 0; i < myVector.size(); ++i)
	{
		cout << "Index " << i << ": " << myVector[i] << endl;
	}
	cout << endl;

	//*** RECURSIVE SEARCHES ***//
	//Searching for random element using recursive binary search
	int target = distributor(rng);
	cout << "Random target 1: " << target << endl;
	int result = recursiveSearch(myVector, target, 0, (myVector.size() - 1));

	//Checking if element is in vector
	if (result != -1)
		cout << "Element " << target << " was found at index " << result << "." << endl;
	else
		cout << "Element " << target << " was not found." << endl;

	//***ITERATIVE SEARCHES***//
	//Searching for random element using iterative binary search
	target = distributor(rng);
	cout << "Random target 2: " << target << endl;
	result = iterativeSearch(myVector, target);

	//Checking if element is in vector
	if (result != -1)
		cout << "Element " << target << " was found at index " << result << "." << endl;
	else
		cout << "Element " << target << " was not found." << endl;

	//***SEQUENTIAL SEARCHES***//
	//Searching for random element using sequential search
	target = distributor(rng);
	cout << "Random target 3: " << target << endl;
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



	
		
	


