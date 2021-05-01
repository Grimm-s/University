#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;
int head = 0;
bool Empty(int massiv[])
{
	if (head == 0)
		return true;
	else
		return false;
}
void Push(int massiv[], int x, int size)
{
	if (head < size)
	{
		massiv[head] = x;
		head += 1;
	}
	else
		cout << "stack is full" << endl;
}
int Pop(int massiv[])
{
	if (Empty(massiv) == true)
	{
		cout << "stack is empty" << endl;
	}
	else
	{
		head--;
		return massiv[head];
	}
}
void Output(int massiv[])
{
	for (int i = 0; i < head; i++)
	{
		cout << massiv[i] << " ";
	}
	cout <<endl;
}

int main()
{	
	int size;
	cout << "stack size: " << endl;
	cin >> size;
	int* massiv = new int[size];
	int p=0;	
	for (int i = 0; i < size; i++) {
		Push(massiv, p, size);
		p++;
	}
	cout << "stack:" << "\n";
	Output(massiv);
	_getch();		
	Pop(massiv);
	cout << "stack after pop:" << "\n";
	Output(massiv);
	_getch();		
	if (Empty(massiv) == 1)
	{
		cout << "stack is empty" << endl;
	}
	else
		cout << "stack is not empty" << endl;
	_getch();					
	cout << "last element: " << massiv[head - 1] << endl;
	_getch();		
	if (head == size)
	{
		cout << "stack is full" << endl;
	
	}
	else {
		cout << "stack is not full" << endl;
	
	}	
	_getch();		
}