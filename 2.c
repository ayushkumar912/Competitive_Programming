#include <stdio.h>

struct P
{
    int id;
    int bt;
    int wt;
    int tat;
};

void waitingtime(struct P p[], int n)
{
    p[0].wt = 0;
    for (int i = 1; i < n; i++)
    {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
    }
}

void turnaroundtime(struct P p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i].tat = p[i].wt + p[i].bt;
    }
}

void avg(struct P p[], int n)
{
    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++)
    {
        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }
    printf("Avg WT: %.2f\n", (float)total_wt / n);
    printf("Avg TAT: %.2f\n", (float)total_tat / n);
}

void print(struct P p[], int n)
{
    printf("\nID\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\n", p[i].id, p[i].bt, p[i].wt, p[i].tat);
    }
}


void sjf(struct P p[], int n)
{
    printf("\nSJF:\n");
    struct P tmp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (p[i].bt > p[j].bt)
            {
                tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;
            }
        }
    }
    waitingtime(p, n);
    turnaroundtime(p, n);
    print(p, n);
    avg(p, n);
}




int main()
{
    int n, q;
    printf("number of processes: ");
    scanf("%d", &n);

    struct P p[n];

    for (int i = 0; i < n; i++)
    {
        printf("burst time %d: ", i + 1);
        p[i].id = i + 1;
        scanf("%d", &p[i].bt);
    }
    sjf(p, n);

    return 0;
}
