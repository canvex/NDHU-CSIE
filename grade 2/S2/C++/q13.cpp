#include <iostream>
#include <vector>
using namespace std;

class matrix {
   private:
    vector<vector<int>> map;
    int n;
    int input;

   public:
    void scan() {
        map.clear();
        cin >> n;
        for (int i = 0; i < n; ++i) {
            vector<int> row;
            for (int j = 0; j < n; ++j) {
                cin >> input;
                row.push_back(input);
            }
            map.push_back(row);
        }
    }
    void printMatrix() {
        if (map.empty())
            printf("No element in matrix can be printed.\n");
        else {
            for (auto row : map) {
                for (auto val : row) {
                    printf("%d ", val);
                }
                printf("\n");
            }
            printf("\n");
        }
    }
    void right() {
        if (map.empty())
            printf("No element in matrix can be rotated.\n");
        else {
            vector<vector<int>> map2(
                n,
                vector<int>(n, 0));  // 建立一個和原始 map 同樣大小的新向量 map2
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    map2[j][n - i - 1] = map[i][j];
                }
            }
            map = map2;
        }
    }
    void left() {
        if (map.empty())
            printf("No element in matrix can be rotated.\n");
        else {
            vector<vector<int>> map2(n, vector<int>(n, 0));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    map2[j][i] = map[i][n - j - 1];
                }
            }
            map = map2;
        }
    }
};

int main() {
    string cmd;
    matrix m;
    while (getline(cin, cmd)) {
        if (cmd == "stop")
            break;
        else if (cmd == "scan") {
            m.scan();
            cin.ignore();  // 忽略換行符號
        } else if (cmd == "rotate right")
            m.right();
        else if (cmd == "rotate left")
            m.left();
        else if (cmd == "print")
            m.printMatrix();
        else
            printf("unknown\n");
    }

    return 0;
}
