/*
Author: Arda
Company: PhysTech
Date: 9/29/20
*/
#include  <iostream>
#include <bits/stdc++.h>
#include <deque>
using namespace std;

void printKMax(int arr[],int n, int k)
{

    deque<int> Qd;

    //Process first window of k
    int i;
    for(i = 0;i<k;++i)
    {
        //For every element, previous smaller elements are useless dispose of them
        while ((!Qd.empty()) && arr[i]>=arr[Qd.back()])
            Qd.pop_back();

        Qd.push_back(i);
    }

    //Processing rest of the elements, through k to n-1
    for(;i<n;++i)
    {
        cout << arr[Qd.front()] << ' ';


        while((!Qd.empty()) && Qd.front()<=i-k)
        {
            //Remove all elements from the previous batch
            Qd.pop_front(); //R
        }

        //Again removing useless elements
        while((!Qd.empty()) && arr[i]>=arr[Qd.back()])
        {
            Qd.pop_back();
        }

        Qd.push_back(i);

    }
    //Print largest element from the last batch
    cout << arr[Qd.front()];

}





int main() {

   int arr[] =  { 12, 1, 78, 90, 57, 89, 56 };
   int n = sizeof(arr)/sizeof(arr[0]);
   int k = 3;
   printKMax(arr,n,k);


   return 0;


}

