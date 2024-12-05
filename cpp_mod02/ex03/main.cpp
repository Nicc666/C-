/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:45:25 by nspinell          #+#    #+#             */
/*   Updated: 2024/10/19 17:50:23 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
	Point a(1.0f, 1.0f);
	Point b(4.0f, 1.0f);
	Point c(3.0f, 2.0f);

	Point p1(1.0f, 1.0f); // Vertice del triangolo
	Point p2(1.5f, 1.1f); // Interno al triangolo
	Point p3(2.5f, 1.0f); // sulla Base triangolo
	Point p4(3.0f, 1.5f);  // Interno al triangolo
    Point p5(0.0f, 0.0f);  // Esterno al triangolo
    Point p6(4.0f, 1.0f);  // Esattamente su un altro vertice del triangolo
    Point p7(3.5f, 2.5f);  // Esterno al triangolo (sopra)
	Point p8(3.0f, 1.9f);  // Interno al triangolo

    std::cout << "Punto p1 (1.0, 1.0): " << bsp(a, b, c, p1) << " (expected: false)" << std::endl;
    std::cout << "Punto p2 (1.5, 1.1): " << bsp(a, b, c, p2) << " (expected: true)" << std::endl;
    std::cout << "Punto p3 (2.5, 1.0): " << bsp(a, b, c, p3) << " (expected: false)" << std::endl;

    std::cout << "Punto p4 (3.0, 1.5): " << bsp(a, b, c, p4) << " (expected: true)" << std::endl;
    std::cout << "Punto p5 (0.0, 0.0): " << bsp(a, b, c, p5) << " (expected: false)" << std::endl;
    std::cout << "Punto p6 (4.0, 1.0): " << bsp(a, b, c, p6) << " (expected: false)" << std::endl;

    std::cout << "Punto p7 (3.5, 2.5): " << bsp(a, b, c, p7) << " (expected: false)" << std::endl;
	std::cout << "Punto p8 (3.0, 1.9): " << bsp(a, b, c, p8) << " (expected: true)" << std::endl;
	return 0;
}
