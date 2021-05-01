#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;
int binary_search(int* massiv, int key, int left, int right) {
	int middle;
	cout << "left index:" << left <<"  "<< "right index:" << right<<endl;
	if (right < left) return -1;
	middle = (left + right) / 2;
	if (massiv[middle] > key)
		return binary_search(massiv, key, left, middle - 1);
	else if (massiv[middle] < key) {
		return binary_search(massiv, key, middle + 1, right);
	}
	else {
		return middle;
	}			
}
int main(int argc, char* argv[])
{
	int size, key, choice, temp, n=0;
	cout << "Select size of massiv:";
	cin >> size;
	int* massiv = new int[size];
	cout << "1.auto input" << endl << "2.manual input" << endl;
	cout << "choice:";
	cin >> choice;
	switch (choice) {
	case 1:
		for (int i = 0; i < size; i++) {
			massiv[i] = n;
			n++;
			cout << massiv[i] << " ";
		}
		cout << endl;
		cout << "key:";
		cin >> key;
		temp = binary_search(massiv, key,0,size-1);
		if (temp == -1) {
			cout << "element not found";

		}
		else {
			cout << "index of key:" << temp;
		}
		break;
	case 2:
		for (int i = 0; i < size; i++) {
			cin >> massiv[i];
		}
		cout << "key:";
		cin >> key;
		temp = binary_search(massiv, key,0,size-1);
		if (temp == -1) {
			cout << "element not found";

		}
		else {
			cout << "index of key:" << temp;
		}
		break;

	}


}