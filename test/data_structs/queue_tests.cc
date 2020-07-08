#include <gtest/gtest.h>

#include "../../data_structs/queue.cc"

TEST(Queue, AddPopItems) {
    Algorithms::Queue queue;
    for (int x: {1, 2, 3}) queue.enqueue(x);
    EXPECT_EQ(queue.size(), 3);

    for (int x: {4, 5}) queue.enqueue(x);
    EXPECT_EQ(queue.size(), 5);

    for (int x: {1, 2, 3, 4}) {
        EXPECT_EQ(queue.dequeue(), x);
    }
    
    EXPECT_EQ(queue.size(), 1);
}
