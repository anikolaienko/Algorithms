#include <gtest/gtest.h>
#include <climits>

#include "../../bitwise/bitwise.cc"

TEST(BitwiseTest, ToStringMinus8) {
    EXPECT_EQ(Algorithms::toBitString<4>(-8), "1000");
}

TEST(BitwiseTest, RightBit_8) {
    EXPECT_EQ(Algorithms::toBitString<4>(Algorithms::getRightBit(8)), "1000");
}

TEST(BitwiseTest, RightBit_10) {
    EXPECT_EQ(Algorithms::toBitString<4>(Algorithms::getRightBit(10)), "0010");
}

TEST(BitwiseTest, RightBit_INT_MIN) {
    EXPECT_EQ(Algorithms::toBitString<32>(Algorithms::getRightBit(INT_MIN)), "10000000000000000000000000000000");
}

TEST(BitwiseTest, RightBit_INT_MAX) {
    EXPECT_EQ(Algorithms::toBitString<32>(Algorithms::getRightBit(INT_MAX)), "00000000000000000000000000000001");
}
