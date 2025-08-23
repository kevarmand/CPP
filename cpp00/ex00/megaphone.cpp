/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:19:16 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/19 13:25:41 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <cctype>


int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	for (int i = 1; i < argc; ++i)
	{
		for (char *c = argv[i]; *c; ++c)
			std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(*c)));
	}
	std::cout << "\n";
	return (0);
}