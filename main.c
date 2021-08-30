#include "funcs.h"
#include "stdio.h"

void test()
{
    float a = 0;
    float b = 0;
    float c = 0;
    // 999 означает отсутствие корня
    float a_array[8]   = {0 , 0 , 1 , 1 , 1 , 1 , 1 , 0};
    float b_array[8]   = {0 , 0 , 1 , 2 , 4 , 1 , 0 , 1};
    float c_array[8]   = {0 , 1 , 1 , 1 , 3 , 0 , 0 , 1};
    float root_num[8]  = {-1, 0 , 0 , 1 , 2 , 2 , 1 , 1};
    float exc_ans_1[8] = {999, 999, 999, -1, -3, -1, 0 , -1};
    float exc_ans_2[8] = {999, 999, 999, 999, -1,  0,999 , 999};
    for (int i = 0; i < 8; i++)
    {
        a = a_array[i];
        b = b_array[i];
        c = c_array[i];
        float ans_array[2] = {0};

        int ans_count = solve(a, b, c, ans_array);
        output(ans_count, ans_array);
        printf("\n");
        printf("Expected ");
        printf("%f", root_num[i]);
        printf(" roots:\n");
        printf("%f", exc_ans_1[i]);
        printf("\n");
        printf("%f", exc_ans_2[i]);
        printf("\n\n");
    }
}

int main() {
    // test();
    float a = extended_input('a');
    float b = extended_input('b');
    float c = extended_input('c');
    float ans_array[2] = {0};
    int ans_count = solve(a, b, c, ans_array);
    output(ans_count, ans_array);
    return 0;
}
