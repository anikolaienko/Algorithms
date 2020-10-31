/**
 * Concrete Simple Word Counter without caching
 * 
 * Author: Andrii Nikolaienko
 */

#ifndef ALGORITHMS_WORD_COUNTER_SIMPLE
#define ALGORITHMS_WORD_COUNTER_SIMPLE

#include <cctype>
#include "word_counter.hh"

namespace Algorithms {
    /**
     * Counts how many times word appears in a text
     * Search is case insensitive
     * 
     * Searches all word appearances in text every time `count` is called
     * Complexity:
     *  * constructor: O(len_of_text) (string::operator= copies the character array)
     *  * count: O(len_of_text)
     */
    class WordCounterSimple: public WordCounter {
        std::string text_;
    public:
        WordCounterSimple(std::string);
        int count(std::string) override;
    };
}

#endif // ALGORITHMS_WORD_COUNTER_SIMPLE