#include<iostream>
#include<cstdlib>


class Sudoku{
public:
static int ans;
static const int size=144;
Sudoku();
Sudoku(int *sm);
void GiveQuestion();
void ReadIn();
int  Solve();
bool checkcolumn(int index);
bool checkrow(int index);
bool checkgrid(int index);
int getzero();
int pop(int *pos,int &posindex);
void push(int *pos,int &posindex,int index);
private:
int map[size];

};
