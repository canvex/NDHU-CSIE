#include <iostream>
using namespace std;

class Point {
   private:
    float x, y;

   public:
    Point(float x1, float y1) : x(x1), y(y1){};
    float getX() { return x; }
    float getY() { return y; }
};

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        float x, y;
        cin >> x >> y;
        Point p(x, y);
        cout << "(" << p.getX() << ", " << p.getY() << ")\n";
    }
    return 0;
}