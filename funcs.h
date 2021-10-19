//
// Created by jdwil on 19/10/2021.
//
#include <vector>

#ifndef TIC_TAC_TOE_FUNCS_H
#define TIC_TAC_TOE_FUNCS_H
void draw_board(std::vector<char> board, std::vector<char> available_moves);
bool winner(std::vector<char> board, char player);
std::vector<char> get_available_moves(std::vector<char> board);
std::vector<char> updated_board(std::vector<char> board, int move, char player);
#endif //TIC_TAC_TOE_FUNCS_H
