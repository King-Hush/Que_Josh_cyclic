#include <iostream>
using namespace std;

int main() {
    const int MAX = 100;
    int adj[MAX][MAX];
    int visited[MAX] = {0};
    int parent[MAX] = {-1};
    int queue[MAX];
    int path[MAX];
    int V;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> adj[i][j];

    
    bool cycleFound = false;
    int cycleStart = -1, cycleEnd = -1;
    int front = 0, rear = 0;

    for (int start = 0; start < V; start++) {
        if (visited[start] == 0) {
        
            front = 0;
            rear = 0;
            queue[rear++] = start;
            visited[start] = 1;
            parent[start] = -1;

            while (front < rear) {
                int u = queue[front++];

                for (int v = 0; v < V; v++) {
                    if (adj[u][v]) {
                        if (!visited[v]) {
                            visited[v] = 1;
                            parent[v] = u;
                            queue[rear++] = v;
                        } else if (v != parent[u]) {
                        
                            cycleFound = true;
                            cycleStart = v;
                            cycleEnd = u;
                            break;
                        }
                    }
                }
                if (cycleFound) break;
            }
        }
        if (cycleFound) break;
    }

    
    if (cycleFound) {
        cout << "\nCycle found using BFS!\n";

      
        int temp = cycleEnd;
        int index = 0;
        path[index++] = cycleEnd;

        while (temp != cycleStart) {
            temp = parent[temp];
            path[index++] = temp;
        }

        path[index++] = cycleEnd; 
        cout << "Vertices in cycle: ";
        for (int i = index - 1; i >= 0; i--)
            cout << path[i] << " ";
        cout << endl;
    } else {
        cout << "\nNo cycle found in the graph using BFS.\n";
    }

    return 0;
}

