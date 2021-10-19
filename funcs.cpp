//
// Created by jdwil on 19/10/2021.
//
#include <iostream>
#include <vector>
#include <sstream>



void draw_board(std::vector<char> board, std::vector<char> available_moves)
{
    for (int a = 0; a < board.size(); a++)
    {
        std::cout << board[a];
        if ((a +1 ) % 3 == 0)
        {
            if (a == 2)
            {
                std::cout << "     " << available_moves[0] << "|" << available_moves[1] << "|" << available_moves[2];
            }
            if (a == 5)
            {
                std::cout << "     " << available_moves[3] << "|" << available_moves[4] << "|" << available_moves[5];
            }
            if (a == 8)
            {
                std::cout << "     " << available_moves[6] << "|" << available_moves[7] << "|" << available_moves[8];
            }
            std::cout << "\n";
        }
        else std::cout << "|";

    }

}

std::vector<char> get_available_moves(std::vector<char> board)
{
    std::vector<char> r {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    for (int a = 0; a < 9; a++)
    {
        if (board[a] == ' ') r[a] = '0' + (a + 1);

    }
    return r;
}



std::vector<char> updated_board(std::vector<char> board, int move, char player)
{

    //std::cout << "I got " << board[0] << "\n";
    board[move-1] = player;
    return board;
}


bool winner(std::vector<char> board, char player)
{

    bool r = false;
    bool done = false;

    while (!r && !done) {
        //check horizontal rows

        for (int row = 0; row < 8; row = row + 3) {
            bool row_check = true;
            //std::cout << "Row check = " << row_check << "\n";

            for (int col = row; col < (row + 3); col = col + 1) {
                //std::cout << board[col] << " vs " << player << "\n";
                if (board[col] != player)
                {
                    //std::cout << "Doh.\n";
                    row_check = false;
                }
            }

            if (row_check) {
                //std::cout << "Matching row!\n";
                return row_check;
            }

        }

        //check vertical rows
        for (int start_row = 0; start_row < 4; start_row++)
        {

            bool col_check = true;
            for (int col = start_row; col < 9; col = col + 3)
            {
                if (board[col] != player) col_check = false;
            }
            if (col_check)
            {
                //std::cout << "Matching col!\n";
                return col_check;
            }
        }

        //Check diags...

        for (int start_row = 0; start_row < 4; start_row = start_row + 3)
        {
            if (start_row == 0)
            {
                bool check_diag = true;
                for (int col = start_row; col < 9; col = col + 4)
                {
                    if (board[col] != player) check_diag = false;
                }
                if (check_diag)
                {
                    //std::cout << "Matching diag 1!\n";
                    return check_diag;
                }
            }
            if (start_row == 2)
            {
                bool check_diag = true;
                for (int col = start_row; col < 7; col = col + 2)
                {
                    if (board[col] != player) check_diag = false;
                }
                if (check_diag)
                {
                    std::cout << "Matching diag 2!\n";
                    return check_diag;
                }
            }
        }
        done = true;

    }
    return r;


}
