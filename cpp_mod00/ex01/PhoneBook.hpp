#include <string>
#include <iostream>

class Contact
{
public :
	int index;
	std::string name;
	std::string surname;
	std::string nickname;
	std::string phone_number;
	std::string secret;
	int date;
	/*Contact (name, surname, nickname, phone_number, secret)
	{
		std::cout << "Inserire il nome" << endl;
		name = std::cin
		//surname = std::cin <<
	}*/
	Contact () : index(0), name(""), surname(""), nickname(""), phone_number(""), secret(""), date(0)
	{
	}
};

class PhoneBook
{
public :
	Contact contact[8];
	int i;

	PhoneBook ()
	{
		i = 0;
		while (i < 8)
		{
			contact[i].index = i + 1;
			i++;
		}
	}
	void add()
	{
		i=0;

		while (i < 8)
		{
			if (contact[i].name == "")
			{
				std::cout << "Insert name" << std::endl;
				std::getline(std::cin, contact[i].name);
				std::cout << "Insert surname" << std::endl;
				std::getline(std::cin, contact[i].surname);
				std::cout << "Insert nickname" << std::endl;
				std::getline(std::cin, contact[i].nickname);
				break;
			}
			i++;
		}
	}
};
