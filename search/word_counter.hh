/**
 * Abstract Word Counter class
 * 
 * Author: Andrii Nikolaienko
 */

#ifndef ALGORITHMS_WORD_COUNTER
#define ALGORITHMS_WORD_COUNTER

#include <string>

namespace Algorithms {
    /**
     * Counts how many times word appears in a text
     * Search is case insensitive
     */
    class WordCounter {
    public:
        virtual int count(std::string) = 0;
        virtual ~WordCounter() {};
    };
}

#endif // ALGORITHMS_WORD_COUNTER