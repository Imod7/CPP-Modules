/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Phonebook.class.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <dsaripap@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 14:46:40 by dsaripap      #+#    #+#                 */
/*   Updated: 2021/11/12 16:51:22 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include <iostream>
#include <string>
#include <sstream>
#include "Contact.class.hpp"

#define ARRAY_MAX 8

class Phonebook {
 private:
  Contact contacts[ARRAY_MAX];

 public:
  unsigned int    arr_length;

  Phonebook(void);
  ~Phonebook();
  void            menu(void);
  void            add(void);
  int             search(void);
  bool            check_if_phonebook_is_empty(void);
  int             prgm_exit(void);
};

#endif
