#include <gtest/gtest.h>
#include <climits>

#include "../../bitwise/swap_two_numbers.cc"

TEST(SwapToNumbers, Swap5And7) {
    int a = 5;
    int b = 7;
    Algorithms::swap(a, b);
    EXPECT_EQ(a, 7);
    EXPECT_EQ(b, 5);
}

TEST(SwapToNumbers, SwapMinus5And7) {
    int a = -5;
    int b = 7;
    Algorithms::swap(a, b);
    EXPECT_EQ(a, 7);
    EXPECT_EQ(b, -5);
}

TEST(SwapToNumbers, SwapBinRepresentation) {
    int a = 0b0011010011;
    int b = 0b0010111000;
    Algorithms::swap(a, b);
    EXPECT_EQ(a, 0b0010111000);
    EXPECT_EQ(b, 0b0011010011);
}

TEST(SwapToNumbers, SwapMinus245And123) {
    int a = -245;
    int b = 123;
    Algorithms::swap(a, b);
    EXPECT_EQ(a, 123);
    EXPECT_EQ(b, -245);
}

TEST(SwapToNumbers, SwapINTMAXandINTMIN) {
    int a = INT_MAX;
    int b = INT_MIN;
    Algorithms::swap(a, b);
    EXPECT_EQ(a, INT_MIN);
    EXPECT_EQ(b, INT_MAX);
}