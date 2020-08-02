#include <gtest/gtest.h>
#include <climits>

#include <factorial.hh>

TEST(FactorialTrailingZeros, Zero) {
    EXPECT_EQ(Algorithms::factorialTrailingZeros(4), 0);
}

TEST(FactorialTrailingZeros, Two) {
    EXPECT_EQ(Algorithms::factorialTrailingZeros(14), 2);
}

TEST(FactorialTrailingZeros, 13) {
    EXPECT_EQ(Algorithms::factorialTrailingZeros(56), 13);
}