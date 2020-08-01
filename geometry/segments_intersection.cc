// Task 16.3 from Cracking Coding Interview

#include <limits>
#include <utility>
#include <algorithm>

#include "point.cc"
#include "line.cc"

namespace Algorithms {
    Point* segmentsIntersection(const Point& line1_a, const Point& line1_b, 
        const Point& line2_a, const Point& line2_b) {
        Line l1(line1_a, line1_b);
        Line l2(line2_a, line2_b);

        if (l1.parallelTo(l2)) return nullptr; // TODO: not always

        Point* point = nullptr;
        if (l1.isVertical() || l2.isVertical()) {
            if (l2.isVertical()) std::swap(l1, l2);
            
            double x = l1.start.x;
            double y = l2.slope * x + l2.offset;

            point = new Point(x, y);
        } else {
            double x = (l2.offset - l1.offset) / (l1.slope - l2.slope);
            double y = l1.slope * x + l1.offset;

            point = new Point(x, y);
        }

        if (l1.withinBounds(*point) && l2.withinBounds(*point)) return point;

        return nullptr;
    }
}