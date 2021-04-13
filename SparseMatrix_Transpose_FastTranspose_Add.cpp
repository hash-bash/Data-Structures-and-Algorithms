#include<iostream>
#include<string.h>

using namespace std;

typedef struct spm {
    int row, col;
    int nval;
};

class sparse {
    spm sp1[10], sp2[10], sp3[20], spltr[10], fstr[10];
    int mat1[10][10], mat2[10][10];
    int r1, r2, c1, c2, i, j, k;
public:
    sparse() {
        r1 = r2 = i = 0;
        j = k = 0;
        c1 = c2 = 0;
    }

    void getmat();

    void showmat();

    void addspm();

    void simpl_trnspose();

    void fast_trnspose();
};

void sparse::getmat() {
    cout << "\nHow many rows in matrix 1: ";
    cin >> r1;
    cout << "\nHow many columns in matrix 1: ";
    cin >> c1;
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            cout << "\nEnter [" << i << "][" << j << "] value of matrix 1: ";
            cin >> mat1[i][j];
        }
    }
    cout << "\nHow many rows in matrix 2: ";
    cin >> r2;
    cout << "\nHow many columns in matrix 2: ";
    cin >> c2;
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            cout << "\nEnter [" << i << "][" << j << "] value of matrix 2: ";
            cin >> mat2[i][j];
        }
    }
}

void sparse::showmat() {
    cout << "\nMatrix 1 values are as follows:\n";
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            cout << "\t" << mat1[i][j];
        }
        cout << "\n";
    }
    cout << "\nMatrix 2 values are as follows:\n";
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            cout << "\t" << mat2[i][j];
        }
        cout << "\n";
    }
}

void sparse::addspm() {
    int n1, n2;
    n1 = n2 = 0;
    sp1[0].row = r1;
    sp1[0].col = c1;
    k = 1;
    cout << "\nSparse matrix 1 non zero value are as follows:\n";
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            if (mat1[i][j] != 0) {
                sp1[k].row = i;
                sp1[k].col = j;
                sp1[k].nval = mat1[i][j];
                k = k + 1;
            }
        }
    }
    sp1[0].nval = k - 1;
    cout << "\nRow\tCol\tValue";
    for (i = 0; i < k; i++) {
        cout << "\n" << sp1[i].row << "\t" << sp1[i].col << "\t" << sp1[i].nval;
    }
    cout << "\nSparse matrix 2 non zero value are as follows:\n";
    sp2[0].row = r2;
    sp2[0].col = c2;
    k = 1;
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            if (mat2[i][j] != 0) {
                sp2[k].row = i;
                sp2[k].col = j;
                sp2[k].nval = mat2[i][j];
                k = k + 1;
            }
        }
    }
    sp2[0].nval = k - 1;
    cout << "\nRow\tCol\tValue";
    for (i = 0; i < k; i++) {
        cout << "\n" << sp2[i].row << "\t" << sp2[i].col << "\t" << sp2[i].nval;
    }
    n1 = sp1[0].nval;
    n2 = sp2[0].nval;
    i = j = k = 1;
    cout << "\nNumber of term in sparse matrix 1: " << n1 << "\nNumber of term in sparse matrix 2: " << n2;
    if (sp1[0].row > sp2[0].row) {
        sp3[0].row = sp1[0].row;
    } else {
        sp3[0].row = sp2[0].row;
    }
    if (sp1[0].col > sp2[0].col) {
        sp3[0].col = sp1[0].col;
    } else {
        sp3[0].col = sp2[0].col;
    }
    while ((i <= n1) && (j <= n2)) {
        if (sp1[i].row == sp2[j].row) {
            if (sp1[i].col == sp2[j].col) {
                sp3[k].row = sp1[i].row;
                sp3[k].col = sp1[i].col;
                sp3[k].nval = sp1[i].nval + sp2[j].nval;
                cout << "\nValue of addition: " << sp3[k].nval;
                i++;
                j++;
                k++;
                cout << "\nValue of i: " << i << "\nValue of j: " << j << "\nValue of k: " << k;

            } else if (sp1[i].col < sp2[j].col) {
                sp3[k].row = sp1[i].row;
                sp3[k].col = sp1[i].col;
                sp3[k].nval = sp1[i].nval;
                i++;
                k++;
                cout << "\nValue of i: " << i << "\nValue of k: " << k;
            } else {
                sp3[k].row = sp2[j].row;
                sp3[k].col = sp2[j].col;
                sp3[k].nval = sp2[j].nval;
                j++;
                k++;
                cout << "\nValue of j: " << j << "\nValue of k: " << k;
            }
        } else if (sp1[i].row < sp2[j].row) {
            sp3[k].row = sp1[i].row;
            sp3[k].col = sp1[i].col;
            sp3[k].nval = sp1[i].nval;
            i++;
            k++;
            cout << "\nValue of i: " << i << "\nValue of k: " << k;
        } else {
            sp3[k].row = sp2[j].row;
            sp3[k].col = sp2[j].col;
            sp3[k].nval = sp2[j].nval;
            j++;
            k++;
            cout << "\nValue of j: " << j << "\nValue of k: " << k;
        }
    }
    while (i <= n1) {
        sp3[k].row = sp1[i].row;
        sp3[k].col = sp1[i].col;
        sp3[k].nval = sp1[i].nval;
        i++;
        k++;
        cout << "\nValue of outer while, i: " << i << "\nValue of k: " << k;
    }
    while (j <= n2) {
        sp3[k].row = sp2[j].row;
        sp3[k].col = sp2[j].col;
        sp3[k].nval = sp2[j].nval;
        j++;
        k++;
        cout << "\nValue of outer while, j: " << j << "\nValue of k: " << k;
    }
    sp3[0].nval = k - 1;
    cout << "\nRow\tCol\tValue";
    for (i = 0; i < k; i++) {
        cout << "\n" << sp3[i].row << "\t" << sp3[i].col << "\t" << sp3[i].nval;
    }
}

