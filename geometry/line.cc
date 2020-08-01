#include <stdexcept>
#include <algorithm>
#include <cmath>
#include "point.cc"

#ifndef ALGORITHMS_LINE
#define ALGORITHMS_LINE

namespace Algorithms {
    struct Line {
        Point start, finish;
        double slope, offset;

        Line(const Point& a, const Point& b) {
            if (a == b) throw std::invalid_argument("Points cannot be are equal!");

            start = a;
            finish = b;

            if (start > finish) std::swap(start, finish);

            if (start.x == finish.x) {
                slope = std::numeric_limits<double>::infinity();
                offset = start.y;
            } else if (start.y == finish.y) {
                slope = 0;
                offset = start.y;
            } else {
                slope = (start.y - finish.y) / (start.x - finish.x);
                offset = start.y - slope * start.x;
            }
        }

        bool withinBounds(const Point& point) const {
            double x1 = start.x, x2 = finish.x;
            double y1 = start.y, y2 = finish.y;

            if (x1 > x2) std::swap(x1, x2);
            if (y1 > y2) std::swap(y1, y2);

            return point.x >= x1 && point.x <= x2
                && point.y >= y1 && point.y <= y2;
        }

        bool isVertical() const {
            return slope == std::numeric_limits<double>::infinity();
        }

        bool parallelTo(const Line& line) {
            if (isVertical() || line.isVertical()) return isVertical() && line.isVertical();

            return std::abs(slope - line.slope) <= std::numeric_limits<double>::epsilon();
        }
    };
}

#endif // ALGORITHMS_LINE