#include <stdio.h>
void main()
{
    int n, cb, cp, bi, pi, sbi = 0, spi = 0, cost = 0, sbir = 0, spir = 0;
    scanf("%d%d%d", &n, &cb, &cp);
    ;
    if (n < 2 || n > 100)
    {
        printf("Invalid value");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &bi, &pi);
            sbi += bi;
            spi += pi;
        }
    }
    spir = spi / 10;
    sbir = sbi / 10;
    if (sbir * 10 < sbi)
    {
        sbir++;
    }
    if (spir * 10 < spi)
    {
        spir++;
    }
    printf("%d\t%d\n", sbi, spi);
    printf("%d\t%d\n", sbir, spir);
    cost = ((sbir * cb) + (spir * cp));
    printf("%d", cost);
}