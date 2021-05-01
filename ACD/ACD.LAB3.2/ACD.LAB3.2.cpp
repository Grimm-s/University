
#include <iostream>
using namespace std;


class List
{
private:
    int* list = nullptr;
    int size = 0;
public:
    List()
    {
        list = new int();
       
    }
    void create()
    {
        cout << "Created\n";
        for (int i = 0; i < size; i++)
            list[i] = NULL;
        size = 0;
    }
    void push_front()
    {
        cout << "Data: ";
        int x;
        cin >> x;
        list[size] = x;
        size++;
        cout << "Added";
    }
    void insert()
    {
        int x, p;
        cout << "Data: ";
        cin >> x;
        cout << "Index: ";
        cin >> p;
        for (int i = size; i >= p; i--)
            list[i + 1] = list[i];
        size++;
        list[p] = x;
        cout << "Added";
    }
    void display()
    {

        if (size == 0)
        {
            cout << "List empty";
        }
        else
        {           
            for (int i = 0; i < size; i++)
            {
                cout << list[i] << " ";
            }
            cout << "\n";
        }
    }

    void remove_at()
    {
        cout << "Index:";
        int p;
        cin >> p;
        for (int i = p ; i <= size - 1; i++)
            list[i] = list[i + 1];
        list[size] = NULL;
        size--;
        cout << "Deleted";
    }
    void find()
    {
        cout << "Select element for search:";
        int num;
        cin >> num;
        int check = 0;
        for (int i = 0; i <= size - 1; i++)
        {
            if (list[i] == num)
            {
                cout << "Index:" << i;
                check = 1;
            }
        }
        if (check == 0)
        {
            cout << " Element not found";
        }
    }
    void sort()
    {
        int temp;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (list[j] > list[j + 1])
                {
                    temp = list[j];
                    list[j] = list[j + 1];
                    list[j + 1] = temp;
                }
            }
        }
        cout << "Sorted";

    }
    void sort_insert()
    {
        cout << "Selecet element for insert:";
        int x;
        cin >> x;
        bool check = false;
        int p = -1;
        for (int i = 0; i <= size; i++)
        {
            if ((x > list[i]) && (x <= list[i + 1]))
            {
                p = i + 1;
                check = 1;
            }
        }
        if (check)
        {
            for (int i = size; i >= p; i--)
                list[i + 1] = list[i];
            size++;
            list[p] = x;
        }
        if (!check)
        {
            list[size] = x;
            size++;
        }
        cout << "Added";
    }

};
int main()
{
   
    cout << "\n-----MENU------\n1. create()\n2. push_front()\n3. insert()\n4. remove_at()\n5. find()\n6. sort()\n7. sort_insert\n8. display()\n9. exit()\n";
    int choice;
    List list;
    while (true)
    {
        cout << "\nFunction: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            list.create();
            break;
        case 2:
            list.push_front();
            break;
        case 3:
            list.insert();
            break;
        case 4:
            list.remove_at();
            break;
        case 5:
            list.find();
            break;
        case 6:
            list.sort();
            break;
        case 7:
            list.sort_insert();
            break;
        case 8:
            list.display();
            break;
        case 9:
            exit(0);
            break;
        }
    }
    return 0;
}
