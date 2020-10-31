#include <gtest/gtest.h>
#include <memory>

#include "../../search/word_counter.hh"
#include "../../search/word_counter_simple.hh"

std::unique_ptr<Algorithms::WordCounter> createWordCounter(std::string text) {
    return std::unique_ptr<Algorithms::WordCounter>(new Algorithms::WordCounterSimple(text));
}

TEST(WordCounterSimpleTest, TextArgumentCopyShouldBeUsed) {
    std::string text = "Empty text!";
    auto counter = createWordCounter(text);
    text = "Hello world!";
    EXPECT_EQ(counter->count("world"), 0);
}

TEST(WordCounterSimpleTest, NoneWordsFound) {
    std::string text = "Hello world! This is sample text.";
    auto counter = createWordCounter(text);
    EXPECT_EQ(counter->count("me"), 0);
}

TEST(WordCounterSimpleTest, OneWordFound) {
    std::string text = "Hello world! This is sample text.";
    auto counter = createWordCounter(text);
    EXPECT_EQ(counter->count("hello"), 1);
}

TEST(WordCounterSimpleTest, ManyWordsFound) {
    std::string text = "Hello world! World is such a beautiful world.";
    auto counter = createWordCounter(text);
    EXPECT_EQ(counter->count("world"), 3);
}