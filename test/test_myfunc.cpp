// Copyright Werner Schoegler
// 21-May-2025

// testing of functions included in class myfunc1 with catch2 test framework
// includes also a benchmark for slow recursive and fast iterative fibonacci number calculation

#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include "myfunc.hpp"

TEST_CASE( "factorials are computed (pass)" ) {
    auto myfunc1 = myfunc();

    REQUIRE( myfunc1.factorial(0) == 1 );
    REQUIRE( myfunc1.factorial(1) == 1 );
    REQUIRE( myfunc1.factorial(2) == 2 );
    REQUIRE( myfunc1.factorial(3) == 6 );
    REQUIRE( myfunc1.factorial(4) == 24 );
    REQUIRE( myfunc1.factorial(5) == 120 );
    REQUIRE( myfunc1.factorial(10) == 3628800 );
}

TEST_CASE( "fibonacci numbers are computed recursively (pass)" ) {
    auto myfunc1 = myfunc();

    CHECK( myfunc1.fiboRecursive(0) == 0 );
    CHECK( myfunc1.fiboRecursive(1) == 1 );
    CHECK( myfunc1.fiboRecursive(2) == 1 );
    CHECK( myfunc1.fiboRecursive(3) == 2 );
    CHECK( myfunc1.fiboRecursive(4) == 3 );
    CHECK( myfunc1.fiboRecursive(5) == 5 );
    CHECK( myfunc1.fiboRecursive(6) == 8 );
    CHECK( myfunc1.fiboRecursive(40) == 102334155 );
    // 80 not included as it takes really a long time ...
}

TEST_CASE( "fibonacci numbers are computed (pass)" ) {
    auto myfunc1 = myfunc();

    CHECK( myfunc1.fibo(0) == 0 );
    CHECK( myfunc1.fibo(1) == 1 );
    CHECK( myfunc1.fibo(2) == 1 );
    CHECK( myfunc1.fibo(3) == 2 );
    CHECK( myfunc1.fibo(4) == 3 );
    CHECK( myfunc1.fibo(5) == 5 );
    CHECK( myfunc1.fibo(6) == 8 );
    CHECK( myfunc1.fibo(40) == 102334155 );
    CHECK( myfunc1.fibo(80) == 23416728348467685 );
}

TEST_CASE("Fibonacci benchmark") {
    BENCHMARK("Fibonacci Recursive") {
        auto myfunc1 = myfunc();

        return myfunc1.fiboRecursive(32);
    };
    BENCHMARK("Fibonacci") {
        auto myfunc1 = myfunc();

        return myfunc1.fibo(32);
    };
}
