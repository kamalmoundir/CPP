/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 12:32:35 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/30 19:52:22 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <climits>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

class PmergeMe
{
    public:
            PmergeMe();
            PmergeMe(const PmergeMe& other);
            PmergeMe& operator=(const PmergeMe& other);
            ~PmergeMe();
            void sort(int ac, char**  av);
            double _timeManVect;
            double _timeManDeq;
    private:
            std::vector<int> vectContainer;
            std::deque<int> dequContainer;
            template<typename T>
            void jacobeInsertionSort(T& mainChain, T& pending);
            std::vector<int> FordJhonAlgoSortVect(std::vector<int> input);
            std::deque<int> FordJhonAlgoSortDequ(std::deque<int>& input);
            void parseInput(int ac,char **av);
            template<typename T>
            void print(T& container, const std::string& label);
};

#endif