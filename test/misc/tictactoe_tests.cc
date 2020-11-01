#include <gtest/gtest.h>

#include "../../misc/tictactoe.hh"

TEST(TicTacToeTest, InitializeEmptyBoard) {
    Algorithms::TicTacToe board;
    EXPECT_EQ(board.to_string(), "___\n"
                                 "___\n"
                                 "___");
    EXPECT_FALSE(board.is_finished());
    EXPECT_EQ(board.winner(), '_');
}

TEST(TicTacToeTest, InitializeBoard) {
    std::string str_board = "_x_\n"
                            "ox_\n"
                            "_ox";
    Algorithms::TicTacToe board(str_board);
    EXPECT_FALSE(board.is_finished());
    EXPECT_EQ(board.winner(), '_');
    EXPECT_EQ(board.to_string(), str_board);
}

TEST(TicTacToeTest, InitializeBoardWithWinner) {
    std::string str_board = "xx_\n"
                            "oxo\n"
                            "_xo";
    Algorithms::TicTacToe board(str_board);
    EXPECT_TRUE(board.is_finished());
    EXPECT_EQ(board.winner(), 'x');
    EXPECT_EQ(board.to_string(), str_board);
}

TEST(TicTacToeTest, InitializeBoardCaseInsensitive) {
    std::string str_board = "Ox_\n"
                            "XOo\n"
                            "_xo";
    Algorithms::TicTacToe board(str_board);
    EXPECT_TRUE(board.is_finished());
    EXPECT_EQ(board.winner(), 'o');
    EXPECT_EQ(board.to_string(), "ox_\n"
                                 "xoo\n"
                                 "_xo");
}

TEST(TicTacToeTest, InitializeBoardWithDraw) {
    std::string str_board = "oxo\n"
                            "xxo\n"
                            "xox";
    Algorithms::TicTacToe board(str_board);
    EXPECT_TRUE(board.is_finished());
    EXPECT_EQ(board.winner(), 'd');
}

TEST(TicTacToeTest, InitializeWithWrongBoardSize) {
    std::string str_board = "oxo_\n"
                            "xxo_\n"
                            "xoo_";
    Algorithms::TicTacToe* board;
    EXPECT_THROW(new Algorithms::TicTacToe(str_board), std::invalid_argument);
}

TEST(TicTacToeTest, InitializeWithWrongSymbol) {
    std::string str_board = "oxo\n"
                            "axo\n"
                            "xoo";
    Algorithms::TicTacToe* board;
    EXPECT_THROW(new Algorithms::TicTacToe(str_board), std::invalid_argument);
}

TEST(TicTacToeTest, MakeMoves) {
    Algorithms::TicTacToe board;
    EXPECT_TRUE(board.move(0,0,'x'));
    EXPECT_TRUE(board.move(0,1,'o'));
    EXPECT_FALSE(board.is_finished());
    EXPECT_EQ(board.to_string(), "x__\n"
                                 "o__\n"
                                 "___");
}

TEST(TicTacToeTest, MakeInvalidMove) {
    Algorithms::TicTacToe board;
    EXPECT_TRUE(board.move(0,0,'x'));
    EXPECT_FALSE(board.move(0,0,'o'));
    EXPECT_FALSE(board.is_finished());
    EXPECT_EQ(board.to_string(), "x__\n"
                                 "___\n"
                                 "___");
}

TEST(TicTacToeTest, MoveToFinishTheGame) {
    Algorithms::TicTacToe board("x_o\n"
                                "xox\n"
                                "_ox");
    EXPECT_TRUE(board.move(1,0,'o'));
    EXPECT_TRUE(board.is_finished());
    EXPECT_EQ(board.winner(), 'o');
    EXPECT_EQ(board.to_string(), "xoo\n"
                                 "xox\n"
                                 "_ox");
}

TEST(TicTacToeTest, MoveAfterGameFinished) {
    Algorithms::TicTacToe board("x_o\n"
                                "xox\n"
                                "_ox");
    EXPECT_TRUE(board.move(1,0,'o'));
    EXPECT_FALSE(board.move(0,2,'x'));
    EXPECT_TRUE(board.is_finished());
    EXPECT_EQ(board.winner(), 'o');
    EXPECT_EQ(board.to_string(), "xoo\n"
                                 "xox\n"
                                 "_ox");
}

TEST(TicTacToeTest, MoveIsTestInsensitive) {
    Algorithms::TicTacToe board("___\n"
                                "___\n"
                                "___");
    EXPECT_TRUE(board.move(1,1,'o'));
    EXPECT_FALSE(board.is_finished());
    EXPECT_EQ(board.winner(), '_');
    EXPECT_EQ(board.to_string(), "___\n"
                                 "_o_\n"
                                 "___");
}

TEST(TicTacToeTest, MoveLeadsToDraw) {
    Algorithms::TicTacToe board("xxo\n"
                                "oox\n"
                                "xo_");
    EXPECT_TRUE(board.move(2,2,'o'));
    EXPECT_TRUE(board.is_finished());
    EXPECT_EQ(board.winner(), 'd');
    EXPECT_EQ(board.to_string(), "xxo\n"
                                 "oox\n"
                                 "xoo");
}

TEST(TicTacToeTest, MoveWithWrongCoordinate) {
    Algorithms::TicTacToe board;
    EXPECT_THROW(board.move(-1,0,'x'), std::invalid_argument);
    EXPECT_THROW(board.move(0,-1,'x'), std::invalid_argument);
    EXPECT_THROW(board.move(3,0,'o'), std::invalid_argument);
    EXPECT_THROW(board.move(0,3,'o'), std::invalid_argument);
    EXPECT_THROW(board.move(10,23,'o'), std::invalid_argument);
}

TEST(TicTacToeTest, MoveWithWrongSymbol) {
    Algorithms::TicTacToe board;
    EXPECT_THROW(board.move(-1,0,'_'), std::invalid_argument);
    EXPECT_THROW(board.move(-1,0,'a'), std::invalid_argument);
}