#include <iostream>
#include <conio.h>
using namespace std;

struct list
{
	int item;
	list* pNext;
};

struct queue
{
	int size;
	struct list* first, * last;
};

void init(struct queue* q)
{
	q->first = new list;
	q->first->pNext = nullptr;
	q->last = q->first;
	q->size = 0;
}

bool Empty(struct queue* q)
{
	if (q->first->pNext == nullptr)
	{
		return true;
	}
	return false;
}

void Insert(queue* q, int x)
{
	q->last->pNext = new list;
	q->last = q->last->pNext;
	q->last->item = x;
	q->last->pNext = nullptr;
	q->size++;
	
}

void Remove(struct queue* q)
{
	q->first = q->first->pNext;
	q->size--;
	
}

void Display(struct queue* q)
{
	if (Empty(q) == true)
	{
		cout << "Queue is empty" << endl;
	}
	list* p;
	p = q->first->pNext;
	while (p != nullptr)
	{
		cout <<p <<'\t'<<p->item <<'\t'<<p->pNext<<endl;
		p = p->pNext;
	}
}
struct List
{
	int x;                                              //информационный элемент
	List* Next, * Head;                                   //Голова стека и указатель на следующий элемент
};

/*ФУНКЦИЯ ДОБАВЛЕНИЯ ЭЛЕМЕНТА В СТЕК (в список LIFO)*/
void Push(int x, List*& MyList)                          //Принимаем элемент стека и указатель на стек, при этом говорим, что принимаемый указатель будет сам по себе указателем
{
	List* temp = new List;                              //Выделяем память для нового элемента
	temp->x = x;                                        //Записываем в поле x принимаемый в функцию элемент x
	temp->Next = MyList->Head;                          //Указываем, что следующий элемент это предыдущий
	MyList->Head = temp;                                //Сдвигаем голову на позицию вперед
}

/*ФУНКЦИЯ ОТОБРАЖЕНИЯ СТЕКА*/
void Output(List* MyList)                                 //Нужен только сам стек
{
	List* temp = MyList->Head;                          //Объявляем указатель и Указываем ему, что его позиция в голове стека
	//с помощью цикла проходим по всему стеку
	while (temp != NULL)                                //выходим при встрече с пустым полем
	{
		cout << temp << '\t' << temp->x << '\t' << temp->Next << endl;
		                       //Выводим на экран элемент стека
		temp = temp->Next;                              //Переходим к следующему элементу
	}
}

/*ФУНКЦИЯ УДАЛЕНИЯ СТЕКА ИЗ ПАМЯТИ*/
void Pop(List* MyList)
{

	List* temp = MyList->Head->Next;                    //Временная переменная для хранения адреса следующего элемента
	delete MyList->Head;                                //Освобождаем адрес обозначающий начало
	MyList->Head = temp;                                //Меняем адрес на следующий

}
void empty(List* MyList) {
	List* temp = MyList->Head;
	if (temp == NULL) {
		cout << "stack is empty";

	}
	else {
		cout << "stack is not empty";
	}

}
void Test(struct queue* q,List *MyList)
{
	if (Empty(q) == true)
	{
		cout << "Queue is empty" << endl;
	}
	list* p;
	p = q->first->pNext;
	while (p != nullptr)
	{
		//cout << p << '\t' << p->item << '\t' << p->pNext << endl;
		Push(p->item, MyList);
		Remove(q);
		p = p->pNext;
	}
}
void Test2(List* MyList)                                 //Нужен только сам стек
{
	while (MyList->Head != NULL) {
		List* temp = MyList->Head->Next; 

		if (temp->x % 3 == 0) {
			cout << temp->x<<" ";
		}
		delete MyList->Head;                                //Освобождаем адрес обозначающий начало
		MyList->Head = temp;
	}                              //Меняем адрес на следующий
}


int main()
{
	queue* q = new queue;
	List* MyList = new List; 
	MyList->Head = NULL;
	init(q);
	MyList->Head = NULL;
	for (int p = 3; p < 56; p++) {
		Insert(q,p);
	}	

	cout << "Queque:" << endl;
	Display(q);
	Test(q, MyList);
	cout << "Stack:" << endl;
	Output(MyList);
	cout << "removed stack elements and multiples of 3:";
	Test2(MyList);
	


	
}

