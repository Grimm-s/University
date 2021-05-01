#include <iostream>
using namespace std;
int p = 0, q = 0;
void quick_sort(int* mas, int size, int& p,int&k) {	
	int i = 0;
	int j = size - 1;	
	int mid = mas[size / 2];		
	do {	
		while (mas[i] < mid) {
			i++;
			k++;
		}		
		while (mas[j] > mid) {
			j--;
			k++;
		}	
		if (i <= j) {
			k++;
			int tmp = mas[i];
			mas[i] = mas[j];
			mas[j] = tmp;
			p++;
			//cout << "Step " << p << ":";
			//for (int k = 0; k < size; k++) {
			//	cout << mas[k] << " ";
			//}
			//cout << endl;
			i++;
			j--;
		}
	} while (i <= j);	
	if (j > 0) {		
		quick_sort(mas, j + 1, p,k);
	}
	if (i < size) {
		quick_sort(&mas[i], size - i,p,k);
	}	
}
void shake_sort(int* arr, int size)
{
	int p = 0,k=0;
	int leftMark = 1;
	int rightMark = size - 1;
	while (leftMark <= rightMark)
	{
		for (int i = rightMark; i >= leftMark; i--) {
			k++;
			if (arr[i - 1] > arr[i])
			{
				int buff;
				buff = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = buff;
				p++;
			}
		}
		leftMark++;


		for (int i = leftMark; i <= rightMark; i++) {
			k++;
			if (arr[i - 1] > arr[i])
			{

				int buff;
				buff = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = buff;
				p++;
				cout << "Step " << p << ":";
				for (int k = 0; k < size; k++) {
					cout << arr[k] << " ";
				}
				cout << endl;
			}
		}
		rightMark--;	
	}
	cout << "number of comparisons: " << k << endl;
	cout << "number of permutations: " << p;
	cout << endl;
}
void counting_sort(int* array, int n, int  k) {
	
	int* c = new int[k + 1]{ 0 };
	for (int i = 0; i < n; ++i) {
		++c[array[i]];
		
	}
	for (int i = 0; i < k; ++i) {
		
		cout << c[i];
	}
	cout << endl;
	int b = 0;
	for (int i = 0; i < k + 1; ++i) {
		for (int j = 0; j < c[i]; ++j) {
			array[b++] = i;
		}
	}
}
int getmax(int a[], int n)
{
	int max = a[0];
	for (int x = 1; x < n; x++)
		if (a[x] > max)
			max = a[x];
	return max;
}


void CountSort(int a[], int n, int exp)
{
	int* result = new int[n];
	int i;
	int count[10] = { 0 };	
	for (i = 0; i < n; i++)
		count[(a[i] / exp) % 10]++;	
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = n - 1; i >= 0; i--)
	{
		result[count[(a[i] / exp) % 10] - 1] = a[i];
		count[(a[i] / exp) % 10]--;
	}
	for (i = 0; i < n; i++)
		a[i] = result[i];
}

void radix_sort(int a[], int n)
{
	int exp, i;
	i = getmax(a, n);
	for (exp = 1; i / exp > 0; exp *= 10)
		CountSort(a, n, exp);
}

int main()
{
	int p = 0,k=0;
	srand((time(0)));
	int size;
	cout << "------quick_sort------" << endl;
	cout << "Select size of array:";
	cin >> size;
	cout << "Array:";
	int* array1 = new int[size];
	for (int i = 0; i < size; i++) {
		array1[i] = 1 + rand() % 100;
		//cin >> array1[i];
		cout << array1[i] << " ";
	}
	cout << endl;
	cout << endl;
	quick_sort(array1, size, p,k);
	for (int i = 0; i < size; i++) {
		cout << array1[i] << " ";
	}
	cout << endl;
	cout << "number of comparisons: " << k << endl;
	cout << "number of permutations: " << p;
	cout << endl;
	delete[] array1;
	array1 = nullptr;
	cout << endl;
	cout << endl;
	cout << "------shake_sort------" << endl;
	cout << "Select size of array:";
	cin >> size;
	cout << "Array:";
	int* array2 = new int[size];
	for (int i = 0; i < size; i++) {
		array2[i] = 1 + rand() % 100;
		//cin >> array2[i];
		cout << array2[i] << " ";
	}
	cout << endl;
	shake_sort(array2, size);
	delete[] array2;
	array2 = nullptr;

	cout << "------counting_sort------" << endl;
	int max;
	cout << "Select size of array:";
	cin >> size;
	cout << "Select maximum possible value:";
	cin >>max;
	cout << "Array:";
	int* array3 = new int[size];
	for (int i = 0; i < size; i++) {
		array3[i] = 1 + rand() % 100;
		//cin >> array3[i];
		cout << array3[i] << " ";
	}
	cout << endl;
	counting_sort(array3, size, max);
	for (int i = 0; i < size; i++) {
		cout << array3[i] << " ";
	}
	cout << endl;
	delete[] array3;
	array3 = nullptr;
	cout << endl;
	cout << "------radix_sort------" << endl;
	cout << "Select size of array:";
	cin >> size;
	cout << "Array:";
	int* array4 = new int[size];
	for (int i = 0; i < size; i++) {
		array4[i] = 1 + rand() % 100;
		//cin >> array4[i];
		cout << array4[i] << " ";
	}
	cout << endl;
	radix_sort(array4, size);
	for (int i = 0; i < size; i++) {
		cout << array4[i] << " ";
	}
	delete[] array4;
	array4 = nullptr;
}

