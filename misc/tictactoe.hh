/**
 * TicTacToe game board
 * 
 * Author: Andrii Nikolaienko
 */

#ifndef ALGORITHMS_TICTACTOE_BOARD
#define ALGORITHMS_TICTACTOE_BOARD

#include <string>
#include <stdexcept>

namespace Algorithms{
    /**
     * TicTacToe game board
     * INFO: Currently board doesn't support checking:
     *  * if sequence of moves is correct
     *  * if number of moves by each player is correct
     */
    class TicTacToe {
        int board_;

    public:
        /**
         * Initializes an empty board
         */
        TicTacToe();

        /**
         * Initializes TicTacToe with a string board representation
         * Example of valid `board` string:
         *   x_o   or   ___
         *   _xo        __o
         *   ox_        _x_
         * 
         * Throws: `invalid_argument` if board is a wrong size or contains invalid characters
         */
        TicTacToe(std::string board);

        /**
         * Make a move if allowed
         * 
         * params:
         *  * x, y - in range [0..2]
         *  * symbol - case insensitive 'x' or 'o' character 
         * 
         * Returns: `true` if cell is free and game is not finished, otherwise `false`
         * Throws: `invalid_argument` if either of the params is out of boundary
         */
        bool move(int x, int y, char symbol);

        /**
         * Returns `true` if game has finished, otherwise `false`
         */
        bool is_finished();

        /**
         * Returns:
         *  * `_` - if game hasn't finished
         *  * `d` - if game finished with draw
         *  * `x` or `o` - if someone has won
         */
        char winner();

        /**
         * Returns string board representation
         */
        std::string to_string();
    };
}

#endif // ALGORITHMS_TICTACTOE_BOARD