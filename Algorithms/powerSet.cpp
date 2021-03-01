/*
Author: Arda
Company: PhysTech
Date: 9/28/20
*/
#include  <iostream>
#include <math.h>

void printPowerSet(int *nums,int size)
{

    unsigned int pow_set_size  = pow(2,size);
    int counter,j;

    for(counter = 0; counter<pow_set_size;++counter)
    {
        for(j = 0;j<size;++j)
        {
            //Check if jth bit in the counter is set, if set then print jth element from set
            if(counter & (1<<j))
                std::cout << nums[j];
        }
        std::cout << std::endl;
    }
}


int main() {
    int nums[] = {1,2,7,6,5,4,3};
    printPowerSet(nums,7);
    return 0;
}
