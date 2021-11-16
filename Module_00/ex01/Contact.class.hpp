/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.class.hpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <dsaripap@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 16:48:03 by dsaripap      #+#    #+#                 */
/*   Updated: 2021/11/16 17:02:50 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <iostream>
#include <string>

class Contact {
 private:
  std::string  _first_name;
  std::string  _last_name;
  std::string  _nickname;
  std::string  _phone_number;
  std::string  _darkest_secret;

 public:
  void          set_first_name(std::string str);
  std::string   get_first_name(void) const;

  void          set_last_name(std::string str);
  std::string   get_last_name(void) const;

  void          set_nickname(std::string str);
  std::string   get_nickname(void) const;

  void          set_phone_number(std::string str);
  std::string   get_phone_number(void) const;

  void          set_darkest_secret(std::string str);
  std::string   get_darkest_secret(void) const;

  Contact       add_contact(void);
  void          check_requested_contact(long index,
                                       unsigned int arr_length) const;

  static void   format_output(std::string text);

  static void   print_contact_header(void);
  void          print_contact_preview(size_t index) const;
  void          print_contact_details(void) const;
};

#endif
