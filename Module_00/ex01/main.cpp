/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <dsaripap@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/02 16:27:13 by dsaripap      #+#    #+#                 */
/*   Updated: 2021/10/07 14:37:44 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <map>
#include "Dispatcher.class.hpp"

typedef void (Dispatcher::*DispatchCommand)( void );

int main( void )
{
    Dispatcher obj;

    std::map<std::string, DispatchCommand> mapping;
    mapping["ADD"] = &Dispatcher::Add;
    mapping["SEARCH"] = &Dispatcher::Search;
    mapping["EXIT"] = &Dispatcher::Exit;

    std::string command;
    std::cout << "Please enter your input : ";
    std::cin >> command;

    (obj.*mapping[command])();

    return 0;
}
