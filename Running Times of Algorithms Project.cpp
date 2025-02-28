// Running Times of Algorithms Project.cpp (Part 3: Rate of Growth): This program takes the
// three search algorithms from Parts 1 and 2 and uses them find a random target value
// in a vector filled with a larger and larger set of random integers. The running times 
// of each algorithm are recorded to compare each algorithms' rate of growth.
// Times will be recorded in nanoseconds.

#include <iostream>
#include <random>
#include <algorithm> //Included to sort vector
#include <vector>
#include <chrono>

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
	//Variable declarations representing size of vector N and 
	//average times for each type of search
	int n = 1000000;
	int sumRBS = 0;
	int sumIBS = 0;
	int sumSeqS = 0;

	//Creating a random number generator (rng)
	mt19937 rng(random_device{}());

	//Setting the range of random integers for distribution
	uniform_int_distribution<int> distributor(1, n);

	//Loop runs 10 times and takes average running times for each search algorithm
	for (int i = 0; i < 10; ++i)
	{
		//Initializing a vector
		vector<int> myVector;

		//Vector is filled with n random integers
		for (int j = 0; j < n; ++j)
		{
			myVector.push_back(distributor(rng));
		}

		//Vector is sorted in ascending order
		sort(myVector.begin(), myVector.end());

		cout << "Vector " << i + 1 << endl;

		//***RBS***//
		//Generating a random target value to find in vector
		int target = distributor(rng);

		//Start time
		auto start = chrono::high_resolution_clock::now();

		//Beginning the search for the target using recursive binary search
		int result = recursiveSearch(myVector, target, 0, myVector.size() - 1);

		//End time
		auto end = chrono::high_resolution_clock::now();

		//Calculating the time of RBS and storing in sumRBS
		double duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		sumRBS += duration;

		cout << "sumRBS: " << sumRBS << " nanoseconds" << endl;

		//***IBS***//
		//Resetting random target value to find
		target = distributor(rng);

		//Start time
		start = chrono::high_resolution_clock::now();

		//Beginning the search for the target using iterative binary search
		result = iterativeSearch(myVector, target);

		//End time
		end = chrono::high_resolution_clock::now();

		//Calculating the time of IBS and storing in sumIBS
		duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		sumIBS += duration;

		cout << "sumIBS: " << sumIBS << " nanoseconds" << endl;

		//***SeqS***//
		//Resetting random target to a 3rd value to find
		target = distributor(rng);

		//Start time
		start = chrono::high_resolution_clock::now();

		//Beginning the search for the target using iterative binary search
		result = sequentialSearch(myVector, target);

		//End time
		end = chrono::high_resolution_clock::now();

		//Calculating the time of IBS and storing in sumIBS
		duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		sumSeqS += duration;

		cout << "sumSeqS: " << sumSeqS << " nanoseconds" << endl;

		cout << endl;
	}
	//Printing out average times for search algorithms
	cout << "Average running time for recursive binary search: " << sumRBS / 10 << " nanoseconds" << endl;
	cout << "Average running time for iterative binary search: " << sumIBS / 10 << " nanoseconds" << endl;
	cout << "Average running time for sequential search: " << sumSeqS / 10 << " nanoseconds" << endl;
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



	
		
	


