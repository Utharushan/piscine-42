/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:00:06 by tuthayak          #+#    #+#             */
/*   Updated: 2024/07/06 14:00:15 by tuthayak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_number(int a, int b)
{
	if (a > 9)
	{
		ft_putchar((a / 10) + 48);
		ft_putchar((a % 10) + 48);
	}
	else
	{
		ft_putchar('0');
		ft_putchar(a + 48);
	}
	ft_putchar(' ');
	if (b > 9)
	{
		ft_putchar((b / 10) + 48);
		ft_putchar((b % 10) + 48);
	}
	else
	{
		ft_putchar('0');
		ft_putchar(b + 48);
	}
	write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a < 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_print_number(a, b);
			b++;
		}
		a++;
	}
	write(1, "98", 2);
	write(1, " ", 1);
	write(1, "99", 2);
}
/*
int	main(void)
{
	ft_print_comb2();
}
*/