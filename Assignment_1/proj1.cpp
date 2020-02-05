//
//  main.cpp
//  Assignment_1
//
//  Created by Yuwen Wu on 9/20/19.
//  Copyright © 2019 Yuwen_Wu. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    // insert code here...
    int total_coin;
    total_coin=1;
    while(total_coin!=0)
{
    cout<<"Enter the number of coins you have for each denomination.\n";
    cout<<"Pennies?\n";
    int pennies;
    cin>>pennies;
    cout<<"Nickels?\n";
    int nickels;
    cin>>nickels;
    cout<<"Dimes?\n";
    int dimes;
    cin>>dimes;
    cout<<"Quarters?\n";
    int quarters;
    cin>>quarters;
    cout<<"Half dollars?\n";
    int half_dollars;
    cin>>half_dollars;
    pennies = pennies * 1;
    nickels = nickels * 5;
    dimes = dimes * 10;
    quarters = quarters * 25;
    half_dollars = half_dollars * 50;
    total_coin = pennies + dimes + nickels + quarters + half_dollars;
    cout<< "The value of all your coins is "<< total_coin<<" cents\n";
}
    return 0;
}
