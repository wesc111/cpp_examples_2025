// example for calculation of pascal triangle in cpp
// from Francis Buontempo "Learn C++ by Examples"

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <format>
#include <fmt/format.h>
#include <cassert>
#include <numeric>

std::vector<int> get_next_row(const std::vector<int> &last_row)
{
    std::vector next_row{ 1 };
    if (last_row.empty())
    {
        return next_row;
    }
    for (size_t idx = 0; idx+1 < last_row.size(); ++idx)
    {
        auto elem = last_row[idx] + last_row[idx + 1];
        next_row.emplace_back(elem);
    }
    next_row.emplace_back(1);
    return next_row;
}

// simple solution, creates data and copies it to triangle
auto generate_triangle1(int rows)
{
    std::vector<int> data;
    std::vector<std::vector<int>> triangle;

    for (int row = 0; row < rows; ++row)
    {
        data = get_next_row(data);
        triangle.push_back(data);
    }
    return triangle;
}

// advanced solution without copying data vector
// pushing the next value directly after the last value in the triangle vector
auto generate_triangle2(int rows)
{
    std::vector<std::vector<int>> triangle { {1} };

    for (int row = 0; row < rows; ++row)
    {
        triangle.push_back(get_next_row(triangle.back()));
    }
    return triangle;
}

void show_vectors(std::ostream & s, const std::vector<std::vector<int>>& v)
{
    size_t final_row_size = v.back().size();
    std::string spaces(final_row_size*3,' ');
    for (const auto& row : v)
    {
        s << spaces;
        if (spaces.size() > 3)
            spaces.resize(spaces.size()-3);
        for (const auto& data : row)
        {
            s << std::format("{: ^{}}", data, 6);
        }
        s << '\n';
    }
}

// do testing by checking properties of the triangle
void check_properties(const std::vector<std::vector<int>>& triangle)
{
    int expected_total = 1;

    for (const auto & row : triangle)
    {
        assert(row.front() == 1);
        assert(row.back() == 1);
        assert(std::accumulate(row.begin(),row.end(),0) == expected_total);
        expected_total *= 2;
    }
}

int main()
{
    auto triangle = generate_triangle2(16);
    check_properties(triangle);
    show_vectors(std::cout, triangle);
}


