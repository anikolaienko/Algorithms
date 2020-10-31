#include "word_counter_simple.hh"

Algorithms::WordCounterSimple::WordCounterSimple(std::string text) {
    text_ = text;
}

int Algorithms::WordCounterSimple::count(std::string word) {
    int j = 0, count = 0;
    for (int i = 0; i < text_.length(); i++) {
        if (tolower(text_[i]) == tolower(word[j])) {
            j++;
            if (j >= word.length()) {
                if (i + 1 == text_.length() || !isalpha(text_[i + 1])) {
                    count++;
                } else {
                    while(i < text_.length() && isalpha(text_[i])) i++;
                }
                j = 0;
            }
        } else j = 0;
    }
    
    return count;
}