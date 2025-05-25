// Copyright Werner Schoegler
// 21-May-2025

#include "myfunc.hpp"

int myfunc::factorial(int number) 
{
   // return number <= 1 ? number : Factorial( number - 1 ) * number;  // fail
   return number <= 1 ? 1      : factorial( number - 1 ) * number;  // pass
}

uint64_t myfunc::fiboRecursive(int n)
{
    uint64_t f;
    if (n==0) {
        f = 0;
    }
    else if (n==1) {
        f = 1;
    }
    else {
        f = (fiboRecursive(n-2) + fiboRecursive(n-1));
    }
    return f;
}

uint64_t myfunc::fibo(int n)
{
    uint64_t previous=0, last=0, buf;

    for (uint64_t i=0; i<=n; i++) {
        if (i==0) {
            last = 0;
        }
        else if (i==1) {
            last = 1;
            previous = 0;
        }
        else {
            buf = last;
            last = previous + last;
            previous = buf;
        }
    }
    return last;
}