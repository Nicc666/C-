/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2024/12/07 17:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor" << std::endl;
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain copy constructor" << std::endl;
    *this = other;
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Brain copy operator" << std::endl;
    int i;
    for (i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
    return(*this);
}

Brain::~Brain()
{
    std::cout << "Brain distructor" << std::endl;
}

void Brain::set_idea(int i, std::string s)
{
    this->ideas[i] = s;
    return;
}

std::string Brain::get_idea(int i) const
{
    return(this->ideas[i]);
}
