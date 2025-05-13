/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:02:06 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/07 15:44:19 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "========== BASIC POLYMORPHISM TESTS ==========" << std::endl;
    
    // Test 1: Basic polymorphic behavior with heap-allocated objects
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << "Dog type: " << j->getType() << std::endl;
    std::cout << "Cat type: " << i->getType() << std::endl;
    
    std::cout << "Cat sound: ";
    i->makeSound(); // Should output the cat sound due to polymorphism
    
    std::cout << "Dog sound: ";
    j->makeSound(); // Should output the dog sound due to polymorphism
    
    std::cout << "Animal sound: ";
    meta->makeSound(); // Generic animal sound

    // Test 2: Wrong hierarchy tests (demonstrates non-polymorphic behavior)
    std::cout << "\n========== WRONG HIERARCHY TESTS ==========" << std::endl;
    
    const WrongAnimal* wrongA = new WrongAnimal();
    const WrongAnimal* wrongC = new WrongCat();
    
    std::cout << "WrongCat type: " << wrongC->getType() << std::endl;
    
    std::cout << "WrongCat sound through WrongAnimal pointer: ";
    wrongC->makeSound(); // Will NOT output cat sound due to missing 'virtual'
    
    std::cout << "WrongAnimal sound: ";
    wrongA->makeSound();
    
    // Test 3: Stack-allocated objects
    std::cout << "\n========== STACK ALLOCATION TESTS ==========" << std::endl;
    
    Animal regularAnimal;
    Dog regularDog;
    Cat regularCat;
    
    std::cout << "Regular Cat type: " << regularCat.getType() << std::endl;
    std::cout << "Regular Dog type: " << regularDog.getType() << std::endl;
    
    std::cout << "Regular Cat sound: ";
    regularCat.makeSound();
    
    std::cout << "Regular Dog sound: ";
    regularDog.makeSound();
    
    // Test 4: Polymorphism through references
    std::cout << "\n========== REFERENCE POLYMORPHISM TESTS ==========" << std::endl;
    
    Animal& catRef = regularCat;
    Animal& dogRef = regularDog;
    
    std::cout << "Cat through reference type: " << catRef.getType() << std::endl;
    std::cout << "Cat through reference sound: ";
    catRef.makeSound(); // Should be cat sound through polymorphism
    
    std::cout << "Dog through reference sound: ";
    dogRef.makeSound(); // Should be dog sound through polymorphism
    
    // Test 5: Wrong hierarchy with direct objects
    std::cout << "\n========== DIRECT WRONG OBJECTS TESTS ==========" << std::endl;
    
    WrongAnimal directWrongAnimal;
    WrongCat directWrongCat;
    
    std::cout << "Direct WrongCat type: " << directWrongCat.getType() << std::endl;
    
    std::cout << "Direct WrongCat sound: ";
    directWrongCat.makeSound(); // This WILL be the cat sound when called directly
    
    WrongAnimal& wrongCatRef = directWrongCat;
    std::cout << "WrongCat through reference sound: ";
    wrongCatRef.makeSound(); // This will NOT be the cat sound due to missing 'virtual'
    
    // Clean up heap-allocated objects
    std::cout << "\n========== CLEANUP ==========" << std::endl;
    delete wrongA;
    delete wrongC;
    delete meta;
    delete i;
    delete j;

    return 0;
}
