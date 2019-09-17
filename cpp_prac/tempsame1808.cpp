#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#define inf 987654321
#define MAXN 10
using namespace std;
 
int board[MAXN];
int ans;
int X;
void dfs(int num, int cnt) {
    int nt = 0;
    int n = num;
    while (n != 0) {
        if (!board[n % 10])break;
        else {
            n = n / 10;
            nt++;
        }
    }
    if (n == 0) {
        if (ans > nt + cnt)ans = nt + cnt;
        return;
    }
     
    for (int i = 2;i*i <= num;i++) {
        if (num%i == 0) {
            int n = i;
            int nt = 0;
            while ( n!= 0) {
                if (!board[n % 10])break;
                else {
                    n = n / 10;
                    nt++;
                }
            }
            if (n == 0) {
                dfs(num / i, cnt + nt+1);
            }
        }
    }
}
     
int main() {
    int T;
    scanf("%d", &T);
    for (int tc = 1;tc <= T;tc++) {
        ans = inf;
        for (int i = 0;i < MAXN;i++) {
            int temp;
            scanf("%d", &temp);
            if (temp) board[i] = 1;
        }
        scanf("%d", &X);
 
        dfs(X, 1);
        if (ans != inf)printf("#%d %d\n", tc, ans);
        else printf("#%d %d\n", tc, -1);
        memset(board, 0, sizeof(board));
    }
    return 0;
}