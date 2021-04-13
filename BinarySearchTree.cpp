#include<iostream>

using namespace std;
struct node {
    int data;
    struct node *left;
    struct node *right;
} *root;

class BST {
public:
    int cnt;
    int ct;

    BST() {
        ct = 0;
    }

    node *create(node *n, int key) {
        if (n == NULL) {
            n = new node;
            n->data = key;
            n->left = NULL;
            n->right = NULL;
            return n;
        } else if (key < n->data) {
            n->left = create(n->left, key);
        } else if (key > n->data) {
            n->right = create(n->right, key);
        }
        return n;
    }

    void inorder(node *root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void preorder(node *root) {
        if (root != NULL) {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(node *root) {
        if (root != NULL) {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }

    void small(node *root) {
        if (root != NULL) {
            if (root->left != NULL) {
                small(root->left);
            } else
                cout << " " << root->data;
        }
    }

    void large(node *root) {
        if (root != NULL) {
            if (root->right != NULL) {
                large(root->right);
            } else
                cout << " " << root->data;
        }
    }

    int height(node *root) {
        if (root == NULL)
            return 0;

        else {
            int lb = height(root->left);
            int rb = height(root->right);
            if (lb > rb)
                return (lb + 1);
            else
                return (rb + 1);
        }
    }

    int count(node *root) {

        if (root != NULL) {
            count(root->left);
            ct++;
            count(root->right);
        }
        return ct;
    }

};

int main() {
    BST b;
    int no, i, data;
    cout << "\n Enter how many elements do you want to insert: ";
    cin >> no;
    cout << "\n Enter the data of the tree:\n";
    for (i = 0; i < no; i++) {
        cin >> data;
        root = b.create(root, data);
    }

    cout << "\n Inorder of given binary search tree is: ";
    b.inorder(root);
    cout << "\n Preorder of given binary search tree is: ";
    b.preorder(root);
    cout << "\n Postorder of given binary search tree is: ";
    b.postorder(root);
    cout << "\n Smallest element in the tree is: ";
    b.small(root);
    cout << "\n Largest element in the tree is: ";
    b.large(root);
    cout << "\n The height of the tree is: ";
    cout << b.height(root);
    cout << "\n The count of the nodes in the tree is: ";
    cout << b.count(root);
    cout << endl;
    return 0;
}

