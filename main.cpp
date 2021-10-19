#include <iostream>
#include <vector>
#include "funcs.h"

int main() {

    bool done = false;
    int goes = 0;
    std::vector<char> board{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    std::vector<char> available_moves;
    char player = 'X';
    while (goes < 9)
    {
        int choice;
        available_moves = get_available_moves(board);
        draw_board(board, available_moves);
        //Lets set the player...
        if (player == 'X') player = 'O';
        else player = 'X';
        //show available moves...
        std::cout << "Available moves:";
        for (int a = 0; a < available_moves.size(); a ++)
        {
            std::cout << available_moves[a];
        }
        std::cout << "\n";
        if (player == 'O')
        {
            std::cout << "Noughts, choose your square:";
        }
        else
        {
            std::cout << "Crosses, choose your square:";
        }
        bool valid = false;
        while (!valid)
        {
            std::cin >> choice;
            if (choice > 0 && choice < 10)
            {
                if (board[choice-1] == ' ') valid = true;
            }
        }
        board = updated_board(board,choice,player);
        if (winner(board,player))
        {
            if (player == 'X')
            {
                std::cout << "Well done crosses!\n";
                draw_board(board, available_moves);
            }
            else
            {
                std::cout << "Well done naughts!\n";
                draw_board(board, available_moves);
            }
            goes = 10;
        }
        goes++;
    }

    return 0;
}
