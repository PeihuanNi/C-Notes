#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main(){
    srand(static_cast<uint>(time(NULL)));
    for (int i=0; i<10; i++){
        cout << rand() << endl;
    }
    return 0;
}
