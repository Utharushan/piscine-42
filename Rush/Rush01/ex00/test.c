/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:24:00 by mabaran           #+#    #+#             */
/*   Updated: 2024/07/06 21:46:35 by mabaran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	test_f(char **grid, char *to_find, int line, int column)
{//test une colonne en partant du principe que les 0 ont la valeur qui nous arrange
	int		testc;
	int		nb;
	int		add;

	nb = 1;
	testc = 0;
	add = 1;
	while (testc + add < line)
	{
		if (grid[line][testc] - grid[line][testc + add] < 0)
		{
			nb++;
			testc += add;
			add = 1;
		}
		else
			add++;
	}
	if (to_find[column] - nb >= '0' && to_find[column] <= '4' - line - 1)
		return (42);
	else
		return (0);
}

int	test_t(char **grid, char *to_find, int line, int column)
{//same pour la ligne de droite
	int		testl;
	int		nb;
	int		add;

	nb = 1;
	testl = 0;
	add = 1;
	while (testl + add < line)
	{
		if (grid[testl][column] - grid[testl + add][column] < 0)
		{
			nb++;
			testl += add;
			add = 1;
		}
		else
			add++;
	}
	if (to_find[line + 8] - nb >= '0' && to_find[line + 8] - nb <= '4' - line - 1)
		return (test_f(grid, to_find, line, column));
	else
		return (0);
}

int	test_s(char **grid, char *to_find, int line, int column)
{//test s'il n y a pas deux fois la meme valeur sur une ligne ou colonne
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < column)
	{
		if (grid[line][column] == grid[line][j])
			return (0);
		j++;
	}
	while (i < line)
	{
		if (grid[line][column] == grid[i][column])
			return (0);
		i++;
	}
	return (test_t(grid, to_find, line, column));
}

int	test(char **grid, char *to_find, int line, int column)
{//test les valeurs remarquables et renvoie directe la bonne hauteur si c'est le cas
	if (to_find[column] == '4')
		return (column + 1);
	if (to_find[column + 4] == '4')
		return (4 - column);
	if (to_find[line + 8] == '4')
		return (line + 1);
	if (to_find[line + 12] == '4')
		return (4 - line);
	return (test_s(grid, to_find, line, column));
}
