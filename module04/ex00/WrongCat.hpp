/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:26:02 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/07 15:18:36 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat:public WrongAnimal
{
    public:
    WrongCat();
    WrongCat(const std::string type);
    WrongCat(const WrongCat& obj);
    WrongCat &operator=(const WrongCat& obj);
    ~WrongCat();
    void makeSound() const;
};

#endif