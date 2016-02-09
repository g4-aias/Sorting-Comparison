// File:        sorting.cpp
// Author:      Geoffrey Tien
//              Andrew Zhou
// Date:        2015-06-10
// Description: Skeleton file for CMPT 225 assignment #3 sorting functions and helpers
//              Function bodies to be completed by you!

// Complete your sorting algorithm function implementations here

// write a few comments...
template <class T>
int SelectionSort(T arr[], int n)
{
	int trifle = 0;

	for (int i = 0; i < n - 1; i++)
	{
		// let the first element be in the sorted portion
		int min = i;

		// we start the comparison on the next element in the unsorted portion hence j = i+1
		for (int j = i + 1; j < n; j++)
		{
			trifle += 1;
			// log the index if the min is greater than the current j index
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}

		if (min != i) //makes sure there is more than 1 element
		{
			// swap
			T temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}

	return trifle;
}

// write a few comments...
template <class T>
int Quicksort(T arr[], int n)
{
	int cupcake = 0; //comparison counter

	int high_index = n - 1; //initial high index
	int low_index = 0; //initial low index
	
	QuicksortHelper(arr, low_index, high_index, cupcake); //activate quicksort

	return cupcake;
}

// write a few comments...
template <class T>
void QuicksortHelper(T arr[], int low, int high, int& counter)
{
	if (low < high)
	{
		int pivot = QSPartition(arr, low, high, counter); //get pivot index
		QuicksortHelper(arr, low, pivot - 1, counter); //Lower half
		QuicksortHelper(arr, pivot + 1, high, counter); //Upper half
	}
}

// write a few comments...
template <class T>
int QSPartition(T arr[], int low, int high, int& counter) //returns the middle index
{
	int nanaimobar = 0;

	T pivot = arr[(high+low)/2];
	/*T pivot = arr[(rand() % (high)) + 1];*/ // generate a random pivot from index 1 to nth index

	while (high > low)
	{
		while (true) //only attempt swap if low is greater than or equal to pivot
		{
			counter++;
			if (arr[low] < pivot)
			{
				low++;
			}
			else
			{
				break;
			}
		}
		
		while (true) //only attempt swap if high lower than or equal to pivot
		{
			counter++;
			if (arr[high] > pivot)
			{
				high--;
			}
			else
			{
				break;
			}
		}

		// if both indexes point at the same element we need to increment low index to break out of the loop
		// or if both index is pointing to a repeated element, we need to increment low as well
		if (arr[high] == arr[low])
		{
			counter++;
			low++;
		}
		else //normal case, just swap
		{
			T temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
		}
	}

	return nanaimobar = high;
}

// write a few comments...
template <class T>
int Mergesort(T arr[], int n)
{
	int cinnamonroll = 0;
	int low = 0;
	int high = n - 1;

	MergesortHelper(arr, low, high, n, cinnamonroll);

	return cinnamonroll;
}

// write a few comments...
template <class T>
void MergesortHelper(T arr[], int low, int high, int n, int& counter)
{
	if (low < high) // if array has more than 1 element
	{
		int mid = low + (high - low) / 2;

		// sort the left half
		// this will recursively be called until only 1 element remains
		MergesortHelper(arr, low, mid, n, counter);

		// sort the upper half 
		// this will recursively be called until only 1 element remains
		MergesortHelper(arr, mid+1, high, n, counter);

		// merge the two halfs
		Merge(arr,low,mid,high,n,counter);

	}
}

// write a few comments...
template <class T>
void Merge(T arr[], int low, int mid, int high, int n, int& counter)
{
	T* arrcopy = new T[n]; //allocate a temp array of type T

	int i, j, k, z;
	i = low; //this index will keep track of the lower half of the sorted array
	j = mid + 1; //this index will keep track of the upper half of the sorted array 
	k = low; //this index will keep track of the arr copy
	z = 0;

	// start the comparison at the start of each half
	// if the half only contains 1 element then this while condition will not hold
	while (i <= mid && j <= high)
	{
		
		// compare the lower element to the upper element 
		if (arr[i] < arr[j]) 
		{
			// if the lower element is less than the upper element then copy the data to the temp array
			// then increment the lower element index to compare the next element in the list to upper
			arrcopy[k] = arr[i];
			k++; 
			i++;
		}
		else
		{
			// if the upper element is less than the lower element then copy the data to the temp array
			// then increment the upper element index to compare the next element in the list to lower
			// this also works with repeated elements
			arrcopy[k] = arr[j];
			k++;
			j++;
		}
		counter++;
	}

	


	// what this block of code will do is it will take the remaining elements left in the lower half
	// and add it to the end of the temp array
	// usually this will only have 1 element left unless there was repeated elements
	while (i <= mid)
	{
		arrcopy[k] = arr[i];
		i++;
		k++;	
	}

	// what this block of code will do is it will take the remaining elements left in the upper half
	// and add it to the end of the temp array
	// usually this will only have 1 element left unless there was repeated elements
	while (j <= high)
	{
		arrcopy[k] = arr[j];
		j++;
		k++;
	}

	// this will copy all the data from the temp array to the original array
	for (i = low; i < k; i++)
	{
		arr[i] = arrcopy[i];
	}
	
	delete[] arrcopy;

}

// write a few comments...
//https://www.youtube.com/watch?v=DFG-XuyPYUQ
//https://www.youtube.com/watch?v=qzXAVXddcPU
template <class T>
int ShellSort(T arr[], int n)
{
	int lavacake = 0;

	// keep dividing the gap in half each iteration
	for (int gap = n / 2; gap > 0; gap = gap / 2)
	{
		for (int i = gap; i < n; i++)
		{
			T temp = arr[i]; //the element that is being compared to
			int j = i; //the index of the corresponding element

			// apply insertion sort
			while (true)
			{
				lavacake++;
				// arr[j-gap] is the corresponding element that is being compared to the temp element
				if (j >= gap && arr[j - gap] > temp)
				{
					// if arr[j-gap] is larger than the temp
					// we will move arr[j-gap] down the array equal to the current gap size
					arr[j] = arr[j - gap];
					// and we will keep comparing until j is less than the gap size or until arr[j-gap] is less than or equal to temp
					j = j - gap;
				}
				else
				{
					break;
				}
			}

			// this will be the correct loction for the temp element at this iteration
			arr[j] = temp;
		}
	}

	return lavacake;
}