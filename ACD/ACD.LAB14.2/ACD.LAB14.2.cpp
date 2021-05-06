#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>
using namespace std;
class Graph {
private:
    int cost = 0;
    int p = 0;
    vector<pair<int, pair<int, int>>> G; 
    vector<pair<int, pair<int, int>>> T; 
    int* parent;
    int V;
public:
    Graph(int V);
    void AddWeightedEdge(int u, int v, int w);
    int find_set(int i);
    void union_set(int u, int v);
    void kruskal();
    void print();
};
Graph::Graph(int V) {
    parent = new int[V];

    for (int i = 0; i < V; i++)
        parent[i] = i;

    G.clear();
    T.clear();
}
void Graph::AddWeightedEdge(int u, int v, int w) {
    G.push_back(make_pair(w,make_pair(u,v)));
}
int Graph::find_set(int i) {
    // If i is the parent of itself
    if (i == parent[i])
        return i;
    else
        // Else if i is not the parent of itself
        // Then i is not the representative of his set,
        // so we recursively call Find on its parent
        return find_set(parent[i]);
}

void Graph::union_set(int u, int v) {
   parent[u] = parent[v];
}
void Graph::kruskal() {
    int i, uRep, vRep;
    sort(G.begin(), G.end()); // increasing weight
    for (i = 0; i < G.size(); i++) {
        uRep = find_set(G[i].second.first);
        vRep = find_set(G[i].second.second);
        p++;
        if (uRep != vRep) {
            T.push_back(G[i]); // add to tree
            union_set(uRep, vRep);
        }
    }
}
void Graph::print() {
    cout << "Edge :" << " Weight" << endl;
    for (int i = 0; i < T.size(); i++) {
        cost += T[i].first;
        cout << T[i].second.first << " - " << T[i].second.second << " : "
            << T[i].first;
        cout << endl;
    }
    cout << "Cost: " << cost<<endl;
	cout << "Number of comparisons: "<<p;
}
int main() {
    Graph g(8);

	
    g.AddWeightedEdge(0, 1, 1);
    g.AddWeightedEdge(0, 3, 2);
	
    g.AddWeightedEdge(1, 3, 4);
    g.AddWeightedEdge(1, 4, 3);
    g.AddWeightedEdge(1, 2, 2);
    g.AddWeightedEdge(1, 0, 1);
	
	
    g.AddWeightedEdge(2, 4, 5);
    g.AddWeightedEdge(2, 5, 2);
    g.AddWeightedEdge(2, 1, 2);
	
    g.AddWeightedEdge(3, 6, 7);
    g.AddWeightedEdge(3, 4, 4);
    g.AddWeightedEdge(3, 1, 4);
    g.AddWeightedEdge(3, 0, 2);
	
    g.AddWeightedEdge(4, 1, 3);
    g.AddWeightedEdge(4, 2, 5);
    g.AddWeightedEdge(4, 3, 5);
    g.AddWeightedEdge(4, 5, 1);
    g.AddWeightedEdge(4, 6, 5);
    
    g.AddWeightedEdge(5, 2, 2);
    g.AddWeightedEdge(5, 4, 1);
    g.AddWeightedEdge(5, 6, 4);
    g.AddWeightedEdge(5, 7, 6);
	
    g.AddWeightedEdge(6, 3, 7);
    g.AddWeightedEdge(6, 4, 5);
    g.AddWeightedEdge(6, 5, 4);
    g.AddWeightedEdge(6, 7, 7);
	
    g.AddWeightedEdge(7, 5, 6);
    g.AddWeightedEdge(7, 6, 7);
	
    g.kruskal();
    g.print();
	
    return 0;
}