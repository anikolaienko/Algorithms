#include <gtest/gtest.h>

#include "../../convertion/to_bit_string.cc"

TEST(ToBitString, TestSomeNums) {
    // References for test data are taken from Wikipedia page:
    // https://en.wikipedia.org/wiki/Double-precision_floating-point_format#Double-precision_examples
    EXPECT_EQ(Algorithms::to_bit_string(1.0),     "0 01111111111 0000000000000000000000000000000000000000000000000000");
    EXPECT_EQ(Algorithms::to_bit_string(2.0),     "0 10000000000 0000000000000000000000000000000000000000000000000000");
    EXPECT_EQ(Algorithms::to_bit_string(5),       "0 10000000001 0100000000000000000000000000000000000000000000000000");
    EXPECT_EQ(Algorithms::to_bit_string(6),       "0 10000000001 1000000000000000000000000000000000000000000000000000");

    EXPECT_EQ(Algorithms::to_bit_string(-2.0),    "1 10000000000 0000000000000000000000000000000000000000000000000000");
    
    EXPECT_EQ(Algorithms::to_bit_string(1.0 / 3),   "0 01111111101 0101010101010101010101010101010101010101010101010101");
    EXPECT_EQ(Algorithms::to_bit_string(3.0 / 256), "0 01111111000 1000000000000000000000000000000000000000000000000000");
}
