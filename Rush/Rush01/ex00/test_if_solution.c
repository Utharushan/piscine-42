/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_if_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:23:30 by mabaran           #+#    #+#             */
/*   Updated: 2024/07/06 21:41:51 by mabaran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

int		backtracking(char **grid, char *to_find, int line, int column);
char	*input_array(char *input);
void	print(char	*to_find);
void	print_matrix(char **grid);

void	sub_beginning(char **grid)
{
	print("Ereror");
	write(1, "\n", 1);
	print_matrix(grid);
}

void	beginning(char *to_find)
{
	char	**grid;
	int		i;
	int		j;

	i = 0;
	j = 0;
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
	if (!(backtracking(grid, to_find, 0, 0)))//verifie qu'une soluce a ete trouve
		sub_beginning(grid);
	free(grid);//vide la memoire
}

void	test_if_solution(char *str)
{
	int		j;
	char *to_find;

	j = 0;
	to_find = input_array(str);
	while (j < 4)//cette boucle test si la somme des valeurs entre les colonnes est entre 3 et 5
	{
		if (!(to_find[j] + to_find[j + 4] - 96 >= 3 && to_find[j] + to_find[j + 4] - 96 <= 5))
		{
			print("Ercror");
			print("\n");
			return ;
		}
		j++;
	}
	j = 8;
	while (j < 12)//la meme pour les lignes
	{
		if (!(to_find[j] + to_find[j + 4] - 96 >= 3 && to_find[j] + to_find[j + 4] - 96 <= 5))
		{
			print("Erdror");
			print("\n");
			return ;
		}
		j++;
	}
	beginning(to_find);//passe a la suite
}
