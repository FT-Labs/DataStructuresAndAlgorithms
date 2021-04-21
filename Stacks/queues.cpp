/*
Author: Arda
Company: PhysTech
Date: 9/26/20
*/
#include  <iostream>
#include <queue>

using namespace std;


void showQueue(queue<int> s) {
    while (!s.empty()) {
        cout << '\t' << s.front();
        s.pop();
    }
}


int main() {
    queue<int> q;

    q.push(10);
    q.push(23);
    q.push(-3);
    q.push(44);

    cout << "The queue is: ";
    showQueue(q);

    return 0;


}