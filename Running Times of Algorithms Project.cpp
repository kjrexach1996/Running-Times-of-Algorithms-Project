// Running Times of Algorithms Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <algorithm>
#include <vector>

using namespace std;

int recursiveSearch(const vector<int>& vec, int value, int low, int high);
int iterativeSearch(const vector<int>& vec, int value);
int sequentialSearch(const vector<int>& vec, int value);

int main()
{
	//Variable declarations representing size of vector N and 
	//average times for each type of search
	int N = 100;
	int sumRBS = 0;
	int sumIBS = 0;
	int sumSeqS = 0;

	//Initializing a vector
	vector<int> myVector;

	//Creating a random number generator (rng)
	mt19937 rng(random_device{}());

	//Setting the range of random integers for distribution
	uniform_int_distribution<int> distributor(1, N);

	//Loop runs 10 times
	for (int i = 0; i < 10; ++i)
	{
		//Fills the vector with N random integers ranging from 1 to N
		for (int j = 0; j < N; ++j)
		{
			myVector.push_back(distributor(rng));
		}
		sort(myVector.begin(), myVector.end());
		
	}

	
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



	
		
	


