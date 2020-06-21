#include <gtest/gtest.h>

#include "../../data_structs/stack3_as_vector1.cc"

TEST(Stack3AsVector1, ResizeStack1) {
    Algorithms::Stack3 stack3;
    stack3.push1(1);
    stack3.push1(2);
    EXPECT_EQ(stack3.size1(), 2);

    stack3.push1(3);
    stack3.push1(4);
    EXPECT_EQ(stack3.size1(), 4);

    std::vector<int> expected {1, 2, 3, 4};
    while(stack3.size1()) {
        EXPECT_EQ(stack3.pop1(), expected.back());
        expected.pop_back();
    }
}

TEST(Stack3AsVector1, ResizeStack2) {
    Algorithms::Stack3 stack3;
    stack3.push2(1);
    stack3.push2(2);
    EXPECT_EQ(stack3.size2(), 2);

    stack3.push2(3);
    stack3.push2(4);
    EXPECT_EQ(stack3.size2(), 4);

    std::vector<int> expected {1, 2, 3, 4};
    while(stack3.size2()) {
        EXPECT_EQ(stack3.pop2(), expected.back());
        expected.pop_back();
    }
}

TEST(Stack3AsVector1, ResizeStack3) {
    Algorithms::Stack3 stack3;
    stack3.push3(1);
    stack3.push3(2);
    EXPECT_EQ(stack3.size3(), 2);

    stack3.push3(3);
    stack3.push3(4);
    EXPECT_EQ(stack3.size3(), 4);

    std::vector<int> expected {1, 2, 3, 4};
    while(stack3.size3()) {
        EXPECT_EQ(stack3.pop3(), expected.back());
        expected.pop_back();
    }
}

TEST(Stack3AsVector1, ResizeStack123) {
    Algorithms::Stack3 stack3;
    stack3.push1(10);
    stack3.push1(11);
    stack3.push1(12);
    EXPECT_EQ(stack3.size1(), 3);
    
    stack3.push2(20);
    stack3.push2(21);
    stack3.push2(22);
    EXPECT_EQ(stack3.size2(), 3);

    stack3.push3(30);
    stack3.push3(31);
    stack3.push3(32);
    EXPECT_EQ(stack3.size3(), 3);

    stack3.push1(13);
    stack3.push1(14);
    EXPECT_EQ(stack3.size1(), 5);

    stack3.push2(23);
    stack3.push2(24);
    EXPECT_EQ(stack3.size2(), 5);
    
    for (int x: {32, 31, 30}) EXPECT_EQ(stack3.pop3(), x);
    for (int x: {24, 23, 22, 21, 20}) EXPECT_EQ(stack3.pop2(), x);
    for (int x: {14, 13, 12, 11, 10}) EXPECT_EQ(stack3.pop1(), x);
}