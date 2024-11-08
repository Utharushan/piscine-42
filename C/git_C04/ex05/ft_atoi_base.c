/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:22:49 by tuthayak          #+#    #+#             */
/*   Updated: 2024/07/11 09:22:50 by tuthayak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
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

int	char_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	sub_ft_atoi(char *str, char *base, int i, int count_sign_moins)
{
	int	atoi;
	int	pos;

	atoi = 0;
	if (count_sign_moins % 2 == 0)
		count_sign_moins = 1;
	else
		count_sign_moins = -1;
	while (char_in_base(str[i], base) != -1)
	{
		pos = char_in_base(str[i], base);
		atoi = atoi * ft_strlen(&base[0]) + pos;
		i++;
	}
	return (count_sign_moins * atoi);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	count_sign_moins;
	int	count_sign;

	i = 0;
	count_sign_moins = 0;
	count_sign = 0;
	if (contains_error(base))
		return (0);
	while (char_in_base(str[i], base) == -1)
	{
		if (str[i] == '\0' || (96 < str[i] && str[i] < 123)
			|| (64 < str[i] && str[i] < 91)
			|| (str[i] != '-' && str[i] != '+' && count_sign != 0))
			return (0);
		else if (str[i] == '-')
		{
			count_sign_moins += 1;
			count_sign += 1;
		}
		else if (str[i] == '+')
			count_sign += 1;
		i++;
	}
	return (sub_ft_atoi(str, base, i, count_sign_moins));
}
/*
#include <stdio.h>

int	main(void)
{
	printf("42:%d\n", ft_atoi_base("2a", "0123456789abcdef"));
	printf("-42:%d\n", ft_atoi_base("   --------+-2a", "0123456789abcdef"));
	printf("42:%d\n", ft_atoi_base("   -+-2a", "0123456789abcdef"));
	printf("0:%d\n", ft_atoi_base("   --------+- 2a", "0123456789abcdef"));
	printf("0:%d\n", ft_atoi_base("   --------+-z", "0123456789abcdef"));
	printf("42:%d\n", ft_atoi_base("vn", "poneyvif"));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", "0"));
	printf("2147483647:%d\n", ft_atoi_base("-+-+-+-+++2147483647", "0123456789"));
	printf("-2147483648:%d\n", ft_atoi_base("d-+-+-+-+-+2147483648", "0123456789"));
}

int	main(int ac, char **av)
{
	if (ac == 3)
		printf("%d\n", ft_atoi_base(av[1], av[2]));
}
*/