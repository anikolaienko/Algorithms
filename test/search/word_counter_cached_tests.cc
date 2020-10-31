#include <gtest/gtest.h>
#include <memory>

#include "../../search/word_counter.hh"
#include "../../search/word_counter_cached.hh"

class WordCounterCachedTest : public testing::Test {
public:
    std::unique_ptr<Algorithms::WordCounter> createCounter(std::string text) {
        return std::unique_ptr<Algorithms::WordCounter>(
            new Algorithms::WordCounterCached(text)
        );
    }
};

TEST_F(WordCounterCachedTest, TextArgumentCopyShouldBeUsed) {
    std::string text = "Empty text!";
    auto counter = createCounter(text);
    text = "Hello world!";
    EXPECT_EQ(counter->count("world"), 0);
}

TEST_F(WordCounterCachedTest, NoneWordsFound) {
    std::string text = "Hello world! This is sample text.";
    auto counter = createCounter(text);
    EXPECT_EQ(counter->count("me"), 0);
}

TEST_F(WordCounterCachedTest, OneWordFound) {
    std::string text = "hello world! This is sample text.";
    auto counter = createCounter(text);
    EXPECT_EQ(counter->count("hello"), 1);
}

TEST_F(WordCounterCachedTest, ManyWordsFound) {
    std::string text = "Hello world, world is such a beautiful world.";
    auto counter = createCounter(text);
    EXPECT_EQ(counter->count("world"), 3);
}
    
TEST_F(WordCounterCachedTest, WordShouldBeSeparate) {
    std::string text = "Cat is not catton";
    auto counter = createCounter(text);
    EXPECT_EQ(counter->count("cat"), 1);
}

TEST_F(WordCounterCachedTest, CaseInsensitive) {
    std::string text = "Hello world! World is here";
    auto counter = createCounter(text);
    EXPECT_EQ(counter->count("world"), 2);
}