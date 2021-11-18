/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Megaphone.class.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <dsaripap@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/10 19:29:21 by dsaripap      #+#    #+#                 */
/*   Updated: 2021/11/18 13:56:26 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Megaphone.class.hpp"

int Megaphone::ft_toupper(int c) {
  if (c >= 97 && c <= 122)
    return (c - 32);
  return (c);
}

int Megaphone::individual_arg_is_spaces(char *argv) {
  int i;

  i = 0;
  while (argv[i] != 0) {
      if (std::isspace(argv[i]) == 0)
        return (0);
      i++;
    }
  return (1);
}

int Megaphone::all_args_are_spaces(char **argv) {
  int i;

  i = 1;
  while (argv[i] != 0) {
    if (individual_arg_is_spaces(argv[i]) == 0) {
      return (0);
    }
    i++;
  }
  return (1);
}

Megaphone::Megaphone(int argc, char **argv) {
  int i;
  int j;

  if ((argc == 1) || (strcmp(argv[1], "") == 0) ||
  all_args_are_spaces(argv) == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  } else {
    i = 1;
    while (i < argc) {
      if (individual_arg_is_spaces(argv[i]) == 1) {
        i++;
      } else {
        j = 0;
        while (argv[i][j] != 0) {
          argv[i][j] = Megaphone::ft_toupper(argv[i][j]);
          std::cout << argv[i][j];
          j++;
        }
        i++;
      }
    }
  }
  std::cout << std::endl;
}
