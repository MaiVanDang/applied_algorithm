//Geometry check point on a segment
#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    Point(): x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}
};

bool onSegment(Point A, Point B, Point C) {
    // Kiểm tra điểm B có nằm trong hình chữ nhật bao quanh AC
    return (B.x <= max(A.x, C.x) && B.x >= min(A.x, C.x) &&
            B.y <= max(A.y, C.y) && B.y >= min(A.y, C.y));
}

int orientation(Point A, Point B, Point C) {
    // Tính tích có hướng để tránh tràn số
    long long val = (long long)(B.y - A.y) * (C.x - B.x) - 
                   (long long)(B.x - A.x) * (C.y - B.y);
    
    if (val == 0) return 0;     // Thẳng hàng
    return (val > 0) ? 1 : 2;   // 1: rẽ phải, 2: rẽ trái
}

int check(Point A, Point B, Point C) {
    // Kiểm tra thẳng hàng và nằm trong đoạn
    int o = orientation(A, B, C);
    return (o == 0 && onSegment(A, B, C)) ? 1 : 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    while (n--) {
        Point A, B, C;
        cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
        cout << check(B, A, C) << '\n';
    }
    return 0;
}