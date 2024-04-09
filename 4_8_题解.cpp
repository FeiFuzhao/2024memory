#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 510;

int n, m, K;
int s[N][N];

int main()
{
    scanf("%d%d%d", &n, &m, &K);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &s[i][j]);
            s[i][j] += s[i - 1][j];
        }

    LL res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            for (int l = 1, r = 1, sum = 0; r <= m; r++)
            {
                sum += s[j][r] - s[i - 1][r];
                while (sum > K)
                {
                    sum -= s[j][l] - s[i - 1][l];
                    l++;
                }
                res += r - l + 1;
            }

    printf("%lld\n", res);
    return 0;
}
