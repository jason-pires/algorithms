# include<iostream>
using namespace std;

// function to recursivelly find the maximum no.
// in a given array.
// params arr[] = the array itself, index = actual index, l = total length of arr[]
int DAC_Max(int arr[], int index, int l)
{
	int max;
	if(index >= l - 2)
	{
		if(arr[index] > arr[index + 1])
		return arr[index];
		else
		return arr[index + 1];
	}
	max = DAC_Max(arr, index + 1, l);
	if(arr[index] > max)
	return arr[index];
	else
	return max;
}

// Function to recursivelly find the minimum no.
// in a given array
// params arr[] = the array itself, index = actual index, l = total length of arr[]
int DAC_Min(int arr[], int index, int l)
{
	int min;
	if(index >= l - 2)
	{
		if(arr[index] < arr[index + 1])
		return arr[index];
		else
		return arr[index + 1];
	}
	
	min = DAC_Min(arr, index + 1, l);
	if(arr[index] < min)
	return arr[index];
	else
	return min;
}

// Driver code
int main()
{
	// defines an generic array
	int arr[] = {120, 17, 190, 88, 256, 58, 23, 75};
	// find the array length calculating their bytes
	int n = sizeof(arr) / sizeof(arr[0]);
	int max, min;
	max = DAC_Max(arr, 0, n);
	min = DAC_Min(arr, 0, n);
	cout << "Maximum: " << max << endl;
	cout << "Minimum: " << min << endl;
	return 0;
}
