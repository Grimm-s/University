#include <iostream>
using namespace std;
int p = 0, q = 0;
void shell_sort(int* array, int size) {
	for (int s = size / 2; s > 0; s /= 2) {
		for (int i = 0; i < size; i++) {
			for (int j = i + s; j < size; j += s) {
				q++;
				if (array[i] > array[j]) {
					int temp = array[j];
					array[j] = array[i];
					array[i] = temp;
					p++;
					cout << "Step " << p << ":";
					for (int k = 0; k < size; k++) {
						cout << array[k] << " ";
					}
					cout << "::s=" << s;
					cout << endl;
				}
			}
		}
	}
	cout << "number of comparisons: " << q << endl;
	cout << "number of permutations: " << p;
	cout << endl;
}
void bubble_sort(int* mass, int n)
{
	int p = 0, q = 0;
	for (int i = 1; i < n; ++i)
	{
		for (int r = 0; r < n - i; r++)
		{
			q++;
			if (mass[r] > mass[r + 1])
			{

				int temp = mass[r];
				mass[r] = mass[r + 1];
				mass[r + 1] = temp;
				p++;
				cout << "Step " << p << ":";
				for (int k = 0; k < n; k++) {
					cout << mass[k] << " ";
				}
				cout << endl;
			}
		}
	}
	cout << "number of comparisons: " << q << endl;
	cout << "number of permutations: " << p;
	cout << endl;
}

int main()
{
	srand((time(0)));
	int size;
	cout << "------bubble_sort------" << endl;
	cout << "Selecet size of array:";
	cin >> size;
	cout << "Array:";
	int* array1 = new int[size];
	for (int i = 0; i < size; i++) {
		//array1[i] = 1 + rand() % 100;
		cin >> array1[i];
		//cout << array1[i] << " ";
	}
	cout << endl;
	bubble_sort(array1, size);
	delete[] array1;
	array1 = nullptr;
	cout << endl;
	cout << endl;
	cout << "------shell_sort------" << endl;
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
	shell_sort(array2, size);
	delete[] array2;
	array2 = nullptr;


}

