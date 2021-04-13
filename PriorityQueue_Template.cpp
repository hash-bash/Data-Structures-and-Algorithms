#include <iostream>
#include <queue>

#define ROW 5
#define COL 2

using namespace std;

struct Person {
    int age;
    float height;

    Person(int age, float height)
            : age(age), height(height) {
    }
};

struct CompareHeight {
    bool operator()(Person const &p1, Person const &p2) {
        return p1.height < p2.height;
    }
};

int main() {
    priority_queue<Person, vector<Person>, CompareHeight> Q;

    float arr[ROW][COL] = {{30, 5.5},
                           {25, 5},
                           {20, 6},
                           {33, 6.1},
                           {23, 5.6}};

    for (int i = 0; i < ROW; ++i)
        Q.push(Person(arr[i][0], arr[i][1]));

    while (!Q.empty()) {
        Person p = Q.top();
        Q.pop();
        cout << p.age << " " << p.height << "\n";
    }
    return 0;
}

