#include "funcs.h"

int main() {
    float a = extended_input('a');
    float b = extended_input('b');
    float c = extended_input('c');
    float ans_array[2] = {0};

    int ans_count = solve(a, b, c, ans_array);
    output(ans_count, ans_array);

    return 0;
}
