#include<iostream>

using namespace std;

class matrix {
    int x[10][10], y[10][10], s[10][10], i, j, n, sum, r1, c1, r2, c2, d, l;
public:
    void entermatrix();

    void showmat();

    void output1();

    void output2();

    void output3();

    void output4();

    void output5();

    void output6();
};

void matrix::entermatrix() {
    repeat:
    cout << "\nEnter the no of rows in the matrix: ";
    cin >> r1;
    cout << "\nEnter the no of columns in the matrix: ";
    cin >> c1;

    if (r1 > 0 && c1 > 0) {
        cout << "\nEnter the matrix [X] elements:\n";
        for (i = 0; i < r1; i++) {
            for (j = 0; j < c1; j++)
                cin >> x[i][j];
        }
    } else {
        cout << "Wrong input." << endl;
        goto repeat;
    }
}

void matrix::showmat() {
    cout << "\nMatrix [X]:\n";
    for (i = 0; i < r1; i++) {
        cout << "\n\n";
        for (j = 0; j < c1; j++)
            cout << x[i][j] << "  ";
    }
}

void matrix::output1() {
    int c;
    c = 0;
    if (r1 == c1) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (i >> j && x[i][j] == 0) {
                    c++;
                }
            }
        }
        d = ((n * (n - 1)) / 2);
        if (c == d)
            cout << "\nYes, the matrix is diagonal upper.";
        else
            cout << "\nNo, the matrix is not a upper triangular matrix.";
    } else
        cout << "\nWrong input.";

}

void matrix::output2() {
    sum = 0;
    if (r1 == c1) {
        for (i = 0; i < r1; i++) {
            for (j = 0; j < c1; j++) {
                if (i == j)
                    sum = sum + x[i][j];
            }
        }
        cout << "\nSum of diagonal matrix is: " << sum;
    } else
        cout << "\nWrong input.";
}

void matrix::output3() {
    int z[10][10];
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            z[j][i] = x[i][j];
        }
    }
    cout << "\nMatrix [Z]:\n";
    for (i = 0; i < c1; i++) {
        cout << "\n\n";
        for (j = 0; j < r1; j++)
            cout << z[i][j] << "  ";
    }
}

void matrix::output4() {
    repeat:
    cout << "\nEnter the no. of rows for the second matrix: ";
    cin >> r2;
    cout << "\nEnter the no. of columns for the second matrix: ";
    cin >> c2;

    cout << "\nEnter the elements for matrix [Y]:\n";
    if (r2 > 0 && c2 > 0) {
        for (i = 0; i < r2; i++) {
            for (j = 0; j < c2; j++)
                cin >> y[i][j];
        }
        cout << "\nMatrix [Y]:\n";
        for (i = 0; i < r2; i++) {
            cout << "\n\n";
            for (j = 0; j < c2; j++)
                cout << y[i][j] << "  ";
        }
    } else {
        cout << "Wrong input.";
        goto repeat;
    }

    if (r1 == r2 && c1 == c2) {
        cout << "\nSum that is, matrix [Z] is:\n";
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                s[i][j] = x[i][j] + y[i][j];
            }
        }
        for (i = 0; i < 3; i++) {
            cout << "\n\n";
            for (j = 0; j < 3; j++)
                cout << s[i][j] << "  ";
        }
    } else
        cout << "\nWrong input.";
}

void matrix::output5() {
    repeat:
    cout << "\nEnter the no. of rows for the second matrix: ";
    cin >> r2;
    cout << "\nEnter the no. of columns for the second matrix: ";
    cin >> c2;

    if (r2 > 0 && c2 > 0) {
        cout << "\nEnter the elements for matrix [Y]:\n";
        for (i = 0; i < r2; i++) {
            for (j = 0; j < c2; j++)
                cin >> y[i][j];
        }
        cout << "\nMatrix [Y]:\n";
        for (i = 0; i < r2; j++) {
            cout << "\n\n";
            for (j = 0; j < c2; j++)
                cout << y[i][j] << "  ";
        }
    } else {
        cout << "\nWrong input.";
        goto repeat;
    }

    if (r1 == r2 && c1 == c2) {
        cout << "\nDifference is, that is matrix [Z] is:\n";
        for (i = 0; i < r1; i++) {
            for (j = 0; j < c1; j++) {
                s[i][j] = x[i][j] - y[i][j];
            }
        }

        for (i = 0; i < r1; i++) {
            cout << "\n\n";
            for (j = 0; j < c1; j++)
                cout << s[i][j] << "  ";
        }
    }
}

void matrix::output6() {
    int p[10][10], summ, multi, w;
    repeat:
    cout << "\nEnter the no. of rows for the second matrix: ";
    cin >> r2;
    cout << "\nEnter the no. of columns for the second matrix: ";
    cin >> c2;

    cout << "\nEnter the elements for matrix [Y]:\n";
    if (r1 > 0 && c1 > 0) {
        for (i = 0; i < r2; i++) {
            for (j = 0; j < c2; j++)
                cin >> y[i][j];
        }
        cout << "\nMatrix [Y]:\n";
        for (i = 0; i < r2; i++) {
            cout << "\n\n";
            for (j = 0; j < c2; j++)
                cout << y[i][j] << "  ";
        }
    } else {
        cout << "\nWrong input.";
        goto repeat;
    }

    if (c1 != r2 && c2 != r1) {
        cout << "\nCannot perform the multiplication.";
        goto repeat;
    } else if (c1 == r2) {
        for (i = 0; i < r1; i++) {
            summ = 0;
            for (w = 0; w < c2; w++) {
                for (j = 0; j < r2; j++) {
                    multi = x[i][j] * y[j][w];
                    summ += multi;
                }
                p[i][w] = summ;
                summ = 0;
            }
        }
        cout << "\nMultiplication is, that is matrix [Z]:\n";
        for (i = 0; i < r1; i++) {
            cout << "\n\n";
            for (j = 0; j < c2; j++)
                cout << p[i][j] << "  ";
        }
    } else if (c2 == r1) {
        for (i = 0; i < r2; i++) {
            summ = 0;
            for (w = 0; w < c1; w++) {
                for (j = 0; j < r1; j++) {
                    multi = x[i][j] * y[j][w];
                    summ += multi;
                }
                p[i][w] = summ;
                summ = 0;
            }
        }
        cout << "\nMultiplication is, that is matrix [Z]:\n";
        for (i = 0; i < r2; i++) {
            cout << "\n\n";
            for (j = 0; j < c1; j++)
                cout << p[i][j] << "  ";
        }
    }
}

int main() {
    matrix m;
    m.entermatrix();
    cout << "\n";
    m.showmat();
    cout << "\n";

    for (;;) {
        int chch;
        cout << "\n========================Matrix Operation========================";
        cout << "\n1. To find whether the matrix is upper triangular in nature";
        cout << "\n2. To find the sum of diagonal elements";
        cout << "\n3. To find transpose";
        cout << "\n4. To find sum of two matrices";
        cout << "\n5. To find difference of two matrices";
        cout << "\n6. To find product of two matrices ";
        cout << "\n7. Exit";
        cin >> chch;
        switch (chch) {
            case 1:
                m.output1();
                break;

            case 2:
                m.output2();
                break;

            case 3:
                m.output3();
                break;

            case 4:
                m.output4();
                break;

            case 5:
                m.output5();
                break;

            case 6:
                m.output6();
                break;

            case 7:
                cout << exit(0);
                break;
        }
    }
}
