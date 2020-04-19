#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " " << x << endl;
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; i < n; i++)
#define ff first
#define ss second
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define mii map<int, int>
#define pqb priority_queue<int>                   //min heap
#define pqs priority_queue<int, vi, greater<int>> //max heap
#define setbits(x) __builtin_popcountll(x)        //number of 1s
#define zrobits(x) __builtin_ctzll(x)             //number of zeroes before first occurence of 1
#define mod 1000000007
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n];
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)

template <typename... T>
void read(T &... args)
{
    ((cin >> args), ...);
}

template <typename... T>
void write(T &... args)
{
    ((cout << args << " "), ...);
}

void inout()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
}

int32_t main()
{
    inout();
    int t;
    cin >> t;
    mk(teacher,t,int);
    mk(student,t,int);
    mk(ans,t,int);
    int count = 0;
    int i, temp;
    fo(i, t)
    {
        cin >> teacher[i];
    }
    fo(i, t)
    {
        cin >> student[i];
    }
    fo(i,t){
        ans[i] = student[i] - teacher[i];
    }
    sort(ans,ans+t);
    fo(i, t)
    {
        auto it = lower_bound(ans+i+1,ans+t,-ans[i]); //returns the index of the smallest number greater than -ans[i]
        int id = it - ans;  //stores the number of pairs with the ith number
        count += (id - (i + 1)); //adds the number of pairs of every ith number
    }
    cout << count<< '\n';
    return 0;
}
