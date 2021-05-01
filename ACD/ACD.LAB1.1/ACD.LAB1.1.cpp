

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int size, min, sum = 0;
    bool p = 0;
    cout << "Enter size:";
    cin >> size;
    int* massiv = new int[size]; 
    for (int i = 0; i < size; i++) {
        cin >> massiv[i];          
    }
    min = massiv[0];
    for (int i = 0; i < size; i++) {     
        if (abs(massiv[i]) < abs(min)) {
            min = massiv[i];
        }
        if (massiv[i] == 0) {
            p = 1;
        }
        if (p) {
            sum += abs(massiv[i]);
        }
    }
    cout << "massiv:";
    for (int i = 0; i < size; i++) {
       
        cout << massiv[i]<<" ";
    }
    cout << endl;
    cout << "min element = " << min<< endl;
    if (p) {
        cout << "sum = " << sum << endl;
    } 
    else {

        cout << "sum = 0 (Element 0 not found)"<<endl;
    }
}

