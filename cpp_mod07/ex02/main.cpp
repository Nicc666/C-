/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2025/01/12 19:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

    std::cout << "-----------------------------------------------" << std::endl;

    Array<int> numbers2(10);
    for (int i = 0; i < 10; i++)
    {
        numbers2[i] = i;
    }
    for (int i = 0; i < 10; i++)
    {
        std::cout << numbers2[i] << std::endl;
    }
    std::cout << "size is: " << numbers2.size() << std::endl;

    std::cout << "-----------------------------------------------" << std::endl;

    Array<int> zero(0);
    Array<int> test2;
    Array<int> test3(test2);
    try
    {
        std::cout << zero[0] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "-----------------------------------------------" << std::endl;
    Array<int> numbers4(140);
    Array<int> numbers5(5);
    numbers5 = numbers4;
    std::cout << "-----------------------------------------------" << std::endl;
    Array<std::string> string(15);
    
    for (int i = 0; i < 15; i++)
    {
        char c = 'A' + i;
        string[i] = "bubu";
        string[i] += c;
    }
    for (int i = 0; i < 10; i++)
    {
        std::cout << string[i] << std::endl;
    }
    // std::cout << "-----------------------------------------------" << std::endl;
    // std::cout << "const test" << std::endl;
    // const int a = 1;
    // const int b = 2;
    // const int c = 45;
    // Array<int*> int_pt(3);
    // int_pt[0] = <int*>&a;
    // int_pt[1] = &b;
    // int_pt[2] = &c;
    // for (int i = 0; i < 10; i++)
    // {
    //     std::cout << int_pt[i] << std::endl;
    // }
    return 0;
}
