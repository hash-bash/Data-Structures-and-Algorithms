#include <iostream>

using namespace std;

int partition(float x[100], int lb, int ub) {
    float a, temp;
    int down, up;
    a = x[lb];
    down = lb;
    up = ub;
    while (down < up) {
        while (x[down] <= a && down < up)
            down++;
        while (x[up] > a)
            up--;

        if (down < up) {
            temp = x[down];
            x[down] = x[up];
            x[up] = temp;
        }
    }
    x[lb] = x[up];
    x[up] = a;
    return up;
}

void quicksort(float x[100], int lb, int ub) {
    int j;
    if (lb < ub) {
        j = partition(x, lb, ub);
        quicksort(x, lb, j - 1);
        quicksort(x, j + 1, ub);
    }
}

int main() {
    float arr[100];
    int i, n;
    cout << "\nEnter number of students: ";
    cin >> n;
    cout << "\nEnter " << n << " student:\n";
    for (i = 0; i < n; i++)
        cin >> arr[i];
    quicksort(arr, 0, n - 1);
    cout << "\nAfter sort, students are: ";
    for (i = 0; i < n; i++)
        cout << arr[i] << "\t";
    return 0;
}
