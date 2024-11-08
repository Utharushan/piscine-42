/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:23:44 by tuthayak          #+#    #+#             */
/*   Updated: 2024/07/02 10:23:45 by tuthayak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	contains_error(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	if (ft_strlen(&base[0]) <= 1)
		return (1);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] < 32 || base[i] > 126)
			return (1);
		while (base[j])
		{
			if (base[j] == base[i])
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len_base;
	long	nb;

	len_base = 0;
	nb = nbr;
	if (!(contains_error(base)))
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb *= -1;
		}
		len_base = ft_strlen(base);
		if (nb < len_base)
			ft_putchar(base[nb]);
		if (nb >= len_base)
		{
			ft_putnbr_base(nb / len_base, base);
			ft_putnbr_base(nb % len_base, base);
		}
	}
}
/*
int		main(void)
{
	write(1, "42:", 3);
	ft_putnbr_base(42, "0123456789");
	write(1, "\n2a:", 4);
	ft_putnbr_base(42, "0123456789abcdef");
	write(1, "\n-2a:", 5);
	ft_putnbr_base(-42, "0123456789abcdef");
	write(1, "\n80:", 4);
	ft_putnbr_base(128, "0123456789abcdef");
	write(1, "\nvn:", 4);
	ft_putnbr_base(42, "poneyvif");
	write(1, "\n101010:", 8);
	ft_putnbr_base(42, "01");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "\t0123456789abcdef");
}

#include <stdlib.h>
int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_putnbr_base(atoi(argv[1]), argv[2]);
	}
}
*/