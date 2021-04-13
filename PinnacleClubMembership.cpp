#include <iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct node {
    int prn;
    char name[20];
    node *next;
};

class panclub {
    int num, cnt;
    char nm[20];
    node *head;
public:
    panclub() {
        num = cnt = 0;
        head = NULL;
    }

    node *create();

    void display(node *);

    node *concat(node *, node *);

    void reverse(node *);

    node *insert_president(node *);

    void insert_sec(node *);

    void insert_member(node *);

    node *del_president(node *);

    node *del_secretary(node *);

    node *del_member(node *);
};

node *panclub::create() {
    node *temp, *n1;
    temp = n1 = NULL;

    cout << "\nHow many students data do you want to insert in Pinnacle club database: ";
    cin >> cnt;
    do {
        n1 = new node;
        cout << "\nEnter the PRN number of student: ";
        cin >> num;
        n1->prn = num;
        cout << "\nEnter the name of student: ";
        cin >> nm;
        strcpy(n1->name, nm);
        n1->next = NULL;
        if (head == NULL) {
            head = n1;
            temp = head;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = n1;
        }
        cnt--;
    } while (cnt > 0);

    return head;
}

void panclub::display(node *head) {
    node *temp;
    temp = head;
    while (temp != NULL) {
        if (temp->next == NULL) {
            cout << "[" << temp->prn << "|" << temp->name << "]->NULL";
        } else {
            cout << "[" << temp->prn << "|" << temp->name << "]->";
        }
        temp = temp->next;
    }
}

node *panclub::concat(node *head1, node *head2) {
    node *head3, *temp, *temp1;
    head3 = temp = temp1 = NULL;
    temp = head1;
    head3 = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp1 = head2;
    temp->next = temp1;
    return head3;
}

void panclub::reverse(node *head) {
    node *temp;
    temp = head;
    if (temp == NULL)
        return;
    reverse(temp->next);
    cout << "[" << temp->prn << "|" << temp->name << "]->";
}

node *panclub::insert_president(node *head) {
    node *temp, *n2;
    temp = n2 = NULL;
    temp = head;
    n2 = new node;
    cout << "\nEnter the PRN number of president: ";
    cin >> n2->prn;
    cout << "\nEnter the name of president: ";
    cin >> n2->name;
    n2->next = temp;
    head = n2;
    return head;
}

void panclub::insert_member(node *head) {
    node *temp, *n2;
    int pn;
    temp = head;
    n2 = new node;
    cout << "\nEnter the PRN number of member: ";
    cin >> n2->prn;
    cout << "\nEnter the name of member: ";
    cin >> n2->name;
    n2->next = NULL;
    cout << "\nEnter the PRN number after which this member to be inserted: ";
    cin >> pn;
    while (temp != NULL) {
        if (temp->prn == pn) {
            n2->next = temp->next;
            temp->next = n2;
            break;
        }
        temp = temp->next;
    }
    cout << "\nMember added successfully.";
}

void panclub::insert_sec(node *head) {
    node *temp, *n2;
    temp = head;
    n2 = new node;
    cout << "\nEnter the PRN number of Secretary: ";
    cin >> n2->prn;
    cout << "\nEnter the Name of Secretary: ";
    cin >> n2->name;
    n2->next = NULL;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n2;
}

node *panclub::del_president(node *head) {
    node *temp;
    temp = head;
    head = temp->next;
    free(temp);
    return head;
}

node *panclub::del_secretary(node *head) {
    node *temp, *t1;
    temp = head;
    while (temp->next != NULL) {
        t1 = temp;
        temp = temp->next;
    }
    t1->next = NULL;
    free(temp);
    return head;
}

node *panclub::del_member(node *head) {
    node *temp, *t1;
    int pn;
    temp = head;
    cout << "\nEnter the PRN number to delete member: ";
    cin >> pn;
    while (temp != NULL) {
        if (temp->prn == pn) {
            t1 = temp->next;
            temp->next = t1->next;
            free(t1);
            break;
        }
        temp = temp->next;
    }
    cout << "\nMember removed successfully.";
    return head;
}

int main() {
    panclub p1, p2, p3;
    node *h1, *h2, *h3;
    h1 = h2 = h3 = NULL;
    int ch;
    cout << "\n==============================MENU==============================" << endl;
    do {
        cout << "\n1. Enter data of SE A division:";
        cout << "\n2. Enter data of SE B division:";
        cout << "\n3. Concatenation of list";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "\nEnter the Pinnacle club data of SE A:\n";
                h1 = p1.create();
                cout << "\nSE A list are as follows:\n";
                p1.display(h1);
                cout << "\nReverse list of SE A:\n";
                p1.reverse(h1);
                p1.insert_sec(h1);
                cout << "\nAfter insertion of secretary:\n";
                p1.display(h1);
                h1 = p1.insert_president(h1);
                cout << "\nAfter insertion of president:\n";
                p1.display(h1);
                p1.insert_member(h1);
                cout << "\nAfter insertion of member:\n";
                p1.display(h1);
                h1 = p1.del_president(h1);
                cout << "\nAfter deletion of president:\n";
                p1.display(h1);
                h1 = p1.del_secretary(h1);
                cout << "\nAfter deletion of secretary:\n";
                p1.display(h1);
                h1 = p1.del_member(h1);
                cout << "\nAfter deletion of member:\n";
                p1.display(h1);
                break;
            case 2:
                cout << "\nEnter the Pinnacle club data of SE B:\n";
                h2 = p2.create();
                cout << "\nSE B list are as follows:\n";
                p2.display(h2);
                cout << "\nReverse list of SE B:\n";
                p1.reverse(h2);
                p2.insert_sec(h2);
                cout << "\nAfter insertion of secretary:\n";
                p2.display(h2);
                h2 = p2.insert_president(h2);
                cout << "\nAfter insertion of president:\n";
                p2.display(h2);
                p2.insert_member(h2);
                cout << "\nAfter insertion of member:\n";
                p2.display(h2);
                h2 = p2.del_president(h2);
                cout << "\nAfter deletion of president:\n";
                p1.display(h2);
                h2 = p2.del_secretary(h2);
                cout << "\nAfter deletion of secretary:\n";
                p1.display(h2);
                h2 = p2.del_member(h2);
                cout << "\nAfter deletion of member:\n";
                p2.display(h2);
                break;
            case 3:
                h3 = p3.concat(h1, h2);
                cout << "\nThe concatenation of Div A and Div B classes are as follows:\n";
                p3.display(h3);
                break;
        }
    } while (ch != 4);
    return 0;
}
