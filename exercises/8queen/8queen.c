#include <stdio.h>
#include <stdlib.h>

// the row of the board
static int n = 0;

int **solutions;
int *solution;

// try insertion and check if the new insertion of i-th row in j-th position is valid
int is_insert_valid(int *, int, int);

// at m-th row, and try to go to next step
int solve(int);

void show_solution(int *);

int main(void)
{

    printf("Input number of rows:\n");
    scanf("%d", &n);

    solutions = (int **)malloc(1000 * sizeof(int *)); // 1k不知道够不够 10皇后，再大就不行了
    // show_solution(solutions[100]); // cant execute for undefined reference to memory

    int ans = solve(-1);

    printf("Answer for %d queens is %d.\n", n, ans);
    // if (ans)
    // {
    //     printf("One possible solution is:\n");
    //     show_solution(solutions[1]);
    // }

    return 0;
}

int is_insert_valid(int *solution, int i, int j)
{
    solution[i] = j;
    for (int k = 0; k < i; k++)
    {
        if (j == solution[k]) // in one column, invalid
        {
            return 0;
        }
        else if ((k + solution[k]) == (i + j) || (i - j == k - solution[k])) // share a diagonal, invalid
        {
            return 0;
        }
    }
    return 1;
}

int solve(int m) // m-th row, n*n board
{
    static int count_solutions;

    if (m == -1) // begin, put counter and solution to 0
    {
        // printf("Go\n");
        count_solutions = 0;
        solution = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            solution[j] = -1;
        }
        *(solutions+count_solutions) = solution;
        // printf("Initialized with %d %d %d %d\n", solution[0],solution[1],solution[2],solution[3]);
        solve(0);
    }
    else if (m == n) // end
    {
        // printf("Arrived\n");
        // solutions[count_solutions] = (int*)malloc(n*sizeof(int));
        *(solutions+count_solutions) = solution;
        // show_solution(solution); // can show correctly these solutions
        if (count_solutions == 1)
        {
            printf("Possible case: \n");
            show_solution(solutions[count_solutions]);
        }
        count_solutions++;
    }
    else
    {
        // printf("m = %d now, %d %d %d %d\n", m, solution[0], solution[1], solution[3], solution[4]);
        for (int j = 0; j < n; j++)
        {
            if (is_insert_valid(solution, m, j))
            {
                solution[m] = j;
                // printf("%d %d %d %d valid\n",solution[0], solution[1], solution[3], solution[4]);
                solve(m + 1);
            }
            else // try failed, retry a value at m row
            {
                continue;
            }
        }
    }

    return count_solutions;
}

void show_solution(int *solution)
{
    // allocate memory to the board
    int **board = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        *(board + i) = (int *)malloc(n * sizeof(int));
    }

    // insert solution positions
    for (int j = 0; j < n; j++)
    {
        printf("---");
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = (solution[i] == j) ? 1 : 0;
            printf("%d  ", board[i][j]);
        }
        printf("\n");
    }
    for (int j = 0; j < n; j++)
    {
        printf("---");
    }
    printf("\n");
}
