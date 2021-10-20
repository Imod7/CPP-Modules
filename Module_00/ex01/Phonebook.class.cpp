/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Phonebook.class.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <dsaripap@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/09 15:01:22 by dsaripap      #+#    #+#                 */
/*   Updated: 2021/10/20 16:23:12 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"
#include "Format.hpp"

Phonebook::Phonebook( void ) {
    arr_length = 0;
    std::cout << BOLDGREEN << " --------------------------------------------- " << std::endl;
    std::cout << "                   _..._                             " << std::endl;
    std::cout << "                 .'     '.      _          " << std::endl;
    std::cout << "                /      .-""-\\   _/ \\            " << std::endl;
    std::cout << "              .-|  /:.    |   |   |          " << std::endl;
    std::cout << "              |  \\  |:.   /.-'- ./           " << std::endl;
    std::cout << "              | .-'-;:__.'      =/            " << std::endl;
    std::cout << "              .'=  *=|       _.='         " << std::endl;
    std::cout << "             /   _.  |      ;            " << std::endl;
    std::cout << "            ;-.-'|    \\    |           " << std::endl;
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
    std::cout << std::endl;
    std::cout << BOLDRED << " ----- Exiting the Phonebook program ----- " << std::endl;
    std::cout << " --------------------------------------------- " << RESET << std::endl;
    exit( EXIT_SUCCESS );
}

void    Phonebook::menu( void ) {

    std::string command;

    std::cout << "Please choose your command [ " << BOLDCYAN << "ADD, SEARCH or EXIT" << RESET << "] : ";

    while (std::getline(std::cin, command)) {
        if (command == "ADD")
            this->add();
        else if (command == "SEARCH") {
            if (this->search() == -1)
                break;
        }
        else if (command == "EXIT") {
            std::cout << std::endl;
            std::cout << BOLDRED << " ----- Exiting the Phonebook program ----- " << std::endl;
            std::cout << " --------------------------------------------- " << RESET << std::endl;
            exit( EXIT_SUCCESS );
        }
        else
            std::cout << BOLDRED << "Please choose a valid command" << RESET << std::endl;
        
        this->menu();
    }

}

void    Phonebook::add( void ) {
    if (this->arr_length < 8)
        this->contacts[this->arr_length] = this->contacts[this->arr_length].add_contact();
    else {
        this->arr_length = 0;
        this->contacts[this->arr_length] = this->contacts[this->arr_length].add_contact();
    }
    this->arr_length++;
    return;
}

int     Phonebook::search( void ) {
    std::string     input_str;
    long            contact_index;

    if (this->check_if_phonebook_is_empty() == false) {
        Contact::print_contact_header();

        for (size_t index = 0; index < 8; index++) 
            if ((this->contacts[index].get_first_name() != "") or 
            (this->contacts[index].get_last_name() != "") or 
            (this->contacts[index].get_nickname() != ""))
                this->contacts[index].print_contact_preview(index);

        std::cout << "Select the index of the Contact you want to see: ";
        std::getline(std::cin, input_str);
        if (!std::cin.eof()) {
            contact_index = 0;
            if (check_if_index_is_valid(input_str) == 0) {
                contact_index = std::stoll(input_str);
                this->contacts[contact_index].check_requested_contact(contact_index, this->arr_length);
            }
            else
                std::cout << BOLDRED << "This is an invalid index!" << RESET << std::endl;
        }
        else
            return -1;
    
    }
    else
        std::cout << BOLDRED << "The Phonebook from Another Galaxy is empty! :( " << RESET << std::endl;

    return 0;
}

int     Phonebook::check_if_index_is_valid(std::string str) {

    long long index;

    try {
        index = std::stoll(str);
        return 0;
    }
    catch (const std::invalid_argument& ia) {
        return -1;
    }

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
