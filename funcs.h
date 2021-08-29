//
// Created by User on 30.08.2021.
//

#ifndef CONT_FUNCS_H
#define CONT_FUNCS_H

int big_is_digit(const char* input);
float check_input();
float find_discriminant(float a_loc, float b_loc, float c_loc);
float fix_zero(float ans);
int solve(float loc_a, float loc_b, float loc_c, float *loc_arr);
float extended_input(char let);
void output(int num, float *loc_arr);

#endif //CONT_FUNCS_H
