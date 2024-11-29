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

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Parameter input error" << std::endl;
		return 1;
	}
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string line;
	std::ifstream file(argv[1]);
	size_t pos;
	size_t newpos;
	size_t found;
	std::string filenew = std::string(argv[1]) + ".repalce";
	std::ofstream outfile(filenew.c_str());
	if (file.is_open() == false)
	{
		std::cout << "Opening file error" << std::endl;
		return 1;
	}
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
	file.close();
	outfile.close();
	return 0;
}
