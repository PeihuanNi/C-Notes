#include <iostream>

using namespace std;

extern int max(int num1, int num2 = 20);

int main(){
    int in1, in2;
    cin >> in1 >> in2;

    cout << max(in1) << endl;
    return 0;
}
