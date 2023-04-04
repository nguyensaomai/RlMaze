#include "qlearning.h"


double alpha = 0.5;

void init_q()
{
    q = malloc(rows * cols * sizeof(double *));
    for (int i = 0; i < rows * cols; i++)
    {
        q[i] = malloc(number_actions * sizeof(double));
    }
}























