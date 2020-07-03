#include <gtest/gtest.h>

#include "../../data_structs/queue_as_stack.cc"

TEST(Stack, AddPopItems) {
    Algorithms::QueueAsStack queue;
    for (int x: {1, 2, 3}) queue.push(x);
    EXPECT_EQ(queue.size(), 3);
    EXPECT_EQ(queue.front(), 1);

    for (int x: {4, 5}) queue.push(x);
    EXPECT_EQ(queue.size(), 5);
    EXPECT_EQ(queue.front(), 1);

    for (int x: {1, 2, 4, 4}) {
        EXPECT_EQ(queue.pop(), x);
    }
    
    EXPECT_EQ(queue.size(), 1);
    EXPECT_EQ(queue.front(), 5);
}
