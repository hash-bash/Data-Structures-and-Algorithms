#include<bits/stdc++.h>

using namespace std;

class permu {
    int i, j, k;
    string n[6] = {"Nikhita", "Aboli", "Megha", "Sanika", "Prutik", "Saurabh"};
public:
    void com();
};

void permu::com() {
    int c = 0;
    for (i = 0; i < 6; i++) {
        for (j = i + 1; j < 6; j++) {
            for (k = j + 1; k < 6; k++) {
                cout << "{" << n[i] << "," << n[j] << "," << n[k] << "}" << endl;
                c++;
            }
        }
    }
    cout << "\nTotal number of combinations: " << c << endl;
}

int main() {
    permu p;
    p.com();
    return 0;
}
