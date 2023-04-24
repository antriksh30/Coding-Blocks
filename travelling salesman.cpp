//write a program for travelling salesman problem using branch and bound algorithm
#include <bits/stdc++.h>
using namespace std;

int n;
int a[10][10];
int visited[10];
int ans = INT_MAX;
int cost = 0;
int final_path[10];
int path[10];
int pos = 0;
int least = INT_MAX;

void copy_to_final(int curr_path[])
{
    for (int i = 0; i < n; i++)
        final_path[i] = curr_path[i];
    final_path[n] = curr_path[0];
}

void TSP(int curr_bound, int curr_weight, int level, int curr_path[])
{
    if (level == n)
    {
        if (a[curr_path[level - 1]][curr_path[0]] != 0)
        {
            int curr_res = curr_weight + a[curr_path[level - 1]][curr_path[0]];
            if (curr_res < ans)
            {
                copy_to_final(curr_path);
                ans = curr_res;
            }
        }
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[curr_path[level - 1]][i] != 0 && visited[i] == 0)
        {
            int temp = curr_bound;
            curr_weight += a[curr_path[level - 1]][i];
            if (level == 1)
                curr_bound -= ((a[0][curr_path[0]] + a[curr_path[level - 1]][i]) / 2);
            else
                curr_bound -= ((a[curr_path[level - 2]][curr_path[level - 1]] + a[curr_path[level - 1]][i]) / 2);
            if (curr_bound + curr_weight < ans)
            {
                curr_path[level] = i;
                visited[i] = 1;
                TSP(curr_bound, curr_weight, level + 1, curr_path);
            }
            curr_weight -= a[curr_path[level - 1]][i];
            curr_bound = temp;
            memset(visited, 0, sizeof(visited));
            for (int j = 0; j <= level - 1; j++)
                visited[curr_path[j]] = 1;
        }
    }
}

void TSP()
{
    int curr_path[n + 1];
    memset(curr_path, -1, sizeof(curr_path));
    memset(visited, 0, sizeof(curr_path));
    for (int i = 0; i < n; i++)
        curr_path[i] = -1;
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    curr_path[0] = 0;
    visited[0] = 1;
    TSP(0, 0, 1, curr_path);
}

int main()
{
    cout << "Enter the number of cities: ";
    cin >> n;
    cout << "Enter the cost matrix: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    TSP();
    cout << "Minimum cost: " << ans << endl;
    cout << "Path: ";
    for (int i = 0; i <= n; i++)
    {
        cout << final_path[i] << " ";
    }
    cout << endl;
    return 0;
}

