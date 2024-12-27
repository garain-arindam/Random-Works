#include <iostream>
#include <string>
#include <bitset>
using namespace std;
int main() {
    // Write C++ code here
    string code = string();

    bitset<16> opCode2(0x3f00);
    bitset<16> opBits(0xfc00);
    code = ((opCode2&opBits).to_string()).substr(0,8);

    cout << "code: " << code;
    return 0;
}