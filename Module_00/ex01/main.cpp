/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <dsaripap@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/02 16:27:13 by dsaripap      #+#    #+#                 */
/*   Updated: 2021/10/09 15:04:24 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <map>
#include "Phonebook.class.hpp"

int main( void )
{
    Phonebook obj;

    std::string command;
    std::cout << "Please enter your input : ";
    std::cin >> command;

    obj.command_handler(command);
    return 0;
}
