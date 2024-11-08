/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 10:02:54 by tuthayak          #+#    #+#             */
/*   Updated: 2024/06/28 10:31:04 by tuthayak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
void	ft_ultimate_div_mod(int *a, int *b);

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp;

	temp = *a / *b;
	*b = *a % *b;
	*a = temp;
}
/*
int	main(void)
{
	int	nba;
	int	nbb;
	int	*a;
	int	*b;

	nba = 15;
	nbb = 6;
	a = &nba;
	b = &nbb;
	ft_ultimate_div_mod(a, b);
	printf("%d\n", nba);
	printf("%d\n", nbb);
}
*/
