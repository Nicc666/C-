#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
public :
	int index;
	std::string name;
	std::string surname;
	std::string nickname;
	std::string phone_number;
	std::string secret;
	Contact () : index(0), name(""), surname(""), nickname(""), phone_number(""), secret("")
	{
	}
	~Contact()
	{
	}
};

#endif
