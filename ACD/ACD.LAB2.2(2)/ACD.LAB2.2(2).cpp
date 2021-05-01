#include <stdio.h>;
#include <iostream>;
using namespace std;
struct comp { 
	int Data; 
	comp* next;
};

void Push(comp** top, int D) { 
	comp* q; 
	q = new comp();
	q->Data = D;
	if (top == NULL) { 
		*top = q; 
	}
	else
	{
		q->next = *top; 
		*top = q; 
	}
}
void Empty(comp* top) {
	if (top == NULL) { 
		cout << "Stack is empty";
	}
	else {
		cout<< "Stack is not empty";
	}
}

void Pop(comp** top) {
	comp* q = *top;
	comp* prev = NULL;
	*top = q->next;
	free(q);
	q->Data = NULL; 
	q->next = NULL;
	q == NULL;
	
		
}
void StackTop(comp* top) {
	comp* q = top;
	cout <<"Stack top:" <<q->Data;
}

void Print(comp* top) { 
	comp* q = top; 
	while (q) { 
		cout <<q<<'\t'<< q->Data<<'\t'<<q->next<<endl;
		q = q->next;
	}
}

void main() {
	comp* top = NULL;
	//Empty(top);
	//cout << endl;
	Push(&top, 1);
	Push(&top, 2);
	Push(&top, 3);
	Push(&top, 4);
	Push(&top, 5);
	cout << "Stack:"<<endl;
	Print(top);
	cout << endl;
	//Empty(top);
	///cout << endl;
	//StackTop(top);
	Pop(&top); 
	Pop(&top);
	cout << endl;
	cout << "Stack after 2 Pop:"<<endl;
	Print(top);
	cout << endl;
	system("pause");
}
