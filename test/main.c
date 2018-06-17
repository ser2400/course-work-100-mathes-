#define CTEST_MAIN

#include "ctest.h"
#include "functions.h"

CTEST(Input_test, take_1_match_Count_100)
{
    int Num = 2;
    int Count = 100;
    int result = check(Num, Count);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(Input_test, take_10_matches_Count_100)
{
    int Num = 10;
    int Count = 100;
    int result = check(Num, Count);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_test, take_11_matches_Count_100)
{
    int Num = 11;
    int Count = 100;
    int result = check(Num, Count);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_test, take_100_matches_Count_100)
{
    int Num = 100;
    int Count = 100;
    int result = check(Num, Count);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_test, take_10_matches_Count_8)
{
    int Num = 10;
    int Count = 8;
    int result = check(Num, Count);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_test, take_11_matches_Count_8)
{
    int Num = 11;
    int Count = 8;
    int result = check(Num, Count);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_test, take_1_match_Count_1)
{
    int Num = 1;
    int Count = 1;
    int result = check(Num, Count);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

int main(int argc, const char** argv) {
    int test_res = ctest_main(argc, argv);
    return test_res;
}


