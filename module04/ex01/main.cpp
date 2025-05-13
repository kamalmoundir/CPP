/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:02:06 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/08 12:10:11 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    std::cout << "========== DEEP COPY TEST ==========" << std::endl;
    {
        Dog* original = new Dog();
        Dog* copy = new Dog(*original);  // This should create a deep copy
        
        // Demonstrate they're different objects with different brains
        std::cout << "Original dog address: " << original << std::endl;
        std::cout << "Copy dog address: " << copy << std::endl;
        
        // Clean up
        delete original;
        delete copy;
        std::cout << "Both dogs and their separate brains properly destroyed!" << std::endl;
    }
    
    std::cout << "\n========== ANIMAL ARRAY TEST ==========" << std::endl;
    {
        const int count = 4;
        Animal* animals[count];
        
        // Create half dogs, half cats
        for (int i = 0; i < count; i++) {
            if (i < count/2)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
        }
        
        // Make sure polymorphism works
        for (int i = 0; i < count; i++) {
            std::cout << "Animal " << i << " says: ";
            animals[i]->makeSound();
        }
        
        // Clean up - this should call the correct destructors
        for (int i = 0; i < count; i++) {
            delete animals[i];
        }
    }
    
    std::cout << "\n========== ADDITIONAL COPY TEST ==========" << std::endl;
    {
        Cat originalCat;
        {
            Cat copyCat = originalCat;  // Test copy constructor
            std::cout << "CopyCat going out of scope..." << std::endl;
        } // copyCat's destructor should be called here
        std::cout << "Original cat still alive!" << std::endl;
    }
    
    return 0;
}
