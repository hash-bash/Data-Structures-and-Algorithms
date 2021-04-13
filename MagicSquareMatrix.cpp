#include<iostream>

using namespace std;

class magic_square {
    int a[10][10];
    int n;
public:
    magic_square() {
        cout << "\nEnter 'N': ";
        cin >> n;
    }

    void get() {
        cout << "\nEnter the elements: ";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
    }

    bool row() {
        int sum[10];
        for (int i = 0; i < n; i++) {
            sum[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum[i] = sum[i] + a[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            if (sum[0] != sum[i])
                return false;

        }
        return true;
    }

    bool column() {
        int sum[10];
        for (int i = 0; i < n; i++) {
            sum[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum[i] = sum[i] + a[j][i];
            }
        }
        for (int i = 0; i < n; i++) {
            if (sum[0] != sum[i])
                return false;

        }
        return true;
    }

    bool diagnol() {
        int d1, d2;
        d1 = d2 = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    d1 = d1 + a[i][j];
                if (i + j == n - 1)
                    d2 = d2 + a[i][j];
            }
        }

        if (d1 != d2)
            return false;
        return true;
    }
};

int main() {
    magic_square m;
    m.get();
    if (m.diagnol() && m.row() && m.column())
        cout << "\nIt is a magic matrix.";
    else
        cout << "\nIt is not a magic matrix.";
    return 0;
}

