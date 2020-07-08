#include <gtest/gtest.h>

#include "../../data_structs/weighted_edge.cc"

TEST(WeightedEdge, Create) {
    Algorithms::WeightedEdge edge(1, 2, 4);
    EXPECT_EQ(edge.either(), 1);
    EXPECT_EQ(edge.other(1), 2);
    EXPECT_EQ(edge.other(2), 1);
    EXPECT_EQ(edge.weight(), 4);
}

TEST(WeightedEdge, LessOperator) {
    Algorithms::WeightedEdge edge1(1, 2, 4);
    Algorithms::WeightedEdge edge2(1, 3, 5);
    EXPECT_LT(edge1, edge2);
}

TEST(WeightedEdge, StringOperator) {
    Algorithms::WeightedEdge edge(1, 2, 4);
    EXPECT_EQ((std::string)edge, "1 (4) 2");
}