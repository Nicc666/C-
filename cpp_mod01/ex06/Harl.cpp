/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2024/10/19 17:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}
void Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. \nI really do!";
    std::cout << std::endl;
    return ;
}

void Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money. \nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";
    std::cout << std::endl;
    return ;
}

void Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. \nI’ve been coming for years whereas you started working here since last month.";
    std::cout << std::endl;
    return ;
}

void Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now.";
    std::cout << std::endl;
    return ;
}

void Harl::complain( std::string level )
{
    if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR")
    {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return ;
    }
    int i = 0;
    int lev = -1;
    std::string possible[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    while (i < 4)
    {
        if (level == possible[i])
            lev = i;
        i++;
    }
    switch (lev)
    {
        case 0:
            std::cout << "[ DEBUG ]" << std::endl;
            this->debug();
            std::cout << std::endl;
        case 1:
            std::cout << "[ INFO ]" << std::endl;
            this->info();
            std::cout << std::endl;
        case 2:
            std::cout << "[ WARNING ]" << std::endl;
            this->warning();
            std::cout << std::endl;
        case 3:
            std::cout << "[ ERROR ]" << std::endl;
            this->error();
            std::cout << std::endl;
    }
    return ;
}
