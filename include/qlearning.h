#ifndef QLEARNING_H
#define QLEARNING_H

#include <dfs.h>

extern char** mazeEnv;
extern int** visited;
extern int rows;
extern int cols;
extern int start_row;
extern int start_col;
extern int state_row;
extern int state_col;
extern int goal_row;
extern int goal_col;

extern double** q;




void init_q();







#endif /* QLEARNING_H */
