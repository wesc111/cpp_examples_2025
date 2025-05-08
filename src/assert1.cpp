
#include <cassert>
#include <iostream>
#include <iterator>
#include <format>
#include <ranges>
#include <string>
#include <vector>

void check_properties()
{
    int a=5;
    int b=6;
    assert(a==b);
}

int main() 
{
    check_properties();
}