#include <iostream>

using namespace std;

int main(){
    int8_t a = 65;
    int8_t b = 1;
    signed char a_c = 65;
    signed char b_c = 1;
    int8_t c = a + b;
    signed char c_c = a_c + b_c;
    cout << static_cast<int>(c) << "," << c_c << endl;
    return 0;
}