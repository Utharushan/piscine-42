/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:46:30 by tuthayak          #+#    #+#             */
/*   Updated: 2024/06/30 15:42:21 by tuthayak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
void	ft_rev_int_tab(int *tab, int size);

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < (size / 2))
	{
		temp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = temp;
		i++;
	}
}
/*
int	main(void)
{
	int	tab[5] = {5, 1, 4, 1, 3};
	int	size = 5;
	int	i;

	i = 0;
	ft_rev_int_tab(&tab[0], size);
	while (i < size)
	{
		printf("%d", tab[i]);
		i++;
	}
}
*/
