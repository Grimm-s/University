#include <iostream>
#include <cstring>
using namespace std;

#define INF 9999999
#define V 8

int G[V][V] = {
  {0,1,0,2,0,0,0,0},
  {1,0,2,4,3,0,0,0},
  {0,2,0,0,5,2,0,0},
  {2,4,0,0,5,0,7,0},
  {0,3,5,5,0,1,5,0},
  {0,0,2,0,1,0,4,6},
  {0,0,0,7,5,4,0,7},
  {0,0,0,0,0,6,7,0}
};
int main() {
	int p = 0;
	int cost = 0;
	int no_edge;           
	int selected[V]; 
	memset(selected, false, sizeof(selected));
	no_edge = 0;
	selected[0] = true;
	int x;
	int y;
	cout << "Edge" << " : " << "Weight";
	cout << endl;
	while (no_edge < V - 1) {
		int min = INF;
		x = 0;
		y = 0;
		for (int i = 0; i < V; i++) {
			if (selected[i]) {
				for (int j = 0; j < V; j++) {
					if (!selected[j] && G[i][j]) { 
						p++;
						if (min > G[i][j]) {
							min = G[i][j];
							x = i;
							y = j;
						}

					}
				}
			}
		}
		cost += G[x][y];
		cout << x << " - " << y << " :  " << G[x][y];
		cout << endl;
		selected[y] = true;
		no_edge++;
	}
	cout << "Cost: " << cost << endl;;
	cout << "Number of comparisons: " << p;
	return 0;
}
