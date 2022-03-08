/*
Created by  : Vaisakh Dileep
Date        : 8, March, 2022
Description : Valid Sudoku.
*/

#include<iostream>

#include<vector>

#include<unordered_set>

#include "../header_files/display_stl/display_stl.hpp"

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_set<string> u_s {};

        for(int i {0}; i < 9; i++)
        {
            for(int j {0}; j < 9; j++)
            {
                if(board[i][j] == '.')
                {
                    continue;
                }

                string key_row {string {board[i][j]} + " -row-> " + to_string(i)};

                string key_column {string {board[i][j]} + " -column-> " + to_string(j)};

                string key_sub_square {string {board[i][j]} + " -sub_square-> " + to_string((int)(i / 3)) + " : " + to_string((int)(j / 3))};

                if((u_s.find(key_row) != u_s.end()) or (u_s.find(key_column) != u_s.end()) or (u_s.find(key_sub_square) != u_s.end()))
                {
                    return false;
                }

                u_s.insert(key_row);

                u_s.insert(key_column);

                u_s.insert(key_sub_square);
            }
        }

        return true;
    }
};

void debug(vector<vector<char>> &input)
{
    bool result {};

    cout<<"isValidSudoku(\n";

    display_vector_vector_char(input);

    result = Solution {}.isValidSudoku(input);

    cout<<"): "<<result;
}

int main()
{
    vector<vector<char>> input {{'5', '3', '.', '.', '7', '.', '.', '.', '.' },
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.' },
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.' },
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3' },
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1' },
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6' },
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.' },
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5' },
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9' }};

    debug(input);

    return 0;
}