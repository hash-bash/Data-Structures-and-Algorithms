#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

class Emp1 {

public:
    int empID;
    char name[10];
    double sal;
    char dest[20];

    void accept() {
        cout << "\nEnter the employee ID: ";
        cin >> empID;
        cout << "\nEnter the name: ";
        cin >> name;
        cout << "\nEnter the salary: ";
        cin >> sal;
        cout << "\nEnter the destination: ";
        cin >> dest;
    }

    void accept2() {
        cout << "\n\tEnter the employee ID to modify: ";
        cin >> empID;
    }

    void accept3() {
        cout << "\n\tEnter the name to modify: ";
        cin >> name;
    }

    int getID() {
        return empID;
    }

    void show() {
        cout << "\n\t" << empID << "\t\t" << name << "\t\t" << sal << "\t\t" << dest;
    }
};

int main() {
    int i, n, ch, ch1, rec, start, count, add, n1, add2, start2, n2, y, a, b, on, oname, add3, start3, n3, y1, add4, start4, n4;
    char name[20], name2[20];
    Emp1 e1;
    count = 0;
    fstream g, f;
    do {
        cout << "\n====================================MENU====================================";
        cout
                << "\n1.Insert the data\n2.Display the data\n3.Search and modify ID\n4.Search and modify name\n5.Search and modify only number\n6.Search and modify only name\n7.Delete a employee Record\n8.Exit\n\tEnter the choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                f.open("Records.txt", ios::out);
            x:
                e1.accept();
                f.write((char *) &e1, (sizeof(e1)));
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
                f.read((char *) &e1, (sizeof(e1)));
                cout << "\n\tEmp ID\t\tName \t\t Salary \t\t Designation ";
                while (f) {
                    e1.show();
                    f.read((char *) &e1, (sizeof(e1)));
                }
                f.close();
                break;
            case 3:
                cout << "\nEnter the ID of the employee: ";
                cin >> rec;
                f.open("Records.txt", ios::in | ios::out);
                f.read((char *) &e1, (sizeof(e1)));
                while (f) {
                    if (rec == e1.empID) {
                        cout << "\nRecord found.";
                        add = f.tellg();
                        f.seekg(0, ios::beg);
                        start = f.tellg();
                        n1 = (add - start) / (sizeof(e1));
                        f.seekp((n1 - 1) * sizeof(e1), ios::beg);
                        e1.accept();
                        f.write((char *) &e1, (sizeof(e1)));
                        f.close();
                        count++;
                        break;
                    }
                    f.read((char *) &e1, (sizeof(e1)));
                }
                if (count == 0)
                    cout << "\nRecord not found.";
                f.close();
                break;

            case 4:
                cout << "\nEnter the name of the employee: ";
                cin >> name;
                f.open("Records.txt", ios::in | ios::out);
                f.read((char *) &e1, (sizeof(e1)));
                while (f) {
                    y = (strcmp(name, e1.name));
                    if (y == 0) {
                        cout << "\nName found.";
                        add2 = f.tellg();
                        f.seekg(0, ios::beg);
                        start2 = f.tellg();
                        n2 = (add2 - start2) / (sizeof(e1));
                        f.seekp((n2 - 1) * sizeof(e1), ios::beg);
                        e1.accept();
                        f.write((char *) &e1, (sizeof(e1)));
                        f.close();
                        break;
                    }
                    f.read((char *) &e1, (sizeof(e1)));
                }
                break;
            case 5:
                cout << "\nEnter the ID of the employee: ";
                cin >> on;
                f.open("Records.txt", ios::in | ios::out);
                f.read((char *) &e1, (sizeof(e1)));
                while (f) {
                    if (on == e1.empID) {
                        cout << "\nNumber found.";
                        add3 = f.tellg();
                        f.seekg(0, ios::beg);
                        start3 = f.tellg();
                        n3 = (add3 - start3) / (sizeof(e1));
                        f.seekp((n3 - 1) * (sizeof(e1)), ios::beg);
                        e1.accept2();
                        f.write((char *) &e1, (sizeof(e1)));
                        f.close();
                        break;
                    }
                    f.read((char *) &e1, (sizeof(e1)));
                }
                break;
            case 6:
                cout << "\nEnter the name of the employee: ";
                cin >> name2;
                f.open("Records.txt", ios::in | ios::out);
                f.read((char *) &e1, (sizeof(e1)));
                while (f) {
                    y1 = (strcmp(name2, e1.name));
                    if (y1 == 0) {
                        cout << "\nName found.";
                        add4 = f.tellg();
                        f.seekg(0, ios::beg);
                        start4 = f.tellg();
                        n4 = (add4 - start4) / (sizeof(e1));
                        f.seekp((n4 - 1) * sizeof(e1), ios::beg);
                        e1.accept3();
                        f.write((char *) &e1, (sizeof(e1)));
                        f.close();
                        break;
                    }
                    f.read((char *) &e1, (sizeof(e1)));
                }
                break;
            case 7:
                int empID1;
                cout << "Enter the ID of employee to delete: ";
                cin >> empID1;
                f.open("Records.txt", ios::in);
                g.open("Temp.txt", ios::out);
                f.read((char *) &e1, sizeof(e1));
                while (!f.eof()) {
                    if (e1.getID() != empID1)
                        g.write((char *) &e1, sizeof(e1));
                    f.read((char *) &e1, sizeof(e1));
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
