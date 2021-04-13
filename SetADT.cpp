#include <iostream>

using namespace std;

const int MAX = 10;

template<class T>
class Set {
    T data[MAX];
    int n;
public:
    Set() {
        n = -1;
    }

    bool insertItem(T);

    bool removeItem(T);

    bool contains(T);

    int size();

    void print();

    void input(int num);

    Set union1(Set, Set);

    Set intersection1(Set, Set);

    Set difference1(Set, Set);

    bool subSet(Set);
};

template<class T>
bool Set<T>::subSet(Set<T> s2) {
    int count = 0;
    int size = s2.size();
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= s2.n; j++) {
            if (data[i] == s2.data[j]) {
                count++;
                break;
            }
        }
    }
    if (count == size) {
        return true;
    }
    return false;
}

template<class T>
void Set<T>::input(int num) {
    T item;
    for (int i = 0; i < num; i++) {
        if (i == 0) {
            cout << "\nEnter the " << i + 1 << "st item: ";
        } else if (i == 1) {
            cout << "\nEnter the " << i + 1 << "nd item: ";
        } else if (i == 2) {
            cout << "\nEnter the " << i + 1 << "rd item: ";
        } else {
            cout << "\nEnter the " << i + 1 << "th item: ";
        }
        cin >> item;
        insertItem(item);
    }
}

template<class T>
void Set<T>::print() {
    for (int i = 0; i <= n; i++)
        cout << " " << data[i];
}

template<class T>
Set<T> Set<T>::union1(Set<T> s1, Set<T> s2) {
    Set<T> s3;

    int flag = 0;
    int i = 0;
    for (i = 0; i <= s1.n; i++) {
        s3.insertItem(s1.data[i]);
    }
    for (int j = 0; j <= s2.n; j++) {
        flag = 0;
        for (i = 0; i <= s1.n; i++) {
            if (s1.data[i] == s2.data[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            s3.insertItem(s2.data[j]);

        }
    }
    return s3;
}

template<class T>
Set<T> Set<T>::difference1(Set<T> s1, Set<T> s2) {
    Set<T> s3;
    int flag = 1;
    for (int i = 0; i <= s1.n; i++) {
        for (int j = 0; j <= s2.n; j++) {
            if (s1.data[i] == s2.data[j]) {
                flag = 0;
                break;
            } else
                flag = 1;
        }
        if (flag == 1) {
            s3.insertItem(s1.data[i]);
        }
    }
    return s3;
}

template<class T>
Set<T> Set<T>::intersection1(Set<T> s1, Set<T> s2) {
    Set<T> s3;
    for (int i = 0; i <= s1.n; i++) {
        for (int j = 0; j <= s2.n; j++) {
            if (s1.data[i] == s2.data[j]) {
                s3.insertItem(s1.data[i]);
                break;
            }
        }
    }
    return s3;
}

template<class T>
bool Set<T>::insertItem(T item) {
    if (n >= MAX - 1) {
        cout << "\nOverflow, set is full.";
        return false;
    }
    data[++n] = item;
    return true;
}

template<class T>
bool Set<T>::removeItem(T item) {
    if (n == -1) {
        cout << "\nUnderflow, cannot perform delete operation on empty set.";
        return false;
    }
    for (int i = 0; i <= n; i++) {
        if (data[i] == item) {
            for (int j = i; j < n; j++) {
                data[j] = data[j + 1];
            }
            return true;
        }
    }
    return false;
}

template<class T>
bool Set<T>::contains(T item) {
    for (int i = 0; i <= n; i++) {
        if (data[i] == item)
            return true;
    }
    return false;
}

template<class T>
int Set<T>::size() {
    return n + 1;
}

int main() {

    Set<int> s1, s2, s3;
    int choice;
    int size1, size2, item;
    cout << "\nEnter number of items in the first set: ";
    cin >> size1;
    s1.input(size1);
    cout << "\nEnter number of items in the second set: ";
    cin >> size2;
    s2.input(size2);
    do {
        cout << "\n====================SET OPERATIONS===================="
             << "\n1.Insert" << "\n2.Remove" << "\n3.Contains" << "\n4.Size of the set" << "\n5.Intersection"
             << "\n6.Union" << "\n7.Difference" << "\n8.Check if subset" << "\n9.Display" << "\n0. Exit"
             << "\nPlease enter the choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "\nPlease enter the item: ";
                cin >> item;
                if (s1.insertItem(item)) {
                    cout << "\n" << item << " inserted.";
                } else {
                    cout << "\n" << "Insertion can not be done.";
                }
                break;

            case 2:
                cout << "\nPlease enter the item: ";
                cin >> item;
                if (s1.removeItem(item)) {
                    cout << "\n" << item << " deleted.";
                } else {
                    cout << "\n" << "Deletion can not be done.";
                }
                break;

            case 3:
                cout << "\nEnter item: ";
                cin >> item;
                if (s1.contains(item)) {
                    cout << "\n" << item << " is present.";
                } else {
                    cout << "\n" << item << "is not present.";
                }
                break;

            case 4:
                cout << "\nSize of set is: " << s1.size();
                break;

            case 5:
                s3 = s1.intersection1(s1, s2);
                cout << "\nFirst set's items are: ";
                s1.print();
                cout << "\nSecond set's items are: ";
                s2.print();
                cout << "\nIntersection: ";
                s3.print();
                break;

            case 6:
                s3 = s1.union1(s1, s2);
                cout << "\nFirst set's items are: ";
                s1.print();
                cout << "\nSecond set's items are: ";
                s2.print();
                cout << "\nUnion: ";
                s3.print();
                break;

            case 7:
                s3 = s1.difference1(s1, s2);
                cout << "\nFirst set's items are: ";
                s1.print();
                cout << "\nSecond set's items are: ";
                s2.print();
                cout << "\nDifference: ";
                s3.print();
                break;

            case 8:
                if (s1.subSet(s2)) {
                    cout << "\nSecond set is subset of first set.";
                } else {
                    cout << "\nSecond set is not a subset of first set.";
                }
                break;

            case 9:
                cout << "\nFirst set's items are: ";
                s1.print();
                cout << "\nSecond set's items are: ";
                s2.print();
                break;
        }
    } while (choice != 0);
    return 0;
}
