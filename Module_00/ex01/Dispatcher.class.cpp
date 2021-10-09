/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dispatcher.class.cpp                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <dsaripap@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 15:22:45 by dsaripap      #+#    #+#                 */
/*   Updated: 2021/10/07 14:12:24 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dispatcher.class.hpp"

void    Dispatcher::Add( void ) {

    std::cout << "ADD command called" << std::endl;
    return;

}

void    Dispatcher::Search( void ) {

    std::cout << "SEARCH command called" << std::endl;
    return; 

}

void    Dispatcher::Exit( void ) {

    std::cout << "EXIT command called" << std::endl;
    return;

}
