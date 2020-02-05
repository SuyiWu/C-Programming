//
//  main.cpp
//  Practice_95_Assignment3
//
//  Created by 吴素仪 on 11/28/19.
//  Copyright © 2019 吴素仪. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;


struct Employee{
    string name;
    string office;
    string phone;
};


ostream& operator<<(ostream& ost, const Employee& pair);

istream& operator>>(istream& ist, Employee& pair);




class Minidir

{
    friend ostream& operator<<(ostream&os, const Minidir& minidir);

    friend istream& operator>>(istream&is, Minidir& minidir);

public:

    bool is_empty() const;

    Employee find(const string&name);

    void add(Employee E);
    
    

private:

    vector<Employee> data;

};

 

ostream& operator<<(ostream& os, const Employee& pair){

    os << pair.name <<" "

       << pair.office << " "

       << pair.phone;

    return os;

}

//operator overloading for Employee

istream& operator>>(istream& is, Employee& pair){

    is >> pair.name

       >> pair.office

       >> pair.phone ;

    return is;

}

 

//Class Implementaion

//add Employee to object under Minidir

void Minidir::add(Employee add){

    data.push_back(add);


}

 

//check if empty

bool Minidir::is_empty() const{

    return(data.size() == 0);

}



//find Employee based on name

Employee Minidir::find(const string& name){
    for (vector<Employee>::const_iterator iter =data.begin() ; iter != data.end(); ++iter)
    if ((iter->name).compare(name) == 0){
       return *iter;
    }
    cout<<"Cannot find this person! "<<endl;
    struct Employee newEmployee;
    return newEmployee;
}

 

//operator overloading for Minidir

ostream& operator<<(ostream& out, const Minidir& minidir){
    for (vector<Employee>::const_iterator iter =minidir.data.begin() ; iter != minidir.data.end(); ++iter)
        out <<" "<< *iter<<" "<<endl;
    return out;
}



//operator overloading for Minidir

istream& operator>>(istream& is, Minidir& minidir){
    bool flag = true;
    while (flag == true){
        cout << "Enter the employee name you want to search "<<endl;
        string name;
        is >> name;
        Employee pair = minidir.find(name);
        cout << "The Employee Find Result is "<<pair<<endl;
        cout << "Do you want to continue? "<<endl;
        string choice;
        cin>>choice;
        if (choice == "Yes"||choice == "yes"|| choice == "YES"){
            flag = true;
        }else{
            flag = false;
        }
    }
    return is;
}




//main

int main(int argc, char** argv){
    Minidir minidir;
    
    cout << "Please enter name of read file: ";
    string iname;
    cin >> iname;
    ifstream ist {iname};
    if (!ist){
        
        cout<<"Can’t open output file!"<<endl;
        return 0;
    }
    
    
    string name, office, phone;
    int i =0;
    while (ist >> name >> office >>phone ) {
        minidir.add({name, office, phone});
        i++;
       }
    
    cout<<"Wheather this document is empty?"<<endl;
    cout<< minidir.is_empty()<<endl;
    
    
    
    if(minidir.is_empty() == 1){
        return 0;
    }
    
    
    cout << "Employee List is "<<endl;
    cout << minidir;
    
    cout << "After Sorting"<<endl;
    
    
    string exit;
    while(exit.compare("exit") !=0&&exit.compare("EXIT") != 0){
        cin >> minidir;
        cout << "Enter 'exit' OR 'EXIT' to quit"<<endl;
        cin >> exit;
    }
    return 0;

}
 

