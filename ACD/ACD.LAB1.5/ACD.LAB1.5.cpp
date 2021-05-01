#include <iostream>
#include <stdlib.h>   
#include <time.h>  
#include <math.h>
using namespace std;
int main()
{
    srand(time(NULL));
    int size;
    cout << "Enter size:";
    cin >> size;
 
    int massiv[100][100];
  
    for (int i2 = 0; i2 < size; i2++) {
        for (int i1 = 0; i1 < size; i1++) {
            if (i1 == i2 ||i1==(size-1)-i2 || i1>i2){
                massiv[i1][i2] = 1;
            }
            else {
                massiv[i1][i2] = 0;
            }
            cout << massiv[i1][i2] << " ";
        }
        cout << endl;
    }
    

    
}




