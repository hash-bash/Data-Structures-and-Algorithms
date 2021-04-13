#include <iostream>

using namespace std;

class Test {
    int dsa[30], i, j, n, sum, cnt[50], k, rn[30];
    float av;
public:
    Test() {
        i = j = n = 0;
        av = sum = k = 0;
    }

    void getdata();

    void show();

    void avg();

    void Ab_stud();

    void HS_LS();

    void MS_score();
};


void Test::getdata() {
    cout << "\nHow many student are in SE A? : ";
    cin >> n;
    cout << "\nEnter the marks scored for first test of subject DSA: ";
    cout << "\n[Student who remains absent for the test please enter -1 for them]";
    for (i = 0; i < n; i++) {
        cout << "\nEnter the marks of roll no: " << i + 1 << " : ";
        cin >> dsa[i];
    }
}

void Test::MS_score() {
    for (i = 0; i < 50; i++) {
        cnt[i] = 0;
    }
    for (i = 0; i < 50; i++) {
        for (j = 0; j < n; j++) {
            if (dsa[j] == i) {
                cnt[i] = cnt[i] + 1;
            }
        }
    }
    cout << "\nMarks scored by most of the student in test are:\n";
    k = 0;
    j = 0;
    int max = cnt[j];
    for (i = 0; i < 50; i++) {
        if (cnt[i] >= max) {
            max = cnt[i];
            k = i;
        }
    }
    cout << "\nMaximum marks " << k << " scored by " << max << " students are:\n";
    for (i = 0; i < n; i++) {
        if (dsa[i] == k) {
            rn[j] = i;
            j++;
        }
    }
    cout << "\nStudents roll number are as follows:\n";
    for (i = 0; i < j; i++) {
        cout << "\t" << rn[i] + 1;
    }
}

void Test::show() {
    cout << "\nFirst test marks of subject DSA are as follows:\n";
    cout << "Roll No\t" << "" << " DSA Marks";

    for (i = 0; i < n; i++) {
        cout << i + 1 << "\t" << dsa[i] << "\t\n";
    }
}

void Test::avg() {
    int p = 0;
    cout << "\nAverage score of the class: ";
    for (i = 0; i < n; i++) {
        if (dsa[i] != -1) {
            sum = sum + dsa[i];
            p++;
        }
    }
    av = sum / p;
    cout << av;
}

void Test::Ab_stud() {
    int cnt = 0;
    cout << "\nTotal number of student absent for DSA Test:";
    cout << "\nRoll No\t Marks\n";
    for (i = 0; i < n; i++) {
        if (dsa[i] == -1) {
            cout << i + 1 << "\tAbsent\n";
            cnt++;
        }
    }
    cout << "\nTotal: " << cnt;
}

void Test::HS_LS() {
    int min = 0;
    int max = 0, rno = 0, i = 0;
    cout << "\nHighest score of the class for DSA subject are as follows:";
    max = dsa[i];
    for (i = 0; i < n; i++) {
        if (dsa[i] == -1) {

        } else if (dsa[i] >= max) {
            max = dsa[i];
            rno = i;
        }
    }
    cout << "\nRoll No: " << rno + 1 << " Marks: " << max;
    cout << "\nLowest Score of the Class for DSA Subject are as follows:";
    rno = 0;
    min = dsa[j];
    for (j = 0; j < n; j++) {
        if (dsa[j] == -1) {

        } else if (dsa[j] <= min) {
            min = dsa[j];
            rno = j;
        }
    }
    cout << "\nRoll No: " << rno + 1 << " Marks: " << min;
}

int main() {
    Test T;
    T.getdata();
    T.show();
    T.avg();
    T.Ab_stud();
    T.HS_LS();
    T.MS_score();

    return 0;
}
