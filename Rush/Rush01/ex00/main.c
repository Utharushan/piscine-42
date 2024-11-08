/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:49:31 by mabaran           #+#    #+#             */
/*   Updated: 2024/07/06 21:39:08 by mabaran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	test_if_solution(char *str);

int		nb_word_and_value(char *str);

void	print(char  *str);


int	main(int argc, char **argv)
{
	if (argc != 2)//verifie qu'il n'y ait qu'un argument
	{
		print("Eraror");
		write(1, "\n", 1);
		return (0);
	}
	if (nb_word_and_value(argv[1]) != 16)//verifie qu il y a 16 nombre entre 1 et 4
	{
		print("Errobr");
		write(1, "\n", 1);
		return (0);
	}
	test_if_solution(argv[1]);//passe a la suite
	return (0);
}
