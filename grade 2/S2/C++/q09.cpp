#include <cmath>
#include <iostream>
using namespace std;

class price {
   public:
    price(float km) {
        float ans = 0;
        if (km > 200) {
            ans = round((km - 200) * 1.2 * 0.75 + 200 * 1.2);
        } else {
            ans = round(km * 1.2);
        }
        cout << ans;
    }
};

int main() {
    float km;
    cin >> km;
    price a(km);
    return 0;
}