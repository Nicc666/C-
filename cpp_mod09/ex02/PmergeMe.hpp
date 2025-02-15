/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2025/01/29 12:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <climits>
#include <algorithm>

class PmergeMe
{
	private:
		std::vector<int> data;
		std::vector<std::pair<int, int> > p;
		std::vector<int> ret;
	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe(void);
		static bool inputerror(char **argv);
		void printlist(std::vector<int> &vec);
		void printpair(void);
		bool fillint(char **argv);
		bool fillpair(void);
		bool orderpair(void);
		bool final(void);
		bool vectorret(std::vector<int> &first, std::vector<int> &second);
		void algoritm(char **argv);
};
