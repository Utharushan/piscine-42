/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 09:36:03 by tuthayak          #+#    #+#             */
/*   Updated: 2024/06/28 10:01:03 by tuthayak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
void	ft_div_mod(int a, int b, int *div, int *mod);

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int	main(void)
{
	int	nbdiv;
	int	nbmod;
	int	*div;
	int	*mod;

	div = &nbdiv;
	mod = &nbmod;
	ft_div_mod(15, 6, div, mod);
	printf("%d\n", nbdiv);
	printf("%d\n", nbmod);
}
*/
