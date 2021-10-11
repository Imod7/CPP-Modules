/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Phonebook.class.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <dsaripap@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/09 15:01:22 by dsaripap      #+#    #+#                 */
/*   Updated: 2021/10/11 22:33:00 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"

Phonebook::Phonebook( void ) {
    arr_length = 0;
    std::cout << BOLDGREEN << " ----- Phonebook from another Galaxy !!! ----- " << RESET << std::endl;
    std::cout << " ------------------------------------------------------ " << std::endl;
    this->menu();

}

int    Phonebook::Exit( void ) {

    std::cout << BOLDRED << "Exiting the Phonebook program" << RESET << std::endl;
    exit( EXIT_SUCCESS );

}

void    Phonebook::command_handler( std::string s ) {

    if (s == "ADD") {
        this->set_contact();
    }
    else if (s == "SEARCH") {
        this->get_contact();
    }
    else if (s == "EXIT") {
        this->Exit();
    }
    else {
        std::cout << "Please choose a valid command (ADD, SEARCH or EXIT)" << std::endl;
    }    

    this->menu();

}

int     Phonebook::menu( void ) {

    std::string command;

    std::cout << "Please choose your command [ " << BOLDCYAN << "ADD, SEARCH or EXIT" << RESET << "] : ";
    std::cin >> command;

    this->command_handler(command);

    return (0);
}

void    Phonebook::set_contact( void ) {
    this->contacts[ this->arr_length ] = this->contacts[ this->arr_length ].Add();
    this->arr_length++;
    return;
}

void    Phonebook::get_contact( void ) {
    unsigned int index;

    std::cout << "Please choose the Contact you would like to see [ 0-7 ]: ";
    std::cin >> index;
    return this->contacts[ index ].Search(this->contacts[ index ], index);
}
