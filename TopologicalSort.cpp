#include<iostream>
#include <list>
#include <stack>

using namespace std;

class Graph {
    int V;

    list<int> *adj;

public:

    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void topological(int v, bool visited[], stack<int> &Stack) {

        visited[v] = true;

        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i])
                topological(*i, visited, Stack);

        Stack.push(v);
    }

    void topologicalSort() {
        stack<int> Stack;

        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        for (int i = 0; i < V; i++)
            if (visited[i] == false)
                topological(i, visited, Stack);

        while (Stack.empty() == false) {
            cout << Stack.top() << " ";
            Stack.pop();
        }
    }
};

int main() {
    int x, y, n, e;
    cout << "\nEnter the number of elements you want to insert: ";
    cin >> n;
    Graph g(n);
    cout << "\nEnter the number of edges you want to insert: ";
    cin >> e;
    cout << "\nEnter the edges: ";
    for (int i = 0; i < e; i++) {
        cout << "\nEnter the first node: ";
        cin >> x;
        cout << "\nEnter the second node: ";
        cin >> y;
        g.addEdge(x, y);
    }
    cout << "\nTopological Sort is: ";
    g.topologicalSort();

    return 0;
}
