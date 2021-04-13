#include<bits/stdc++.h>

using namespace std;

class stringfunc {
    int n;
    string s;
public:
    void getdata();

    void frequency();

    void deletes();

    void chardelete();

    void replace();

    void palin();
};

void stringfunc::getdata() {
    cout << "\nEnter length of the string: ";
    cin >> n;
    while (n <= 0) {
        cout << "\nEnter the length again: ";
        cin >> n;
    }
    cout << "\nEnter a string: ";
    cin >> s;
    if (n != s.size()) {
        cout << "\nEnter the string again: ";
        cin >> s;
    }
}

void stringfunc::frequency() {
    char a;
    cout << "\nEnter a character whose frequency is to be calculated: ";
    cin >> a;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == a)
            ans++;
    }
    cout << "\nThe frequency of the character in the string is " << ans << ".";
}

void stringfunc::deletes() {
    string a;
    int x, l;
    cout << "\nEnter the starting index: ";
    cin >> x;
    while (x < 0) {
        cout << "\nInvalid number, enter the index again: ";
        cin >> x;
    }
    cout << "\nEnter the length: ";
    cin >> l;
    while (l < 0) {
        cout << "\nInvalid number, enter the length again: ";
        cin >> l;
    }
    cout << "\nString after deleting the length of the substring: ";
    if (l == 0) {
        cout << s << "\n";
        return;
    }
    for (int i = 0; i < n;) {
        if (i != x) {
            a.push_back(s[i++]);
        } else i += l;
    }
    s = a;
    n = s.size();
    cout << s << "\n";
}

void stringfunc::chardelete() {
    string f;
    char a;
    cout << "\nEnter the character to be deleted: ";
    cin >> a;
    cout << "\nString after deleting all the occurrences of the given character: ";
    for (int i = 0; i < n; i++)
        if (s[i] != a)
            f.push_back(s[i]);
    s = f;
    n = s.size();
    cout << s;
}

void stringfunc::replace() {
    string f;
    string a, b;
    cout << "\nEnter the string to be replaced: ";
    cin >> a;
    cout << "\nEnter the string to be replaced with: ";
    cin >> b;
    cout << "\nString after replacement: ";
    int x = a.size();
    for (int i = 0; i <= n - x; i++) {
        int ok = 0;
        for (int j = 0; j < x; j++) {
            if (s[i + j] != a[j])
                ok = 1;
        }
        if (ok == 0) {
            f += b;
            i += x - 1;
        } else f.push_back(s[i]);
    }
    s = f;
    n = s.size();
    cout << s;
}

void stringfunc::palin() {
    cout << s;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            cout << "\nGiven string is not a palindrome.";
            return;
        }
    }
    cout << "\nGiven string is a palindrome.";
}

int main() {
    stringfunc obj;
    obj.getdata();
    int c;
    while (1) {
        cout << "\n=============================MENU=============================\n";
        cout << "1.Frequency of a particular character\n";
        cout << "2.Deletes the string of given length from given index\n";
        cout << "3.Deletes all occurrences of a particular character\n";
        cout << "4.Replace a substring with another string\n";
        cout << "5.Check whether string is palindrome or not\n";
        cout << "0.For exit\n";
        cout << "Enter your choice: \n";
        cin >> c;
        if (!c)break;
        switch (c) {
            case 1:
                obj.frequency();
                break;
            case 2:
                obj.deletes();
                break;
            case 3:
                obj.chardelete();
                break;
            case 4:
                obj.replace();
                break;
            case 5:
                obj.palin();
                break;
            default:
                cout << "Wrong input.\n";
        }
    }
    return 0;
}
