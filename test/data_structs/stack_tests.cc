#include <gtest/gtest.h>

#include "../../data_structs/stack.cc"

TEST(Stack, AddPopItems) {
    Algorithms::Stack stack;
    for (int x: {1, 2, 3}) stack.push(x);
    EXPECT_EQ(stack.size(), 3);

    for (int x: {4, 5}) stack.push(x);
    EXPECT_EQ(stack.size(), 5);

    for (int x: {5, 4, 3, 2}) {
        EXPECT_EQ(stack.pop(), x);
    }
    
    EXPECT_EQ(stack.size(), 1);
}
