#include <iostream>  // 載入與輸出輸入相關
using namespace std;

class velocity {
   public:
    double speed(double distance, double time) { return distance / time; }
};

int main() {
    float x, y;
    cin >> x >> y;
    velocity v;
    cout << v.speed(x, y);

    return 0;
}