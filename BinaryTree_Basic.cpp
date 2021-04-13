#include<bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node *left;
    node *right;
} *root;

class Binary {
public:
    Binary() {
        root = NULL;
    }

    node *create() {
        int x;
        cout << "\n Enter the data (-1 for no sub node): ";
        cin >> x;
        node *tmp = new node;
        tmp->data = x;

        if (x == -1)
            return NULL;

        cout << "\n Enter the left child of " << x << ": ";
        tmp->left = create();

        cout << "\n Enter the right child of " << x << ": ";
        tmp->right = create();
        return tmp;
    }

    void preorder(node *root) {
        if (root != NULL) {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void inorder(node *root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void postorder(node *root) {
        if (root != NULL) {
            preorder(root->left);
            preorder(root->right);
            cout << root->data << " ";
        }
    }

};

int main() {
    Binary o;
    root = o.create();

    cout << "\n Inorder of given tree is: ";
    o.inorder(root);

    cout << "\n Preorder of given tree is: ";
    o.preorder(root);

    cout << "\n Postorder of given tree is: ";
    o.postorder(root);

    return 0;
}
