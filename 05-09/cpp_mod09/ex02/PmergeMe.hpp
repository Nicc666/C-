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
#include <deque>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <ctime>

class PmergeMe
{
	private:
		std::vector<int> data;
		std::vector<int> ret;
		std::deque<int> d;
		std::deque<int> fin;
	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe(void);

		static bool inputerror(char **argv);

		void printvector(std::vector<int> &vec);
		bool fillvector(char **argv);
		void fill_order_pair(std::vector<std::pair<int, int> > &p);
		void merge(std::vector<int> &v, int left, int mid, int right);
		void mergesort(std::vector<int> &v, int left, int right);
		void binaryinsertion(std::vector<int> &second);
		void algorithm(std::vector<std::pair<int, int> > &p);
		void sortvector(void);

		void printdeque(std::deque<int> &vec);
		bool filldeque(char **argv);
		void fill_order_pair_d(std::deque<std::pair<int, int> > &p);
		void merge_d(std::deque<int> &v, int left, int mid, int right);
		void mergesort_d(std::deque<int> &v, int left, int right);
		void binaryinsertion_d(std::deque<int> &second);
		void algorithm_d(std::deque<std::pair<int, int> > &p);
		void sortdeque(void);

		bool sort(char **argv);
};
