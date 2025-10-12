#include <bits/stdc++.h>
using namespace std;

int solve(int dimension[], int n)
{
    int dp[n - 1][n - 1];// creating table of size less than dimension array size
    int s = sizeof(dp) / sizeof(dp[0]); //storing size of dp

    for (int g = 0; g < s; g++)
    {

        for (int i = 0, j = g; j < s; i++, j++)
        {
            if (g == 0) //when gap is zero;
            {
                dp[i][j] = 0;
            }
            else if (g == 1) //when gap is one
            {
                dp[i][j] = dimension[i] * dimension[j] * dimension[j + 1];
            }
            else // when gap is more than two
            {
                int min = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    //dp[i][k] is left half
                    //dp[k+1][j+1] is right half
                    int left = dp[i][k];//cost of left opertaion
                    int right = dp[k + 1][j];//cost of right operation
                    int mc = dimension[i] * dimension[k + 1] * dimension[j + 1]; //multiplication cost of left and right 
                    int tc = left + right + mc;// total cost;
                    if (tc < min)// we have have to take minimum cost of all the cost
                    {
                        min = tc;
                    }
                }
                dp[i][j] = min;// storing our minimum cost in our table
            }
        }
    }
    return dp[0][s - 1];
}

int main()
{
    int dimension[] = {10, 20, 30};
    int n = sizeof(dimension) / sizeof(dimension[0]);
    cout << "answer" << endl;
    cout << solve(dimension, n);
}