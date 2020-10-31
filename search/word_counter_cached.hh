/**
 * Concrete Word Counter with words caching into hashtable
 * 
 * Author: Andrii Nikolaienko
 */

#ifndef ALGORITHMS_WORD_COUNTER_CACHED
#define ALGORITHMS_WORD_COUNTER_CACHED

#include <cctype>
#include <unordered_map>
#include "word_counter.hh"

namespace Algorithms {
    /**
     * Counts how many times word appears in a text
     * Search is case insensitive
     * 
     * Hashes all words from text into hashtable
     * 
     * Complexity:
     *  * constructor: O(len_of_text)
     *  * count: O(len_of_word)
     */
    class WordCounterCached: public WordCounter {
        std::unordered_map<std::string, int> wordCount_;
    public:
        WordCounterCached(std::string);
        int count(std::string) override;
    };
}

#endif // ALGORITHMS_WORD_COUNTER_CACHED