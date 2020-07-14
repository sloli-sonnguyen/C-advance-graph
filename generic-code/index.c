#include <stdio.h>
#include <stdlib.h> // Thu vien de qoi ham qsort

int compareInt(void const *x, void const *y)
{
    int m, n;
    m = *((int *)x);
    n = *((int *)y);

    if (m == n)
        return 0;
    return m > n ? -1 : 1;
}
int compareFloat(void const *x, void const *y)
{
    float m, n;
    m = *((float *)x);
    n = *((float *)y);

    if (m == n)
        return 0;
    return m > n ? 1 : -1;
}

// ham search nhi phan ( tra ve index cua phan tu)
int search(void *buf, int size, int l, int r, void *item, int (*compare)(void const *, void const *))
{
    if (r < l)
        return -1;
    int i = (l + r) / 2;
    int result = compare(item, (char *)buf + (size * i));
    if (result == 0)
    {
        return i;
    }
    else if (result == 1)
    {
        return search(buf, size, i + 1, r, item, compare);
    }
    return search(buf, size, l, i - 1, item, compare);
}

int main()
{
    // ham rand() ==> tra ve 1 so random
    //vd
    int randomNumber = rand() % 100;
    printf("\nRandom number: %d\n", randomNumber);

    int intValues[4] = {10, 1, 20, 3};
    float floatValues[5] = {10.2, 2, 2.1, 20, 100};

    qsort(intValues, 4, sizeof(int), compareInt);
    printf("\nSort int values: \n");
    for (int i = 0; i < sizeof(intValues) / sizeof(int); i++)
    {
        printf("%d ", intValues[i]);
    }

    qsort(floatValues, 5, sizeof(float), compareFloat);
    printf("\nSort float values: \n");
    for (int i = 0; i < sizeof(floatValues) / sizeof(float); i++)
    {
        printf("%.2f ", floatValues[i]);
    }

    int item = 1;
    int result = search(intValues, sizeof(int), 0, 3, &item, compareInt);
    printf("\nResult: %d", result);

    return 0;
}