void sparse::simpl_trnspose() {
    spltr[0].row = sp3[0].col;
    spltr[0].col = sp3[0].row;
    spltr[0].nval = sp3[0].nval;
    k = 1;
    for (i = 0; i <= spltr[0].row; i++) {
        for (j = 0; j <= spltr[0].nval; j++) {
            if (sp3[j].col == i) {
                spltr[k].row = sp3[j].col;
                spltr[k].col = sp3[j].row;
                spltr[k].nval = sp3[j].nval;
                k++;
            }
        }
    }
    cout << "\nSimple transpose of addition matrix are as follows:";
    cout << "\nRow\tCol\tValue";
    for (i = 0; i < k - 1; i++) {
        cout << "\n" << spltr[i].row << "\t" << spltr[i].col << "\t" << spltr[i].nval;
    }
}

void sparse::fast_trnspose() {
    int term[5], pos[5];
    fstr[0].row = sp3[0].col;
    fstr[0].col = sp3[0].row;
    fstr[0].nval = sp3[0].nval;

    for (i = 0; i <= sp3[0].col; i++) {
        term[i] = 0;
    }

    for (i = 1; i <= sp3[0].nval; i++) {
        term[sp3[i].col]++;
    }

    pos[0] = 1;
    for (i = 1; i <= sp3[0].col; i++) {
        pos[i] = pos[(i - 1)] + term[(i - 1)];
    }

    for (i = 1; i <= sp3[0].nval; i++) {
        j = pos[sp3[i].col];
        fstr[j].row = sp3[i].col;
        fstr[j].col = sp3[i].row;
        fstr[j].nval = sp3[i].nval;
        pos[sp3[i].col] = j + 1;

        cout << "\nFast transpose of addition matrix are as follows:";
        cout << "\nRow\tCol\tValue";
        for (i = 0; i <= fstr[0].nval; i++) {
            cout << "\n" << fstr[i].row << "\t" << fstr[i].col << "\t" << fstr[i].nval;
        }
    }
}

int main() {
    int n;
    sparse s1;
    s1.getmat();
    s1.showmat();
    s1.addspm();
    s1.simpl_trnspose();
    s1.fast_trnspose();

    return 0;
}
