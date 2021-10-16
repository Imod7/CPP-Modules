/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Phonebook.class.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <dsaripap@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/09 15:01:22 by dsaripap      #+#    #+#                 */
/*   Updated: 2021/10/16 20:43:25 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"
#include "Format.hpp"

Phonebook::Phonebook( void ) {
    arr_length = 0;
    std::cout << BOLDGREEN << " --------------------------------------------- " << std::endl;
    std::cout << "                   _..._                             " << std::endl;
    std::cout << "                 .'     '.      _          " << std::endl;
    std::cout << "                /   .-""-\\   _/ \\            " << std::endl;
    std::cout << "              .-|  /:.    |   |   |          " << std::endl;
    std::cout << "              |  \\  |:.   /.-'-./           " << std::endl;
    std::cout << "              | .-'-;:__.'    =/            " << std::endl;
    std::cout << "              .'=  *=|     _.='         " << std::endl;
    std::cout << "             /   _.  |    ;            " << std::endl;
    std::cout << "            ;-.-'|    \\   |           " << std::endl;
    std::cout << "           /   | \\    _\\  _\\         " << std::endl;
    std::cout << "          \\__/'._;.  ==' ==\\            " << std::endl;
    std::cout << "                   \\    \\   |            " << std::endl;
    std::cout << "                   /    /   /            " << std::endl;
    std::cout << "                   /-._/-._/         " << std::endl;
    std::cout << "                  \\   `\\  \\          " << std::endl;
    std::cout << "                   `-._/._/          " << std::endl;

    std::cout << " ----- Phonebook from Another Galaxy !!! ----- " << std::endl;
    std::cout << " --------------------------------------------- " << RESET << std::endl;
    this->menu();

}

Phonebook::~Phonebook( void ) {
    std::cout << BOLDRED << " ----- Exiting the Phonebook program ----- " << RESET << std::endl;
    std::cout << " ------------------------------------------------------ " << std::endl;

}

// int    Phonebook::prgm_exit( void ) {

//     std::cout << BOLDRED << "Exiting the Phonebook program" << RESET << std::endl;
//     exit( EXIT_SUCCESS );

// }

void    Phonebook::menu( void ) {

    std::string command;

    std::cout << "Please choose your command [ " << BOLDCYAN << "ADD, SEARCH or EXIT" << RESET << "] : ";
    std::cin >> command;

    if (command == "ADD")
        this->add();
    else if (command == "SEARCH")
        this->search();
    else if (command == "EXIT") {
        std::cout << BOLDRED << "Exiting the Phonebook program" << RESET << std::endl;
        exit( EXIT_SUCCESS );
    }
    else
        std::cout << BOLDRED << "Please choose a valid command" << RESET << std::endl;
    
    this->menu();

}

void    Phonebook::add( void ) {
    this->contacts[ this->arr_length ] = this->contacts[ this->arr_length ].add_contact();
    this->arr_length++;
    return;
}

void    Phonebook::search( void ) {
    long     contact_index;

    if (this->check_if_phonebook_is_empty() == false) {
        Contact::print_contact_header();

        for (size_t index = 0; index < 8; index++) 
            if ((this->contacts[index].get_first_name() != "") or 
            (this->contacts[index].get_last_name() != "") or 
            (this->contacts[index].get_nickname() != ""))
                this->contacts[index].print_contact_preview(index);
        
        // std::cout << "Please choose the Contact you would like to see [ 0-7 ]: ";
        // std::cin >> index_str;

        // result = check_is_unsigned_long(index_str);
        // index = std::stol(index_str);

        std::cout << "Select the index of the Contact you want to see: ";
        std::cin >> contact_index;
        this->contacts[contact_index].check_requested_contact(contact_index);
    }
    else
        std::cout << BOLDRED << "The Phonebook from Another Galaxy is empty! :( " << RESET << std::endl;

}

bool    Phonebook::check_if_phonebook_is_empty(void) {
    
    bool is_empty = true;

    for (size_t index = 0; index < 8; index++) {
        if ((this->contacts[index].get_first_name() != "") or 
        (this->contacts[index].get_last_name() != "") or 
        (this->contacts[index].get_nickname() != "")) {
            is_empty = false;
            break;
        }
    }
    return is_empty;
}

// bool     Phonebook::check_is_unsigned_long( std::string str ) {

//     for (unsigned long i = 0; i < str.length(); i++)
//     {
//         if (i == 0 and str[i] == '+')
//             ;
//         if (isdigit(str[i]) == false)
//             return false;
//     }
//     return true;

// }
