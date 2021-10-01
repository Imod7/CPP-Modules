/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <dsaripap@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/01 18:06:49 by dsaripap      #+#    #+#                 */
/*   Updated: 2021/10/01 18:20:27 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int		ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}

int main(int argc, char **argv)
{
	int j;

	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}

	j = 1;
	while (j < argc) {
		int i;

		i = 0;
		while (argv[j][i] != 0) {
			argv[j][i] = ft_toupper(argv[j][i]);
			std::cout << argv[j][i];
			i++;
		}
		j++;
	}
	
	std::cout << std::endl;
	return 0;

}