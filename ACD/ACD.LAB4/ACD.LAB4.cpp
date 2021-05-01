#include <iostream>
#define CMP_EQ(a, b) ((a) == (b))
#define CMP_LT(a, b) ((a) < (b))
#define CMP_GT(a, b) ((a) > (b))
using namespace std;

int tabs = 0;
int kol_vo = 0;



struct Branch
{
	int Data;
	Branch* LeftBranch;
	Branch* RightBranch;
};


void Add(int aData, Branch*& aBranch)
{

	if (!aBranch)
	{
		aBranch = new Branch;
		aBranch->Data = aData;
		aBranch->LeftBranch = 0;
		aBranch->RightBranch = 0;
		return;
	}
	else
		if (aBranch->Data > aData)
		{
			Add(aData, aBranch->LeftBranch);
		}
		else
		{
			Add(aData, aBranch->RightBranch);
		};
}

void print(Branch* aBranch)
{
	if (!aBranch) return;
	tabs += 5;
	print(aBranch->LeftBranch);
	for (int i = 0; i < tabs; i++) cout << " ";
	cout << aBranch->Data << endl;
	print(aBranch->RightBranch);
	tabs -= 5;
	return;
}

void add_elem(int aData, Branch*& aBranch)
{
	if (!aBranch)
	{
		aBranch = new Branch;
		aBranch->Data = aData;
		aBranch->LeftBranch = 0;
		aBranch->RightBranch = 0;
		return;
	}
	else
	{
		if (aData < aBranch->Data) {
			add_elem(aData, aBranch->LeftBranch);
		}
		else if (aData > aBranch->Data) {
			add_elem(aData, aBranch->RightBranch);
		}
	}
}

void is_Empty(Branch*& aBranch)
{
	if (!aBranch)
	{
		cout << "Дерево пустое...";
	}
	else
	{
		cout << "Дерево не пустое...";
	}
}

void FreeTree(Branch* aBranch)
{
	if (!aBranch) return;
	FreeTree(aBranch->LeftBranch);
	FreeTree(aBranch->RightBranch);
	delete aBranch;
	return;
}

Branch* del_elem(Branch*& aBranch, int aData) {
	if (aBranch == NULL)
		return aBranch;

	if (aData == aBranch->Data) {

		Branch* tmp;
		if (aBranch->RightBranch == NULL)
			tmp = aBranch->LeftBranch;
		else {

			Branch* ptr = aBranch->RightBranch;
			if (ptr->LeftBranch == NULL) {
				ptr->LeftBranch = aBranch->LeftBranch;
				tmp = ptr;
			}
			else {

				Branch* pmin = ptr->LeftBranch;
				while (pmin->LeftBranch != NULL) {
					ptr = pmin;
					pmin = ptr->LeftBranch;
				}
				ptr->LeftBranch = pmin->RightBranch;
				pmin->LeftBranch = aBranch->LeftBranch;
				pmin->RightBranch = aBranch->RightBranch;
				tmp = pmin;
			}
		}

		delete aBranch;
		return tmp;
	}
	else if (aData < aBranch->Data)
		aBranch->LeftBranch = del_elem(aBranch->LeftBranch, aData);
	else
		aBranch->RightBranch = del_elem(aBranch->RightBranch, aData);
	return aBranch;
}
void straight(Branch*& root)
{
	if (!root)
		return;
	cout << root->Data << " ";
	straight(root->LeftBranch);
	straight(root->RightBranch);
}
void reverse(Branch*& root)
{
	if (!root)
		return;
	reverse(root->LeftBranch);

	cout << root->Data << " ";

	reverse(root->RightBranch);
}
void tail(Branch*& root)
{
	if (!root)
		return;
	tail(root->LeftBranch);
	tail(root->RightBranch);
	cout << root->Data << " ";
}
Branch* search_for_val(Branch*& root, int val)
{

	if (root->Data == val) {
		return root;
	}
	else {}
	return search_for_val(root->RightBranch, val);
	return search_for_val(root->LeftBranch, val);
}


int main()
{
	setlocale(LC_ALL, "rus");
	Branch* Root = 0;
	int size;
	int element;
	int k;

	//cout << "Введите кол-во элементов для будущего дерева: ";
	//cin >> size;
	//cout << endl;

	//cout << "Проверим дерево на пустоту до его заполнения: " << endl;
	//is_Empty(Root);
	//cout << endl;
	int massiv[9] = { 12,24,35,2,35,4,56,78,100 };
	for (int i = 0; i < 9; i++)
	{
		add_elem(massiv[i],Root);
	}

//	cout << "Проверим дерево на пустоту после его заполнения: " << endl;
	//is_Empty(Root);
	//cout << endl;

	cout << "Вывод бинарного дерева: " << endl;
	print(Root);
	cout << endl;

	cout << "Удалим элемент из бинарного дерева:" << endl;
	cout << "Введите элемент: ";
	cin >> element;
	del_elem(Root, element);

	cout << "Вывод бинарного дерева: " << endl;
	print(Root);
	cout << endl;

	cout << "Добавим новый элемент в бинарное дерево:" << endl;
	cout << "Введите новый элемент: ";
	cin >> element;
	add_elem(element, Root);

	cout << "Вывод бинарного дерева: " << endl;
	print(Root);
	/*cout << endl;
	cout << "Прямой обход:";
	straight(Root);
	cout << endl;
	cout << "Обратный обход:";
	reverse(Root);
	cout << endl;
	cout << "Концевой обход:";
	tail(Root);
	cout << endl;
	//cout << "Поиска элемента:";*/
	FreeTree(Root);
	//cout << "Поиска элемента:";
	//int x;
	//cin >> x;
//	print(search_for_val(Root, x));
	//cout << search_for_val(Root, x);
	cout << "Вся динамическая память очищена..." << endl;
	return 0;
}