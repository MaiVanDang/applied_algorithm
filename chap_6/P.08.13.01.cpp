//Geometry compute cross product of 2 vectors
#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

Point O(0, 0), A(0, 0), B(0, 0);

void input() {
    int a, b;
    cin >> a >> b;
    O = Point(a, b); // Initialize point O
    cin >> a >> b;
    A = Point(a, b); // Initialize point A
    cin >> a >> b;
    B = Point(a, b); // Initialize point B
}

void solve() {
    long long xOA = A.x - O.x;
    long long yOA = A.y - O.y;
    long long xOB = B.x - O.x;
    long long yOB = B.y - O.y;

    // Calculate the cross product
    cout << xOA * yOB - xOB * yOA;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solve();
    return 0;
}