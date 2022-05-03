#include <stdio.h>

struct INSTRUCCION
{
    int pid, arrival, burst, turnaround;
};

int main()
{

    int i, num, j;
    float avg = 0.0, sum = 0.0;

    struct INSTRUCCION p[10], temp;

    printf("Introduce el número de procesos :\n");

    scanf("%d", &num);

    for (i = 0; i < num; i++)
    {
        printf("Introduce el tiempo de llegada y burst time para la intrucción %d : \n", i + 1);
        scanf("%d %d", &p[i].arrival, &p[i].burst);
        p[i].pid = i + 1;
    }
    for (i = 0; i < num - 1; i++)
    {
        for (j = 0; j < num - i - 1; j++)
        {
            if (p[j].arrival > p[j + 1].arrival)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < num; i++)
    {
        sum = sum + p[i].burst;
        p[i].turnaround = sum;
    }

    sum = 0;
    printf("PID/LLEGADA/VALOR/CAMBIO-ORDEN\n");
    for (i = 0; i < num; i++)
    {
        printf("%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival, p[i].burst, p[i].turnaround);
        sum += p[i].turnaround;
    }
    avg = sum / (float)num;
    printf("\nTotal turnaround time : %f", sum);
    printf("\nAverage : %f", avg);

    return 0;
}