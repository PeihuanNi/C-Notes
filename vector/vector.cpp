#include <iostream>
#include <vector>
using namespace std;
int main(){
    std::vector<int> myVector(5, 10);
    std::vector<int>::iterator ptr = myVector.begin();
    for(; ptr != myVector.end(); ptr++) cout << *ptr << " ";
    cout << endl;
    return 0;
}