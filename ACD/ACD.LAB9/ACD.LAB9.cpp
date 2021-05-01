#include <iostream>
using namespace std;

/*void linear_insert(int* arr, int size) {
	int n = 0,p=0;
	for (int i = 1; i < size; i++) {
		n++;
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
			int tmp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = tmp;
			n++;
			p++;
			cout << "Step " << p << ":";
			for (int k = 0; k < size; k++) {
				cout << arr[k] << " ";
			}
			cout << endl;
			
		}		
	}
	cout << "number of comparisons: " << n << endl;;
	cout << "number of permutations: " << p;
	cout << endl;
}
void simple_choice (int* num, int size)
{
	int n = 0,p=0;
	int min;
	for (int i = 0; i < size - 1; i++) {
		min = i; 		
		for (int j = i + 1; j < size; j++) {
			if (num[j] < num[min]) 
				min = j;  
			n++;
		}
		int temp = num[i];     
		num[i] = num[min];
		num[min] = temp;
		p++;
		cout << "Step " << p << ":";
		for (int k = 0; k < size; k++) {
			cout << num[k] << " ";
		}
		cout << endl;
	}
	cout << "number of comparisons: " << n<<endl;
	cout << "number of permutations: " << p;
	cout << endl;
}*/
void linear_insert(int* arr, int size) {
	int n = 0, p = 0;
	for (int i = size-1; i >=0; i--) {
		n++;
		for (int j = i; j < size-1 && arr[j] > arr[j+1]; j++) {
			int tmp = arr[j + 1];
			arr[j + 1] = arr[j];
			arr[j] = tmp;
			n++;
			p++;
			cout << "Step " << p << ":";
			for (int k = 0; k < size; k++) {
				cout << arr[k] << " ";
			}
			cout << endl;

		}
	}
	cout << "number of comparisons: " << n << endl;;
	cout << "number of permutations: " << p;
	cout << endl;
}
void simple_choice(int* num, int size)
{
	int n = 0, p = 0;
	int max;
	for (int i = size-1; i >=0; i--) {
		max = i;
		for (int j = i-1; j >=0; j--) {
			if (num[j] > num[max])
				max = j;
			n++;
		}
		int temp = num[i];
		num[i] = num[max];
		num[max] = temp;
		p++;
		cout << "Step " << p << ":";
		for (int k = 0; k < size; k++) {
			cout << num[k] << " ";
		}
		cout << endl;
	}
	cout << "number of comparisons: " << n << endl;
	cout << "number of permutations: " << p;
	cout << endl;
}
int main()
{
	srand((time(0)));
	int size;
	cout << "------linear_insert------"<<endl;
	cout << "Selecet size of array:";
	cin >> size;
	cout << "Array:";
	int* array1 = new int[size];
	for (int i = 0; i < size; i++) {
		//array1[i] = 1+ rand() % 100;
		cin >> array1[i];
		cout  << array1[i]<<" ";
	}
	cout << endl;
	linear_insert(array1,size);
	delete[] array1;
	array1 = nullptr;
	cout << endl;
	cout << endl;
	cout << "------simple_choice------" << endl;
	cout << "Selecet size of array:";
	cin >> size;
	cout << "Array:";
	int* array2 = new int[size];
	for (int i = 0; i < size; i++) {
		//array2[i] = 1 + rand() % 100;
		cin >> array2[i];
		//cout << array2[i] << " ";
	}
	cout << endl;
	simple_choice(array2, size);
	delete[] array2;
	array2 = nullptr;


}

