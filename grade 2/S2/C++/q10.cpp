#include <cmath>
#include <iostream>
#include <string>
using namespace std;

class carlicense {
   public:
    carlicense(int find4) {
        string s = to_string(find4);
        size_t found = s.find("4");

        if (found != string::npos) {
            cout << "Yes";
        } else
            cout << "No";
    }
};

int main() {
    int license;
    cin >> license;
    carlicense mycar(license);
    return 0;
}