// C++ program for Knight Tour problem
#include <bits/stdc++.h>
using namespace std;

int n;

int exploreAll(int x, int y, int movei, vector<vector<int>> &solution,
				int xMove[], int yMove[]);

/* A utility function to check if i,j are
valid indexes for N*N chessboard */
int isSafe(int x, int y, vector<vector<int>> &solution)
{
	return (x >= 0 && x < n && y >= 0 && y < n
			&& solution[x][y] == -1);
}

/* A utility function to print
solution matrix sol[N][N] */
void printSolution(vector<vector<int>> &solution)
{
    for(auto it : solution){
        for(auto it1 : it){
            cout<<it1<<" ";
        }
        cout<<"\n";
    }
}

int solve()
{
    vector<vector<int>> solution(n, vector<int>(n, -1));

	int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	// Since the Knight is initially at the first block
	solution[0][0] = 0;

	/* Start from 0,0 and explore all tours using
	exploreAll() */
	if (exploreAll(0, 0, 1, solution, xMove, yMove) == 0) {
		cout << "Solution does not exist";
		return 0;
	}
	else
		cout<<"solution is\n";
        printSolution(solution);
	return 1;
}

/* A recursive utility function to solve Knight Tour
problem */
int exploreAll(int x, int y, int movei, vector<vector<int>> &solution,
				int xMove[8], int yMove[8])
{
	int k, next_x, next_y;
	if (movei == n * n)
		return 1;

	/* Try all next moves from
	the current coordinate x, y */
	for (k = 0; k < 8; k++) {
		next_x = x + xMove[k];
		next_y = y + yMove[k];
		if (isSafe(next_x, next_y, solution)) {
			solution[next_x][next_y] = movei;
			if (exploreAll(next_x, next_y, movei + 1, solution,
							xMove, yMove)
				== 1)
				return 1;
			else
				
			// backtracking
				solution[next_x][next_y] = -1;
		}
	}
	return 0;
}

// Driver Code
int main()
{
	// Function Call
    cout<<"please enter the size of chess board\n";
    cin>>n;
	solve();
	return 0;
}