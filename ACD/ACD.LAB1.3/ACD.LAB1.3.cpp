#include <iostream>
#include <stdlib.h>   
#include <time.h>  
#include <conio.h>
#include <math.h>
using namespace std;
int main()
{
    srand(time(NULL));
    int x, y,choice,n;
    cout << "Enter x:";
    cin >> x;
    cout << "Enter y:";
    cin >> y;
    int massiv[100][100];
    int massiv_c[100];
    int q=1;
    for (int i2 = 0; i2 < y; i2++) {
        for (int i1 = 0; i1 < x; i1++) {
            massiv[i1][i2] = rand() % 10;
            cout << massiv[i1][i2] << " ";
        }
        q++;
        cout << endl;

    }
    while (true) {
        
        system("cls");
        for (int i2 = 0; i2 < y; i2++) {
            for (int i1 = 0; i1 < x; i1++) {
                cout << massiv[i1][i2] << " ";
            }
            cout << endl;
        }
        cout << "Cyclic shift" << endl << "Set the mode:" << endl << "1.Right" << endl << "2.Down" << endl<<"Any key.exit" <<endl<< "Choice:";
        cin >> choice;
      
        switch (choice) {
        case 1:
            cout << "n=";
            cin >> n;
            for (int i = 0; i < n; i++) {
                for (int p = 0; p < y; p++) {
                    massiv_c[p] = massiv[x - 1][p];
                    for (int k = x - 1; k > 0; k--) {
                        massiv[k][p] = massiv[k - 1][p];
                    }
                    massiv[0][p] = massiv_c[p];
                }
            }
            break;
        case 2:
            cout << "n=";
            cin >> n;
            for (int i = 0; i < n; i++) {
                for (int p = 0; p < x; p++) {
                    massiv_c[p] = massiv[p][y - 1];
                    for (int k = y - 1; k > 0; k--) {
                        massiv[p][k] = massiv[p][k - 1];
                    }
                    massiv[p][0] = massiv_c[p];
                }
            }
            break;
        default:
            exit(0);
        }
        for (int i2 = 0; i2 < y; i2++) {
            for (int i1 = 0; i1 < x; i1++) {
                cout << massiv[i1][i2] << " ";
            }
            cout << endl;
        }
        _getch();
        
    }
    cout << endl;   
}
   



