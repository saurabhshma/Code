//https://www.hackerrank.com/challenges/2d-array
#include <bits/stdc++.h>

using namespace std;

int findSum(vector< vector<int> > &A, int x, int y)
{
    int sum = 0;
    for(int i = y; i < y + 3; i++)
        sum += A[x][i] + A[x + 2][i];
    return (sum + A[x + 1][y + 1]);
}

int main(){
    vector< vector<int> > arr(6,vector<int>(6));
    for(int arr_i = 0;arr_i < 6;arr_i++){
       for(int arr_j = 0;arr_j < 6;arr_j++){
          cin >> arr[arr_i][arr_j];
       }
    }
    int max = INT_MIN;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            int temp = findSum(arr, i, j);
            if(temp > max)
                max = temp;
        }
    }
    cout << max << "\n";
    return 0;
}