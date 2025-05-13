/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:17:19 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/06 10:25:20 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
/*
     // Test default constructor
     std::cout << "\n=== Creating ClapTrap with default constructor ===\n" << std::endl;
     ClapTrap defaultCT;
     
     // Test parameterized constructor
     std::cout << "\n=== Creating ClapTrap with name ===\n" << std::endl;
     ClapTrap bob("Bob");
     
     // Test copy constructor
     std::cout << "\n=== Creating ClapTrap with copy constructor ===\n" << std::endl;
     ClapTrap bobClone(bob);
     
     // Test assignment operator
     std::cout << "\n=== Testing assignment operator ===\n" << std::endl;
     ClapTrap assigned;
     assigned = bob;
     
     // Test attack function
     std::cout << "\n=== Testing attack function ===\n" << std::endl;
     bob.attack("Enemy");
     
     // Test taking damage
     std::cout << "\n=== Testing takeDamage function ===\n" << std::endl;
     bob.takeDamage(3);
     
     // Test repairing
     std::cout << "\n=== Testing beRepaired function ===\n" << std::endl;
     bob.beRepaired(2);
     
     // Test multiple attacks to deplete energy
     std::cout << "\n=== Testing energy depletion ===\n" << std::endl;
     for (int i = 0; i < 10; i++) {
         std::cout << "Attack " << i+1 << ": ";
         bob.attack("Enemy");
     }
     
     // Try to attack with no energy
     std::cout << "\n=== Testing attack with no energy ===\n" << std::endl;
     bob.attack("Enemy");
     
     // Try to repair with no energy
     std::cout << "\n=== Testing repair with no energy ===\n" << std::endl;
     bob.beRepaired(5);
     
     // Test taking enough damage to be destroyed
     std::cout << "\n=== Testing taking fatal damage ===\n" << std::endl;
     defaultCT.takeDamage(15); // More than default hit points
     
     // Try actions when destroyed
     std::cout << "\n=== Testing actions when destroyed ===\n" << std::endl;
     defaultCT.attack("Enemy");
     defaultCT.beRepaired(5);
     defaultCT.takeDamage(5);
     
     std::cout << "\n=== End of tests of ClapTrap class, destructors will be called ===\n\n\n" << std::endl;
     

     std::cout << "\n===  ScavTrap class tests ===\n" << std::endl;
    // Test default constructor
    std::cout << "\n=== Creating ScavTrap with default constructor ===\n" << std::endl;
    ScavTrap defaultST;
    
    // Test parameterized constructor
    std::cout << "\n=== Creating ScavTrap with name ===\n" << std::endl;
    ScavTrap jhon("Jhon");
    
    // Test copy constructor
    std::cout << "\n=== Creating ScavTrap with copy constructor ===\n" << std::endl;
    ScavTrap jhonclone(jhon);
    
    //Test guardGate function
    std::cout << "\n=== Creating test for guardGate function ===\n" << std::endl;
    jhon.guardGate();
    
    // Test assignment operator
    std::cout << "\n=== Testing assignment operator ===\n" << std::endl;
    ScavTrap assigned1;
    assigned1 = jhon;
    
    // Test attack function
    std::cout << "\n=== Testing attack function ===\n" << std::endl;
    jhon.attack("Enemy");
    
    // Test taking damage
    std::cout << "\n=== Testing takeDamage function ===\n" << std::endl;
    jhon.takeDamage(3);
    
    // Test repairing
    std::cout << "\n=== Testing beRepaired function ===\n" << std::endl;
    jhon.beRepaired(2);
    
    // Test multiple attacks to deplete energy
    std::cout << "\n=== Testing energy depletion ===\n" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << "Attack " << i+1 << ": ";
        jhon.attack("Enemy");
    }
    
    // Try to attack with no energy
    std::cout << "\n=== Testing attack with no energy ===\n" << std::endl;
    jhon.attack("Enemy");
    
    // Try to repair with no energy
    std::cout << "\n=== Testing repair with no energy ===\n" << std::endl;
    jhon.beRepaired(5);
    
    // Test taking enough damage to be destroyed
    std::cout << "\n=== Testing taking fatal damage ===\n" << std::endl;
    defaultST.takeDamage(15); // More than default hit points
    
    // Try actions when destroyed
    std::cout << "\n=== Testing actions when destroyed ===\n" << std::endl;
    defaultST.attack("Enemy");
    defaultST.beRepaired(5);
    defaultST.takeDamage(5);
    
    
    std::cout << "\n=== End of tests, destructors will be called ===\n" << std::endl;
    
    // Adding FragTrap tests
    std::cout << "\n===  FragTrap class tests ===\n" << std::endl;
    
    // Test default constructor
    std::cout << "\n=== Creating FragTrap with default constructor ===\n" << std::endl;
    FragTrap defaultFT;
    
    // Test parameterized constructor
    std::cout << "\n=== Creating FragTrap with name ===\n" << std::endl;
    FragTrap smith("Smith");
    
    // Test copy constructor
    std::cout << "\n=== Creating FragTrap with copy constructor ===\n" << std::endl;
    FragTrap smithClone(smith);
    
    // Test highFiveGuys function
    std::cout << "\n=== Creating test for highFiveGuys function ===\n" << std::endl;
    smith.highFivesGuys();
    
    // Test assignment operator
    std::cout << "\n=== Testing assignment operator ===\n" << std::endl;
    FragTrap assigned2;
    assigned2 = smith;
    
    // Test attack function
    std::cout << "\n=== Testing attack function ===\n" << std::endl;
    smith.attack("Enemy");
    
    // Test taking damage
    std::cout << "\n=== Testing takeDamage function ===\n" << std::endl;
    smith.takeDamage(30);
    
    // Test repairing
    std::cout << "\n=== Testing beRepaired function ===\n" << std::endl;
    smith.beRepaired(20);
    
    // Test multiple attacks to deplete energy
    std::cout << "\n=== Testing energy depletion ===\n" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << "Attack " << i+1 << ": ";
        smith.attack("Enemy");
    }
    
    // Try to attack with no energy
    std::cout << "\n=== Testing attack with no energy ===\n" << std::endl;
    smith.attack("Enemy");
    
    // Try to repair with no energy
    std::cout << "\n=== Testing repair with no energy ===\n" << std::endl;
    smith.beRepaired(5);
    
    // Test taking enough damage to be destroyed
    std::cout << "\n=== Testing taking fatal damage ===\n" << std::endl;
    defaultFT.takeDamage(150); // More than default hit points
    
    // Try actions when destroyed
    std::cout << "\n=== Testing actions when destroyed ===\n" << std::endl;
    defaultFT.attack("Enemy");
    defaultFT.beRepaired(5);
    defaultFT.takeDamage(5);
    defaultFT.highFivesGuys(); // Test special function when destroyed
    
    std::cout << "\n=== End of all tests, destructors will be called ===\n" << std::endl;
    */

    // Adding DiamondTrap tests
    std::cout << "\n\n===  DiamondTrap class tests ===\n" << std::endl;

    // Test default constructor
    std::cout << "\n=== Creating DiamondTrap with default constructor ===\n" << std::endl;
    DiamondTrap defaultDT;

    // Test parameterized constructor
    std::cout << "\n=== Creating DiamondTrap with name ===\n" << std::endl;
    DiamondTrap dave("Dave");

    // Test copy constructor
    std::cout << "\n=== Creating DiamondTrap with copy constructor ===\n" << std::endl;
    DiamondTrap daveClone(dave);

    // Test whoAmI function
    std::cout << "\n=== Testing whoAmI function ===\n" << std::endl;
    dave.whoAmI();

    // Test inherited abilities
    std::cout << "\n=== Testing inherited abilities ===\n" << std::endl;
    dave.guardGate();
    dave.highFivesGuys();

    // Test assignment operator
    std::cout << "\n=== Testing assignment operator ===\n" << std::endl;
    DiamondTrap assigned3;
    assigned3 = dave;
    assigned3.whoAmI();

    // Test attack function (should use ScavTrap's version)
    std::cout << "\n=== Testing attack function ===\n" << std::endl;
    dave.attack("Enemy");

    // Test taking damage
    std::cout << "\n=== Testing takeDamage function ===\n" << std::endl;
    dave.takeDamage(30);

    // Test repairing
    std::cout << "\n=== Testing beRepaired function ===\n" << std::endl;
    dave.beRepaired(20);

    // Test energy depletion (DiamondTrap should have ScavTrap's 50 energy points)
    std::cout << "\n=== Testing energy depletion (should take 50 attacks) ===\n" << std::endl;
    for (int i = 0; i < 50; i++) {
        if (i % 10 == 0) {
            std::cout << "Attack " << i+1 << ": ";
            dave.attack("Enemy");
        } else {
            dave.attack("Enemy");
        }
    }

    // Try to attack with no energy
    std::cout << "\n=== Testing attack with no energy ===\n" << std::endl;
    dave.attack("Enemy");

    // Try to repair with no energy
    std::cout << "\n=== Testing repair with no energy ===\n" << std::endl;
    dave.beRepaired(5);

    // Test taking fatal damage
    std::cout << "\n=== Testing taking fatal damage ===\n" << std::endl;
    defaultDT.takeDamage(150); // More than default hit points

    // Try actions when destroyed
    std::cout << "\n=== Testing actions when destroyed ===\n" << std::endl;
    defaultDT.attack("Enemy");
    defaultDT.beRepaired(5);
    defaultDT.takeDamage(5);
    defaultDT.whoAmI();
    defaultDT.guardGate();
    defaultDT.highFivesGuys();

    std::cout << "\n=== End of DiamondTrap tests, destructors will be called ===\n" << std::endl;

    return 0;
}