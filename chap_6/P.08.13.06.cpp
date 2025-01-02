//Geometry check points inside convex hull
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

struct Point {
    int x, y;
    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}
};

vector<Point> hull;
Point points[N];
Point origin;

long long dist2(const Point& a, const Point& b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    return dx * dx + dy * dy;
}

long long cross_product(const Point& O, const Point& A, const Point& B) {
    long long xa = A.x - O.x;
    long long ya = A.y - O.y;
    long long xb = B.x - O.x;
    long long yb = B.y - O.y;
    return xa * yb - ya * xb;
}

bool compare(const Point& A, const Point& B) {
    long long cp = cross_product(origin, A, B);
    return cp == 0 ? dist2(origin, A) < dist2(origin, B) : cp > 0;
}

int orientation(const Point& a, const Point& b, const Point& c) {
    long long cp = cross_product(a, b, c);
    if (cp == 0) return 0;    // collinear
    return (cp < 0) ? -1 : 1; // clockwise : counter-clockwise
}

bool sameSide(const Point& a, const Point& b, const Point& c, const Point& d) {
    int oc = orientation(a, b, c);
    int od = orientation(a, b, d);
    return oc * od >= 0;
}

void buildConvexHull(Point* points, int n) {
    hull.clear();
    
    // Find bottommost point (leftmost if tied)
    int k = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y < points[k].y || 
            (points[i].y == points[k].y && points[i].x < points[k].x)) {
            k = i;
        }
    }
    
    swap(points[0], points[k]);
    origin = points[0];
    
    // Sort points by polar angle
    sort(points + 1, points + n, compare);
    
    // Build hull
    hull.push_back(points[0]);
    hull.push_back(points[1]);
    
    for (int i = 2; i < n; i++) {
        while (hull.size() > 1 && 
               orientation(hull[hull.size()-2], hull.back(), points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
}

bool pointInConvexHull(const vector<Point>& poly, const Point& p) {
    int n = poly.size();
    if (!sameSide(poly[0], poly[1], poly[n-1], p)) return false;
    if (!sameSide(poly[0], poly[n-1], poly[1], p)) return false;
    
    int left = 1, right = n - 1;
    while (right - left > 1) {
        int mid = (left + right) >> 1;
        if (sameSide(poly[0], poly[mid], poly[n-1], p)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    
    return sameSide(poly[left], poly[right], poly[0], p);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    
    buildConvexHull(points, n);
    
    bool isValidHull = (hull.size() == n);
    
    int k;
    cin >> k;
    
    while (k--) {
        int x, y;
        cin >> x >> y;
        Point p(x, y);
        cout << (isValidHull && pointInConvexHull(hull, p)) << '\n';
    }
    
    return 0;
}