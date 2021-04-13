#include<iostream>

#define max 9999;
using namespace std;

class edge {
    int start, end, wt;

public:
    edge() {
        start = -1;
        end = -1;
        wt = -1;
    }

    friend class graph;
};

class graph {
public:
    edge e[100];
    int eno, n;
    int g[100][100];
    char node1[20];

    graph() {
        cout << "\nEnter the number of element in the graph: ";
        cin >> n;

        eno = 0;

        for (int i = 0; i < n; i++) {
            cout << "\nEnter the name of node " << i + 1 << ": ";
            cin >> node1[i];
        }
        for (int i = 0; i < n; i++) {

            for (int j = i; j < n; j++) {
                if (i == j) {
                    g[i][j] = max;
                } else {
                    cout << "\nEnter the weight between " << node1[i] << " and " << node1[j] << " or -1 for no edge: ";
                    cin >> g[i][j];
                    g[j][i] = g[i][j];
                    if (g[i][j] == -1) {
                        g[i][j] = max;
                        g[j][i] = max;
                    } else {
                        e[eno].start = i;
                        e[eno].end = j;
                        e[eno].wt = g[i][j];
                        eno++;
                    }
                }
            }
        }
    }

    void show(edge *an, int x) {
        for (int i = 0; i < x; i++) {
            cout << node1[an[i].start] << " -> " << node1[an[i].end] << " = " << an[i].wt << endl;
        }
    }

    void prims() {
        edge *ans = new edge[n - 1];
        int visit[100], dist[100], from[100];

        for (int k = 0; k < n; k++) {
            dist[k] = g[0][k];
            visit[k] = 0;
            from[k] = 0;
        }
        visit[0] = 1;
        int min, i, j, ind;
        i = 0;
        j = 0;
        ind = 0;

        while (i < (n - 1)) {
            min = max;

            for (int k = 0; k < n; k++) {
                if (min > dist[k] && visit[k] == 0) {
                    min = dist[k];
                    j = k;
                }
            }
            visit[j] = 1;
            ans[ind].start = from[j];
            ans[ind].end = j;
            ans[ind].wt = min;
            ind++;

            for (int k = 0; k < n; k++) {
                if (g[j][k] < dist[k] && visit[k] == 0) {
                    dist[k] = g[j][k];
                    from[k] = j;
                }
            }
            i++;
        }

        show(ans, n - 1);
    }
};

int main() {
    graph g1;
    g1.prims();
    return 0;
}
