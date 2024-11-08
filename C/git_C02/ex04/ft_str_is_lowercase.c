/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:40:06 by tuthayak          #+#    #+#             */
/*   Updated: 2024/07/01 10:40:09 by tuthayak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_str_is_lowercase(char *str)
{
	unsigned int	i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (1);
	while (str[i] != '\0')
	{
		if (!(96 < str[i] && str[i] < 123))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
/*
int	main(void)
{
	char	word[42] = "abcdefghijklmnopqrstuvwxyz";
	int	value;

	value = ft_str_is_lowercase(&word[0]);
	printf("%d", value);
}
*/