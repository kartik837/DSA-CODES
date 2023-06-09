#include <stdio.h>
#include <stdbool.h>
#define n 9
void solution(int board[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
             printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}
int isSafe(int board[n][n], int row, int col, int num)
{
    for (int i = 0; i < n; i++)
    {
      if (board[row][i] == num || board[i][col] == num)
      {
         return 0;
      }
    }
    int subRow = (row / 3) * 3;
    int subCol = (col / 3) * 3;
    for (int i = subRow; i < subRow + 3; i++)
    {
        for (int j = subCol; j < subCol + 3; j++)
        {
           if (board[i][j] == num)
           {
               return 0;
           }
        }
    }
    return 1;
}

int solveSudoku(int board[n][n], int row, int col)
{
    if (row >= n)
        return 1;

    if (board[row][col] != 0)
    {
        if (col == n-1)
        {
             return solveSudoku(board, row+1, 0);
        }
        else
        {
            return solveSudoku(board, row, col+1);
        }
    }

    for (int num = 1; num <= n; num++)
    {
        if (isSafe(board, row, col, num))
        {
            board[row][col] = num;

            if (col == n-1)
            {
                if (solveSudoku(board, row+1, 0))
                    return 1;
            }
            else
            {
                if (solveSudoku(board, row, col+1))
                    return 1;
            }

            board[row][col] = 0;
        }
    }

    return 0;
}
int main()
{
    int board[n][n] = { {3, 0, 6, 5, 0, 8, 4, 0, 0},
                        {5, 2, 0, 0, 0, 0, 0, 0, 0},
                        {0, 8, 7, 0, 0, 0, 0, 3, 1},
                        {0, 0, 3, 0, 1, 0, 0, 8, 0},
                        {9, 0, 0, 8, 6, 3, 0, 0, 5},
                        {0, 5, 0, 0, 9, 0, 6, 0, 0},
                        {1, 3, 0, 0, 0, 0, 2, 5, 0},
                        {0, 0, 0, 0, 0, 0, 0, 7, 4},
                        {0, 0, 5, 2, 0, 6, 3, 0, 0} }; // Initialize the board with zeros
    solution(board);
    printf("\nThe solution to the above suduko board is : \n");
    /*printf("Enter the board of sudoku\n");
    for (int i = 0; i < n; i++)
    {
       for (int j = 0; j < n; j++)
       {
           scanf("%d", &board[i][j]);
       }
    }*/
    if (solveSudoku(board, 0, 0))
    {
        solution(board);
    }
    else
    {
        printf("No solution exists.\n");
    }
    return 0;
}
//One more input
/*
8 4 9 0 0 3 5 7 0

0 1 0 0 0 0 0 0 0

7 0 0 0 9 0 0 8 3

0 0 0 9 4 6 7 0 0

0 8 0 0 5 0 0 4 0

0 0 6 8 7 2 0 0 0

5 7 0 0 1 0 0 0 4

0 0 0 0 0 0 0 1 0

0 2 1 7 0 0 8 6 5*/
//editing backtracking_logic_2_sodoku_problem
