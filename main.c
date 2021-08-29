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

int solve(const float loc_a, const float loc_b, const float loc_c)
{
    float eps = 0.0000001;
    float disc = find_discriminant(loc_a, loc_b, loc_c);
    if (disc < 0)
    {
        printf("No roots");
    }
    else if (fabs(disc) < eps)
    {
        printf("Only root: ");

        printf("%f", fix_zero(-loc_b / (2 * loc_a)));
    }
    else
    {
        printf("Two roots\n");
        printf("Root 1: ");
        printf("%f", fix_zero((-loc_b - sqrt(disc)) / (2 * loc_a)));
        printf("\n");
        printf("Root 2: ");
        printf("%f", fix_zero((-loc_b + sqrt(disc)) / (2 * loc_a)));
        printf("\n");
    }
    return 0;
}

float extended_input(const char let)
{
    printf("Input ");
    printf("%c", let);
    printf(":\n");
    float ans = check_input();
    return ans;
}

int main() {
    float a = extended_input('a');
    while (a == 0)
    {
        printf("a must not be 0\n");
        a = check_input();
    }
    float b = extended_input('b');
    float c = extended_input('c');
    solve(a, b, c);
    return 0;
}
