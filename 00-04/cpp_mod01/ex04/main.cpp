/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:45:25 by nspinell          #+#    #+#             */
/*   Updated: 2024/10/19 15:45:26 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

void	replace(std::string s1, std::string s2, std::ifstream &file, std::ofstream &outfile)
{
	size_t pos = 0;
	size_t newpos = 0;
	size_t found = 0;
	std::string line;

	while (std::getline(file, line))
	{
		pos = 0;
		newpos = 0;
		found = 0;
		while ((newpos = line.find(s1, pos)) != std::string::npos)
		{
			outfile << line.substr(pos, newpos - pos);
			outfile << s2;
			pos = newpos + s1.length();
			found = 1;
		}
		if (found == 0)
			outfile << line;
		else
			outfile << line.substr(pos);
		if (file.eof() != true)
			outfile << std::endl;
	}
	return ;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Parameter input error" << std::endl;
		return 1;
	}
	std::ifstream file(argv[1]);
	if (file.is_open() == false)
	{
		std::cout << "Error: Opening file" << std::endl;
		return 1;
	}
	std::string s1 = argv[2];
	if (s1.empty())
	{
        std::cout << "Error: Empty string" << std::endl;
        return 1;
    }
	std::string s2 = argv[3];
	std::string filenew = std::string(argv[1]) + ".replace";
	std::ofstream outfile(filenew.c_str());
	if (outfile.is_open() == false)
	{
		std::cout << "Error: Cannot create output file" << std::endl;
		return 1;
	}
	replace(s1, s2, file, outfile);
	return 0;
}
