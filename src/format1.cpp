// some trials to use format library available at
// https://fmt.dev/latest/index.html
// https://github.com/fmtlib/fmt
// with Format string syntax similar to Python's format
//
// cheat sheet: https://hackingcpp.com/cpp/libs/fmt.html
// WSC, 8-May-2025

#include <format>
#include <fmt/format.h>
#include <iostream>

int main() {
    int element = 3214;

    auto str = std::format("->{:d}<-", element);
    std::cout << str << '\n';
    str = std::format("->{: ^8}<-", element);
    std::cout << str << '\n';
    str = std::format("->{: <8}<-", element);
    std::cout << str << '\n';
    str = std::format("->{: >8}<-", element);
    std::cout << str << '\n';
    str = std::format("HEX ->{: ^8X}<-", element);
    std::cout << str << '\n';
    fmt::print("Unicode Example: Слава Україні!\n");
    fmt::print("Floating point output format examples:\n");
    double d = 34.567;
    fmt::print("{:.3}\n", d);   // precision 3
    fmt::print("{:+8.3}\n", d); // width 8
    fmt::print("{:e}\n", d);    // exponential
    fmt::print("{:.3e}\n", d);  // exp+prec
    fmt::print("{:-<12}\n", ""); // line
    fmt::print("{:*>+12.1e}\n", d);

    // parameters can also be given by {} inside the format string and put as argument
    auto len=12;
    str = std::format("->{: ^{}x}<-", element, len);
    std::cout << str << '\n';

    return 0;
}