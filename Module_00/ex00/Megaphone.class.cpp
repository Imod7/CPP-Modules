/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Megaphone.class.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <dsaripap@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/10 19:29:21 by dsaripap      #+#    #+#                 */
/*   Updated: 2021/11/11 22:05:18 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Megaphone.class.hpp"

int Megaphone::ft_toupper(int c) {
  if (c >= 97 && c <= 122)
    return (c - 32);
  return (c);
}

Megaphone::Megaphone(int argc, char **argv) {
  int j;


  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  } else {
    j = 1;
    while (j < argc) {
      int i;

      i = 0;
      while (argv[j][i] != 0) {
        argv[j][i] = Megaphone::ft_toupper(argv[j][i]);
        std::cout << argv[j][i];
        i++;
      }
      j++;
    }
  }

  std::cout << std::endl;
}
