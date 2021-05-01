
#include <iostream>
#include<string>
using namespace std;


template<typename T>

class List {
public:
	List();
	~List();
	void clear();
	void sort();
	void sort_insert(T num);
	void find(T num);
	void display();
	void pop_back();
	void insert(T value, int index);
	void pop_front();
	void remove_at(int index);
	void push_back(T data);
	int get_size() {
		return size;
	}
	void push_front(T data);
	T& operator[](const int index);
private:
	template<typename T>
	class Node {
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	int size;
	Node<T>* head;

};
template<typename T>
List<T>::List() {
	size = 0;
	head = nullptr;
}
template<typename T>
List<T>::~List() {
	clear();
}

template<typename T>
void List<T> ::push_back(T data) {
	if (head == nullptr) {
		head = new Node<T>(data);

	}
	else {
		Node<T>* current = this->head;
		while (current->pNext != nullptr) {
			current = current->pNext;

		}
		current->pNext = new Node<T>(data);
	}
	size++;
}
template<typename T>
T& List<T> :: operator[](const int index) {
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr) {
		if (counter == index) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	}


}
template<typename T>
void List<T> ::pop_front() {
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	size--;
}
template<typename T>
void List<T> ::clear() {
	while (size) {
		pop_front();
	}
}
template<typename T>
void List<T> ::push_front(T data) {
	head = new Node<T>(data, head);
	size++;
}
template<typename T>
void List<T> ::insert(T value, int index) {
	if (index == 0) {
		push_front(value);
	}
	else {
		Node<T>* previous = this->head;
		for (int i = 0; i < index; i++) {
			previous = previous->pNext;
		}
		previous->pNext = new Node<T>(value, previous->pNext);
		size++;
	}

}
template<typename T>
void List<T> ::remove_at(int index) {
	if (index == 0) {
		pop_front();
	}
	else {
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++) {
			previous = previous->pNext;
		}
		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		size--;
	}
}
template<typename T>
void List<T> ::pop_back() {

	remove_at(size - 1);
}
template<typename T>
void List<T> ::display() {
	Node<T>* current = this->head;
	while (current != nullptr) {
		cout <<current <<'\t'<< current->data <<'\t'<<current->pNext<<endl;
		current = current->pNext;
	}
}
template<typename T>
void List<T> ::find(T num) {
	Node<T>* current = this->head;
	bool temp = false;;
	for (int i = 0; i < size; i++) {
		if (current->data == num) {
			cout << "index:" << i;
			temp = true;
			break;
		}
		current = current->pNext;
	}
	if (!temp) {
		cout << "Element not found";
	}
}
template<typename T>
void List<T> ::sort() {
	
	for (int i = 0; i < size; i++) {
		Node<T>* current1 = this->head;
		Node<T>* current2 = this->head;
		current2 = current1->pNext;
		while (current2 != nullptr) {
			if (current1->data > current2->data) {
				int temp = current1->data;
				current1->data = current2->data;
				current2->data = temp;
			}
			current1 = current1->pNext;
			current2 = current2->pNext;
		}
	}
}
template<typename T>
void List<T> ::sort_insert(T num) {
	
	Node<T>* current = this->head;
	bool check = true;
	while (current != nullptr) {
		if (current->data > num) {
			int temp = current->data;
			current->data = num;
			current->pNext = new Node<T>(temp, current->pNext);
			size++;
			check = false;
			break;
		}		
		current = current->pNext;
	}
	if (check) {
		push_back(num);		
	}
}
int main()
{
	List<int> list;
	int list_size, n = 15;
	int choice;
	int Data;
	int num;
	int i = 0;
	//cout << "List size:";
	//cin >> list_size;
	//for (int i = 0; i < list_size; i++) {
		//list.push_back(n);
	//	n--;
	//}
	cout << "\n-----MENU-----\n1. display().\n2. clear()\n3. pop_back()\n4. insert()\n5. pop_front()\n6. remove_at\n7. push_back\n8. push_front\n9. get_size()\n10. find()\n11. sort()\n12. sort_insert\n13. exit()\n14. create new list";
	while (true)
	{
		cout << "\nFunction: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			list.display();
			break;
		case 2:
			list.clear();
			cout << "Cleared";
			break;
		case 3:
			list.pop_back();
			cout << "Added";
			break;
		case 4:
			cout << "Data:";
			cin >> Data;
			
			cout << "Index:";
			cin >> i;
			
			list.insert(Data, i);
			cout << "Added";
			break;
		case 5:
			list.pop_front();
			cout << "Added";
			break;
		case 6:
			cout << "Index:";
			cin >> i;
			cout << endl;
			list.remove_at(i);
			cout << "Deleted";
			break;
		case 7:
			cout << "Data:";
			cin >> Data;
			
			list.push_back(Data);
			cout << "Added";
			break;
		case 8:
			cout << "Data:";
			cin >> Data;
			
			list.push_front(Data);
			cout << "Added";
			break;
		case 9:
			cout <<"Size:" <<list.get_size();
			break;
		case 10:
			cout << "Select element for search:";
			cin >> num;
			list.find(num);
			break;
		case 11:
			list.sort();
			cout << "Sorted";
			break;
		case 12:
			cout << "Selecet element for insert:";
			cin >> num;
			list.sort_insert(num);
			cout << "Added";
			break;
		case 13:
			exit(0);
			break;
		case 14:
			list.~List();
			List<int> list;			 			
			break;
		}
	}
	return 0;
}

