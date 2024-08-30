#include <stdio.h>

int main()
{
    int numbers[] = {1, 2, 3, 4, 5};
    size_t length = sizeof(numbers) / sizeof(numbers[0]);

    for (size_t i = 0; i < length; i++)
    {
        printf("Element %zu: %d\n", i, numbers[i]);
    }

    return 0;
}
