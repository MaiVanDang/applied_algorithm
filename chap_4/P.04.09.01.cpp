//Chapter 4 - TSP
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n; // Number of cities
vector<vector<int>> c; // Distance matrix
vector<int> x; // Current permutation (tour)
vector<bool> visited; // Visited cities
int currentCost = 0; // Current cost of the tour
int bestCost = INT_MAX; // Minimal cost found
vector<int> bestTour; // Best tour found

// Check function to validate a partial tour
bool check(int city, int k) {
    return !visited[city];
}

// Backtracking function to find the optimal tour
void tryTour(int k) {
    for (int city = 1; city <= n; city++) {
        if (check(city, k)) {
            x[k] = city;
            visited[city] = true;
            currentCost += c[x[k - 1]][city];

            if (k == n) {
                // Complete the tour and calculate cost
                int totalCost = currentCost + c[city][x[1]];
                if (totalCost < bestCost) {
                    bestCost = totalCost;
                    bestTour = x;
                }
            } else {
                // Continue exploring
                if (currentCost < bestCost) {
                    tryTour(k + 1);
                }
            }

            // Backtrack
            visited[city] = false;
            currentCost -= c[x[k - 1]][city];
        }
    }
}

int main() {
    cin >> n;
    c.resize(n + 1, vector<int>(n + 1));
    x.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }

    // Initialize the tour starting from city 1
    x[1] = 1;
    visited[1] = true;
    tryTour(2);

    // Output the result
    cout << bestCost << endl;

    return 0;
}