/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.class.cpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <dsaripap@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 16:49:28 by dsaripap      #+#    #+#                 */
/*   Updated: 2021/10/11 22:33:18 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include "Contact.class.hpp"

void    Contact::set_first_name( std::string str ) {
    this->first_name = str;
}

std::string  Contact::get_first_name() {
    return this->first_name;
}

void    Contact::set_last_name( std::string str ) {
    this->last_name = str;
}

std::string     Contact::get_last_name( void ) {
    return this->last_name;
}

void    Contact::set_nickname( std::string str ) {
    this->nickname = str;
}

std::string     Contact::get_nickname( void ) {
    return this->nickname;
}

void    Contact::set_phone_number( std::string str ) {
    this->phone_number = str;
}

std::string     Contact::get_phone_number( void ) {
    return this->phone_number;
}

void    Contact::set_darkest_secret( std::string str ) {
    this->darkest_secret = str;
}

std::string     Contact::get_darkest_secret( void ) {
    return this->darkest_secret;
}

Contact    Contact::Add( void ) {

    std::string input;
    Contact     obj;

    std::cout << "Please insert your first name: " << std::endl;
    std::cin >> input;
    obj.set_first_name(input);

    std::cout << "Please insert your last name: " << std::endl;
    std::cin >> input;
    obj.set_last_name(input);

    std::cout << "Please choose a nickname: " << std::endl;
    std::cin >> input;
    obj.set_nickname(input);

    std::cout << "Please insert a phone number: " << std::endl;
    std::cin >> input;
    obj.set_phone_number(input);

    std::cout << "Please share your darkest secret: " << std::endl;
    std::cin >> input;
    obj.set_darkest_secret(input);

    return obj;

}

void    Contact::Search( Contact contact_obj, unsigned int index ) {

    std::cout << "SEARCH command called" << std::endl;

    std::cout << std::setw(11) << std::right;
    std::cout << "index|";
    
    std::cout << std::setw(11) << std::right;
    std::cout << "first name|";
    
    std::cout << std::setw(11) << std::right;
    std::cout << "last name|";
    
    std::cout << std::setw(11) << std::right;
    std::cout << "nickname|" << std::endl;

    std::cout << std::setw(10) << std::right;
    std::cout << index;

    std::cout << std::setw(1) << std::right;
    std::cout << "|";

    this->format_output( contact_obj.get_first_name() );
    this->format_output( contact_obj.get_last_name() );
    this->format_output( contact_obj.get_nickname() );

    std::cout << std::endl;

    return; 

}

void    Contact::format_output( std::string str ) {
    if (str.length() > 10) {
        std::cout << std::setw(11) << std::right;
        std::cout << str.substr(0, 9) + ".|";
    } 
    else {
        std::cout << std::setw(11) << std::right;
        std::cout << str.substr(0, 10) + "|";
    }

}
