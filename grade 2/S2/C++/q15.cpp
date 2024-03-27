#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

class MIPS {
private:
    string op, rs, rt, rd;

public:
    MIPS(string _op, string _rs, string _rt, string _rd) : op(_op), rs(_rs), rt(_rt), rd(_rd) {
        if (op == "addi") {
            opTable(op);
            regTable(rt);
            regTable(rs);
            regTable(rd);
        } else {
            opTable(op);
            regTable(rt);
            regTable(rd);
            regTable(rs);
            shamt();
            funct(op);
        }
    }

    void opTable(string op) {
        if (op == "addi") cout << "001000";
        else if (op == "add" || op == "sub" || op == "or" || op == "and") cout << "000000";
    }

    void regTable(const string& input) {
        if (input == "$t0") cout << "01000";
        else if (input == "$t1") cout << "01001";
        else if (input == "$t2") cout << "01010";
        else if (input == "$t3") cout << "01011";
        else if (input == "$t4") cout << "01100";
        else if (input == "$t5") cout << "01101";
        else if (input == "$t6") cout << "01110";
        else if (input == "$t7") cout << "01111";
        else dec2bin(input);
    }

    void dec2bin(const string& dec) {
        int decimal = std::stoi(dec);
        std::bitset<16> binary(decimal);
        cout << binary;
    }

    void shamt() {
        cout << "00000";
    }

    void funct(const string& fun) {
        if (op == "add") cout << "100000";
        else if (op == "sub") cout << "100010";
        else if (op == "or") cout << "100101";
        else if (op == "and") cout << "100100";
    }
};

string removeComma(const string& input) {
    size_t found = input.find(',');
    if (found != std::string::npos) {
        return input.substr(0, found) + input.substr(found + 1);
    }
    return input;
}

int main() {
    string op, rs, rt, rd;
    while (cin >> op >> rs >> rt >> rd) {
        op = removeComma(op);
        rs = removeComma(rs);
        rt = removeComma(rt);
        rd = removeComma(rd);
        MIPS a(op, rs, rt, rd);
        cout << endl;
    }
    return 0;
}
