#include <stdio.h>

void copyString(char src[], char dest[], int index)
{
    if(src[index] != '\0')
    {
        dest[index] = src[index];
        copyString(src, dest, index + 1);
    }
}

int main()
{
    char src[100];
    char dest[100];

    printf("Enter the string to copy: ");
    scanf("%s", src);

    copyString(src, dest,0 );

    printf("Copied string: %s\n", dest);

    return 0;
}
