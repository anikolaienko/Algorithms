#include <gtest/gtest.h>

#include "../../permutation/permutate_string.cc"

TEST(PermutateStringTest, StringA) {
    vector<string> expected {"a"};
    EXPECT_EQ(permutate("a"), expected);
}

TEST(PermutateStringTest, StringAB) {
    vector<string> expected {"ab", "ba"};
    EXPECT_EQ(permutate("ab"), expected);
}