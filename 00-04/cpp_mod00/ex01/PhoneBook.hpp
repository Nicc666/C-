/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:40:59 by nspinell          #+#    #+#             */
/*   Updated: 2024/11/23 18:24:18 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
private :
	Contact contact[8];
	int 	i;
	int 	current_index;
public :
	PhoneBook ();
	~PhoneBook ();
	void 		add();
	void		add_detail(int i);
	std::string truncate(std::string s);
	void 		search(int j);
};

#endif