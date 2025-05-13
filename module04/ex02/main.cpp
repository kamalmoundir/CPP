/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:02:06 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/08 12:09:56 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AbstractAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{

    AbstractAnimal *abs;
    
    std::cout << "========== DEEP COPY TEST ==========" << std::endl;
    {
        Dog* original = new Dog();
        Dog* copy = new Dog(*original);  // This should create a deep copy
        //Dog* copy = original; //this should create a shallow copy
        
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
        AbstractAnimal* AbstractAnimal[count];
        
        // Create half dogs, half cats
        for (int i = 0; i < count; i++) {
            if (i < count/2)
            AbstractAnimal[i] = new Dog();
            else
            AbstractAnimal[i] = new Cat();
        }
        
        // Make sure polymorphism works and overrid makeSound
        for (int i = 0; i < count; i++) {
            std::cout << "Animal " << i << " says: ";
            AbstractAnimal[i]->makeSound();
        }
        
        // Clean up - this should call the correct destructors
        for (int i = 0; i < count; i++) {
            delete AbstractAnimal[i];
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
