#include<iostream>

using namespace std;

class sort {
    float m[30];
    int i, j, n;
public:
    void insert() {
        cout << "\nEnter the number of students: ";
        cin >> n;
        cout << "\nEnter marks: ";
        for (i = 0; i < n; i++) {
            cout << "\n" << m[i];
        }
    }

    void display() {
        cout << "\nMarks entered are: ";
        for (i = 0; i < n; i++)
            cout << "\n" << m[i];
    }

    void bubble() {
        float temp;
        for (i = 0; i < n - 1; i++) {
            for (j = 0; j < (n - 1) - i; j++) {
                if (m[j] > m[j + 1]) {
                    temp = m[j];
                    m[j] = m[j + 1];
                    m[j + 1] = temp;
                }
            }
        }
        cout << "\nTop five students are: ";
        for (i = n - 1; i >= (n - 5); i--) {
            cout << "\n" << m[i];
        }
    }

    void selection() {
        int min;
        float temp;
        for (i = 0; i < (n - 1); i++) {
            min = i;
            for (j = i + 1; j < n; j++) {
                if (m[j] < m[min]) {
                    min = j;
                }
            }
            temp = m[i];
            m[i] = m[min];
            m[min] = temp;

        }
        cout << "\nTop five students are: ";
        for (i = n - 1; i >= (n - 5); i--) {
            cout << "\n" << m[i];
        }
    }
};

int main() {
    sort s;
    int ch, x;
    cout << "\n==============================MERIT LIST (Top 5)==============================";
    do {
        cout
                << "\n1.Create \n2.Display \n3.Top five using bubble sort\n4.Top five using insertion sort\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                s.insert();
                break;
            case 2:
                s.display();
                break;
            case 3:
                s.bubble();
                break;
            case 4:
                s.selection();
                break;
            default:
                cout << "\nWrong choice.";
        }
        cout << "\nDo you want ot continue? 1.Yes 2.No : ";
        cin >> x;
    } while (x == 1);
    return 0;
}
