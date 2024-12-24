/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:40:48 by nspinell          #+#    #+#             */
/*   Updated: 2024/11/23 18:20:24 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

int	Contact::getindex(void)
{
	return(this->index);
}

std::string	Contact::get_first_name(void)
{
	return(this->name);
}

std::string	Contact::get_last_name(void)
{
	return(this->last_name);
}

std::string	Contact::get_nickname(void)
{
	return(this->nickname);
}

std::string	Contact::get_phone_number(void)
{
	return(this->phone_number);
}

std::string	Contact::get_darkest_secret(void)
{
	return(this->darkest_secret);
}

void	Contact::setindex(int i)
{
	this->index = i;
	return ;
}

void	Contact::set_first_name(std::string s)
{
	this->name = s;
	return ;
}

void	Contact::set_last_name(std::string s)
{
	this->last_name = s;
	return ;
}

void	Contact::set_nickname(std::string s)
{
	this->nickname = s;
	return ;
}

void	Contact::set_phone_number(std::string s)
{
	this->phone_number = s;
	return ;
}

void	Contact::set_darkest_secret(std::string s)
{
	this->darkest_secret = s;
	return ;
}
