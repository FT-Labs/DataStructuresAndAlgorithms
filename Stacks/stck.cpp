/*
Author: Arda
Company: PhysTech
Date: 9/26/20
*/
#include  <iostream>
#include <bits/stdc++.h>
using namespace std;



void showstack(stack<int> s)
{
    while(!s.empty())
    {
        int top = s.top();
        s.pop();
        cout << '\t' << top;
    }
}

int main() {



    stack<int> s;
    s.push(10);
    s.push(23);
    s.push(34);
    s.push(5);
    s.push(1);

    cout << "Stack is:";
    showstack(s);



    return 0;
}




