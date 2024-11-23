/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:40:27 by nspinell          #+#    #+#             */
/*   Updated: 2024/11/23 18:19:38 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
private :
	int index;
	std::string name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
public :
	Contact () : index(0), name(""), last_name(""), nickname(""), phone_number(""), darkest_secret("")
	{
	}
	~Contact()
	{
	}
	int	getindex(void);
	std::string	get_first_name(void);
	std::string	get_last_name(void);
	std::string	get_nickname(void);
	std::string	get_phone_number(void);
	std::string	get_darkest_secret(void);
	void	setindex(int i);
	void	set_first_name(std::string s);
	void	set_last_name(std::string s);
	void	set_nickname(std::string s);
	void	set_phone_number(std::string s);
	void	set_darkest_secret(std::string s);
};

#endif
