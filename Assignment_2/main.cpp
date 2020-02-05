//
//  main.cpp
//  Assignment 2
//
//  Created by 吴素仪 on 10/12/19.
//  Copyright © 2019 Yuwen_Wu. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


// function declarations

void solve_linear(double b, double c);

void solve_quadratic(double a, double b, double c);

int main()

{

// input the coefficients of the polynomial
    
    double a, b, c; // coefficients of the polynomial
    cout << "Please enter the coefficients of a quadratic equation a*x**2 + b*x + c:" << endl;
    cin >> a>>b>>c;
    // figure out the rest yourself!!
    // handle degenerate case (linear equation) and quit

    if (a == 0) // linear equation, not quadratic
        solve_linear(b, c);
    else // genuine quadratic equation ... forge ahead
        solve_quadratic(a, b, c);
    return 0;
}

// solve the linear equation b*x + c == 0

void solve_linear(double b, double c)

{
    cout << "Trying to solve linear equation "<< b << "*x + " << c << " == 0\n";
    // figure out the rest yourself!
    if (b == 0 && c != 0)
        //Check for A contradiction
    cout << "This is a contradictory statement " << c << " == 0."<< endl;
    else if (b == 0 && c == 0)
        //Check for a 0 == 0 identitiy
    cout << "This is an identity statement : 0 == 0." << endl;
        //Find the solution for linear equation
        //When c == 0 and b != 0
    else if(b != 0 && c == 0)
        cout << "Linear Equation, root: x = 0." << endl;
    else
    {
        double x  = -c/b;
        cout << "Linear Equation, root: x = " << x << endl;
    }
}

// use classical quadratic formula to solve a genuine quadratic equation

// a*xˆ2 + b*x + c ==0, with a != 0

void solve_quadratic(double a, double b, double c)

{
    cout << "Trying to solve the quadratic equation "<< a << "*x*x + " << b << "*x + " << c << " == 0\n";

    // figure out the rest yourself!
    double discriminant = (b*b)-(4*a*c);
    if (discriminant < 0)
    
    {
    //If the funtion has no real roots notify the user and close the program
        cout << "No real roots." << endl;
    }
    else if(discriminant == 0)
    
    {
    //Variable declaration for single and double root funtions
        double same_root = 0;
    //Determine if the funtion has one or two real roots
        same_root = -b/(2*a);
        cout << "One double root, x = " << same_root<< endl;
    }
        
    else
    
    {
        double root_1 = 0;
        double root_2 = 0;
        //Calculate the first root of the funtion
        root_1 = (-b + sqrt(discriminant))/(2*a);
        //Calculate the second root of the funtion
        root_2 = (-b - sqrt(discriminant))/(2*a);
        //Print the funtion and both roots

        cout << "Two Roots, x = " << root_2 << " and x = " << root_1 << endl;

    }

}
