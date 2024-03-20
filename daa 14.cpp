#include <stdio.h>

void findMinMaxSequence(int list[], int size)
{
    int minVal = list[0];
    int maxVal = list[0];

    for (int i = 1; i < size; i++)
    {
        if (list[i] < minVal)
            minVal = list[i];
        if (list[i] > maxVal)
            maxVal = list[i];
    }

    printf("Minimum value: %d, Maximum value: %d\n", minVal, maxVal);
}

int main()
{
    int size, i;

    printf("Enter the size of the list: ");
    scanf("%d", &size);

    int list[size];

    printf("Enter the elements of the list:\n");
    for (i = 0; i < size; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &list[i]);
    }

    findMinMaxSequence(list, size);

    return 0;
}
