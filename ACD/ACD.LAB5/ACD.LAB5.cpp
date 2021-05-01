#include <iostream>
#include <cmath>
using namespace std;
struct Triangle
{
	int x[3] = { 0 };
	int y[3] = { 0 };
	double r1, r2, r3;
	double perim;
	double sq;
	Triangle()
	{
		sq = -1;
	}
	Triangle(int* x1, int* y1)
	{
		for (int i = 0; i < 3; i++)
		{
			x[i] = x1[i];
			y[i] = y1[i];
		}
		r1 = sqrt(pow(x[0] - x[1], 2) + pow(y[0] - y[1], 2));
		r2 = sqrt(pow(x[1] - x[2], 2) + pow(y[1] - y[2], 2));
		r3 = sqrt(pow(x[0] - x[2], 2) + pow(y[0] - y[2], 2));
	}
	void print()
	{
		cout << "Square: " << getSquare() << " Perimeter: " << getPerim() << endl;
	}
	double  getSquare()
	{
		double p = getPerim() / 2;
		sq = sqrt((p * (p - r1) * (p - r2) * (p - r3)));
		return sq;
	}

	double getPerim()
	{
		perim = r1+r2+r3;
		return perim;
	}
};
struct HashTable
{
private:
	Triangle* array;
	const double A = 0.62585613;
	int N;

public:
	HashTable(int size)
	{
		N = size;
		array = new Triangle[N];
	}
	Triangle* Entering()
	{
		int x[3], y[3];
		for (int i = 0; i < 3; i++)
		{
			cout << "Enter x : ";
			cin >> x[i];
			cout << "Enter y : ";
			cin >> y[i];
			cout << endl;
		}
		double r1 = sqrt(pow(x[0] - x[1], 2) + pow(y[0] - y[1], 2));
		double r2 = sqrt(pow(x[1] - x[2], 2) + pow(y[1] - y[2], 2));
		double r3 = sqrt(pow(x[0] - x[2], 2) + pow(y[0] - y[2], 2));
		if (r1 <= abs(r2 - r3) || r1 >= r2 + r3) {
			cout << "It isn’t a triangle..." << endl;
			Entering();
		}			
		else {			
			return new Triangle(x, y);
		}
	}

	bool add()
	{
		const double c = 1.3794231;
		Triangle* toAdd = Entering();
		int hash = getHash(toAdd->getSquare());
		cout << toAdd->getPerim() <<"-----"<< toAdd->getSquare()<<"----"<<hash<<endl;
		if (getHash(array[hash].getSquare()) < 0) {
			array[hash] = *toAdd;
			return true;
		}
		else
		{
			int i = 0;
			while (true)
			{

				hash = getHash(toAdd->getSquare()) + c * i;
				i++;
				if (getHash(array[hash].getSquare()) < 0)
				{
					array[hash] = *toAdd;
					return true;
				}
				if (hash > N)
				{
					cout << "Hashcode more than size of HashTable" << endl;
					return false;
				}
			}
		}

	}
	int getHash(int key)
	{
		return N * fmod(key * A, 1);
	}
	void printTable()
	{
		for (int i = 0; i < N; i++)
		{
			if (getHash(array[i].getSquare()) > 0)
			{
				cout << i << " Square: " << array[i].getSquare() << " Perimeter: " << array[i].getPerim() << " Hashcode: " << getHash(array[i].getSquare()) << endl;
				cout << "Coordinates: (" << array[i].x[0] << "; " << array[i].y[0] << ") (" << array[i].x[1] << "; " << array[i].y[1] << ") (" << array[i].x[2] << "; " << array[i].y[2] << ")" << endl;
				cout << endl;
			}
			else
			{
				cout << i << " is empty " << endl;
				cout << endl;
			}
		}
	}
};



int main()
{
	cout << "Enter size of HashTable: ";
	int size;
	cin >> size;

	HashTable* hashTable = new HashTable(size);
	int choice;
	while (true)
	{
		cout << "1) Add element\n2) Print" << endl;
		cout << "Choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			if (hashTable->add())
			{
				cout << "Element added." << endl;
			}
			else
			{
				cout << "Error." << endl;
			}
			break;
		case 2:
			hashTable->printTable();
			break;
		}
	}

}