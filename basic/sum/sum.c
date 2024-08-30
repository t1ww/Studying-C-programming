#include <stdio.h>

int main(int argc, char const *argv[])
{
    // init
    int sum_value = 0;

    // scan
    printf("Insert amount of number you provided is %d :\n", argc);

    // loop by amount given
    for (size_t i = 0; i < argc; i++)
    {
        int input_value = 0;
        printf("Amount %d :\n", i, input_value);
        sum_value += input_value;
    }
    printf("Total sum is : %d", sum_value);

    return 0;
}
