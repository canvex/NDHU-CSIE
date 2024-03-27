#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class numbers{
private:
    vector<int> num;
    int n;

public:
    void insert(){
        cin >> n;
        num.resize(n);
        for(int i = 0; i < n; i++)
            cin >> num[i];
    }

    int revInt(int a){
        string tmp = to_string(a);
        reverse(tmp.begin(), tmp.end());
        a = stoi(tmp);
        return a;
    }

    bool same(int a){
        string s1 = to_string(a);
        string s2 = s1;
        reverse(s1.begin(), s1.end());
        return s1 == s2;
    }

    void procedure(){
        for(int i = 0; i < n; i++){
            int time = 0;
            int sum = num[i];
            do {
                sum += revInt(sum);
                time++;
            } while(!same(sum));
            cout << time << " " << sum << endl;
        }
    }
};

int main() {
    numbers a;
    a.insert();
    a.procedure();
    return 0;
}
