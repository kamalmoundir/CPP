/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:01:38 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/17 13:16:50 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Bureaucrat.hpp"
#include "Form.hpp"

void testFrom(void);

int main() {
    std::cout << "===== BUREAUCRAT TESTS =====\n";
    
    // Test valid bureaucrats
    try {
        Bureaucrat high("High", 1);
        std::cout << "Created: " << high << std::endl;
        
        Bureaucrat low("Low", 150);
        std::cout << "Created: " << low << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    // Test too high grade
    try {
        std::cout << "\nTrying to create bureaucrat with too high grade (0)..." << std::endl;
        Bureaucrat tooHigh("TooHigh", 0);
        std::cout << "This line should not execute" << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    
    // Test too low grade
    try {
        std::cout << "\nTrying to create bureaucrat with too low grade (151)..." << std::endl;
        Bureaucrat tooLow("TooLow", 151);
        std::cout << "This line should not execute" << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    
    // Test grade incrementation/decrementation
    try {
        
        Bureaucrat b("Worker", 75);
        std::cout << "\nCreated: " << b << std::endl;
        
        b.incrementGrade();
        std::cout << "After increment: " << b << std::endl;
        
        b.decrementGrade();
        std::cout << "After decrement: " << b << std::endl;

        
        
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout<<"\n\n==Decrement low grade =="<<std::endl;
        Bureaucrat limitGrade("LowGrade",150);
        limitGrade.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout<<"\n\n==increment high grade =="<<std::endl;
        
        Bureaucrat limitGrade1("HighGrade", 1);
        limitGrade1.incrementGrade();
    
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    testFrom();
    return 0;
}


void testFrom(void)
{

    std::cout <<"\n============= FORM TESTS =============\n";
    try
    {
       //create a form with valid grades
    Form validForm("Tax Form", false, 50, 25);
    std::cout<< validForm << std::endl;
    
    //create a bureaucrat (Manager) with sufficiente grade
    Bureaucrat manager("Manager",45);
    manager.signForm(validForm);
    std::cout<<validForm<<std::endl;

    //TEST : signign with sufficient grade
    Bureaucrat clerk("Clerk", 100);
    Form FormWithhighRequarment("high privilege",false,10,10);
    clerk.signForm(FormWithhighRequarment);

    // test invalid form
    Form invalidFrom("invalid Form", false ,0 ,160);
    
    }
    catch(const std::exception& e)
    {
        std::cerr <<"Exception in form tests:" <<e.what() << '\n';
    }
    
    
}