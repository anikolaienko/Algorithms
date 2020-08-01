#include <cmath>
#include <limits>

#ifndef ALGORITHMS_POINT
#define ALGORITHMS_POINT

namespace Algorithms {
    struct Point {
    private:
        #define D_EPSILON  std::numeric_limits<double>::epsilon()
        #define D_INFINITY std::numeric_limits<double>::infinity()

    public:
        double x;
        double y;

        Point(): x{D_INFINITY}, y{D_INFINITY} {}
        Point(double x_, double y_): x{x_}, y{y_} {}
        Point(const Point& point) {
            x = point.x;
            y = point.y;
        }

        bool operator==(const Point& point) const {
            return std::abs(x - point.x) <= D_EPSILON 
                && std::abs(y - point.y) <= D_EPSILON;
        }

        bool operator>(const Point& point) const {
            if (std::abs(x - point.x) <= D_EPSILON) return y > point.y;
            return x > point.x;
        }
    };
}

#endif // ALGORITHMS_POINT