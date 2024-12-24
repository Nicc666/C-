/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2024/12/07 17:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : type("empty")
{
}

AMateria::AMateria(std::string const &type) : type(type)
{
}

AMateria::AMateria(AMateria const &other)
{
    *this = other;
}

AMateria &AMateria::operator=(AMateria const &other)
{
    this->type = other.type;
    return (*this);
}

AMateria::~AMateria()
{
}

std::string const &AMateria::getType() const
{
    return (this->type);
}

void AMateria::use(ICharacter& target)
{
    (void)target;
    std::cout << "AMateria generic use" << std::endl;
}
