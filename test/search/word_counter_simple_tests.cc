#include <gtest/gtest.h>
#include <memory>

#include "../../search/word_counter.hh"
#include "../../search/word_counter_simple.hh"

class WordCounterSimpleTest : public testing::Test {
public:
    std::unique_ptr<Algorithms::WordCounter> createCounter(std::string text) {
        return std::unique_ptr<Algorithms::WordCounter>(
            new Algorithms::WordCounterSimple(text)
        );
    }
};

TEST_F(WordCounterSimpleTest, TextArgumentCopyShouldBeUsed) {
    std::string text = "Empty text!";
    auto counter = createCounter(text);
    text = "Hello world!";
    EXPECT_EQ(counter->count("world"), 0);
}

TEST_F(WordCounterSimpleTest, NoneWordsFound) {
    std::string text = "Hello world! This is sample text.";
    auto counter = this->createCounter(text);
    EXPECT_EQ(counter->count("me"), 0);
}

TEST_F(WordCounterSimpleTest, OneWordFound) {
    std::string text = "hello world! This is sample text.";
    auto counter = this->createCounter(text);
    EXPECT_EQ(counter->count("hello"), 1);
}

TEST_F(WordCounterSimpleTest, ManyWordsFound) {
    std::string text = "Hello world, world is such a beautiful world.";
    auto counter = this->createCounter(text);
    EXPECT_EQ(counter->count("world"), 3);
}

TEST_F(WordCounterSimpleTest, WordShouldBeSeparate) {
    std::string text = "Cat is not catton";
    auto counter = this->createCounter(text);
    EXPECT_EQ(counter->count("cat"), 1);
}

TEST_F(WordCounterSimpleTest, CaseInsensitive) {
    std::string text = "Hello world! World is here";
    auto counter = this->createCounter(text);
    EXPECT_EQ(counter->count("world"), 2);
}