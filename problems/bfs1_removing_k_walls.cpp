// Given a 2D binary matrix of size N *M, where 0 represents an empty space while 1 represents a wall you cannot walk through.You are also given an integer K.
// You can walk up, down, left, or right.
// Given that you can remove up to K walls, return the minimum number of steps to walk from the top left corner(0, 0) to the bottom right corner(N - 1, M - 1).

// time-limit: 3000
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef queue<int> qi;
typedef bitset<8> bit8;

// Debug
template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vec)
{
    if (vec.empty())
    {
        out << "[]";
        return out;
    }
    out << '[';
    for (int i = 0; i < vec.size() - 1; i++)
    {
        out << vec[i] << ", ";
    }
    return out << vec.back() << ']';
}

template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &out, const std::pair<T1, T2> &pair)
{
    return out << '(' << pair.first << ", " << pair.second << ')';
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::deque<T> &deq)
{
    if (deq.empty())
    {
        out << "[]";
        return out;
    }
    out << '[';
    for (int i = 0; i < deq.size() - 1; i++)
    {
        out << deq[i] << ", ";
    }
    return out << deq.back() << ']';
}

template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &out, const std::unordered_map<T1, T2> &map)
{
    out << '{';
    for (auto it = map.begin(); it != map.end(); it++)
    {
        std::pair<T1, T2> element = *it;
        out << element.first << ": " << element.second;
        if (std::next(it) != map.end())
        {
            out << ", ";
        }
    }
    return out << '}';
}

template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &out, const std::map<T1, T2> &map)
{
    out << '{';
    for (auto it = map.begin(); it != map.end(); it++)
    {
        std::pair<T1, T2> element = *it;
        out << element.first << ": " << element.second;
        if (std::next(it) != map.end())
        {
            out << ", ";
        }
    }
    return out << '}';
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::unordered_set<T> &set)
{
    out << '{';
    for (auto it = set.begin(); it != set.end(); it++)
    {
        T element = *it;
        out << element;
        if (std::next(it) != set.end())
        {
            out << ", ";
        }
    }
    return out << '}';
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::multiset<T> &set)
{
    out << '{';
    for (auto it = set.begin(); it != set.end(); it++)
    {
        T element = *it;
        out << element;
        if (std::next(it) != set.end())
        {
            out << ", ";
        }
    }
    return out << '}';
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::unordered_multiset<T> &set)
{
    out << '{';
    for (auto it = set.begin(); it != set.end(); it++)
    {
        T element = *it;
        out << element;
        if (std::next(it) != set.end())
        {
            out << ", ";
        }
    }
    return out << '}';
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::set<T> &set)
{
    out << '{';
    for (auto it = set.begin(); it != set.end(); it++)
    {
        T element = *it;
        out << element;
        if (std::next(it) != set.end())
        {
            out << ", ";
        }
    }
    return out << '}';
}

// Source: https://stackoverflow.com/a/31116392/12128483
template <typename Type, unsigned N, unsigned Last>
struct TuplePrinter
{
    static void print(std::ostream &out, const Type &value)
    {
        out << std::get<N>(value) << ", ";
        TuplePrinter<Type, N + 1, Last>::print(out, value);
    }
};

template <typename Type, unsigned N>
struct TuplePrinter<Type, N, N>
{
    static void print(std::ostream &out, const Type &value)
    {
        out << std::get<N>(value);
    }
};

template <typename... Types>
std::ostream &operator<<(std::ostream &out, const std::tuple<Types...> &value)
{
    out << '(';
    TuplePrinter<std::tuple<Types...>, 0, sizeof...(Types) - 1>::print(out, value);
    return out << ')';
}

#define MP make_pair
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define ALL(a) a.begin(), a.end()
#define PI acos(-1)
#define ms(x, y) memset(x, y, sizeof(x))
#define inf 1e9
#define INF 1e16
#define pb push_back
#define MAX 100005
#define debug(a, b) cout << a << ": " << b << endl
#define Debug cout << "Reached here" << endl
#define prnt(a) cout << a << "\n"
#define mod 1000000007LL
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORr(i, a, b) for (int i = (a); i >= (b); i--)
#define itrALL(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)
#define lc ((node) << 1)
#define rc ((node) << 1 | 1)
#define VecPrnt(v)           \
    FOR(J, 0, v.size())      \
        cout << v[J] << " "; \
    cout << endl
#define endl "\n"
#define PrintPair(x) cout << x.first << " " << x.second << endl
#define EPS 1e-9
#define ArrPrint(a, st, en)        \
    for (int J = st; J <= en; J++) \
        cout << a[J] << " ";       \
    cout << endl;

// /* 128 bit integer reading */

// __int128 read()
// {
//     __int128 x = 0, f = 1;
//     char ch = getchar();
//     while (ch < '0' || ch > '9')
//     {
//         if (ch == '-')
//             f = -1;
//         ch = getchar();
//     }
//     while (ch >= '0' && ch <= '9')
//     {
//         x = x * 10 + ch - '0';
//         ch = getchar();
//     }
//     return x * f;
// }
// void print(__int128 x)
// {
//     if (x < 0)
//     {
//         putchar('-');
//         x = -x;
//     }
//     if (x > 9)
//         print(x / 10);
//     putchar(x % 10 + '0');
// }
// bool cmp(__int128 x, __int128 y) { return x > y; }

// /* a = read() for reading the integer and print(a) to print that integer.  */

#define MX 10e9
#define MAX 100000
const int SMX = 10e9;
const int MOD = (int)1e9 + 7;



int shortestPath(vector<vector<int>> grid, int k){
    int n = grid.size();
    int m = grid[0].size(); 

    if(n == 1 and m==1 and (grid[0][0]==0 or k>=1)){
        return 0;
    }

    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(k+1, false)));

    int steps = 0; 

    queue<vector<int>> q;
    q.push({0, 0, k}); 


    int dir1[4] = {1, -1, 0, 0}; 
    int dir2[4] = {0, 0, -1, 1}; 

    while(!q.empty()){
        int size = q.size(); 

        steps++; 

        while(size--){
            auto curr = q.front();
            int i = curr[0], j = curr[1], w = curr[2]; 

            q.pop();

            visited[i][j][w] = true; 

            FOR(dir, 0, 4){
                int new_x = i + dir1[dir]; 
                int new_y = j + dir2[dir]; 
                int new_w = w; 

                if(new_x >= 0 and new_x < n and new_y >= 0 and new_y < m){
                    if(grid[new_x][new_y] == 0 and !visited[new_x][new_y][new_w]){
                        if(new_x == n-1 and new_y == m-1){
                            return steps; 
                        }
                        q.push({new_x, new_y, new_w});
                        visited[new_x][new_y][new_w] = true;    
                    }
                    else if (grid[new_x][new_y] == 1 and new_w >= 1 and !visited[new_x][new_y][new_w-1]){
                        if (new_x == n - 1 and new_y == m - 1)
                        {
                            return steps;
                        }
                        q.push({new_x, new_y, new_w-1});
                        visited[new_x][new_y][new_w - 1] = true; 
                    }
                }
            }
        }
    }

    return -1; 
}



int main()
{
    vector<vector<int>> mat = {{0, 0, 0}, {0, 0, 1}, {0, 1, 0}};
    int K = 1;

    // Function call
    cout << shortestPath(mat, K);   

    return 0;
}
