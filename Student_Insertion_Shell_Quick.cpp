#include<iostream>

using namespace std;

const int MAX = 20;

class Student {
    float perc[MAX];
    int n;
public:
    void accept();

    void display();

    void insertionSort();

    void shellSort();

    void displayTop5();

    void quickSort(int start, int end);

    int getn() {
        return n;
    }
};

void Student::accept() {
    cout << "\nEnter number of students: ";
    cin >> n;
    cout << "\nEnter percentages of " << n << " students: ";
    for (int i = 0; i < n; i++) {
        cin >> perc[i];
    }
}

void Student::display() {
    cout << "\nStudent list: ";
    for (int i = 0; i < n; i++) {
        cout << perc[i] << " ";
    }
}

void Student::displayTop5() {
    int c;
    for (int i = n - 1, c = 0; i >= 0 && c < 5; i--, c++) {
        cout << c + 1 << " )" << perc[i] << "\n";
    }
}

void Student::insertionSort() {
    int i, j;
    for (int i = 1; i < n; i++) {
        float temp = perc[i];
        for (j = i - 1; j >= 0 && perc[j] > temp; j--) {
            perc[j + 1] = perc[j];
        }
        perc[j + 1] = temp;
    }
    cout << "\nSorted list is: ";
    display();
}

void Student::shellSort() {
    int i, j, k;
    float temp;
    for (int i = n / 2; i > 0; i = i / 2) {
        for (j = i; j < n; j++) {
            temp = perc[j];
            for (k = j - 1; k >= 0 && perc[k] > temp; k--) {
                perc[k + 1] = perc[k];
            }
            perc[k + 1] = temp;
        }
    }
    cout << "\nSorted list is: ";
    display();
}

void Student::quickSort(int start, int end) {
    int pivot, i, j;
    float temp;
    if (start < end) {
        pivot = start;
        i = start + 1;
        j = end;

        while (i < j) {

            while (perc[i] <= perc[pivot] && i < j)
                i++;
            while (perc[j] >= perc[pivot] && i <= j)
                j--;
            if (i <= j) {
                temp = perc[i];
                perc[i] = perc[j];
                perc[j] = temp;
            }
        }
        temp = perc[pivot];
        perc[pivot] = perc[j];
        perc[j] = temp;

        quickSort(start, j - 1);
        quickSort(j + 1, end);
    }
}

int main() {
    Student s;
    int choice, num;
    do {
        cout << "\n==========================MENU==========================";
        cout << "\n1.Insertion sort";
        cout << "\n2.Shell sort";
        cout << "\n3.Display top 5";
        cout << "\n4.Quick sort";
        cout << "\n0.Exit";
        cout << "\nEnter the choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                s.accept();
                cout << "\nBefore sorting: ";
                s.display();
                cout << "\nAfter sorting: ";
                s.insertionSort();
                break;
            case 2:
                s.accept();
                cout << "\nBefore sorting: ";
                s.display();
                cout << "\nAfter sorting: ";
                s.shellSort();
                break;
            case 3:
                cout << "\n5 Toppers are: ";
                s.displayTop5();
                break;
            case 4:
                s.accept();
                cout << "\nBefore sorting: ";
                s.display();
                cout << "\nAfter sorting: ";
                num = s.getn();
                s.quickSort(0, num - 1);
                s.display();
                break;
        }
    } while (choice != 0);

    return 0;
}
