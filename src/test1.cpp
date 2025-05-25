// test1.cpp: showing behavior of std::remove_if() and std::drop_while() and std::filter()
//            which are all part of the ranges include

#include <cassert>
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

void trial1() {
    auto v = vector{ 0,1,2,3,4,5 };

    // remove_if does not remove elements, but shunts elements to the start of the collection
    // and gives back a new_end showing where the vector ends
    auto new_end = std::remove_if(v.begin(),v.end(), [](int i) {return i < 3; });
    
    // solution with error: unexpected result, as new end is not taken into account
    for (int n : v) {
        cout << n << ' ';
    }
    cout << '\n';
    // correct solution: taking new end into account
    for (auto it = v.begin(); it != new_end; ++it) {
        cout << *it << ' ';
    }
    cout << '\n';

    // preferred (alternative) solution: 
    // use drop_while, this drops elements and you don't need to care about a new end
    auto v2 = vector{ 0,1,2,3,4,5 };
    for (int n : v2 | std::views::drop_while([] (int i) {return i < 3; }))
    {
        cout << n << ' ';
    }
    cout << '\n';

    // filter out all negatives in vector
    auto n1 = vector{ 0,1,2,-1,-2,-3};
    // define lambda function named negative
    auto negative = [] (int i) {return i < 0; };
    // find all negatives inside of n1
    auto negatives = n1 | std::views::filter(negative);
    for (int n : negatives)
    {
        cout << n << ' ';
    }
    cout << '\n';
    // check that there are negatives found
    assert(!negatives.empty());
}

int main() {
    trial1();
    return 0;
}