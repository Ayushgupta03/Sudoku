#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isSafe(int **grid,int row,int col,int num);
bool unassignvalue(int **grid,int &row,int &col);
bool solvesudoku(int **grid)
{
    int row,col;
    if(!unassignvalue(grid,row,col))
        return true;
    for(int num=1;num<=9;num++)
    {
        if(isSafe(grid,row,col,num))
        {
            grid[row][col] = num;
            if(solvesudoku(grid))
                return true;
            grid[row][col]=0;    
        }
    }
    return false;
}
bool unassignvalue(int **grid,int &row,int &col)
{
    for(row=0;row<9;row++)
    {
        for(col=0;col<9;col++)
        {
            if(grid[row][col]==0)
                return true;
        }
    }
    return false;
}
bool isSafe(int **grid,int row,int col,int num)
{
    for(int i=0;i<9;i++)
    {
        if(grid[row][i]==num)
            return false;
    }
    for(int i=0;i<9;i++)
    {
        if(grid[i][col]==num)
            return false;
    }
    int boxrow = row - row%3;
    int boxcol = col - col%3;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(grid[boxrow+i][boxcol+j]==num)
                return false;
        }
    }
    if(grid[row][col]!=0)
        return false;
    return true;
}
void print(int **grid)
{
	cout<<"Solution is:"<<endl;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main() {
//	int grid[9][9]={{3, 0, 6, 5, 0, 8, 4, 0, 0},  
//                      {5, 2, 0, 0, 0, 0, 0, 0, 0},  
//                      {0, 8, 7, 0, 0, 0, 0, 3, 1},  
//                      {0, 0, 3, 0, 1, 0, 0, 8, 0},  
//                      {9, 0, 0, 8, 6, 3, 0, 0, 5},  
//                      {0, 5, 0, 0, 9, 0, 6, 0, 0},  
//                      {1, 3, 0, 0, 0, 0, 2, 5, 0},  
//                      {0, 0, 0, 0, 0, 0, 0, 7, 4},  
//                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};  
	int ** grid = new int*[9];
	cout<<"Enter the values(row wise) for sudoku,instead of blank put zero"<<endl;
	for(int i=0;i<9;i++)
	{
		grid[i] = new int[9];
		for(int j=0;j<9;j++)
		{
			cin>>grid[i][j];
		}
	}
    if(solvesudoku(grid))
    {
        print(grid);
    }
    else
        cout<<"no solution exist";
	
	return 0;
}
