/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 12:30:21 by mabaran           #+#    #+#             */
/*   Updated: 2024/07/06 21:48:59 by mabaran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	test(char **grid, char *to_find, int line, int column);

int	final_test(char **grid, char *to_find, int line, int column);

int backtracking(char **grid, char *to_solve, int line, int column);

void    clear(char **grid, int line, int column);

int	backtracking(char **grid, char *to_solve, int line, int column)
{
	char	size;//taille de la boite a placer
	int		pin;//permet de savoir si la solution est trouve
	int		i;//va prendre la valeur du retour de test pour limiter les boucles

	pin = 0;
	size = '1';
	write(1, "g", 1);
	while (size <= '4' && pin == 0)
	{
		write(1, "a", 1);
		//write(1, "a", 1);
		clear(grid, line, column);//remet a zero les valeurs des branches mortes
		i = test(grid, to_solve, line, column);
		if (i > 0)
		{
			if (i != 42)//42 c'est la valeur renvoye dans les cas normaux
			 	size = i + 48;
			grid[line][column] = size;//place la valeur valide dans le plateau
			if (line == 3 && column == 3 && final_test(grid, to_solve, 0, 0) != 0)
				return (1);//ca permet de dire qu'une solution est trouve
			if (column == 3)
			{
				line++;
				pin = backtracking(grid, to_solve, line, 0);
			}
			else
			{
				column++;
				pin = backtracking(grid, to_solve, line, column);//again
			}
		}
		size++;//va tester avec la valeur de size d apres
	}
	return (pin);//si c est 0 ca veut dire que la branche est morte si c est 1 qu une soluce est trouve
}

int	main(int argc, char **argv)
{
	char	**grid;
	int		i;
	int		j;

	i = 0;
	j = 0;
	(void)argc;
	grid = (char **)malloc(4 * sizeof(char *));//creer une matrice 4 4
	while (i < 4)//remplit la matrice precedemment creer du char 0
	{
		grid[i] = (char *)malloc(4 * sizeof(char));
		while (j < 4)
		{
			grid[i][j] = '0';
			j++;
		}
		i++;
		j = 0;
	}
	printf("%d", backtracking(grid, argv[1], 0, 0));
}