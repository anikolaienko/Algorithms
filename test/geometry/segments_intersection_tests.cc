#include <gtest/gtest.h>

#include "../../geometry/segments_intersection.cc"

using Point = Algorithms::Point;

TEST(SegmentsIntersection, Parallel) {
    Point l1A(1, 1), l1B(2, 2), l2A(1, 0), l2B(2, 1);
    Point *point = Algorithms::segmentsIntersection(l1A, l1B, l2A, l2B);
    
    EXPECT_EQ(point, nullptr);
}

TEST(SegmentsIntersection, Intersect_2__3) {
    Point l1A(1, 1), l1B(3, 5), l2A(0, 5), l2B(5, 0);
    Point *point = Algorithms::segmentsIntersection(l1A, l1B, l2A, l2B);
    
    ASSERT_TRUE(point != nullptr);
    EXPECT_EQ(*point, Point(2, 3));
}

TEST(SegmentsIntersection, Intersect_Line1_Vertical) {
    Point l1A(3, 0), l1B(3, 5), l2A(1, 1), l2B(5, 5);
    Point *point = Algorithms::segmentsIntersection(l1A, l1B, l2A, l2B);
    
    ASSERT_TRUE(point != nullptr);
    EXPECT_EQ(*point, Point(3, 3));
}

TEST(SegmentsIntersection, Intersect_Line1_Horizontal) {
    Point l1A(0, 3), l1B(5, 3), l2A(1, 5), l2B(5, 1);
    Point *point = Algorithms::segmentsIntersection(l1A, l1B, l2A, l2B);
    
    ASSERT_TRUE(point != nullptr);
    EXPECT_EQ(*point, Point(3, 3));
}

// TODO: add test cases