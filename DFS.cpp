#include <iostream>
using namespace std;

int main() {
    const int MAX = 100;
    int adj[MAX][MAX];
    int visited[MAX];
    int parent[MAX];
    int queue[MAX];
    int front, rear;
    int V;

    // Input number of vertices
    cout<<"Enter number of vertices: ";
    cin>>V;

    // Input adjacency matrix
    cout<< "Enter adjacency matrix:";
       for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) 
        cin>>adj[i][j];

    // ========== DFS without function ==========
    cout << "\n--- DFS Check ---\n";
    for (int i = 0; i < V; i++) visited[i] = 0;

    bool cycleDFS = false;
    int stack[MAX];
    int top = -1;
    int parentDFS[MAX];
    for (int start = 0; start < V; start++) {
        if (visited[start] == 0) {
            top = -1;
            stack[++top] = start;
            parentDFS[start] = -1;

            while (top >= 0) {
                int u = stack[top--];
                if (visited[u]) continue;
                visited[u] = 1;

                for (int v = 0; v < V; v++) {
                    if (adj[u][v]) {
                        if (!visited[v]) {
                            stack[++top] = v;
                            parentDFS[v] = u;
                        } else if (v != parentDFS[u]) {
                            cout << "Cycle found using DFS between " << u << " and " << v << "\n";
                            cycleDFS = true;
                            break;
                        }
                    }
                }
                if (cycleDFS) break;
            }
        }
        if (cycleDFS) break;
    }

    if (!cycleDFS)
        cout << "No cycle found using DFS.\n";


    return 0;
}