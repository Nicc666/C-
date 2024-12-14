/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2024/12/07 17:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal(const std::string &type);
		WrongAnimal &operator=(const WrongAnimal &other);
		virtual ~WrongAnimal();
		void makeSound(void) const;
		std::string getType(void) const;
	protected:
		std::string type;
};

#endif
