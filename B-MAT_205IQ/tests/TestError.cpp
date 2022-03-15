/*
** EPITECH PROJECT, 2021
** B-MAT_205IQ
** File description:
** TestError
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Iq.hpp"
#include "Error.hpp"

Test(error_handling_ex, not_enough_args)
{
    const int ac = 1;
    const char *av[] = {"\0"};

    cr_assert_any_throw(IQ iq(ac, av));
}

Test(error_handling_ex, too_many_args)
{
    const int ac = 6;
    const char *av[] = {"\0", "hey", "hey", "hey", "hey", "hey"};

    cr_assert_any_throw(IQ iq(ac, av));
}

Test(error_handling_ex, division_by_0)
{
    const int ac = 3;
    const char *av[] = {"\0", "100", "0"};

    cr_assert_any_throw(IQ iq(ac, av));
}

Test(error_handling_ex, invalid_args)
{
    const int ac = 3;
    const char *av[] = {"\0", "100", "eurfih"};

    cr_assert_any_throw(IQ iq(ac, av));
}