#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;
int linear_search(int *massiv, int key,int size){
    for (int i = 0; i < size; i++) {
        if (massiv[i] == key) {
            return i;
        }
    }
    return -1;
}
int main(int argc, char* argv[])
{
    srand(time(0)); 
    int size, key,choice,temp;
    cout << "Select size of massiv:";
    cin >> size;
    int *massiv = new int[size];
    cout << "1.random input" << endl << "2.manual input" << endl;
    cout << "choice:";
    cin >> choice;
    switch (choice) {
    case 1:
        for (int i = 0; i < size; i++) {
            massiv[i] = 1 + rand() % 100;
            cout << massiv[i]<<" ";
        }
        cout << endl;
        cout << "key:";
        cin >> key;
        temp = linear_search(massiv, key, size);
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
        temp = linear_search(massiv, key, size);
        if (temp == -1) {
            cout << "element not found";

        }
        else {
            cout << "index of key:" << temp;
        }
        break;
    
    }

    
}