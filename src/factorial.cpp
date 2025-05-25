// an example class containing some functions
// WSC, 21-May-2025

class myfunc {
    int factorial(int number);
};

int myfunc::factorial(int number) 
{
   // return number <= 1 ? number : Factorial( number - 1 ) * number;  // fail
   return number <= 1 ? 1      : factorial( number - 1 ) * number;  // pass
}
