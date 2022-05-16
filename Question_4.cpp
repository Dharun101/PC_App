#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
 
float part_a(vector<float>& A)
{
    float mini, diff;
    mini = A[0];
    diff = A[1] - A[0];
    for (int i = 0; i < A.size(); i++)
    {
        mini = min(mini, A[i]);
        if ((A[i] - mini) > diff)
            diff = A[i] - mini; 
    }
    return diff;
}

float part_b(vector<float>& A)
{
    float mini, maxi, profit;
    mini = A[0];
    maxi = A[0];
    profit = 0;
    bool brought = false;
    for (int i = 1; i < A.size(); i++)
    {
        if (brought)
        {
            if (A[i] > A[i - 1])
            {
                maxi = A[i];
            }
            else
            {
                brought = false;
                profit += maxi - mini;
                mini = A[i];
            }
        }
        else
        {
            if (A[i] > A[i - 1])
            {
                brought = true;
                maxi = A[i];
            }
            else
                mini = A[i];
        }
    }
    if (brought)
        profit += maxi - mini;
    return profit;
}

float part_c(vector<float>& A, float x)
{
    float mini, maxi, profit;
    mini = A[0];
    maxi = A[0];
    profit = 0;
    bool brought = false;
    for (int i = 1; i < A.size(); i++)
    {
        if (brought)
        {
            if (A[i] > A[i - 1])
            {
                maxi = A[i];
            }
            else
            {
                brought = false;
                if (((1-x)*maxi - (1 + x)*mini) > 0)
                profit += maxi - mini;
                mini = A[i];
            }
        }
        else
        {
            if (A[i] > A[i - 1])
            {
                brought = true;
                maxi = A[i];
            }
            else
                mini = A[i];
        }
    }
    if (brought && (((1-x)*maxi - (1 + x)*mini) > 0))
        profit += maxi - mini;
    return profit;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    // We can invoke the functions from here.
    return 0;
}