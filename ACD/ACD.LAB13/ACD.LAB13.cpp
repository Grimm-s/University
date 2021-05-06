#include <array>
#include <iostream>
#include <vector>
using namespace std;
void Simple_Merging_Sort(char* name) {
	int a1, a2, k, i, j, kol;
	FILE* f, * f1, * f2;
	kol = 0;
	if ((f = fopen(name, "r")) == NULL)
		printf("\n Вихідний файл не може бути прочитаний...");
	else {
		while (!feof(f)) {
			fscanf(f, "%d", &a1);
			kol++;
		}
		fclose(f);
	}
	k = 1;
	while (k < kol) {
		f = fopen(name, "r");
		f1 = fopen("smsort_1", "w");
		f2 = fopen("smsort_2", "w");
		if (!feof(f)) fscanf(f, "%d", &a1);
		while (!feof(f)) {
			for (i = 0; i < k && !feof(f); i++) {
				fprintf(f1, "%d ", a1);
				fscanf(f, "%d", &a1);
			}
			for (j = 0; j < k && !feof(f); j++) {
				fprintf(f2, "%d ", a1);
				fscanf(f, "%d", &a1);
			}
		}
		fclose(f2); fclose(f1); fclose(f);
		f = fopen(name, "w");
		f1 = fopen("smsort_1", "r");
		f2 = fopen("smsort_2", "r");
		if (!feof(f1)) fscanf(f1, "%d", &a1);
		if (!feof(f2)) fscanf(f2, "%d", &a2);
		while (!feof(f1) && !feof(f2)) {
			i = 0;
			j = 0;
			while (i < k && j < k && !feof(f1) && !feof(f2)) {

				if (a1 < a2) {
					fprintf(f, "%d ", a1);
					fscanf(f1, "%d", &a1);
					i++;
				}
				else {
					fprintf(f, "%d ", a2);
					fscanf(f2, "%d", &a2);
					j++;
				}
			}
			while (i < k && !feof(f1)) {
				fprintf(f, "%d ", a1);
				fscanf(f1, "%d", &a1);
				i++;
			}
			while (j < k && !feof(f2)) {
				fprintf(f, "%d ", a2);
				fscanf(f2, "%d", &a2);
				j++;
			}
		}
		while (!feof(f1)) {
			fprintf(f, "%d ", a1);
			fscanf(f1, "%d", &a1);
		}
		while (!feof(f2)) {
			fprintf(f, "%d ", a2);
			fscanf(f2, "%d", &a2);
		}
		fclose(f2);
		fclose(f1);
		fclose(f);
		k *= 2;
	}
	remove("smsort_1");
	remove("smsort_2");
}
void merge(int merged[], int lenD, int L[], int lenL, int R[], int lenR, int& k) {
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
	int k = 0;
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
		for (int i = 0; i < middle; i++)
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
		merge(data, lenD, L, middle, R, rem, k);
	}
}
int* natural_merge(int merged[], int size, int L[], int n, int R[], int m)
{
	int i = 0;
	int j = 0;
	while (i < n || j < m) {
		if (i < n && j < m) {
			if (L[i] <= R[j]) {
				merged[i + j] = L[i];
				i++;
			}
			else {
				merged[i + j] = R[j];
				j++;
			}
		}
		else if (i < n) {
			merged[i + j] = L[i];
			i++;
		}
		else if (j < m) {
			merged[i + j] = R[j];
			j++;
		}
	}
	return merged;
}

void natural_merge_sort(int arr[], int size)
{
	int* L = new int[size]{0};
	int* R = new int[size]{0};
	int n = 0, m = 0;
	bool done = true;
	int side = -1;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			done = false;
			side *= -1;
		}	
		switch(side)
		{
		case 1:			
			R[m] = arr[i];
			m++;
			break;
		case -1:
			L[n] = arr[i];
			n++;
			break;
		}
	}
	for (int i =0 ;i<n;i++)
	{
		cout << L[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < m; i++)
	{
		cout << R[i] << " ";
	}
	cout << endl;
	natural_merge(arr, size, L, n, R, m);
	if(!done)
	{
		natural_merge_sort(natural_merge(arr, size, L, n, R, m), size);
	}
}
int* many_ways_merge(int size,int num_arr, int* B[], int* C[], int b[],int c[])
{
	//cout << "==============================="<<endl;
	int* p = new int[num_arr] {0};
	
	for (int i = 0; i < size; i++) {
		int min=1000,imin=0;
		//min = B[0][p[0]];
		for (int k = 0; k < num_arr; k++) {
			if(B[k][p[k]]<min)
			{
				if(p[k]>=b[k])
				{
					continue;
				}
				imin = k;
				min = B[k][p[k]];
			}
			
		}
		//B[imin]--;
		p[imin]++;		
		C[0][i] = min;
	//	cout<< C[0][i] << " ";
		//B = {0};
		
	}
	//cout << endl;
	//cout << "==============================="<<endl;
	return *C;
}

void many_ways_merge_sort(int arr[], int size,size_t num_arr)
{

	int** B = new int* [num_arr];
	for (size_t i = 0; i < num_arr; i++)
	{
		B[i] = new int[size];

	}
	int** C = new int* [2];
	for (size_t i = 0; i < 2; i++)
	{
		C[i] = new int[size];

	}
	int* b = new int[num_arr]{0};
	int* c = new int[2]{0};
	bool done = true;
	int part = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			done = false;
			
			part++;
			if (part==num_arr)
			{
				part = 0;
			}
		}
		B[part][b[part]] = arr[i];
		b[part]++;
	}
	for (size_t k = 0; k < num_arr; k++) {
		
		for (int i = 0; i < b[k]; i++)
		{
			cout << B[k][i] << " ";
		}
		cout << endl;
	}	
	if (!done)
	{
		many_ways_merge_sort(many_ways_merge(size, num_arr, B, C, b, c), size,num_arr);
	}
	
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
		array2[i] = 1 + rand() % 100;
		//cin >> array2[i];
		cout << array2[i] << " ";
	}
	cout << endl;
	natural_merge_sort(array2, size);
	for (int i = 0; i < size; i++) {
		//array2[i] = 1 + rand() % 100;
		//cin >> array2[i];
		cout << array2[i] << " ";
	}
	cout << endl;

	delete[] array2;
	array2 = nullptr;


	cout << "------merge_sort------------" << endl;
	size_t num_arr;
	cout << "Select size of array:";
	cin >> size;
	cout << "Array:";
	
	cout << "Select number of sub arrays:";
	cin >> num_arr;
	
	int* array3 = new int[size];
	for (int i = 0; i < size; i++) {
		array3[i] = 1 + rand() % 100;
		
		cout << array3[i] << " ";
	}
	cout << endl;
	many_ways_merge_sort(array3, size,num_arr);
	for (int i = 0; i < size; i++) {
		array2[i] = 1 + rand() % 100;
		
		cout << array2[i] << " ";
	}
	cout << endl;
	
	delete[] array2;
	array2 = nullptr;
	
	
}

