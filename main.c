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
    char input_string[256];
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
    float ans;
    sscanf(input_string, "%f", &ans);
    return ans;
}

float find_discriminant(float a_loc, float b_loc, float c_loc)
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

int main() {
    printf("Input a:\n");
    float a = check_input();
    while (a == 0)
    {
        printf("a must not be 0\n");
        a = check_input();
    }
    printf("Input b:\n");
    float b = check_input();
    printf("Input c:\n");
    float c = check_input();
    float eps = 0.0000001;
    float disc = find_discriminant(a, b, c);
    if (disc < 0)
    {
        printf("No roots");
    }
    else if (fabs(disc) < eps)
    {
        printf("Only root: ");

        printf("%f", fix_zero(-b / (2 * a)));
    }
    else
    {
        printf("Root 1: ");
        printf("%f", fix_zero((-b - sqrt(disc)) / (2 * a)));
        printf("\n");
        printf("Root 2: ");
        printf("%f", fix_zero((-b + sqrt(disc)) / (2 * a)));
        printf("\n");
    }
    return 0;
}
