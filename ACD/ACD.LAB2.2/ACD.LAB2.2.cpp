
#include <iostream>
#include <conio.h>
using namespace std;
/*НАША СТРУКТУРА*/
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
		cout << temp->x << " ";                         //Выводим на экран элемент стека
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
void Empty(List* MyList) {
	List* temp = MyList->Head;
	if (temp==NULL) {
		cout << "stack is empty";

	}
	else {
		cout << "stack is not empty";
	}

}


int main()
{
	List* MyList = new List; //Выделяем память для стека
	MyList->Head = NULL;
	cout << "How many items do you want to enter"<<endl;
	//cout << "value: ";
	int size;
	cin >> size;
	
	int p = 0;
	for (int i = 0; i < size; i++) {
		Push(p, MyList);
		p++;
	}
	//cin >> x;
	//test.Push(x);
	cout << "Stack: ";
	Output(MyList);
	cout << endl;
	_getch();	
	//Pop();
	Pop(MyList);	
	cout << "Stack after pop: ";
	Output(MyList);
	cout << endl;
	_getch();		
	Empty(MyList);	
	_getch();		
	
	
				
}