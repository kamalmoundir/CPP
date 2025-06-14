/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:41:15 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/14 16:19:51 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():AForm("ShrubberyCreation",false,145,137),_target("default")
{}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):AForm("ShrubberyCreation",false,145,137),_target(target)
{}
ShrubberyCreationForm::~ShrubberyCreationForm()
{}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):AForm(other),_target(other._target)
{}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)  
{
    if(this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

void ShrubberyCreationForm::execute( const Bureaucrat& executor) const
{
   
    if(!this->getIsSigned())
        throw AForm::FormNotSignedException();
    if(executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::string filename = _target + "_shrubbery";
    std::ofstream outFile(filename.c_str());

    if (!outFile.is_open())
        throw FileOpenException();

    outFile << "         v" << std::endl;
    outFile << "        >X<" << std::endl;
    outFile << "         A" << std::endl;
    outFile << "        d$b" << std::endl;
    outFile << "      .d\\$$b." << std::endl;
    outFile << "    .d$i$$\\$$b." << std::endl;
    outFile << "       d$$@b" << std::endl;
    outFile << "      d\\$$$ib" << std::endl;
    outFile << "    .d$$$\\$$$b" << std::endl;
    outFile << "  .d$$@$$$$\\$$ib." << std::endl;
    outFile << "      d$$i$$b" << std::endl;
    outFile << "     d\\$$$$@$b" << std::endl;
    outFile << "  .d$@$$\\$$$$$@b." << std::endl;
    outFile << ".d$$$$i$$$\\$$$$$$b." << std::endl;
    outFile << "        ###" << std::endl;
    outFile << "        ###" << std::endl;
    outFile << "        ###" << std::endl;

    outFile.close();
}

const char *ShrubberyCreationForm::FileOpenException::what() const throw()
{
    return "Could not open file for writing";
}