/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 12:13:43 by tuthayak          #+#    #+#             */
/*   Updated: 2024/06/30 12:25:10 by tuthayak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
void	ft_sort_int_tab(int *tab, int size);
void	ft_swap(int *tab, int a, int b);
int		ft_min(int *tab, int size, int start);

void	ft_swap(int *tab, int a, int b)
{
	int	temp;

	temp = tab[a];
	tab[a] = tab[b];
	tab[b] = temp;
}

int	ft_min(int *tab, int size, int start)
{
	int	i;
	int	min;
	int	ind_min;

	i = start + 1;
	min = tab[start];
	ind_min = start;
	while (i < size)
	{
		if (tab[i] < min)
		{
			min = tab[i];
			ind_min = i;
		}
		i++;
	}
	return (ind_min);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	start;
	int	ind_min;

	start = 0;
	while (start < (size - 1))
	{
		ind_min = ft_min(&tab[0], size, start);
		if (ind_min != start)
		{
			ft_swap(&tab[0], start, ind_min);
		}
		start++;
	}
}
/*
int	main(void)
{
	int	tab[10] = {8, 6, 9, 10, 4, 1, 2, 7, 5, 3};
	int	size = 10;
	int	i = 0;

	ft_sort_int_tab(&tab[0], size);
	while (i < size)
	{
		printf("%d", tab[i]);
		i++;
	}
}
*/
