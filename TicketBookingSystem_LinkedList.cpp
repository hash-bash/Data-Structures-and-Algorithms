#include <iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

struct node {
    int flag;
    char movie_name[20];
    char name[20];
    long mno;
    node *next;
    node *prev;
};

struct hnode {
    node *next;
    int cnt;
};

class Cinemax {
    hnode *head[11];
    node *temp, *t1, *p;
    int n, i, j;
public:
    Cinemax() {
        for (i = 1; i <= 10; i++) {
            head[i] = new hnode;
            head[i]->next = NULL;
            head[i]->cnt = 0;
        }
        temp = t1 = p = NULL;
        n = i = j = 0;
    }

    void create();

    void show();

    int book_my_show(int, int, char[]);

    int cancel_my_show(int, int, char[]);
};

int Cinemax::book_my_show(int r, int n, char name[20]) {
    cout << "\nYou request for " << n << " tickets of " << name << " movie: \n";
    temp = head[r]->next;
    int max;
    max = head[r]->cnt;
    if (max == 7) {
        cout << "\nNo seat available in this row.";
        return 0;
    } else {
        int seat[5], cnt = 0, sn;
        for (i = 0; i < n; i++) {
            cout << "\nEnter the seat number: ";
            cin >> sn;
            seat[i] = sn - 1;
        }
        i = 0;
        while (temp->next != head[r]->next) {
            if (cnt != seat[i]) {
                cnt++;
                temp = temp->next;
            } else {
                if (temp->flag == 0) {
                    strcpy(temp->movie_name, name);
                    temp->flag = 1;
                    cout << "\nEnter your name: ";
                    cin >> temp->name;
                    cout << "\nEnter your mobile number: ";
                    cin >> temp->mno;
                    head[r]->cnt = head[r]->cnt + 1;
                    cnt = 0;
                    temp = head[r]->next;
                    i++;
                    if (i == n)
                        break;
                }
            }
        }
    }
    if ((temp->next == head[r]->next)) {
        if (temp->flag == 0) {
            strcpy(temp->movie_name, name);
            temp->flag = 1;
            cout << "\nEnter your name:";
            cin >> temp->name;
            cout << "\nEnter your mobile number: ";
            cin >> temp->mno;
            head[r]->cnt = head[r]->cnt + 1;
        }
    }
    return 1;
}

int Cinemax::cancel_my_show(int r, int n, char name[20]) {
    cout << "\nYour cancel request for " << n << " tickets of " << name << " movie: \n";
    temp = head[r]->next;
    int max;
    max = head[r]->cnt;
    if (max == -1) {
        cout << "\nNo such seat available in this row for cancel.";
        return 0;
    } else {
        int seat[5], cnt = 0, sn;
        for (i = 0; i < n; i++) {
            cout << "\nEnter the seat number: ";
            cin >> sn;
            seat[i] = sn - 1;
        }
        i = 0;
        while (temp->next != head[r]->next) {
            if (cnt != seat[i]) {
                cnt++;
                temp = temp->next;
            } else {
                if (temp->flag == 1) {
                    strcpy(temp->movie_name, "NIL");
                    temp->flag = 0;
                    strcpy(temp->name, "NIL");
                    temp->mno = 00;
                    head[r]->cnt = head[r]->cnt - 1;
                    cnt = 0;
                    temp = head[r]->next;
                    i++;
                    if (i == n)
                        break;
                }
            }
        }
    }
    if ((temp->next == head[r]->next)) {
        if (temp->flag == 1) {
            strcpy(temp->movie_name, "NIL");
            temp->flag = 0;
            strcpy(temp->name, "NIL");
            temp->mno = 00;
            head[r]->cnt = head[r]->cnt - 1;
        }
    }
    return 1;
}

void Cinemax::create() {
    node *f1;
    for (i = 1; i <= 10; i++) {
        p = new node;
        p->next = NULL;
        p->prev = NULL;
        p->flag = 0;
        strcpy(p->movie_name, "NIL");
        strcpy(p->name, "NIL");
        p->mno = 0;

        if (head[i]->next == NULL) {
            head[i]->next = p;
            p->prev = p;
            p->next = p;
        }
        temp = head[i]->next;
        f1 = temp;
        for (j = 1; j <= 6; j++) {
            t1 = new node;
            t1->flag = 0;
            t1->mno = 0;
            strcpy(t1->movie_name, "NIL");
            strcpy(t1->name, "NIL");
            t1->next = head[i]->next;
            temp->next = t1;
            t1->prev = temp;
            f1->prev = t1;
            temp = t1;
        }
    }
}

void Cinemax::show() {
    cout << "Rows status are as follows:";
    cout << "\nHead Node\tCol1\t\tCol2\t\tCol3\t\tCol4\t\tCol5\t\tCol6\t\tCol7";
    for (i = 1; i <= 10; i++) {
        cout << "\nRow: " << i;
        temp = head[i]->next;
        cout << "[ " << head[i]->cnt << " ]--->";
        while (temp->next != head[i]->next) {
            cout << "[ " << temp->flag << "|" << temp->movie_name << "|" << temp->name
                 << "]->";
            temp = temp->next;
        }
        if (temp->next == head[i]->next) {
            cout << "[ " << temp->flag << "|" << temp->movie_name << "|" << temp->name
                 << "]->";
        }
        cout << "\n";
    }
}

int main() {
    Cinemax c1;
    int row, n, am, ch, amnt = 150;
    char mname[20];
    c1.create();
    do {
        cout << "\n=======================Cinemax Theater=======================";
        cout << "\n1.Book the show\n2.Display seat status\n3.Cancel my show";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "\nWelcome To Cinemax theater!";
                cout << "\nFriday's movies are as follows:";
                cout
                        << "\n1.Mohenjo_Daro\n2.Rustom\n3.Happy_Bag_Jayegi\n4.Bar_Bar_Dekho\n5.Akira\n6.Rangoon\n7.Flying_Jatt";
                cout << "\nEnter the movie name to book the show: (Note: space is not allowed in movie name): ";
                cin >> mname;
                c1.show();
                cout << "\nEnter the row number to book your ticket: ";
                cin >> row;
                cout << "\nHow many tickets do you want to book: ";
                cin >> n;
                am = c1.book_my_show(row, n, mname);
                if (am != 0) {
                    c1.show();
                    cout << "\nPlease pay the cash, your total amount is: " << amnt * n;
                    cout << "\nYour booking is confirmed please check the status.";
                } else {
                    cout << "\nTry for another row.\n";
                }
                break;
            case 2:
                cout << "\n The Booking status of the Cinemax theater are as follows: ";
                c1.show();
                break;
            case 3:
                cout << "\nEnter the movie name to cancel the show: (Note: space is not allowed in movie name): ";
                cin >> mname;
                c1.show();
                cout << "\nEnter the row number to cancel your ticket: ";
                cin >> row;
                cout << "\nHow many tickets do you want to cancel: ";
                cin >> n;
                am = c1.cancel_my_show(row, n, mname);
                if (am != 0) {
                    c1.show();
                    cout << "\nYour total refund amount is: " << ((amnt * n) - 50);
                    cout << "\nYour booking is canceled please see the status.";
                } else {
                    cout << "\nCancellation not available.";
                }
                break;
        }
    } while (ch != 4);
    return 0;
}
