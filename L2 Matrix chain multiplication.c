#include <stdio.h>

void order(int i, int j, int s[30][30], char *ch) {
    if (i == j) {
        printf("%c", (*ch)++);
        return;
    }
    printf("(");
    order(i, s[i][j], s, ch);
    order(s[i][j] + 1, j, s, ch);
    printf(")");
}

int main() {
    int n, i, j, k, l;
    int p[30];
    int m[30][30];
    int s[30][30];
    int INF = 1000000000;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter dimensions (p[0] p[1] ... p[n]):\n");
    for (i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    for (i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    for (l = 2; l <= n; l++) {
        for (i = 1; i <= n - l + 1; i++) {
            j = i + l - 1;
            m[i][j] = INF;
            for (k = i; k < j; k++) {
                int q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    char ch = 'A';
    printf("Optimal Parenthesization: ");
    order(1, n, s, &ch);
    printf("\nMinimum number of multiplications: %d\n", m[1][n]);

    return 0;
}

