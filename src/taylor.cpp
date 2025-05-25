// a first test to check how copilot is working in visual studio code
// calculation of sin(x) using Taylor series expansion
// Werner Schoegler, 25-May-2025

#include <iostream>
#include <cmath>

#include "taylor.hpp"

double taylor::factorial(double n) {
    if (n <= 1) return 1.0; // base case
    double result = 1.0;
    for (double i = 2; i <= n; ++i) {
        result *= i; // calculate factorial iteratively
    }
    return result;
}
double taylor::sin(double x) {
    double prod = 0.0, retVal = 0.0;
    double exp = 1.0;
    for (int i=0; i<50; i++) {
        prod = std::pow(x,exp)/factorial(exp); // calculate x^exp / exp!
        exp=exp+2.0;
        if (i % 2 == 1) {
            prod = -prod; // alternate signs
        }
        retVal += prod; // accumulate the result
        if (debugFlag)
            std::cout << "i=" << i << " exp=" << exp  << " prod=" << prod << " retVal=" << retVal << "\n";
        if (fabs(prod) < 1e-10 && fabs(retVal) < 1e-10) {
            std::cout << "Term is very small, stopping early.\n";
            break; // stop if the term is very small
        }
    }
    return retVal; // return the final result
}

int main()
{
    taylor ts;
    double x=0.0, result;
 
    for (int i = 0; i < 20; ++i) {
        result = ts.sin(x);
        std::cout << "sin(" << x << ") = " << result << "    math.sin(" << x << ") = " << sin(x) << " err = " << result - sin(x) << "\n";       
        x += 0.5; // increment x for demonstration
    }

    return 0;
}