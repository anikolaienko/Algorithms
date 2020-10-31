#include "word_counter_cached.hh"

Algorithms::WordCounterCached::WordCounterCached(std::string text) {
    std::string word;
    for (int i = 0; i <= text.length(); i++) {
        if (i < text.length() && isalpha(text[i])) {
            word.push_back(tolower(text[i]));
        } else if (!word.empty()) {
            wordCount_[word]++;
            word.clear();
        }
    }
}

int Algorithms::WordCounterCached::count(std::string word) {
    return wordCount_[word];
}