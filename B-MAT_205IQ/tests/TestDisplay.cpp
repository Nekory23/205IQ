/*
** EPITECH PROJECT, 2021
** B-MAT_205IQ
** File description:
** TestDisplay
*/

#include <string>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Error.hpp"
#include "Iq.hpp"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(display_one_val, subject_1, .init=redirect_all_stdout)
{
    std::string comp = "33.8% of people have an IQ inferior to 90\n";
    const int ac = 4;
    const char *av[] = {"\0", "100", "24", "90"};

    IQ iq(ac, av);
    iq.ComputeLower();
    cr_assert_stdout_eq_str(comp.c_str());
}

Test(display_two_vals, subject_2, .init=redirect_all_stdout)
{
    std::string comp = "7.9% of people have an IQ between 90 and 95\n";
    const int ac = 5;
    const char *av[] = {"\0", "100", "24", "90", "95"};

    IQ iq(ac, av);
    iq.ComputeBetween();
    cr_assert_stdout_eq_str(comp.c_str());
}

Test(return_value, return_0, .init=redirect_all_stdout)
{
    const int ac = 3;
    const char *av[] = {"\0", "100", "15"};

    cr_assert_eq(start(ac, av), 0);
}

Test(return_value_2, return_0, .init=redirect_all_stdout)
{
    const int ac = 4;
    const char *av[] = {"\0", "100", "24", "90"};

    cr_assert_eq(start(ac, av), 0);
}

Test(return_value_3, return_0, .init=redirect_all_stdout)
{
    const int ac = 3;
    const char *av[] = {"\0", "100", "24", "90", "95"};

    cr_assert_eq(start(ac, av), 0);
}