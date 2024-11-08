/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 20:06:22 by tuthayak          #+#    #+#             */
/*   Updated: 2024/07/01 20:06:24 by tuthayak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
int	sub_ft_atoi(char *str, int i, int count_sign_moins)
{
	int	atoi;

	atoi = 0;
	if (count_sign_moins % 2 == 0)
		count_sign_moins = 1;
	else
		count_sign_moins = -1;
	while (47 < str[i] && str[i] < 58)
	{
		atoi = atoi * 10 + (str[i] - '0');
		i++;
	}
	return (count_sign_moins * atoi);
}

int	ft_atoi(char *str)
{
	int	i;
	int	count_sign_moins;
	int	count_sign;
	int	atoi;

	i = 0;
	count_sign_moins = 0;
	count_sign = 0;
	while (!(47 < str[i] && str[i] < 58))
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
	atoi = sub_ft_atoi(str, i, count_sign_moins);
	return (atoi);
}
/*
#include <stdio.h>
int main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	printf(">%d.\n", ft_atoi(av[1]));
}
*/
/*
int	main(void)
{
	printf("42:%d\n", ft_atoi("  \n  42t4457"));
	printf("-42:%d\n", ft_atoi(" -d-+-42sfs:f545"));
	printf("0:%d\n", ft_atoi("\0 1337"));
	printf("0:%d\n", ft_atoi("-0"));
	printf("0:%d\n", ft_atoi(" - 1 3 2 5 6 3 2 1 6 7"));
	printf("-1325632167:%d\n", ft_atoi("-1325632167"));
	printf("-100:%d\n", ft_atoi("-100"));
	printf("min:%d\n", ft_atoi("\t---+2147483648"));
	printf("max:%d\n", ft_atoi("\v2147483647"));
	printf("-1234:%d\n", ft_atoi(" ---+--+1234ab567"));
}
*/