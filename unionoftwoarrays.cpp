// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int doUnion(int *, int, int *, int);

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n, m;
        cin >> n >> m;
        int a[n], b[m];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < m; i++)
            cin >> b[i];

        cout << doUnion(a, n, b, m) << endl;
    }

    return 0;
} // } Driver Code Ends

//User function template in C++

// a and b : given array with n and m size respectively

int doUnion(int a[], int n, int b[], int m)
{
    sort(a, a + n);
    sort(b, b + m);
    int i = 0, j = 0;
    int count = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            if (i > 0 && a[i] == a[i - 1])
            {
                i++;
                continue;
            }
            count++;
            i++;
        }
        else if (a[i] == b[j])
        {
            if (i > 0 && a[i] == a[i - 1])
            {
                i++;
                continue;
            }
            if (j > 0 && b[j] == b[j - 1])
            {
                j++;
                continue;
            }
            count++;
            i++;
            j++;
        }
        else if (a[i] > b[j])
        {
            if (j > 0 && b[j] == b[j - 1])
            {
                j++;
                continue;
            }
            count++;
            j++;
        }
    }
    while (i < n)
    {
        if (i > 0 && a[i] == a[i - 1])
        {
            i++;
            continue;
        }
        count++;
        i++;
    }
    while (j < m)
    {
        if (j > 0 && b[j] == b[j - 1])
        {
            j++;
            continue;
        }
        count++;
        j++;
    }
    return count;
}