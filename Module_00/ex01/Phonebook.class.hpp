/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Phonebook.class.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <dsaripap@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 14:46:40 by dsaripap      #+#    #+#                 */
/*   Updated: 2021/10/09 15:10:32 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Phonebook {

public:
    void Add( void );
    void Search( void );
    void Exit( void );
    void command_handler( std::string s );
};