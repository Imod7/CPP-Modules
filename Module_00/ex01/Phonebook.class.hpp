/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Phonebook.class.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <dsaripap@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 14:46:40 by dsaripap      #+#    #+#                 */
/*   Updated: 2021/10/11 22:31:28 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include <iostream>
#include <string>
#include "Contact.class.hpp"

#define ARRAY_MAX 8

//Define colors to print colored text on terminal
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */

class Phonebook {

private:
    Contact contacts[ ARRAY_MAX ];

public:
    unsigned int arr_length;
    Phonebook( void );
    void    set_contact( void );
    void    get_contact( void );
    int Exit( void );
    int menu( void );
    void command_handler( std::string s );

};

#endif