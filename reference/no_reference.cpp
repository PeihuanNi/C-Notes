#include <iostream>
using namespace std;
void swap(int x, int y);

int main(){
    int A = 200;
    int B = 100;
    swap(A, B);
    cout << A << ", " << B << endl;
    return 0;
}

void swap(int x, int y){
    int temp = x;
    x = y;
    y = temp;
}