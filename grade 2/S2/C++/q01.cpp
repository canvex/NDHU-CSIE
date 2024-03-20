#include <iostream>

using namespace std;

class Point {
   public:
    float x;  // X 座標
    float y;  // Y 座標

    Point(float xCoord, float yCoord) : x(xCoord), y(yCoord) {}  // 建構子
};

int main() {
    int N;
    float x, y;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x;
        cin >> y;
        Point p(x, y);  // 使用者輸入的座標
        cout << "(" << p.x << ", " << p.y << ")" << endl;
    }
    return 0;
}