/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Phonebook.class.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <dsaripap@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/09 15:01:22 by dsaripap      #+#    #+#                 */
/*   Updated: 2021/11/12 17:01:04 by dsaripap      ########   odam.nl         */
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
  exit(EXIT_SUCCESS);
}

void    Phonebook::menu(void) {
  std::string command;

  std::cout << "Please choose your command [ ";
  std::cout << BOLDCYAN << "ADD, SEARCH or EXIT" << RESET << "] : ";

  while (std::getline(std::cin, command)) {
    if (command == "ADD") {
      this->add();
    } else if (command == "SEARCH") {
      if (this->search() == -1)
        break;
    } else if (command == "EXIT") {
      std::cout << BOLDRED << "----- Exiting the Phonebook program -----";
      std::cout << RESET << std::endl;
      exit(EXIT_SUCCESS);
    } else {
      std::cout << BOLDRED << "Please choose a valid command" << RESET;
      std::cout << std::endl;
    }
    this->menu();
  }
}

void    Phonebook::add(void) {
  if (this->arr_length < 8) {
    this->contacts[this->arr_length] = \
    this->contacts[this->arr_length].add_contact();
  } else {
    this->arr_length = 0;
    this->contacts[this->arr_length] = \
    this->contacts[this->arr_length].add_contact();
  }
  this->arr_length++;
  return;
}

int     Phonebook::search(void) {
  std::stringstream ss;
  std::string input_str;
  size_t contact_index;

  if (this->check_if_phonebook_is_empty() == false) {
    Contact::print_contact_header();

    for (size_t index = 0; index < 8; index++)
      if ((this->contacts[index].get_first_name() != "") ||
      (this->contacts[index].get_last_name() != "") ||
      (this->contacts[index].get_nickname() != ""))
        this->contacts[index].print_contact_preview(index);
    std::cout << "Select the index of the Contact you want to see ";
    if (arr_length > 0) {
      std::cout << "[ " << BOLDCYAN << "0 - " << arr_length - 1;
    } else {
      std::cout << "[ " << BOLDCYAN << "0";
    }
    std::cout << RESET << " ] : ";
    std::getline(std::cin, input_str);
    ss << input_str;
    ss >> contact_index;
    if (ss.fail()) {
      std::cout << BOLDRED << "This is an invalid index!";
      std::cout << RESET << std::endl;
    } else {
      this->contacts[contact_index].check_requested_contact(
            contact_index, this->arr_length);
    }
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
    (this->contacts[index].get_nickname() != "")) {
      is_empty = false;
      break;
    }
  }
  return is_empty;
}
