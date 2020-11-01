#include "tictactoe.hh"

Algorithms::TicTacToe::TicTacToe() {}

Algorithms::TicTacToe::TicTacToe(std::string board) {
    if (board.length() != Algorithms::TicTacToe::BOARD_SIZE) {
        throw std::invalid_argument("Board has wrong size");
    }
    int pos = 0;
    for (int i = 0; i < board.length(); i++) {
        char ch = tolower(board[i]);

        if (i == 3 || i == 7) {
            if (ch != '\n') throw std::invalid_argument("Invalid newline character; allowed: \\n");
            continue;
        }

        if (ch != 'o' && ch != 'x' && ch != '_') {
            throw std::invalid_argument("Invalid symbol: `" + std::string(1, ch) + "`; allowed: x, o, X, O, _");
        }

        if (ch != '_') setTaken(pos, ch);
        pos++;
    }

    checkBoard();
}

bool Algorithms::TicTacToe::isTaken(int pos) {
    return board_ & (1 << pos);
}

void Algorithms::TicTacToe::setTaken(int pos, char &c) {
    board_ |= 1 << pos;
    if (c == 'x') board_ |= 1 << (9 + pos);
}

void Algorithms::TicTacToe::setWinner(char symbol) {
    finished_ = true;
    winner_ = symbol;
}

void Algorithms::TicTacToe::checkBoard() {
    int ver[] {0, 0, 0}, hor[] {0, 0, 0};
    int diag1 = 0, diag2 = 0, taken = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int pos = j * 3 + i;

            if (!isTaken(pos)) continue;
            taken++;

            int point = board_ & (1 << (9 + pos)) ? 1 : -1;
            char sym = point > 0 ? 'x' : 'o';

            ver[i] += point;
            if (abs(ver[i]) == 3) return setWinner(sym);

            hor[j] += point;
            if (abs(hor[j]) == 3) return setWinner(sym);

            if (i == j) {
                diag1 += point;
                if (abs(diag1) == 3) return setWinner(sym);
            }
            if (i == 2 - j) {
                diag2 += point;
                if (abs(diag2) == 3) return setWinner(sym);
            }
        }
    }

    if (taken == 9) setWinner('d');
}

bool Algorithms::TicTacToe::move(int x, int y, char symbol) {
    if (x < 0 || x > 2 || y < 0 || y > 2) {
        throw std::invalid_argument("One or two of positions in out of range [0..2]");
    }
    symbol = tolower(symbol);
    if (symbol != 'x' && symbol != 'o') {
        throw std::invalid_argument("Symbol is invalid: `" + std::string(1, symbol) + "`; allowed: x, o, X, O");
    }

    if (is_finished()) return false;

    int pos = y * 3 + x;
    if (isTaken(pos)) return false;
    setTaken(pos, symbol);

    checkBoard();
    return true;
}

bool Algorithms::TicTacToe::is_finished() {
    return finished_;
}

char Algorithms::TicTacToe::winner() {
    return winner_;
}

std::string Algorithms::TicTacToe::to_string() {
    std::string str;

    for (int i = 0; i < 9; i++) {
        if (i == 3 || i == 6) str.push_back('\n');

        if (board_ & (1 << i)) {
            str.push_back((board_ & (1 << (9 + i))) ? 'x' : 'o');
        } else {
            str.push_back('_');
        }
    }

    return str;
}