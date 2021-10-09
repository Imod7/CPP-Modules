/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Phonebook.class.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <dsaripap@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/09 15:01:22 by dsaripap      #+#    #+#                 */
/*   Updated: 2021/10/09 15:13:37 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Phonebook.class.hpp"

void    Phonebook::Add( void ) {

    std::cout << "ADD command called" << std::endl;
    return;

}

void    Phonebook::Search( void ) {

    std::cout << "SEARCH command called" << std::endl;
    return; 

}

void    Phonebook::Exit( void ) {

    std::cout << "EXIT command called" << std::endl;
    return;

}

void    Phonebook::command_handler( std::string s ) {

    std::cout << "Handling user input" << std::endl;

    if (s == "ADD") {
        this->Add();
    }
    else if (s == "SEARCH") {
        this->Search();
    }
    else if (s == "EXIT") {
        this->Exit();
    }
    else {
        std::cout << "Please choose one valid command (ADD, SEARCH or EXIT)" << std::endl;
    }    

    return;

}