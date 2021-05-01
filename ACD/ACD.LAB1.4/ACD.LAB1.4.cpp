#include <iostream>
#include <stdlib.h>   
#include <time.h>  
#include <math.h>
using namespace std;
int main()
{
    srand(time(NULL));
    int x, y, q=0;
    cout << "Enter x:";
    cin >> x;
    cout << "Enter y:";
    cin >> y;
    int massiv[100][100];
    int massiv_c[100];
    for (int i2 = 0; i2 < y; i2++) {
        for (int i1 = 0; i1 < x; i1++) {
            massiv[i1][i2] = rand() % 10;
            cout << massiv[i1][i2] << " ";
        }       
        cout << endl;
    }
    for (int i2 = 0; i2 < y; i2++) {
        for (int i1 = 0; i1 < x; i1++) {
            if (massiv[i1][i2] == 3) {
                if (i1 - 1 < 0) {
                    massiv_c[q]=massiv[i1+1][i2];
                    q++;
                }
                else if (i1 + 1 > x-1) {
                    massiv_c[q] = massiv[i1 - 1][i2];
                    q++;

                }
                else {
                    massiv_c[q] = massiv[i1 - 1][i2] + massiv[i1 + 1][i2];
                    q++;
                }
           }
        }
    }
   
    cout << endl;
    for (int p = 0; p < q; p++) {
        cout << massiv_c[p] << " ";

    }
    cout << endl;

}




