/*
** EPITECH PROJECT, 2021
** B-MAT_205IQ
** File description:
** Iq
*/

#include <cmath>
#include <iomanip>

#include "Error.hpp"
#include "Iq.hpp"

IQ::IQ(const int ac, const char **av)
{
    if (ac < 3 || ac > 5)
        throw Error(std::cerr, "Invalid number of arguments");
    for (int i = 1; i != ac; ++i) {
        for (int j = 0; av[i][j] != '\0'; ++j)
            if (av[i][j] < '0' || av[i][j] > '9')
                throw Error(std::cerr, "Argument must be a positive number");
    }
    _iq1 = 0;
    _iq2 = 0;
    _mean = std::atoi(av[1]);
    _standDev = std::atoi(av[2]);
    if (ac == 4)
        _iq1 = std::atoi(av[3]);
    else if (ac == 5) {
        _iq1 = std::atoi(av[3]);
        _iq2 = std::atoi(av[4]);
    }
    if (_standDev == 0)
        throw Error(std::cerr, "Division by 0");
}

void IQ::PrintDistrib(int x, double distrub) noexcept
{
    std::cout << x << " ";
    std::cout << std::fixed << std::setprecision(5);
    std::cout << distrub << std::endl;
}

void IQ::NormalDistrib() noexcept
{
    double e = 0;
    double total = 0;
    double distrub = 1 / (_standDev * sqrt(2 * M_PI));

    for (int i = 0; i != 201; ++i) {
        e = pow(i - _mean, 2) / (2 * pow(_standDev, 2));
        e = e * -1;
        e = exp(e);
        total = distrub * e;
        PrintDistrib(i, total);
    }
}

static double computeNormalDistrib(double mean, double stanDev, double i)
{
    double distrub = 1 / (stanDev * sqrt(2 * M_PI));
    double res = 0;

    res = pow(i - mean, 2) / (2 * pow(stanDev, 2));
    res *= -1;
    res = std::exp(res);
    res *= distrub;
    return res;
}

void IQ::DisplayLower(double prop) noexcept
{
    std::cout << std::fixed << std::setprecision(1);
    std::cout << prop << "% of people have an IQ inferior to ";
    std::cout << std::fixed << std::setprecision(0);
    std::cout << _iq1 << std::endl;
}

void IQ::ComputeLower() noexcept
{
    double prop = 0;

    for (double i = 0; i != _iq1 * 100; i += 1)
        prop += computeNormalDistrib(_mean, _standDev, i / 100);
    DisplayLower(prop);
}

void IQ::DisplayBetween(double prop) noexcept
{
    std::cout << std::fixed << std::setprecision(1);
    std::cout << prop << "% of people have an IQ between ";
    std::cout << std::fixed << std::setprecision(0);
    std::cout << _iq1 << " and " << _iq2 << std::endl;
}

void IQ::ComputeBetween() noexcept
{
    double prop = 0;
    
    for (double i = _iq1 * 100; i != _iq2 * 100; i += 1)
        prop += computeNormalDistrib(_mean, _standDev, i / 100);
    DisplayBetween(prop);
}