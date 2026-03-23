#include <iostream>
#include <vector>
using namespace std;

// Class for each person
class Person {
public:
    bool knowsRumor;           // does person know rumor?
    vector<int> neighbors;     // connections

    Person() {
        knowsRumor = false;
    }
};

// Class for rumor engine
class RumorEngine {
public:
    vector<Person> people;

    // create people
    RumorEngine(int n) {
        people.resize(n);
    }

    // connect two people
    void connect(int a, int b) {
        people[a].neighbors.push_back(b);
        people[b].neighbors.push_back(a);
    }

    // start rumor
    void startRumor(int source) {
        people[source].knowsRumor = true;
    }

    // spread rumor
    void spreadRumor() {
        vector<bool> temp(people.size());

        // copy current state
        for (int i = 0; i < people.size(); i++) {
            temp[i] = people[i].knowsRumor;
        }

        // spread to neighbors
        for (int i = 0; i < people.size(); i++) {
            if (people[i].knowsRumor) {
                for (int j : people[i].neighbors) {
                    temp[j] = true;
                }
            }
        }

        // update state
        for (int i = 0; i < people.size(); i++) {
            people[i].knowsRumor = temp[i];
        }
    }

    // display result
    void display(int step) {
        cout << "Step " << step << ": ";
        for (int i = 0; i < people.size(); i++) {
            if (people[i].knowsRumor)
                cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    RumorEngine r(4);

    // connections
    r.connect(0, 1);
    r.connect(1, 2);
    r.connect(2, 3);

    // start rumor
    r.startRumor(0);

    // simulate steps
    for (int i = 0; i < 4; i++) {
        r.display(i);
        r.spreadRumor();
    }

    return 0;
}