#include<bits/stdc++.h>

using namespace std;

struct node {
    string label;
    int count;
    node *child[10];
} *root;

class Book {
public:

    Book() {
        root = NULL;
    }


    void create() {
        root = new node;
        cout << "\n Enter the name of the book: ";
        cin >> root->label;
        cout << "\n Enter the number of chapters: ";
        cin >> root->count;

        for (int i = 0; i < root->count; i++) {
            root->child[i] = new node;
            cout << "\n Enter the name of the " << i + 1 << " chapter: ";
            cin >> root->child[i]->label;
            cout << "\n Enter the number of sections: ";
            cin >> root->child[i]->count;


            for (int j = 0; j < root->child[i]->count; j++) {
                root->child[i]->child[j] = new node;
                cout << "\n Enter the name of the " << j + 1 << " section: ";
                cin >> root->child[i]->child[j]->label;
                cout << "\n Enter the number sub sections: ";
                cin >> root->child[i]->child[j]->count;


                for (int k = 0;
                     k < root->child[i]->child[j]->count; k++) {
                    root->child[i]->child[j]->child[k] = new node;
                    cout << "\n Enter the name of the " << k + 1 << " sub section: ";
                    cin >> root->child[i]->child[j]->child[k]->label;
                }
            }
        }
    }


    void display() {
        cout << "\n Name of the book is: ";
        cout << root->label;
        cout << "\n Name of the chapter and the sections is: ";

        for (int i = 0; i < root->count; i++) {
            cout << i + 1 << " " << root->child[i]->label << endl;
            node *temp;
            temp = root->child[i];
            for (int j = 0; j < temp->count; j++) {
                node *temp2;
                temp2 = root->child[i]->child[j];
                cout << i + 1 << " " << root->child[i]->child[j]->label << endl;
                for (int k = 0; k < temp2->count; k++) {
                    cout << i + 1 << " " << root->child[i]->child[j]->child[k]->label << endl;
                }
            }
        }
    }
};

int main() {
    Book o;
    o.create();
    o.display();
    return 0;
}
