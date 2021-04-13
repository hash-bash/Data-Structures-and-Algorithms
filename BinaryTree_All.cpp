#include
<bits/stdc++.h>

using namespace std;
struct node {
int data;
node *left;
node *right;
};

class Binary {
public:
int ct;
node *root, *temp;

Binary() {
root = NULL;
temp = NULL;
ct = 0;
}

node *create() {
node *newnode = new node;
cout << "\nEnter the data: ";
cin >> newnode->data;
newnode->left = NULL;
newnode->right = NULL;
return newnode;
}

void construct() {
temp = root;
if (root == NULL) {
temp = create();
root = temp;
cout << "\nNode has been inserted.";
return;
} else {
char c;
int flag = 0;
while (flag == 0) {
cout << "\nEnter the side of " << temp->data << " you want to insert the node: (left-l)(right-r): ";
cin >> c;
if (c == 'l') {
if (temp->left == NULL) {
node *lchild = create();
temp->left = lchild;
flag = 1;
cout << "\nNode has been inserted.";
} else {
temp = temp->left;
}
} else if (c == 'r') {
if (temp->right == NULL) {
node *rchild = create();
temp->right = rchild;
flag = 1;
cout << "\nNode has been inserted.";
} else
temp = temp->right;
}
}
}
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

node *mirror(node *n) {
node *current = new node;
if (!n) {
return NULL;
} else {
current->left = mirror(n->right);
current->right = mirror(n->left);
current->data = n->data;
return current;
}
}

node *operator=(node *n) {
node *newnode = new node;
if (!n)
return NULL;
else {
newnode->left = (n->left);
newnode->right = (n->right);
newnode->data = n->data;
return newnode;
}
}

int identicalTrees(node *a, node *b) {
if (a == NULL && b == NULL)
return 1;
if (a != NULL && b != NULL) {
return
(
a->data == b->data &&
identicalTrees(a->left, b->left) &&
identicalTrees(a->right, b->right)
);
}
return 0;
}

node *buildTree(int in[], int pre[], int inStrt, int inEnd) {
static int preIndex = 0;
if (inStrt > inEnd)
return NULL;
node *tNode = newNode(pre[preIndex++]);
if (inStrt == inEnd)
return tNode;
int inIndex = search(in, inStrt, inEnd, tNode->data);
tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
tNode->right = buildTree(in, pre, inIndex + 1, inEnd);
return tNode;
}

int search(int arr[], int strt, int end, int value) {
int i;
for (i = strt; i <= end; i++) {
if (arr[i] == value)
return i;
}
return -1;
}

node *newNode(int data) {
node *Node = new node();
Node->data = data;
Node->left = NULL;
Node->right = NULL;
return (Node);
}

void erase(node *n) {
if (n) {
erase(n->left);
erase(n->right);
cout << "\nDeleted node: " << n->data;
}
root = NULL;
}
};

int main() {
int ch, no;
char ch2;
Binary o, o2, o3, o4, o5;
do {
cout << "\n=====================MENU=====================";
cout
<< "\n1.Construct \n2.Preorder \n3.Inorder \n4.Postorder \n5.Mirror image \n6.Copy tree (use '=' operator) \n7.Height \n8.Count nodes \n9.Erase nodes \n10.Check if two trees are identical \n11.Construct tree from given inorder and preorder \n12.Exit";
cout << "\nEnter your choice: ";
cin >> ch;
switch (ch) {
case 1:
cout << "\nEnter the number of nodes you want to insert: ";
cin >> no;
for (int i = 0; i < no; i++) {
o.construct();
}
break;
case 2:
cout << "\nPreorder of given tree is: ";
o.preorder(o.root);
break;
case 3:
cout << "\nInorder of given tree is: ";
o.inorder(o.root);
break;
case 4:
cout << "\nPostorder of given tree is: ";
o.postorder(o.root);
break;
case 5:
o2.root = o2.mirror(o.root);
cout << "\nInorder of original tree: ";
o.inorder(o.root);
cout << "\nInorder of mirror: ";
o2.inorder(o2.root);
break;
case 6:
o3 = o;
cout << "\nInorder of copied: ";
o3.inorder(o3.root);
break;
case 7:
cout << "\nThe height of the tree is: ";
cout << o.height(o.root);
break;
case 8:
cout << "\nThe count of the nodes in the tree is: ";
cout << o.count(o.root);
break;
case 9:
o.erase(o.root);
cout << "\nThis tree is erased.";
break;
case 10:
cout << "\nEnter the number of nodes you want to insert in second tree: ";
cin >> no;
for (int i = 0; i < no; i++) {
o4.construct();
}
if (o.identicalTrees(o.root, o4.root)) {
cout << "\nThe trees are identical.";
} else
cout << "\nThe trees are not identical.";
break;
case 11:
int x;
cout << "\nEnter number of elements to be inserted: ";
cin >> x;
int a[x], b[x];
cout << "\nEnter the inorder of the tree:";
for (int i = 0; i < x; i++) {
cout << "\nEnter " << i + 1 << " element: ";
cin >> a[i];
}
cout << "\nEnter the preorder of the tree:";
for (int i = 0; i < x; i++) {
cout << "\nEnter " << i + 1 << " element: ";
cin >> b[i];
}
int len = sizeof(a) / sizeof(a[0]);
o5.root = o5.buildTree(a, b, 0, len - 1);
cout << "\nInorder traversal of the constructed tree is: ";
o5.inorder(o5.root);
}
cout << "\nDo you want to continue? (y/n): ";
cin >> ch2;
} while (ch2 == 'y');
return 0;
}
