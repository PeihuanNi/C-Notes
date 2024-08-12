#include<iostream>

using namespace std;

class Initiator {
public:
    int sendTransaction(int data) {
        // 发送数据事务
		int send_data = data;
        cout << "Sending data: " << send_data << endl;
		return send_data;
    }
};

class Target {
public:
    int receiveTransaction(int data) {
        // 接收数据事务
		int received_data = data;
        cout << "Received data: " << received_data << endl;
   		return received_data;
   }
};

int main() {
    Initiator initiator;
    Target target;
    
    int data = 42;
	int send_data;
	int received_data;
    send_data = initiator.sendTransaction(data);
    received_data = target.receiveTransaction(send_data);
    
    return 0;
}
