#include <stdio.h>
#include <string.h>
#include "robots.h"

/* --- Some constants and types are defined in robots.h (use in your TODOs and do NOT modify, and do NOT redefine them here) --- */

/* Direction tables for convenience (do NOT modify) */
static const int DX[4]       = { 0, 1, 0,-1 };  // step in x for N,E,S,W
static const int DY[4]       = { 1, 0,-1, 0 };  // step in y for N,E,S,W
static const Direction LEFT_OF[4]  = { DIR_W, DIR_N, DIR_E, DIR_S };
static const Direction RIGHT_OF[4] = { DIR_E, DIR_S, DIR_W, DIR_N };


/* -------- TODOs: implement the following helper functions -------- */

/* Convert a direction character (`N',`E',`S',`W') to a Direction value
   If c is not one of these, return DIR_N by default. */
Direction dir_from_char(char c)
{
    if (c == 'N') return DIR_N;
    else if (c == 'E') return DIR_E;
    else if (c == 'S') return DIR_S;
    else if (c == 'W') return DIR_W;
    else return DIR_N; /* default */
}

/* Convert a Direction value to the corresponding character (`N',`E',`S',`W'). */
char char_from_dir(Direction d)
{
   if (d == DIR_N) return 'N';
   else if (d == DIR_E) return 'E';
   else if (d == DIR_S) return 'S';
   else if (d == DIR_W) return 'W';
   else return 'N'; /* default */ 
}

/* Rotate the robot 90 degrees to the left (counterclockwise). */
void turn_left(Robot *r)
{
    r->dir = LEFT_OF[r->dir];
}

/* Rotate the robot 90 degrees to the right (clockwise). */
void turn_right(Robot *r)
{
    r->dir = RIGHT_OF[r->dir];
}

/* Compute the forward step for a given direction.
   After calling this, (*dx,*dy) should hold the change in (x,y)
   if a robot moves one cell forward while facing d. */
void forward_delta(Direction d, int *dx, int *dy)
{
    *dx = DX[d];
    *dy = DY[d];
}

/* Return 1 if (x,y) is inside the N x N grid (0 <= x < N, 0 <= y < N),
   otherwise return 0. */
int inside(int N, int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N);
}

/* Find the index of the robot whose name matches `name` in rs[0..m-1].
   Return the index if found, or -1 if there is no such robot. */
int find_robot(Robot *rs, int m, const char *name)
{
    for (int i = 0; i < m; ++i) 
    {
        if (strcmp(rs[i].name, name) == 0) 
        {
            return i; // Found the robot, return its index
        }
    }
    return -1; // Robot not found
}

/* Move R[idx] according to the defined rule. 
   - occ[y][x] is either EMPTY or a robot's index.*/
// ...existing code...
void step_forward(int N, int occ[][MAXN], Robot R[], int idx)
{
    int dx, dy;
    forward_delta(R[idx].dir, &dx, &dy);
    int new_x = R[idx].x + dx;
    int new_y = R[idx].y + dy;
    if (!inside(N, new_x, new_y)) {
        return;
    }
    if (occ[new_y][new_x] != EMPTY) {
        printf("COLLISION %s %s\n", R[idx].name, R[occ[new_y][new_x]].name);
        return;
    }
    occ[R[idx].y][R[idx].x] = EMPTY; 
    occ[new_y][new_x] = idx;         
    R[idx].x = new_x;
    R[idx].y = new_y;
}
