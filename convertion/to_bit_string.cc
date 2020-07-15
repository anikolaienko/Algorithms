#include <stdlib.h>
#include <string>
#include <algorithm>

namespace Algorithms {
    std::string to_bit_string(double d) {
        union doubleInt {
            double dValue;
            uint64_t iValue;
        };

        doubleInt di {d};
        std::string result;

        for (int i = 0; i < 64; ++i) {
            if (i == 63 || i == 52) result.push_back(' ');
            
            result.push_back('0' + (di.iValue & 1));
            di.iValue >>= 1;
        }
        std::reverse(begin(result), end(result));
        return result;
    }
}