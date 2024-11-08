/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:11:13 by mabaran           #+#    #+#             */
/*   Updated: 2024/07/06 21:53:06 by mabaran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	test_final_fi(char **grid, char *to_find, int line, int column)
{//same pour la colonne en bas
	int		testc;
	int		nb;
	int		add;

	nb = 1;
	testc = 3;
	add = 1;
	while (testc - add >= 0)
	{
		if (grid[line][testc] - grid[line][testc - add] < 0)
		{
			nb++;
			testc -= add;
			add = 1;
		}
		else
			add++;
	}
	if (to_find[column + 4] - nb == '0')
		return (4);
	else
		return (0);
}

int	test_final_fo(char **grid, char *to_find, int line, int column)
{//same pour la ligne de droite
	int		testl;
	int		nb;
	int		add;

	nb = 1;
	testl = 4;
	add = 1;
	while (testl - add >= 0)
	{
		if (grid[testl][column] - grid[testl - add][column] < 0)
		{
			nb++;
			testl -= add;
			add = 1;
		}
		else
			add++;
	}
	if (to_find[line + 12] - 48 == nb)
		return (test_final_fi(grid, to_find, line, column));
	else
		return (0);
}

int	test_final_t(char **grid, char *to_find, int line, int column)
{//same pour la colonne du haut
	int		testc;
	int		nb;
	int		add;

	nb = 1;
	testc = 0;
	add = 1;
	while (testc + add < 4)
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
	if (to_find[column] - nb >= '0')
		return (test_final_fo(grid, to_find, line, column));
	else
		return (0);
}

int	test_final_s(char **grid, char *to_find, int line, int column)
{//test pour la valeurs de gauche si la ligne est bonne
	int		testl;
	int		nb;
	int		add;

	nb = 1;
	testl = 0;
	add = 1;
	while (testl + add < 4)
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
	if (to_find[line + 8] - nb == '0')
		return (test_final_t(grid, to_find, line, column));
	else
		return (0);
}


int	final_test(char **grid, char *to_find, int line, int column)
{
	write(1, "q", 1);
	while (line <= 3)//test pour chaque valeur d'une diagonale si c est bon
	{
		if (test_final_s(grid, to_find, line, column) == 0)
			return (0);
		line++;
		column++;
	}
	return (1);
}
