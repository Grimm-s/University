#define QMAX 20
#include <conio.h>
#include <cmath>
#include <iostream>
using namespace std;

struct queue
{
	int arr[QMAX];
	int last, first;
};

void Insert(struct queue* q, int x)
{
	if (q->last < QMAX - 1)
	{
		q->last++;
		q->arr[q->last] = x;
	}
	else
		cout << "Queue is full!\n";
}

bool Empty(struct queue* q)
{
	if (q->last < q->first)
	{
		return true;
	}
	return false;
}

void Display(struct queue* q)
{
	if (Empty(q) == 1)
	{
		cout << "Queue is empty!\n";
		return;
	}
	cout << "Your queue is: " << endl;
	for (int i = q->first; i <= q->last; i++)
		cout << q->arr[i] << " ";
	cout << "\n";
}

int Remove(struct queue* q)
{
	int x;
	if (Empty(q) == true)
	{
		cout << "Queue is already empty." << endl;
		return 0;
	}
	else
	{
		x = q->arr[q->first];
		q->first++;
		return x;
	}
}

int main()
{
	queue* q = new queue;
	q->first = 1;
	q->last = 0;

	if (Empty(q) == true)
	{
		cout << "Queue is empty!" << endl;
	}
	else cout << "Queue is not empty" << endl;
	Insert(q, 1);
	Insert(q, 2);
	Insert(q, 3);
	Insert(q, 4);
	Insert(q, 5);
	Display(q);
	if (Empty(q) == true)
	{
		cout << "Queue is empty!" << endl;
	}
	else cout << "Queue is not empty" << endl;
	Remove(q);
	cout << "After remove";
	cout << endl;;

	Display(q);
}