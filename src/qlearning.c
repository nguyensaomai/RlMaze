#include "qlearning.h"
#include "mazeEnv.h"



double learning_rate = 0.5;
int number_episode = 1000;
double return_rate = 0.9;
int horizon = 1000;
float epsilon = 0.3;


void init_q()
{
    q = malloc(rows * cols * sizeof(double *));
    for (int i = 0; i < rows * cols; i++)
    {
        q[i] = malloc(number_actions * sizeof(double));
        for (int j = 0; j<number_actions; j++){
            q[i][j]= 0;
        }
    }
    
}

//transform each actions into a specific int 
int actions_to_int(action a){
    if (a == up)
    {
        return 0;
    }
    else if (a == down)
    {
        return 1;
    }
    else if (a == right)
    {
        return 2;
    }
    else 
    {
        return 3;
    }
}

//Do the opposite transformation 
action int_to_action(int i){
    if (i==0){
        return up;
    }
    else if (i ==1){
        return down;
    }
    else if (i==2){
        return right;
    }
    else {
        return left;
    }
        
    
}


//Find the maximal possible outcome for a specific position

double max_actions(int s){
    double max = q[s][0];
    for (int j =1; j<number_actions; j++){
        if (q[s][j]>max){
            max = q[s][j];
        }
    }
    return max;
}

// Find the action that maximise the outcome for a specific position

int best_action(int s){
    double max = q[s][0];
    int id_max = 0;
    for (int j =1; j<number_actions; j++){
        if (q[s][j]>max){
            id_max = j;
        }
    }
    return id_max;
}

void epsilon_greedy(){
    for (int i =0; i< number_episode; i++ ){
        int s = start_col +start_row*cols; //Initialization of the state
        int n = 0; //Number of actions performed in the episode
        int done =0;

        //Initialization of the variables 
        int next_action;
        float tirage;
        struct envOutput Env;
        int next_s;
        srand(time(NULL));


        //Pick an action unless the goal is reached 
        while (n<horizon && done ==0){

            //Pick an action according to the epsilon greedy algorithme

            next_action = 0;
            tirage = 0;
            
            tirage = rand() / (RAND_MAX +1.0);
            

            if (tirage <epsilon){
                next_action = env_action_sample();
            }
            else {
                next_action = best_action(s);
            }

            //Upadating Q with the new state
        
            Env = mazeEnv_step(int_to_action(next_action));
            next_s = Env.new_col + Env.new_row*cols;
            done = Env.done;

            q[s][next_action]= q[s][next_action] + learning_rate*(Env.reward + return_rate*max_actions(next_s)- q[s][next_action]);
            s = next_s;
            n++;


        }

    }

}


void print_q (){
    for (int i = 0; i < rows * cols; i++){
        printf("%d : up %lf down %lf right %lf left %lf \n", i, q[i][0], q[i][1], q[i][2], q[i][3]);

    }
}

void destroy_q(){
    for (int i = 0; i < rows * cols; i++)
    {
        free( q[i] );
    }
    free (q);
}





















