#include <stdio.h>
#include <ctype.h>
#include <math.h>

int big_is_digit(const char* input) {
    int minus_counter = 0;
    int dot_counter = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if ((isdigit(input[i])) == 0)
        {
            if (input[i] != '.')
            {
                dot_counter++;
                if (dot_counter > 1)
                {
                    return 0;
                }
            }
            else if (input[i] != '-')
            {
                minus_counter++;
                if (minus_counter > 1)
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
    }
    return 1;
}

float check_input()
{
    char input_string[256] = {0};
    while (1)
    {
        scanf("%s", input_string);
        if (big_is_digit(input_string) == 0)
        {
            printf("incorrect input\n");
        }
        else
        {
            break;
        }
    }
    float ans = 0.0;
    sscanf(input_string, "%f", &ans);
    return ans;
}

float find_discriminant(const float a_loc, const float b_loc, const float c_loc)
{
    return b_loc * b_loc - 4 * a_loc * c_loc;
}

float fix_zero(float ans) // Чтобы избежать ситуаций, когда корень равен -0.000000
{
    if (fabs(ans) < 0.0000001)
    {
        return fabs(ans);
    }
    return ans;
}

int solve(const float loc_a, const float loc_b, const float loc_c, float *loc_arr)
{
    float eps = 0.0000001;
    float disc = find_discriminant(loc_a, loc_b, loc_c);
    if (fabs(loc_a) < eps)
    {
        if (fabs(loc_b) < eps)
        {
            if (fabs(loc_c) < eps)
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            loc_arr[0] = -(loc_c / loc_b);
            return 1;
        }
    }
    else if (disc < 0)
    {
        return 0;
    }
    else if (fabs(disc) < eps)
    {
        loc_arr[0] = fix_zero(-loc_b / (2 * loc_a));
        return 1;
    }
    else
    {
        loc_arr[0] = fix_zero((-loc_b - sqrt(disc)) / (2 * loc_a));
        loc_arr[1] = fix_zero((-loc_b + sqrt(disc)) / (2 * loc_a));
        return 2;
    }
}

float extended_input(const char let)
{
    printf("Input ");
    printf("%c", let);
    printf(":\n");
    float ans = check_input();
    return ans;
}

void output(int num, float *loc_arr)
{
    if (num == -1)
    {
        printf("Infinite number of roots");
    }
    else if (num == 0)
    {
        printf("No roots");
    }
    else if (num == 1)
    {
        printf("One root:\n");
        printf("%f", loc_arr[0]);
    }
    else
    {
        printf("Two roots\n");
        printf("%f", loc_arr[0]);
        printf("\n");
        printf("%f", loc_arr[1]);
    }
}

int main() {
    float a = extended_input('a');
    float b = extended_input('b');
    float c = extended_input('c');
    float ans_array[2] = {0};
    int ans_count = solve(a, b, c, ans_array);
    output(ans_count, ans_array);
    return 0;
}
