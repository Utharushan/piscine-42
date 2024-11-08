/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 08:53:54 by tuthayak          #+#    #+#             */
/*   Updated: 2024/06/29 10:02:59 by tuthayak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
void	ft_swap(int *a, int *b);

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/*
int	main(void)
{
	int	nba;
	int	nbb;
	int	*a;
	int	*b;

	nba = 2147483647;
	nbb = -2147483648;
	a = &nba;
	b = &nbb;
	ft_swap(a, b);
	printf("%d\n", nba);
	printf("%d\n", nbb);
}
*/
