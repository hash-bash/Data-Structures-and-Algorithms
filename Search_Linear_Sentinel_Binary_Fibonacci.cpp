#include<iostream>

using namespace std;

class search {
public:
    int n, i, data[50], son[50], sortdata[50], s;

    void intake() {
        cout << "\nEnter no. of elements: ";
        cin >> n;
        cout << "\nEnter Elements:\n";
        for (i = 1; i <= n; i++) {
            cin >> data[i];
            son[i] = data[i];
        }
    }

    void search_lini(int item) {
        s = 0;
        for (i = 1; i <= n; i++) {
            if (data[i] == item) {
                s = 1;
                break;
            }
        }
        if (s == 1)
            cout << "\nAttended training program.";
        else
            cout << "\nDidn't attended training program.";
    }

    void search_senti(int a) {
        int i = 0;
        while (data[i] != a && i < n) { i++; }
        if (i < n)
            cout << "\n" << a << " attended training program.";
        else
            cout << "\n" << a << " didn't attend training program.";
    }

    void search_bin(int x) {
        int y = 0;
        int left, right, mid;
        left = 0;
        right = n - 1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (data[mid] == x) {
                y = 1;
                break;
            } else if (data[mid] > x)
                right = mid - 1;
            else if (data[mid] < x)
                left = mid + 1;
        }
        if (y == 1) { cout << "\n" << x << " attended training program."; }
        else { cout << "\n" << x << " didn't attend training program."; }
    }

    int fibsearch(int x) {
        int inf = 0, pos, k;
        static int kk = -1, nn = -1;
        static int fib[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 98,
                            1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811,
                            514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817,
                            39088169, 63245986, 102334155, 165580141};
        if (nn != n) {
            k = 0;
            while (fib[k] < n)
                k++;
            kk = k;
            nn = n;
        } else
            k = kk;
        while (k > 0) {
            pos = inf + fib[--k];
            if ((pos >= n) || (x < data[pos]));

            else if (x > data[pos]) {
                inf = pos + 1;
                k--;
            } else
                return pos;
        }
        return -1;
    }

    void sort() {
        int p, j, temp;
        for (p = 1; p <= n - 1; p++) {
            for (j = 1; j <= n - 1; j++) {
                if (data[j] > data[j + 1]) {
                    temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }
};

int main() {
    int s, r, pos;
    char y = 'y';
    search t;
    t.intake();
    t.sort();
    while (y == 'y') {
        cout << "\n==============================Searching Techniques==============================";
        cout << "\n1. Linear search.\n2. Sentinel search.\n3. Binary search.\n4. Fibonacci search";
        cin >> s;
        cout << "\nEnter roll no. to search:";
        cin >> r;
        switch (s) {
            case 1:
                cout << "\nUsing linear search:\n";
                t.search_lini(r);
                break;
            case 3:
                cout << "\nUsing binary search:\n";
                t.search_bin(r);
                break;
            case 2:
                cout << "\nUsing sentinel search:\n";
                t.search_senti(r);
                break;
            case 4:
                cout << "\nUsing fibonacci search:\n";
                pos = t.fibsearch(r);
                if (pos >= 0)
                    cout << "\nAttended the training program." << endl;
                else
                    cout << "\nDidn't attended training program." << endl;
                break;
        }
        cout << "\nDo you want to continue? (y/n): ";
        cin >> y;
    }
    return 0;
}

