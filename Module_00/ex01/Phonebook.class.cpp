/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Phonebook.class.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <dsaripap@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/09 15:01:22 by dsaripap      #+#    #+#                 */
/*   Updated: 2021/11/14 20:55:07 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"
#include "Format.hpp"

Phonebook::Phonebook(void) {
  arr_length = 0;
  std::cout << BOLDGREEN << " --------------------------------------------- ";
  std::cout << std::endl;
  std::cout << "                   _..._                             ";
  std::cout << std::endl;
  std::cout << "                 .'     '.      _          " << std::endl;
  std::cout << "                /      .-""-\\   _/ \\            ";
  std::cout << std::endl;
  std::cout << "              .-|  /:.    |   |   |          " << std::endl;
  std::cout << "              |  \\  |:.   /.-'- ./           " << std::endl;
  std::cout << "              | .-'-;:__.'      =/            " << std::endl;
  std::cout << "              .'=  *=|       _.='         " << std::endl;
  std::cout << "             /   _.  |      ;            " << std::endl;
  std::cout << "            ;-.-'|    \\    |           " << std::endl;
  std::cout << "           /   | \\    _\\  _\\         " << std::endl;
  std::cout << "          \\__/'._;.  ==' ==\\            " << std::endl;
  std::cout << "                   \\    \\   |            " << std::endl;
  std::cout << "                   /    /   /            " << std::endl;
  std::cout << "                   /-._/-._/         " << std::endl;
  std::cout << "                  \\   `\\  \\          " << std::endl;
  std::cout << "                   `-._/._/          " << std::endl;

  std::cout << " ----- Phonebook from Another Galaxy !!! ----- " << std::endl;
  std::cout << " --------------------------------------------- " << RESET;
  std::cout << std::endl;
  this->menu();
}

Phonebook::~Phonebook() {
  std::cout << std::endl;
  std::cout << BOLDRED << " ----- Exiting the Phonebook program ----- ";
  std::cout << RESET << std::endl;
}

void    Phonebook::menu(void) {
  std::string command;

  if (!std::cin.eof()) {
    std::cout << "Please choose your command [ ";
    std::cout << BOLDCYAN << "ADD, SEARCH or EXIT" << RESET << "] : ";
  }

  while (std::getline(std::cin, command)) {
    if (command == "ADD") {
      this->add();
    } else if (command == "SEARCH") {
      if (this->search() == -1)
        break;
    } else if (command == "EXIT") {
      std::cout << BOLDRED << " ----- Exiting the Phonebook program ----- ";
      std::cout << RESET << std::endl;
      exit(0);
    } else {
      std::cout << BOLDRED << "Please choose a valid command" << RESET;
      std::cout << std::endl;
    }
    this->menu();
  }
}

void    Phonebook::add(void) {
  Contact contact_instance;

  if (this->arr_length == 8)
    this->arr_length = 0;

  contact_instance = contact_instance.add_contact();
  if (check_if_contact_not_empty(contact_instance) == true) {
    this->contacts[this->arr_length] = contact_instance;
    this->arr_length++;
  }

  return;
}

int     Phonebook::search(void) {
  if (this->check_if_phonebook_is_empty() == false) {
    Contact::print_contact_header();

    for (size_t index = 0; index < 8; index++)
      if (check_if_contact_not_empty(this->contacts[index]) == true)
        this->contacts[index].print_contact_preview(index);

    if (select_contact_index() == -1)
      return (-1);
  } else {
    std::cout << BOLDRED << "The Phonebook from Another Galaxy is empty!:(";
    std::cout << RESET << std::endl;
  }
  return 0;
}

bool Phonebook::check_if_phonebook_is_empty(void) {
  bool is_empty = true;

  for (size_t index = 0; index < 8; index++) {
    if ((this->contacts[index].get_first_name() != "") ||
    (this->contacts[index].get_last_name() != "") ||
    (this->contacts[index].get_nickname() != "") ||
    (this->contacts[index].get_phone_number() != "") ||
    (this->contacts[index].get_darkest_secret() != "")) {
      is_empty = false;
      break;
    }
  }
  return is_empty;
}

bool        Phonebook::check_if_contact_not_empty(Contact obj) {
  bool not_empty = true;

  if ((obj.get_first_name() == "") &&
  (obj.get_last_name() == "") &&
  (obj.get_nickname() == "") &&
  (obj.get_phone_number() == "") &&
  (obj.get_darkest_secret() == "")) {
    not_empty = false;
  }
  return not_empty;
}

int        Phonebook::select_contact_index(void) {
  std::stringstream ss;
  std::string input_str;
  size_t contact_index;

  std::cout << "Select the index of the Contact you want to see ";
  if (arr_length > 1) {
    std::cout << "[ " << BOLDCYAN << "0 - " << arr_length - 1;
  } else {
    std::cout << "[ " << BOLDCYAN << "0";
  }
  std::cout << RESET << " ] : ";

  std::getline(std::cin, input_str);
  if (std::cin.eof()) {
    return (-1);
  }
  ss << input_str;
  ss >> contact_index;
  if (ss.fail()) {
    std::cout << BOLDRED << "This is an invalid index!";
    std::cout << RESET << std::endl;
  } else {
    this->contacts[contact_index].check_requested_contact(
          contact_index, this->arr_length);
  }
  return (0);
}
