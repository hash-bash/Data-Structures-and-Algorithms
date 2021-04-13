#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

class tel {

public:
    int rollNum;
    char name[10];
    char div;
    char address[20];

    void accept() {
        cout << "\nEnter the roll number: ";
        cin >> rollNum;
        cout << "\nEnter the name: ";
        cin >> name;
        cout << "\nEnter the division: ";
        cin >> div;
        cout << "\nEnter the address: ";
        cin >> address;
    }

    void accept2() {
        cout << "\n\tEnter the roll no. to modify: ";
        cin >> rollNum;
    }

    void accept3() {
        cout << "\n\tEnter the name to modify: ";
        cin >> name;
    }

    int getrollNum() {
        return rollNum;
    }

    void show() {

        cout << "\n\t" << rollNum << "\t\t" << name << "\t\t" << div << "\t\t" << address;
    }
};

int main() {
    int i, n, ch, ch1, rec, start, count, add, n1, add2, start2, n2, y, a, b, on, oname, add3, start3, n3, y1, add4, start4, n4;
    char name[20], name2[20];
    tel t1;
    count = 0;
    fstream g, f;
    do {
        cout << "\n====================================MENU====================================";
        cout
                << "\n1.Insert the data\n2.Display the data\n3.Search and modify number\n4.Search and modify name\n5.Search and modify only number\n6.Search and modify only name\n7.Delete a Student Record\n8.Exit\n\tEnter the Choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                f.open("Records.txt", ios::out);
            x:
                t1.accept();
                f.write((char *) &t1, (sizeof(t1)));
                cout << "\nDo you want to enter more records?\n1.Yes\n2.No";
                cin >> ch1;
                if (ch1 == 1)
                    goto x;
                else {
                    f.close();
                    break;
                }

            case 2:
                f.open("Records.txt", ios::in);
                f.read((char *) &t1, (sizeof(t1)));
                cout << "\n\tRoll No.\t\tName \t\t Division \t\t Address";
                while (f) {
                    t1.show();
                    f.read((char *) &t1, (sizeof(t1)));
                }
                f.close();
                break;
            case 3:
                cout << "\nEnter the roll number of the student: ";
                cin >> rec;
                f.open("Records.txt", ios::in | ios::out);
                f.read((char *) &t1, (sizeof(t1)));
                while (f) {
                    if (rec == t1.rollNum) {
                        cout << "\nRecord found.";
                        add = f.tellg();
                        f.seekg(0, ios::beg);
                        start = f.tellg();
                        n1 = (add - start) / (sizeof(t1));
                        f.seekp((n1 - 1) * sizeof(t1), ios::beg);
                        t1.accept();
                        f.write((char *) &t1, (sizeof(t1)));
                        f.close();
                        count++;
                        break;
                    }
                    f.read((char *) &t1, (sizeof(t1)));
                }
                if (count == 0)
                    cout << "\nRecord not found.";
                f.close();
                break;

            case 4:
                cout << "\nEnter the name of the student: ";
                cin >> name;
                f.open("Records.txt", ios::in | ios::out);
                f.read((char *) &t1, (sizeof(t1)));
                while (f) {
                    y = (strcmp(name, t1.name));
                    if (y == 0) {
                        cout << "\nName found.";
                        add2 = f.tellg();
                        f.seekg(0, ios::beg);
                        start2 = f.tellg();
                        n2 = (add2 - start2) / (sizeof(t1));
                        f.seekp((n2 - 1) * sizeof(t1), ios::beg);
                        t1.accept();
                        f.write((char *) &t1, (sizeof(t1)));
                        f.close();
                        break;
                    }
                    f.read((char *) &t1, (sizeof(t1)));
                }
                break;
            case 5:
                cout << "\nEnter the roll number of the student: ";
                cin >> on;
                f.open("Records.txt", ios::in | ios::out);
                f.read((char *) &t1, (sizeof(t1)));
                while (f) {
                    if (on == t1.rollNum) {
                        cout << "\nNumber found.";
                        add3 = f.tellg();
                        f.seekg(0, ios::beg);
                        start3 = f.tellg();
                        n3 = (add3 - start3) / (sizeof(t1));
                        f.seekp((n3 - 1) * (sizeof(t1)), ios::beg);
                        t1.accept2();
                        f.write((char *) &t1, (sizeof(t1)));
                        f.close();
                        break;
                    }
                    f.read((char *) &t1, (sizeof(t1)));
                }
                break;
            case 6:
                cout << "\nEnter the name of the student: ";
                cin >> name2;
                f.open("Records.txt", ios::in | ios::out);
                f.read((char *) &t1, (sizeof(t1)));
                while (f) {
                    y1 = (strcmp(name2, t1.name));
                    if (y1 == 0) {
                        cout << "\nName found.";
                        add4 = f.tellg();
                        f.seekg(0, ios::beg);
                        start4 = f.tellg();
                        n4 = (add4 - start4) / (sizeof(t1));
                        f.seekp((n4 - 1) * sizeof(t1), ios::beg);
                        t1.accept3();
                        f.write((char *) &t1, (sizeof(t1)));
                        f.close();
                        break;
                    }
                    f.read((char *) &t1, (sizeof(t1)));
                }
                break;
            case 7:
                int roll;
                cout << "Please enter the roll number of student to delete: ";
                cin >> roll;
                f.open("Records.txt", ios::in);
                g.open("Temp.txt", ios::out);
                f.read((char *) &t1, sizeof(t1));
                while (!f.eof()) {
                    if (t1.getrollNum() != roll)
                        g.write((char *) &t1, sizeof(t1));
                    f.read((char *) &t1, sizeof(t1));
                }
                cout << "Record deleted." << endl;
                f.close();
                g.close();
                remove("Records.txt");
                rename("Temp.txt", "Records.txt");
                break;
            case 8:
                break;
        }
    } while (ch != 8);
}
