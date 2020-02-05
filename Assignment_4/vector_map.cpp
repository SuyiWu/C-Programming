//
//  main.cpp
//  Assignment4
//
//  Created by 吴素仪 on 12/13/19.
//  Copyright © 2019 吴素仪. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    // map of vectors where the key of the map is of type string
    map<string, vector<int>> mp;
    map<string, int> total_hours;
    
    string name;
    int hours;
    
    int all_hour[5];
    
    //Total five weekdays a week
    for(int i = 1; i<= 5;i++){
        cout<<"Day " << i << endl;
        all_hour[i-1]=0;
        
        string choice;
        cout<<"Is any people work today? (Y/N)\n";
        cin>>choice;
        
        while(choice == "Y" || choice == "y" || choice == "yes"|| choice == "Yes"){
            // Ask the user for their name and the hours they worked for that day.
            cout<<"Enter name and the hours for this day: \n";
            cin>> name;
            cin>> hours;
            // If Person's name not on the map
            // Add a new key and put before days with 0 hours
            // if a new employee comes along, we should make sure we skip the previous slots in that vector.
            if(mp.find(name) == mp.end()){
                vector<int> vt(i-1,0);
                //insert person's each work hour in vector of map
                mp.insert(pair<string, vector<int>>(name, vt));
                mp[name].push_back(hours);
                //insert person's day work hour in int of map
                total_hours.insert(pair<string, int>(name, 0));
                total_hours[name] += hours;
                //calculate each day total work hour for all people
                all_hour[i-1] += hours;
                
            }else{
                //If the user already inputted the hours for a particular day, they can not change their hours again.
                if(mp[name].size() == i){
                    // Write a message telling the user they already inputted the hours.
                    cout << "You have already inputted the hours, and you cannot change your hours again\n";
                }else{
                    if (mp[name].size() <(i-1)){
                        for(int j=(mp[name].size()+1); j<i; j++){
                            mp[name].push_back(0);
                        }
                    }
                    // After add all 0s, add this person's latest work hour this day
                    mp[name].push_back(hours);
                    total_hours[name] += hours;
                    all_hour[i-1] += hours;
                }
            }
            
            
            string yes;
            cout << "Are you finished all the info input? Please enter the (Y/N) \n";
            cin >> yes;
            if(yes == "Y" || yes == "y" || yes == "yes"|| yes == "Yes"){
                 break;
            }
        }
        if(i!=5){
            cout << "Next day \n" << endl;
        }
        
    }
    //7) At the end of the week (Friday). Calculate, the total hours worked per person and total hours worked per day and terminate the program.
    
    
    cout << "Total hours worked per person ---------------------" << endl;
    for(auto iter = total_hours.begin(); iter != total_hours.end(); ++iter){
        cout << iter->first << ": " << iter->second << endl;
    }
    
      
    cout << "Total hours worked per day ---------------------" << endl;
    for(int i=0; i<5; i++){
        cout << "Day " << i+1 << ": " << all_hour[i] << endl;
    }
    return 0;
}

