#include <iostream>
#include <vector>
using namespace std;
int k = 0;
void merge(int merged[], int lenD, int L[], int lenL, int R[], int lenR,int &k) {
	int i = 0;
	int j = 0;
	while (i < lenL || j < lenR) {
		if (i < lenL && j < lenR) {
			k++;
			if (L[i] <= R[j]) {
				merged[i + j] = L[i];
				i++;
			}
			else {
				merged[i + j] = R[j];
				j++;
			}
		}
		else if (i < lenL) {
			merged[i + j] = L[i];
			i++;
		}
		else if (j < lenR) {
			merged[i + j] = R[j];
			j++;
		}
	}
}
void mergeSort(int data[], int lenD)
{
	if (lenD > 1) {
		int middle = lenD / 2;
		int rem = lenD - middle;
		int* L = new int[middle];
		int* R = new int[rem];
		for (int i = 0; i < lenD; i++) {
			if (i < middle) {
				L[i] = data[i];
			}
			else {
				R[i - middle] = data[i];
			}
		}
		cout << "Left:";
		for(int i =0;i<middle;i++)
		{
			cout << L[i] << " ";;
		}
		cout << endl;
		cout << "Right:";
		for (int i = 0; i < rem; i++)
		{
			cout << R[i] << " ";;
		}
		cout << endl;
		mergeSort(L, middle);
		mergeSort(R, rem);
		merge(data, lenD, L, middle, R, rem,k);
	}
}
void siftDown(int* numbers, int root, int bottom,int &p,int &k)
{
	int maxChild; 
	int done = 0; 
	
	while ((root * 2 <= bottom) && (!done))
	{
		if (root * 2 == bottom)   
			maxChild = root * 2;    
		 
		else if (numbers[root * 2] > numbers[root * 2 + 1])
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;
		
		k++;
		if (numbers[root] < numbers[maxChild])
		{
			p++;
			int temp = numbers[root];
			numbers[root] = numbers[maxChild];
			numbers[maxChild] = temp;
			root = maxChild;
		}
		else 
			done = 1; 
	}
}

void heapSort(int* numbers, int array_size)
{
	int p = 0,k=0;
	
	for (int i = (array_size / 2); i >= 0; i--) {
		siftDown(numbers, i, array_size - 1,p,k);
		for (int i = 0; i < array_size; i++)
		{
			cout << numbers[i] << " ";
		}
		cout << endl;
	}
	
	
	for (int i = array_size - 1; i >= 1; i--)
	{
		int temp = numbers[0];
		numbers[0] = numbers[i];
		numbers[i] = temp;
		p++;
		
		siftDown(numbers, 0, i - 1,p,k);
		for (int i = 0; i < array_size; i++)
		{
			cout << numbers[i] << " ";
		}
		cout << endl;
	}
	
	cout << endl;
	cout << "number of permutations:" << p<<endl;
	cout << "number of comparisons: " << k << endl;
}


int main()
{
	
	srand((time(0)));
	int size;
	cout << "------merge_sort------------" << endl;
	cout << "Select size of array:";
	cin >> size;
	cout << "Array:";
	int* array2 = new int[size];
	for (int i = 0; i < size; i++) {
		//array2[i] = 1 + rand() % 100;
		cin >> array2[i];
		//cout << array2[i] << " ";
	}
	cout << endl;
	mergeSort(array2, size);
	for (int i = 0; i < size; i++) {
		//array2[i] = 1 + rand() % 100;
		//cin >> array2[i];
		cout << array2[i] << " ";
	}	
	cout << endl;
	cout << "number of comparisons: " << k<<endl;
	delete[] array2;
	array2 = nullptr;

	cout << "------heap_sort------------" << endl;
	cout << "Select size of array:";
	cin >> size;	
	cout << "Array:";
	int* array3 = new int[size];
	for (int i = 0; i < size; i++) {
		//array3[i] = 1 + rand() % 100;
		cin >> array3[i];
		//cout << array3[i] << " ";
	}
	cout << endl;
	heapSort(array3, size);
	for (int i = 0; i < size; i++) {
		cout << array3[i] << " ";
	}
	cout << endl;
	delete[] array3;
	array3 = nullptr;
	cout << endl;
}

