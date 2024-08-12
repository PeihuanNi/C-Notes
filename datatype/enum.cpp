#include <iostream>
using namespace std;

int main(){
    enum color{
        red,
        green=5,
        blue
    } a, c;
    a = red;
    c = blue;
    cout << a << ',' << c << endl;
}
