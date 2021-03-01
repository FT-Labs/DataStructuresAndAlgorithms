/*
Author: Arda
Company: PhysTech
Date: 9/26/20
*/
#include  <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Job{
    char id; //or int id doesnt matter
    int dead; //deadline for job
    int profit; //profit for job
};



//This function is used to sort all the jobs in descending order
bool comparison(Job a,Job b)
{
    return (a.profit > b.profit);
}

//Returns min number of platforms
void jobScheduling(Job arr[],int n)
{
    //Sort all jobs using the helper function
    sort(arr,arr+n,comparison);

    int result[n]; //To store result jobs
    bool slot[n]; //To keep track of free time slots

    //Initialize all slots
    for(int i=0;i<n;++i)
        slot[i] = false;

    for(int i=0;i<n;++i)
    {
        //Find a free slot (Starting from last possible job)
        for(int j=min(n,arr[i].dead)-1;j>=0;--j)
        {
            //Free slot
            if(slot[j]== false)
            {
                result[j] = i;  //Add slot to result
                slot[j] = true; //Make slot occupied
                break;
            }
        }
    }

    for(int i=0;i<n;++i)
        if(slot[i])
            cout << arr[result[i]].id << ' ';
}


int main() {
    Job arr[] = {{'a',1,1000} , {'b',2,2000},{'c',2,500},{'d',0,1200}};
    int n = sizeof(arr)/sizeof(arr[0]);
    jobScheduling(arr,n);
    return 0;
}
