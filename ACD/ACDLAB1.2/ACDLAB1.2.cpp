#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    
    int size,p=0,k=0;
    cout << "Enter size:";
    cin >> size;
    int* massiv = new int[size];
    cout << "Input massiv:";
    for (int i = 0; i < size; i++) {
        massiv[i] = p;
        p++;
        cout << massiv[i] << " ";
    }
    for (int i = 1; i < size/2+k; i+=1) {
        if (size % 2 == 0 && size>3) {
            swap(massiv[i], massiv[2 * i]);
        }
        else {
            k = 1;
            swap(massiv[i], massiv[2 * i]);
        }
    } 
    cout << endl;
    cout << "Output massiv:";
    for (int i = 0; i < size; i++) {
        cout << massiv[i] << " ";
    }
    cout << endl;
    
}
