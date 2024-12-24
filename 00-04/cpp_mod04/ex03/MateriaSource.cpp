/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    MateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2024/12/07 17:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		mat[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
	*this = other;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
	for (int i = 0; i < 4; i++)
	{
		if (mat[i] != NULL)
			delete mat[i];
	}
	for (int i = 0; i < 4; i++)
	{
		if (other.mat[i] != NULL)
			this->mat[i] = other.mat[i]->clone();
		else
			this->mat[i] = NULL;
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (mat[i] != NULL)
			delete mat[i];
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (m == NULL)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (mat[i] == NULL)
		{
			mat[i] = m;
			return;
		}
	}
	std::cout << "Mat Source is full" << std::endl;
	return;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (mat[i]!= NULL && mat[i]->getType() == type)
		{
			return (mat[i]->clone());
		}
	}
	std::cout << "No type found in Mat Source array" << std::endl;
	return (NULL);
}
