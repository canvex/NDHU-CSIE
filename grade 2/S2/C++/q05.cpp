#include <iostream>  // 載入與輸出輸入相關
using namespace std;

class seg {
   public:
    bool point(double p1, double p2, double p3, double p4) {
        return (p3 > p1 && p3 < p2) || (p2 > p3 && p2 < p4) ||
               (p4 > p1 && p4 < p2) || (p1 > p3 && p1 < p4);
    }
};

int main() {
    int n1, n2, n3, n4;
    cin >> n1;
    cin >> n2;
    cin >> n3;
    cin >> n4;
    if (n1 > n2)
        swap(n1, n2);
    if (n3 > n4)
        swap(n3, n4);

    seg segment;
    bool ans = segment.point(n1, n2, n3, n4);
    if (ans)
        cout << "overlay" << endl;
    else
        cout << "no overlay" << endl;

    return 0;
}