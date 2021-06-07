//
//  main.cpp
//  Quintic
//
//  Created by Karinne Summers on 6/2/21.
//
// Test program for compiling code with arrays so that the arrays are accessible in Javascript

#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int power = 5;
double roots[5];
    
double fOf(int y[], double x){
    x = y[0]*pow(x,5) + y[1]*pow(x,4) + y[2]*pow(x,3) + y[3]*pow(x,2) + y[4]*x + y[5];
    return x;
}

double fPrimeOf(int y[], double x){
    x = 5*y[0]*pow(x,4) + 4*y[1]*pow(x,3) + 3*y[2]*pow(x,2) + 2*y[3]*x + y[4];
    return x;
}

double findRoot(int arr[], double x0){
    double f, fPrime, x1;
    
    while(abs(fOf(arr, x0)) > 0.00001){
        f = fOf(arr, x0);
        fPrime = fPrimeOf(arr, x0);
        x1 = x0 - (f/fPrime);
        x0 = x1;
    }
    return x0;
}

int main() {
    cout <<"This program solves for the real roots of a quintic of the form:\n" <<
    "ax^5 + bx^4 + cx^3 + dx^2 +ex + g"<< endl;
    //int a=1, b=-3, c=-23, d=51, e=94, f=-120;
    int a, b, c, d, e, g;
    cout <<"Enter the first coefficient (a): ";
    cin >> a;
    cout <<"Enter the second coefficient (b): ";
    cin >> b;
    cout <<"Enter the third coefficient (c): ";
    cin >> c;
    cout <<"Enter the fourth coefficient (d): ";
    cin >> d;
    cout <<"Enter the fifth coefficient (e): ";
    cin >> e;
    cout <<"Enter the final constant (g): ";
    cin >> g;
    
    int vars[6] = {a,b,c,d,e,g};
    
    //finding the power of the quintic
    /*for(int i=0; i<6; i++){
        if(vars[i] != 0){
            break;
        } else {
            --roots.power;
        }
    }*/
    //creating an array to hold the roots sized by the power of the polynomxial
   
    
    //initializing the roots array with the basic case: not real roots
    for(int i=0; i<power; i++){
        roots[i] = -0;
    }

    cout <<"\nYour polynomial: " << a << "x^5 + "<< b<< "x^4 + "<< c<< "x^3 + "<< d<<
    "x^2 + "<< e<<"x + "<< vars[5]<< "\n" << endl;
    
    //counter for what number root we have found
    int rootnum = 0;
    
    double k=0, j=0;
    for(double l = (-1)*abs(vars[5]) - 0.0001, i = (-1)*abs(vars[5]) + 0.9999;
        i < abs(vars[5]) + 1.9999; l++, i++){
        j = fOf(vars, l);
        k = fOf(vars, i);
        
        if(j*k <= 0){
            if (fPrimeOf(vars,i) != 0) {
                roots[rootnum] = findRoot(vars,l);
                rootnum++;
            }
        } else if (abs(j) < 0.00001 && fPrimeOf(vars,i)*fPrimeOf(vars,l) <= 0) {
            roots[rootnum] = findRoot(vars,l);
            rootnum++;
        }
    }
    
    for (int count = 0; count <power; count++){
        cout <<"ROOT: " << roots[count] <<endl;
    }
    
    cout << "DONE" << endl;
}


extern "C"{
    double getRoot(int i){
        return roots[i];
    }
}



