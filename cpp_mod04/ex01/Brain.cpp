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
    *this = other;
}

Brain &Brain::operator=(const Brain &other)
{
    int i;
    for (i = 0; i < 100; i++);
        this->ideas[i] = other.ideas[i];
    return(*this);
}

Brain::~Brain()
{
    std::cout << "Brain distructor" << std::endl;
}
