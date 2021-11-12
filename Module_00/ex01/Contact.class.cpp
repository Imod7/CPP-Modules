/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.class.cpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <dsaripap@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 16:49:28 by dsaripap      #+#    #+#                 */
/*   Updated: 2021/11/12 17:05:17 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include "Format.hpp"

void        Contact::set_first_name(std::string str) {
  this->first_name = str;
}

std::string Contact::get_first_name() {
  return this->first_name;
}

void        Contact::set_last_name(std::string str) {
  this->last_name = str;
}

std::string Contact::get_last_name(void) {
  return this->last_name;
}

void        Contact::set_nickname(std::string str) {
  this->nickname = str;
}

std::string Contact::get_nickname(void) {
  return this->nickname;
}

void        Contact::set_phone_number(std::string str) {
  this->phone_number = str;
}

std::string Contact::get_phone_number(void) {
  return this->phone_number;
}

void        Contact::set_darkest_secret(std::string str) {
  this->darkest_secret = str;
}

std::string Contact::get_darkest_secret(void) {
  return this->darkest_secret;
}

Contact     Contact::add_contact(void) {
  std::string     input;
  Contact         obj;

  std::cout << "Please insert your first name: " << std::endl;
  std::getline(std::cin, input);
  if (!std::cin.eof())
    obj.set_first_name(input);
  else
    return obj;

  std::cout << "Please insert your last name: " << std::endl;
  std::getline(std::cin, input);
  if (!std::cin.eof())
    obj.set_last_name(input);
  else
    return obj;

  std::cout << "Please choose a nickname: " << std::endl;
  std::getline(std::cin, input);
  if (!std::cin.eof())
    obj.set_nickname(input);
  else
    return obj;

  std::cout << "Please insert a phone number: " << std::endl;
  std::getline(std::cin, input);
  if (!std::cin.eof())
    obj.set_phone_number(input);
  else
    return obj;

  std::cout << "Please share your darkest secret: " << std::endl;
  std::getline(std::cin, input);
  if (!std::cin.eof())
    obj.set_darkest_secret(input);
  else
    return obj;

  return obj;
}

void        Contact::format_output(std::string str) {
  if (str.length() > 10) {
    std::cout << std::setw(11) << std::right;
    std::cout << str.substr(0, 9) + ".|";
  } else {
    std::cout << std::setw(11) << std::right;
    std::cout << str.substr(0, 10) + "|";
  }
}

void        Contact::print_contact_header(void) {
  std::cout << std::setw(11) << std::right;
  std::cout << "index|";

  std::cout << std::setw(11) << std::right;
  std::cout << "first name|";

  std::cout << std::setw(11) << std::right;
  std::cout << "last name|";

  std::cout << std::setw(11) << std::right;
  std::cout << "nickname|" << std::endl;
}

void        Contact::print_contact_preview(size_t index) {
  std::cout << std::setw(10) << std::right;

  std::cout << index << "|";
  format_output(this->get_first_name());
  format_output(this->get_last_name());
  format_output(this->get_nickname());
  std::cout << std::endl;
}

void        Contact::print_contact_details() {
  std::cout << std::setw(10) << std::right;

  std::cout << "First name: ";
  std::cout << this->get_first_name();
  std::cout << std::endl;

  std::cout << "Last name: ";
  std::cout << this->get_last_name();
  std::cout << std::endl;

  std::cout << "Nickname: ";
  std::cout << this->get_nickname();
  std::cout << std::endl;

  std::cout << "Phone number: ";
  std::cout << this->get_phone_number();
  std::cout << std::endl;

  std::cout << "Darkest secret: ";
  std::cout << this->get_darkest_secret();
  std::cout << std::endl;
}

void        Contact::check_requested_contact(long int index,
                                                    unsigned int arr_length) {
  if (index < 0 || index > 7) {
    std::cout << BOLDRED << "The requested index is out of bound!";
    std::cout << RESET << std::endl;
    std::cout << BOLDCYAN << "Please choose an index between 0 and ";
    std::cout << arr_length - 1 << "!" RESET << std::endl;
  } else if ((!(index < 0 || index > 7)) &&
  (this->check_if_contact_exists() == true)) {
    this->print_contact_details();
  } else if (this->check_if_contact_exists() == false) {
    std::cout << BOLDRED << "No Contact exists in this index!";
    std::cout << RESET << std::endl;
  } else {
    std::cout << BOLDRED << "Choose a valid index!" << RESET << std::endl;
  }
}

bool                Contact::check_if_contact_exists() {
  bool exists = false;

  if ((this->get_first_name() != "") ||
  (this->get_last_name() != "") ||
  (this->get_nickname() != ""))
    exists = true;

  return exists;
}
