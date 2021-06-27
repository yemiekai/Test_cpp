#ifndef _36_VALID_SUDOKU_H
#define _36_VALID_SUDOKU_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <string>

#include <vector>
#include <map>
#include <set>

// 36 有效的数独
class Solution36 {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board);

    void test();

};

#endif