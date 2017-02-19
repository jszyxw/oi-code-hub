
/*{{{*/
//#pragma GCC optimize("O3")

#include <bits/stdc++.h>

#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

typedef long long ll;
typedef std::pair<int, int> pii;

std::string Name = __FILE__;
std::string iput = Name.substr(0, Name.length() - 4) + ".in";
std::string oput = Name.substr(0, Name.length() - 4) + ".out";

template <class T> inline bool chkmin(T &x, T y) { return x > y ? x = y, true : false; }
template <class T> inline bool chkmax(T &x, T y) { return x < y ? x = y, true : false; }

template <class T> inline T &read(T &x)
{
    static int f;
    static char c; 
    for (f = 1; !isdigit(c = getchar()); ) {
        if (c == '-')
            f = -1;
    }
    for (x = 0; isdigit(c); c = getchar()) {
        x = x * 10 + c - 48;
    }
    return x *= f;
}
 
template <class T> inline void write(T x, const char p = '\n')
{
    static int top;
    static int s[30];
    if (x < 0) {
        x = -x;
        putchar('-');
    }
    do s[++ top] = x % 10 + 48;
    while (x /= 10);
    while (top)
        putchar(s[top --]);
    putchar(p);
}
/*}}}*/
 
const int maxn = 1e5 + 5;
const int maxk = 20 + 1;
 
int n;
int m;
int a[maxn];
int dp[maxn][maxk][3];


void exec()
{
    read(n);
    read(m);
    for (int i = 1; i <= n; ++ i) {
        char c;
        while (!isalpha(c = getchar())) ;
        if (c == 'P')
            a[i] = 0;
        else if (c == 'S')
            a[i] = 1;
        else
            a[i] = 2;
    }
    dp[1][0][0] = (a[1] == 0);
    dp[1][0][1] = (a[1] == 1);
    dp[1][0][2] = (a[1] == 2);
    static int ans;
    for (int i = 2; i <= n; ++ i) {
        for (int j = 0; j <= m; ++ j) {
            for (int k = 0; k < 3; ++ k) {
                dp[i][j][k] = dp[i - 1][j][k] + (a[i] == k);
                for (int l = 0; j && l < 3; ++ l)
                    chkmax(dp[i][j][k], dp[i - 1][j - 1][l] + (a[i] == k));
                chkmax(ans, dp[i][j][k]);
            }
        }
    }
    write(ans);
}

/*{{{*/
int main() 
{
    if (fopen(iput.c_str(), "r") != NULL) {
        freopen(iput.c_str(), "r", stdin);
        freopen(oput.c_str(), "w", stdout);
    }

    exec();

    fclose(stdin);
    fclose(stdout);

    return 0;
}
/*}}}*/

