/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Megaphone.class.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <dsaripap@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/10 19:29:58 by dsaripap      #+#    #+#                 */
/*   Updated: 2021/11/18 13:46:53 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEGAPHONE_CLASS_HPP
# define MEGAPHONE_CLASS_HPP

#include <iostream>
#include <string>

class Megaphone {
 public:
  static int  ft_toupper(int c);
  int         individual_arg_is_spaces(char *argv);
  int         all_args_are_spaces(char **argv);
  Megaphone(int argc, char **argv);
};

#endif
