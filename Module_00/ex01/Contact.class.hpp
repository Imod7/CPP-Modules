/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.class.hpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <dsaripap@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 16:48:03 by dsaripap      #+#    #+#                 */
/*   Updated: 2021/10/11 21:53:34 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <iostream>
#include <string>

class Contact {

private:
    std::string     first_name;
    std::string     last_name;
    std::string     nickname;
    std::string     phone_number;
    std::string     darkest_secret;

public:
    void        set_first_name( std::string str );
    std::string get_first_name( void );

    void        set_last_name( std::string str );
    std::string get_last_name( void );

    void        set_nickname( std::string str );
    std::string get_nickname( void );

    void        set_phone_number( std::string str );
    std::string get_phone_number( void );

    void        set_darkest_secret( std::string str );
    std::string get_darkest_secret( void );

    Contact     Add( void );
    void        Search( Contact contact_obj, unsigned int index );

    void        format_output( std::string text );

};

#endif