#include<iostream>
#include<string>
#include<cstring>
#include<stack>

using namespace std;

int getWeight(char ch) {
    switch (ch) {
        case '^':
            return 3;
        case '/':
        case '*':
            return 2;
        case '+':
        case '-':
            return 1;
        default :
            return 0;
    }
}


void infix2postfix(char infix[], char postfix[], int size) {
    stack<char> s;
    int weight;
    int i = 0;
    int k = 0;
    char ch;

    while (i < size) {
        ch = infix[i];
        if (ch == '(') {
            s.push(ch);
            i++;
            continue;
        }
        if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix[k++] = s.top();
                s.pop();
            }

            if (!s.empty()) {
                s.pop();
            }
            i++;
            continue;
        }
        weight = getWeight(ch);
        if (weight == 0) {

            postfix[k++] = ch;

        } else {

            if (s.empty()) {

                s.push(ch);
            } else {

                while (!s.empty() && s.top() != '(' && weight <= getWeight(s.top())) {
                    postfix[k++] = s.top();
                    s.pop();
                }

                s.push(ch);
            }
        }

        i++;
    }

    while (!s.empty()) {
        postfix[k++] = s.top();
        s.pop();
    }
    postfix[k] = 0;
}

void infix2prefix(char infix[], char prefix[], int size) {
    stack<char> s;
    int weight;
    int i = 0;
    int k = 0;
    char ch;
    char infix0[size];
    int m = 0, n = size - 1;
    while (m < size) {
        if (infix[n] == '(')
            infix0[m] = ')';
        else if (infix[n] == ')')
            infix0[m] = '(';
        else
            infix0[m] = infix[n];
        m++;
        n--;
    }
    infix0[m] = 0;
    while (i < size) {
        ch = infix0[i];
        if (ch == '(') {

            s.push(ch);
            i++;
            continue;
        }
        if (ch == ')') {

            while (!s.empty() && s.top() != '(') {
                prefix[k++] = s.top();
                s.pop();
            }

            if (!s.empty()) {
                s.pop();
            }
            i++;
            continue;
        }
        weight = getWeight(ch);
        if (weight == 0) {

            prefix[k++] = ch;

        } else {

            if (s.empty()) {

                s.push(ch);
            } else {

                while (!s.empty() && s.top() != '(' && weight < getWeight(s.top())) {
                    prefix[k++] = s.top();
                    s.pop();
                }

                s.push(ch);
            }
        }
        i++;
    }

    while (!s.empty()) {
        prefix[k++] = s.top();
        s.pop();
    }
    prefix[k] = 0;
}


string postfix2infix(char postfix1[], int size) {
    string infix1;
    stack<string> s;
    int k = 0;
    while (k < size) {
        char ch = postfix1[k];
        int weight = getWeight(ch);
        if (weight == 0) {
            string e;
            e = ch;
            s.push(e);
        } else {

            string operand_2 = s.top();
            s.pop();
            string operand_1 = s.top();
            s.pop();
            s.push("(" + operand_1 + ch + operand_2 + ")");
        }
        k++;
    }
    infix1 = s.top();
    s.pop();
    return infix1;
}


string postfix2prefix(char postfix1[], int size) {
    string prefix1;
    stack<string> s;
    int k = 0;
    while (k < size) {
        char ch = postfix1[k];
        int weight = getWeight(ch);
        if (weight == 0) {
            string e;
            e = ch;
            s.push(e);
        } else {

            string operand_2 = s.top();
            s.pop();
            string operand_1 = s.top();
            s.pop();
            s.push(ch + operand_1 + operand_2);
        }
        k++;
    }
    prefix1 = s.top();
    s.pop();
    return prefix1;
}


string prefix2infix(char prefix1[], int size) {
    string infix1;
    stack<string> s;
    int k = size - 1;
    while (k >= 0) {
        char ch = prefix1[k];
        int weight = getWeight(ch);
        if (weight == 0) {
            string e;
            e = ch;
            s.push(e);
        } else {

            string operand_1 = s.top();
            s.pop();
            string operand_2 = s.top();
            s.pop();
            s.push("(" + operand_1 + ch + operand_2 + ")");
        }
        k--;
    }
    infix1 = s.top();
    s.pop();
    return infix1;
}

string prefix2postfix(char prefix1[], int size) {
    string postfix1;
    stack<string> s;
    int k = size - 1;
    while (k >= 0) {
        char ch = prefix1[k];
        int weight = getWeight(ch);
        if (weight == 0) {
            string e;
            e = ch;
            s.push(e);
        } else {

            string operand_1 = s.top();
            s.pop();
            string operand_2 = s.top();
            s.pop();
            s.push(operand_1 + operand_2 + ch);

        }
        k--;
    }
    postfix1 = s.top();
    s.pop();
    return postfix1;
}

int main() {
    char ch;
    int c, size;
    char infix[20], postfix[20], prefix[20], postfix1[20], prefix1[20];
    string infix1, prefix2, postfix2;
    do {
        cout << "\n================================EXPRESSION CONVERSION================================";
        cout << "\n1. Infix to other";
        cout << "\n2. Postfix to other";
        cout << "\n3. Prefix to other";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> c;
        if (c != 4) {
            switch (c) {
                case 1:
                    cout << "\nInsert infix expression: ";
                    cin >> infix;
                    size = strlen(infix);
                    infix2postfix(infix, postfix, size);
                    infix2prefix(infix, prefix, size);
                    cout << "\nInfix expression: " << infix;
                    cout << "\nPostfix expression: " << postfix;
                    cout << "\nPrefix expression: ";

                    for (int i = strlen(prefix) - 1; i >= 0; i--) {
                        cout << prefix[i];
                    }
                    cout << endl << endl;
                    break;
                case 2:
                    cout << "\nInsert postfix expression: ";
                    cin >> postfix1;
                    size = strlen(postfix1);
                    infix1 = postfix2infix(postfix1, size);
                    prefix2 = postfix2prefix(postfix1, size);
                    cout << "\nPostfix expression: " << postfix1;
                    cout << "\nInfix expression: " << infix1;
                    cout << "\nPrefix expression: " << prefix2;
                    cout << endl << endl;
                    break;
                case 3:
                    cout << "\nInsert prefix expression: ";
                    cin >> prefix1;
                    size = strlen(prefix1);
                    infix1 = prefix2infix(prefix1, size);
                    postfix2 = prefix2postfix(prefix1, size);
                    cout << "\nPrefix expression: " << prefix1;
                    cout << "\nInfix expression: " << infix1;
                    cout << "\nPostfix expression: " << postfix2;
                    cout << endl << endl;
                    break;
                case 4:
                    break;
            }
            cout << "Do you want to continue? (y/n): ";
            cin >> ch;
        }
    } while (ch == 'y');

    return 0;
}
