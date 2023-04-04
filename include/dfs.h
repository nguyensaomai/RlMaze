#ifndef DFS_H
#define DFS_H

#include <mazeEnv.h>

int dfs(int row, int col);

char** mazeEnv;
int** visited;
int rows;
int cols;
int start_row;
int start_col;
int state_row;
int state_col;
int goal_row;
int goal_col;

#endif
