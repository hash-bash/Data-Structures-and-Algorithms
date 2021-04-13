#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

struct node {
    int priority;
    int info;
    struct node *link;
};

class Priority_Queue {
private:
    node *front;
public:
    Priority_Queue() {
        front = NULL;
    }

    void insert(int item, int priority) {
        node *tmp, *q;
        tmp = new node;
        tmp->info = item;
        tmp->priority = priority;
        if (front == NULL || priority < front->priority) {
            tmp->link = front;
            front = tmp;
        } else {
            q = front;
            while (q->link != NULL && q->link->priority <= priority)
                q = q->link;
            tmp->link = q->link;
            q->link = tmp;
        }
    }

    void del() {
        node *tmp;
        if (front == NULL)
            cout << "\nQueue underflow.";
        else {
            tmp = front;
            cout << "\nDeleted item is: " << tmp->info << "." << endl;
            front = front->link;
            free(tmp);
        }
    }

    void display() {
        node *ptr;
        ptr = front;
        if (front == NULL)
            cout << "\nQueue is empty.";
        else {
            cout << "\nQueue is :";
            cout << "\nPriority       Item";
            while (ptr != NULL) {
                cout << ptr->priority << "                 " << ptr->info << endl;
                ptr = ptr->link;
            }
        }
    }
};

int main() {
    int choice, item, priority;
    Priority_Queue pq;
    do {
        cout << "\n==============PIZZA PARLOUR==============";
        cout << "\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Display";
        cout << "\n4. Quit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "\nInput the item value to be added in the queue: ";
                cin >> item;
                cout << "\nEnter its priority: ";
                cin >> priority;
                pq.insert(item, priority);
                break;
            case 2:
                pq.del();
                break;
            case 3:
                pq.display();
                break;
            case 4:
                break;
            default :
                cout << "\nWrong choice.";
        }
    } while (choice != 4);
    return 0;
}
