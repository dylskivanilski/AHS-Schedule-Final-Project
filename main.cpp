#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <chrono>
#include <cstdlib>

using namespace std;

struct Assignment {
    string name;
    int daysLeft;
    int points;
    int hours;
    int progress;
    double score;
};

// Calculates priority using deadline, points, time, and progress.
// Higher score means higher priority.
double calculateScore(const Assignment& a, int maxPoints, int maxHours) {
    double urgency = 1.0 / a.daysLeft;
    double value = (double)a.points / maxPoints;
    double timeCost = (double)a.hours / maxHours;
    double progressBonus = (double)a.progress / 100.0;

    return (0.25 * urgency)
         + (0.45 * value)
         - (0.10 * timeCost)
         + (0.20 * progressBonus);
}

bool compareScore(const Assignment& a, const Assignment& b) {
    return a.score > b.score;
}

void rankAssignments(vector<Assignment>& assignments) {
    int maxPoints = 1;
    int maxHours = 1;

    for (const auto& a : assignments) {
        maxPoints = max(maxPoints, a.points);
        maxHours = max(maxHours, a.hours);
    }

    for (auto& a : assignments) {
        a.score = calculateScore(a, maxPoints, maxHours);
    }

    sort(assignments.begin(), assignments.end(), compareScore);
}

void printAssignments(const vector<Assignment>& assignments) {
    for (int i = 0; i < assignments.size(); i++) {
        cout << i + 1 << ". " << left << setw(18) << assignments[i].name
             << " Score: " << fixed << setprecision(4)
             << assignments[i].score << endl;
    }
}

void runTestCase(string title, vector<Assignment> assignments) {
    cout << "\n" << title << endl;
    cout << "-----------------------------" << endl;

    rankAssignments(assignments);
    printAssignments(assignments);
}

void runtimeTest(int n) {
    vector<Assignment> assignments;

    for (int i = 0; i < n; i++) {
        Assignment a;
        a.name = "Assignment" + to_string(i);
        a.daysLeft = (rand() % 30) + 1;
        a.points = (rand() % 200) + 1;
        a.hours = (rand() % 20) + 1;
        a.progress = rand() % 101;
        a.score = 0;
        assignments.push_back(a);
    }

    auto start = chrono::high_resolution_clock::now();
    rankAssignments(assignments);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> elapsed = end - start;

    cout << "n = " << setw(6) << n
         << " Runtime: " << elapsed.count() << " ms" << endl;
}

int main() {
    cout << "Adaptive Homework Scheduler (AHS)" << endl;
    cout << "=================================" << endl;

    vector<Assignment> test1 = {
        {"Essay", 2, 100, 5, 20, 0},
        {"Quiz", 1, 20, 1, 0, 0},
        {"Project", 5, 200, 10, 50, 0}
    };

    vector<Assignment> test2 = {
        {"Research Paper", 4, 250, 12, 80, 0},
        {"Homework", 2, 20, 1, 0, 0},
        {"Presentation", 6, 100, 4, 50, 0}
    };

    vector<Assignment> test3 = {
        {"Lab", 1, 50, 2, 90, 0},
        {"Essay", 5, 100, 8, 20, 0},
        {"Quiz", 2, 25, 1, 0, 0}
    };

    runTestCase("Test Case 1: Urgency vs Value", test1);
    runTestCase("Test Case 2: Progress and Value", test2);
    runTestCase("Test Case 3: Near Deadline", test3);

    cout << "\nRuntime Measurements" << endl;
    cout << "-----------------------------" << endl;

    runtimeTest(100);
    runtimeTest(1000);
    runtimeTest(10000);
    runtimeTest(50000);

    return 0;
}
