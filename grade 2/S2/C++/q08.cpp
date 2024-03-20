#include <cmath>
#include <iostream>
#include <unordered_set>
using namespace std;

bool operator==(Point a, Point b) {
    return (a.getX() == b.getX() && a.getY() == b.getY());
}

class Path {
   public:
    Path(Segment* arr, int n) {
        double length = arr[0].length();
        bool legal = true;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i].getEnd(0) == arr[i + 1].getEnd(0))
                length += arr[i + 1].length();
            else if (arr[i].getEnd(0) == arr[i + 1].getEnd(1))
                length += arr[i + 1].length();
            else if (arr[i].getEnd(1) == arr[i + 1].getEnd(0))
                length += arr[i + 1].length();
            else if (arr[i].getEnd(1) == arr[i + 1].getEnd(1))
                length += arr[i + 1].length();
            else {
                legal = false;
                break;
            }

            // Check for duplicate nodes
            for (int j = 0; j < i; j++) {
                if (arr[i + 1].getEnd(0) == arr[j].getEnd(0) ||
                    arr[i + 1].getEnd(0) == arr[j].getEnd(1) ||
                    arr[i + 1].getEnd(1) == arr[j].getEnd(0) ||
                    arr[i + 1].getEnd(1) == arr[j].getEnd(1)) {
                    legal = false;
                    break;
                }
            }
        }
        if (legal)
            cout << length;
        else
            cout << "-1";
    }
};