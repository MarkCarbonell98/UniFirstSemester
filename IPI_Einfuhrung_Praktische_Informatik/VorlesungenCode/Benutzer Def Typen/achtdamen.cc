#include "fcpp.hh"
#include <string>

const int board_size = 8;
typedef int columns[boards_size];

bool good_position(int new_row, columns queen_cols, int new_col) 
{
    for(int row = 0; row<new_row; row++)
        if((queen_cols[row] == new_col) || (new_row - row == abs(queen_cols[row - new_col])))
            return false;
        return true;
}

void display_board(columns queen_cols)
{
    for(int r = 0; r < board_size; r++) 
    {
        std::string s("");
        for(int c = 0; c < board_size; c++) 
            if(c != queen_cols[r])
                s += ".";
            else 
                s += "D";
            print(s);
    }
    print(" ");
}

    // TODO FIX THIS
int queen_configs(int row, columns queen_cols)
{
    if(row == board_size) {
        display_board(queen_cols);
        return 1;
    } else {
        int nr_configs = 0;
        for(int col = 0; col < board_size; col++) 
            if(good_position(row, queen_cols, col))
            {
                queen_cols[row] = col;
                nr_configs += queen_configs(row+1, queen_cols);
            }
        return nr_configs;
    }
}

int main(int argc, char const *argv[])
{
    columns queen_cols;
    print("solutions: ");
    print(queen_configs(0, queen_cols));
    
    return 0;
}
