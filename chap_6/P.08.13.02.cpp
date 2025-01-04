//Geometry Intersection 2 segments
#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    Point(): x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}
};

// Tính tích có hướng
int cross_product(Point A, Point B) {
    return A.x * B.y - A.y * B.x;
}

// Tính vector từ A đến B
Point VECTOR(Point A, Point B) {
    return Point(B.x - A.x, B.y - A.y);
}


// Kiểm tra xem hai đoạn AB và CD có giao nhau không
bool check(Point A, Point B, Point C, Point D) {
    // Tính tích có hướng
    int d1 = cross_product(VECTOR(A, B), VECTOR(A, C));
    int d2 = cross_product(VECTOR(A, B), VECTOR(A, D));
    int d3 = cross_product(VECTOR(C, D), VECTOR(C, A));
    int d4 = cross_product(VECTOR(C, D), VECTOR(C, B));
    
    // Kiểm tra giao nhau thông thường
    if (d1 * d2 < 0 && d3 * d4 < 0) return true;

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    while (n--) {
        Point A, B, C, D;
        cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
        cout << (check(A, B, C, D) ? 1 : 0) << '\n';
    }
    return 0;
}
