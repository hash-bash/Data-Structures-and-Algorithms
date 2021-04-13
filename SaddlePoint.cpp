#include<iostream>

using namespace std;

class smat {
    int mat[10][10], i, j, row, col, min, max;

public:
    smat() {
        i = j = row = col = 0;
        min = max = 0;
    }

    void getdata();

    void showmat();

    void saddlepoint();
};

void smat::getdata() {
    cout << "\nEnter how many rows in matrix: ";
    cin >> row;
    cout << "\nEnter how many columns in matrix: ";
    cin >> col;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            cout << "\nEnter matrix mat[" << i << "][" << j << "] element: ";
            cin >> mat[i][j];
        }
    }
}

void smat::showmat() {
    cout << "\nThe elements inside the matrix are as follows:\n";
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            cout << "\t" << mat[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

void smat::saddlepoint() {
    int big[5], small[5];
    for (i = 0; i < 5; i++) {
        big[i] = small[i] = 0;
    }

    for (i = 0; i < row; i++) {
        small[i] = mat[i][0];
        for (j = 0; j < col; j++) {
            if (mat[i][j] <= small[i]) {
                small[i] = mat[i][j];
            }
        }
    }

    for (j = 0; j < col; j++) {
        big[j] = mat[0][j];
        for (i = 0; i < row; i++) {
            if (mat[i][j] >= big[j]) {
                big[j] = mat[i][j];
            }
        }
    }

    max = small[0];
    for (i = 0; i < row; i++) {
        if (small[i] >= max) {
            max = small[i];
        }
    }

    min = big[0];
    for (j = 0; j < col; j++) {
        if (big[j] <= min) {
            min = big[j];
        }
    }

    if (min == max) {
        cout << "\nSaddle point " << min << " is present in the matrix.";
    } else {
        cout << "\nSaddle point is not present in given matrix.";
    }
}

int main() {
    smat s1;
    s1.getdata();
    s1.showmat();
    s1.saddlepoint();
    return 0;
}
