// Running Times of Algorithms Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include <chrono>

using namespace std;

int recursiveSearch(const vector<int>& vec, int value, int low, int high);
int iterativeSearch(const vector<int>& vec, int value);
int sequentialSearch(const vector<int>& vec, int value);

int main()
{
	//Variable declarations representing size of vector N and 
	//average times for each type of search
	int N = 5000;
	int sumRBS = 0;
	int sumIBS = 0;
	int sumSeqS = 0;

	//Creating a random number generator (rng)
	mt19937 rng(random_device{}());

	//Setting the range of random integers for distribution
	uniform_int_distribution<int> distributor(1, N);

	//Loop runs 10 times
	for (int i = 0; i < 10; ++i)
	{
		//Initializing a vector
		vector<int> myVector;

		//Vector is filled with N random integers
		for (int j = 0; j < N; ++j)
		{
			myVector.push_back(distributor(rng));
		}
		//Vector is sorted in ascending order
		sort(myVector.begin(), myVector.end());

		//***RBS***//
		//Generating a random target value to find in vector
		int target = distributor(rng);

		cout << "Target for RBS: " << target << endl;

		//Start time
		auto start = chrono::high_resolution_clock::now();

		//Beginning the search for the target using recursive binary search
		int result = recursiveSearch(myVector, target, 0, myVector.size() - 1);

		//End time
		auto end = chrono::high_resolution_clock::now();

		//Calculating the time of RBS and storing in sumRBS
		double duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		sumRBS += duration;

		cout << "sumRBS: " << sumRBS << endl << endl;

		//***IBS***//
		//Resetting random target value to find
		target = distributor(rng);

		cout << "Target for IBS: " << target << endl;

		//Start time
		start = chrono::high_resolution_clock::now();

		//Beginning the search for the target using iterative binary search
		result = iterativeSearch(myVector, target);

		//End time
		end = chrono::high_resolution_clock::now();

		//Calculating the time of IBS and storing in sumIBS
		duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		sumIBS += duration;

		cout << "sumIBS: " << sumIBS << endl << endl;

		//***SeqS***//
		//Resetting random target to a 3rd value to find
		target = distributor(rng);

		cout << "Target for SeqS: " << target << endl;

		//Start time
		start = chrono::high_resolution_clock::now();

		//Beginning the search for the target using iterative binary search
		result = sequentialSearch(myVector, target);

		//End time
		end = chrono::high_resolution_clock::now();

		//Calculating the time of IBS and storing in sumIBS
		duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		sumSeqS += duration;

		cout << "sumSeqS: " << sumSeqS << endl << endl;
	}
	cout << "Average running time for recursive binary search: " << sumRBS / 10 << " nanoseconds" << endl;
	cout << "Average running time for iterative binary search: " << sumIBS / 10 << " nanoseconds" << endl;
	cout << "Average running time for sequential search: " << sumSeqS / 10 << " nanoseconds" << endl;
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



	
		
	


