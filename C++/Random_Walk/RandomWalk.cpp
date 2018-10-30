//Author: William Seagle
//Name: Random Walk Simulation [v2]
//Date 22Sep15

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <unistd.h>

using namespace std;

//User Input Variables
int seed;   //User input of seed
int times;  //User input of loops
int size;   //User input of grid size

//Board Variables
int board[26][26];  //Maximum size of board
int posx;           //Position on board X Coord
int posy;           //Position on board Y Coord
int startPos;       //Size divided by 2 = starting position

//Memory Variables
int clk;        //Stores initial times entry
int rep = 0;    //Stores amount of repetition
int dir;        //Stores the last direction of the entity
char cardinal[4] = {'N','S','E','W'};

//Error Variables
int err = 0;
string error[6] =  { "Errors: None","Errors: Exceeded Maximum Repetitions",
                     "Errors: Walked off Board to the South!",
                     "Errors: Walked off Board to the North!",
                     "Errors: Walked off Board to the East!",
                     "Errors: Walked off Board to the West!"};

//Draws a square grid of 0's with a size depending on the "size" variable
void DrawBoard()
{
    int xAxis = 0;
    int yAxis = 0;

    for(;;)
    {
        xAxis++;
        cout << board[xAxis][yAxis];
        cout << " ";

        //When the X Axis reaches size borders start new line
        if (xAxis == size)
        {
            cout << endl;
            yAxis++;
            xAxis = 0;
        }

        //When the Y Axis reaches size borders, finish Draw
        if (yAxis == size)
        {
            xAxis = 0;
            yAxis = 0;
            break;
        }
    }
}

int main(int nNumberofArgs, char* pszArgs[])
{
    //Intro----------------------------------------

    while(size < 1 || size > 25)
    {
    system("cls");
    cout << "Random Walk Simulator v2" << endl;
    //User determines size of grid
    cout << "Size Maximum 25" << endl;
    cout << "Size: ";
    cin >> size;
    }

    //User determines what seed random will use
    cout << "Seed: ";
    cin >> seed;

    //User determines how many times the loop runs
    cout << "Iterations: ";
    cin >> times;
    clk = times;

    //Take user size to determine the center starting position
    startPos = size/2;
    posx = startPos;
    posy = startPos;
    board[posx][posy] = 1;

    srand(seed);
    system("cls");
    //---------------------------------------------

    for(;times > 1; --times)
    {
        dir = (rand() %4);
        rep++;
        if(dir == 0)
        {
            board[posx][--posy] = ++board[posx][posy];
        }
        if(dir == 1)
        {
            board[posx][++posy] = ++board[posx][posy];
        }
        if(dir == 2)
        {
            board[++posx][posy] = ++board[posx][posy];
        }
        if(dir == 3)
        {
            board[--posx][posy] = ++board[posx][posy];
        }

        if(board[posx][posy] == 10)
        {
            --board[posx][posy];
            err = 1;
            break;
        }
        if(posx == size)
        {
            err = 4;
            break;
        }
        if(posx == 0)
        {
            err = 5;
            break;
        }
        if(posy == size)
        {
            err = 2;
            break;
        }
        if(posy == 0)
        {
            err = 3;
            break;
        }
        system("cls");
        DrawBoard();
        cout << endl << "Size: " << size;
        cout << endl << "Seed: " << seed;
        cout << endl << "Attempted Iterations: " << clk;
        cout << endl << "Succesful Iterations: " << (rep + 1) << endl;
        cout << error[err] << endl;
        cout <<"Direction: " << cardinal[dir] << endl;
        usleep(300000);
    }
    system("cls");
    DrawBoard();
    cout << endl << "Size: " << size;
    cout << endl << "Seed: " << seed;
    cout << endl << "Attempted Iterations: " << clk;
    cout << endl << "Succesful Iterations: " << (rep + 1) << endl;
    cout << error[err] << endl;
}
