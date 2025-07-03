/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:51:44 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/30 23:26:40 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sys/time.h> 

static long getMicros(timeval start, timeval end) {
    return (end.tv_sec - start.tv_sec) * 1000000L 
           + (end.tv_usec - start.tv_usec);
}

PmergeMe::PmergeMe()
{}
PmergeMe::PmergeMe(const PmergeMe& other):vectContainer(other.vectContainer), dequContainer(other.dequContainer)
{}
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if(this != &other)
    {
        this->vectContainer = other.vectContainer;
        this->dequContainer = other.dequContainer;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{}

void PmergeMe::parseInput(int ac,char **av)
{
    int i = 1;

     struct timeval startVect, endVect, startDeq, endDeq;
    
     gettimeofday(&startVect, NULL);
    while(i < ac)
    {
            char *endpoint;
            
            long value = strtol(av[i], &endpoint, 10);
            
            if(*endpoint != '\0')
            {
                throw std::runtime_error("Error");
            }
            if(value < 0 || value > INT_MAX)
                throw std::runtime_error("Error");
            else
            {
                this->vectContainer.push_back(static_cast<int>(value));
              
            }
        i ++;
    }
     gettimeofday(&endVect, NULL);
    _timeManVect = getMicros(startVect, endVect);
    
    i = 1;
    gettimeofday(&startDeq, NULL);
    while(i < ac)
    {
            char *endpoint;
            
            long value = strtol(av[i], &endpoint, 10);
            
            if(*endpoint != '\0')
            {
                throw std::runtime_error("Error");
            }
            if(value < 0 || value > INT_MAX)
                throw std::runtime_error("Error");
            else
            {
               
                this->dequContainer.push_back(static_cast<int>(value));
            }
        i ++;
    }
    gettimeofday(&endDeq, NULL);
    _timeManDeq = getMicros(startDeq, endDeq);
}

template<typename T>
void PmergeMe::print(T& container, const std::string& label)
{
    typename T::iterator it = container.begin();
    std::cout<< label <<" : ";
    for (;it != container.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

std::vector<int> PmergeMe::FordJhonAlgoSortVect(std::vector<int> input)
{
    int leftOver = -1;
    std::vector<std::pair<int, int> >pairs;
    std::vector<int> mainChain;
    std::vector<int> pending;

    if(input.size() <= 1)
    {
        return input;
    }
    
    if(input.size() % 2 != 0)
    {
        leftOver = input.back();
        input.pop_back();
    }
    
    for(size_t i = 0 ; i < input.size() - 1 ; i += 2)
    {
        pairs.push_back(std::make_pair(input[i], input[i + 1]));
    }
    std::vector< std::pair<int, int> >::iterator it = pairs.begin();
    for(; it != pairs.end(); ++it)
    {
        if(it->first > it->second)
        {
            mainChain.push_back(it->first);
            pending.push_back(it->second);
        }
        else
        {
            mainChain.push_back(it->second);
            pending.push_back(it->first);
        }
    }
    if(leftOver >= 0)
    {
        pending.push_back(leftOver);
    }
    
    //recursive sort of mainchain
    mainChain = FordJhonAlgoSortVect(mainChain);
    /*for(size_t i = 0; i < pending.size(); i++)
    {
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(),mainChain.end(), pending[i]);
        mainChain.insert(it, pending[i]);
    }*/
    jacobeInsertionSort(mainChain, pending);
    return mainChain;
}

std::deque<int> PmergeMe::FordJhonAlgoSortDequ(std::deque<int>& input)
{
     int leftOver = -1;
    std::deque<std::pair<int, int> >pairs;
    std::deque<int> mainChain;
    std::deque<int> pending;
    
    if(input.size() <= 1)
    {
        return input;
    }
    if(input.size() % 2 != 0)
    {
        leftOver = input.back();
        input.pop_back();
    }
    for(size_t i = 0 ; i < input.size() - 1 ; i += 2)
    {
        pairs.push_back(std::make_pair(input[i], input[i + 1]));
    }
    std::deque< std::pair<int, int> >::iterator it = pairs.begin();
    for(; it != pairs.end(); ++it)
    {
        if(it->first > it->second)
        {
            mainChain.push_back(it->first);
            pending.push_back(it->second);
        }
        else
        {
            mainChain.push_back(it->second);
            pending.push_back(it->first);
        }
    }
    if(leftOver >= 0)
    {
        pending.push_back(leftOver);
    }
    
    //recursive sort of mainchain
    mainChain = FordJhonAlgoSortDequ(mainChain);
    
    //iteration insertion 
    /*for(size_t i = 0; i < pending.size(); i++)
    {
        std::deque<int>::iterator it = std::lower_bound(mainChain.begin(),mainChain.end(), pending[i]);
        mainChain.insert(it, pending[i]);
    }*/
    //
    jacobeInsertionSort(mainChain, pending);
    return mainChain;
    
}

void PmergeMe::sort(int ac, char**  av)
{
    struct timeval startVect, endVect, startDeq, endDeq;
    
    //parse and emplement vector and deque
    parseInput(ac, av);
    
    //sort vector 
    this->print(vectContainer, "Before");
    gettimeofday(&startVect, NULL);
    vectContainer = FordJhonAlgoSortVect(vectContainer);
    gettimeofday(&endVect, NULL);
    this->print(vectContainer, "After");
    double time_us = getMicros(startVect, endVect);
    std::cout<< "Time to process a range of " << vectContainer.size() <<" elements with std::vector : ";
    std::cout << std::fixed << std::setprecision(5) << time_us + _timeManVect << " us" <<std::endl;

    //sort deque
    //print(dequContainer, "Before");
    gettimeofday(&startDeq, NULL);
    dequContainer = FordJhonAlgoSortDequ(dequContainer);
    gettimeofday(&endDeq, NULL);
    //print(dequContainer, "After");
    double timeDequ = getMicros(startDeq, endDeq);
    std::cout<< "Time to process a range of "<<dequContainer.size()<<" elements with std::deque : ";
    std::cout << std::fixed << std::setprecision(5) << timeDequ + _timeManDeq << " us"<<std::endl;
    
}

template<typename T>
void PmergeMe::jacobeInsertionSort(T& mainChain, T& pending)
{
    if (pending.empty())
        return ;
    
    if (mainChain.empty()) {
        mainChain.push_back(pending[0]);  // Just add directly if empty
    } else {
        typename T::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pending[0]);
        mainChain.insert(it, pending[0]);
    }
    
    if (pending.size() == 1)
        return ;
    std::vector<int> jacobsthal;
    jacobsthal.push_back(1);
    jacobsthal.push_back(3);
    int i = 2;
    while(true)
    {
    
        size_t next = jacobsthal[i - 1] + 2 * jacobsthal[i  - 2];
        if(next >= pending.size())
            break;
        jacobsthal.push_back(next);
        i ++;
    }
    size_t prev = 0;
    for(size_t j = 0; j < jacobsthal.size(); j ++)
    {
        size_t current = jacobsthal[j];
        if(current < pending.size())
        {
            typename T::iterator  it = std::lower_bound(mainChain.begin(), mainChain.end(), pending[current]);
            mainChain.insert(it, pending[current]);
        }
        
       for(size_t k = current; k > prev + 1; k--) {  
            if (k - 1 < pending.size()) {
                typename T::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pending[k - 1]);
                mainChain.insert(it, pending[k - 1]);
            }
        }
        prev = current;
    }
    for(size_t i = prev + 1; i < pending.size(); i++)
    {
         typename T::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(),pending[i]);
        mainChain.insert(it, pending[i]);
    }

}