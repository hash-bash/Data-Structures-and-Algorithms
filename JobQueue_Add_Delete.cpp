#include <iostream>

using namespace std;
#define size 5

class spq {
    int f, r, job, djob;
    int simpq[size], prioq[size];
public:
    spq() {
        f = r = -1;
        job = djob = 0;
        prioq[-1] = 0;
    }

    int isQfull() {
        if (r == size - 1)
            return 1;
        else
            return 0;
    }

    int isQempty() {
        if ((f == -1) || (f > r))
            return 1;
        else
            return 0;
    }

    void simpqadd();

    void showsimpleQ();

    void delsimpleQ();

    void prioqadd();

    void delprioQ();

    void showprioQ();
};

void spq::simpqadd() {
    cout << "\nEnter the Job: ";
    cin >> job;
    if (isQfull())
        cout << "\nCannot add, queue full.";
    else {
        if (f == -1) {
            f = r = 0;
            simpq[r] = job;
        } else {
            r = r + 1;
            simpq[r] = job;
        }
    }

}

void spq::delsimpleQ() {
    if (isQempty())
        cout << "\nCannot delete, queue empty.";
    else {
        djob = simpq[f];
        f = f + 1;
        cout << "\nDeleted job is: " << djob;
    }
}

void spq::showsimpleQ() {
    cout << "\nSimple queue jobs are as follows:\n";
    int temp;
    for (temp = f; temp <= r; temp++) {
        cout << "\t" << simpq[temp];
    }
}

void spq::delprioQ() {
    if (isQempty())
        cout << "\nCannot delete, queue empty.";
    else {
        djob = prioq[f];
        f = f + 1;
        cout << "\nDeleted job is: " << djob;
    }
}

void spq::showprioQ() {
    cout << "\nPriority queue jobs are as follows:\n";
    int temp;
    for (temp = f; temp <= r; temp++) {
        cout << "\t" << prioq[temp];
    }
}

void spq::prioqadd() {
    int t = 0;
    cout << "\nEnter the job: ";
    cin >> job;
    if (isQfull())
        cout << "\nCannot add, queue full.\n";
    else {
        if (f == -1) {
            f = r = 0;
            prioq[r] = job;
        } else if (job < prioq[r]) {
            t = r;
            while (job < prioq[t]) {
                prioq[t + 1] = prioq[t];
                t = t - 1;
            }
            t = t + 1;
            prioq[t] = job;
            r = r + 1;
        } else {
            r = r + 1;
            prioq[r] = job;
        }
    }
}

int main() {
    spq s1, s2;
    int ch;
    do {
        cout << "\n================================Job Queue================================";
        cout
                << "\n1.SimpleQ Add_Job\n2.SimpleQ Del_Job\n3.Show SimpleQ\n4.PrioQ Add_Job\n5.PrioQ Del_Job\n6.Show PrioQ";
        cout << "\nEnter your Choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                s1.simpqadd();
                break;
            case 2:
                s1.delsimpleQ();
                break;
            case 3:
                s1.showsimpleQ();
                break;
            case 4:
                s2.prioqadd();
                break;
            case 5:
                s2.delprioQ();
                break;
            case 6:
                s2.showprioQ();
                break;
        }
    } while (ch != 7);
    return 0;
}
