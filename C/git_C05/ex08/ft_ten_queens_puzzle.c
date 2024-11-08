/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:58:58 by tuthayak          #+#    #+#             */
/*   Updated: 2024/07/11 10:58:59 by tuthayak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_tab(int *tab)
{
	int		i;
	char	temp;

	i = 0;
	while (i < 10)
	{
		temp = tab[i] + 48;
		write(1, &temp, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_abs(int nb)
{
	if (nb >= 0)
		return (nb);
	else
		return (-nb);
}

void	ft_recursive(int *board, int column, int *nb_sol)
{
	int	row;
	int	pos;

	row = 0;
	if (column == 10)
	{
		ft_print_tab(board);
		*nb_sol += 1;
	}
	while (row < 10)
	{
		pos = 0;
		while (pos < column)
		{
			if (board[pos] == row || column - pos == ft_abs(board[pos] - row))
				pos = column;
			pos++;
		}
		if (pos == column)
		{
			board[column] = row;
			ft_recursive(board, column + 1, nb_sol);
		}
		row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	nb_sol;

	nb_sol = 0;
	ft_recursive(board, 0, &nb_sol);
	return (nb_sol);
}
