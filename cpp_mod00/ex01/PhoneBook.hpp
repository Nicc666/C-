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
				
				while (contact[i].name == "")
				{
					std::cout << "Insert name" << std::endl;
					std::getline(std::cin, contact[i].name);
				}
				while (contact[i].surname == "")
				{
					std::cout << "Insert surname" << std::endl;
					std::getline(std::cin, contact[i].surname);
				}
				while (contact[i].nickname == "")
				{
					std::cout << "Insert nickname" << std::endl;
					std::getline(std::cin, contact[i].nickname);
				}
				while (contact[i].phone_number == "")
				{
					std::cout << "Insert phone_number" << std::endl;
					std::getline(std::cin, contact[i].phone_number);
				}
				while (contact[i].secret == "")
				{
					std::cout << "Insert dark_secret" << std::endl;
					std::getline(std::cin, contact[i].secret);
				}
				std::cout << "Contact added" << std::endl;
				break;
			}
			i++;
		}
		return ;
	}
	void search(int j)
	{
		i=0;

		if (j < 1 || j > 8)
		{
			std::cout << "Insert a valid index" << std::endl;
			return ;
		}
		while (i + 1 != j)
			i++;
		std::cout << contact[i].index << std::endl;
		std::cout << contact[i].name << std::endl;
		std::cout << contact[i].surname << std::endl;
		std::cout << contact[i].nickname << std::endl;
	}
};
