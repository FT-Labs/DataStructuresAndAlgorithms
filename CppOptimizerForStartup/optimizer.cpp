/*
Author: Arda
Company: PhysTech
Date: 10/1/20
*/
#include  <iostream>
int start_up() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}

int static r = start_up();

#define endl '\n';

//If cin.tie() is used, you need to manually flush cout << flush everytime if you want it to be visible on screen
