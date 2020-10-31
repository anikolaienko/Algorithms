/**
 * Concrete Simple Word Counter without caching
 * 
 * Author: Andrii Nikolaienko
 */

#ifndef ALGORITHMS_WORD_COUNTER_SIMPLE
#define ALGORITHMS_WORD_COUNTER_SIMPLE

#include "word_counter.hh"

namespace Algorithms {
    /**
     * Counts how many times word appears in a text
     * Search is case insensitive
     */
    class WordCounterSimple: public WordCounter {
        std::string text_;
    public:
        WordCounterSimple(std::string);
        int count(std::string) override;
    };
}

#endif // ALGORITHMS_WORD_COUNTER_SIMPLE