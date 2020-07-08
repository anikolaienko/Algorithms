#include <gtest/gtest.h>

#include "../../data_structs/vector.cc"

TEST(Vector, IndexingCheck) {
    Algorithms::Vector vect;
    for (int x: {1, 2}) vect.push(x);
    EXPECT_EQ(vect.size(), 2);

    for (int i = 0; i < 2; ++i) EXPECT_EQ(vect[i], i + 1);
}

TEST(Vector, IndexAssignment) {
    Algorithms::Vector vect(2, 0);
    for (int i = 0; i < 2; ++i) vect[i] = i + 1;
    EXPECT_EQ(vect.size(), 2);

    for (int i = 0; i < 2; ++i) EXPECT_EQ(vect[i], i + 1);
}