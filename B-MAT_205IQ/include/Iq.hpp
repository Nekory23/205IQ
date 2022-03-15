/*
** EPITECH PROJECT, 2021
** EpitechTools
** File description:
** main
*/

#ifndef MAIN_HPP_
#define MAIN_HPP_

class IQ {
    public:
        IQ(const int ac, const char **av);
        ~IQ() = default;

        void NormalDistrib() noexcept;
        void PrintDistrib(int x, double distrub) noexcept;
        void ComputeLower() noexcept;
        void DisplayLower(double prop) noexcept;
        void ComputeBetween() noexcept;
        void DisplayBetween(double prop) noexcept;

    protected:
    private:
        double _mean;
        double _standDev;
        double _iq1;
        double _iq2;
};

/* STATIC CONST */
static const int SUCCESS = 0;
static const int FAIL = 1;
static const int ERROR = 84;

/* PROTOTYPES */
int start(const int ac, const char **av);

#endif /* !MAIN_HPP_ */
