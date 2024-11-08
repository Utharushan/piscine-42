/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:51:38 by tuthayak          #+#    #+#             */
/*   Updated: 2024/07/01 10:51:40 by tuthayak         ###   ########.fr       */
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

int	ft_str_is_printable(char *str)
{
	unsigned int	i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (1);
	while (str[i] != '\0')
	{
		if (!(31 < str[i] && str[i] < 127))
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
	char	word[42] = "ƒœ€FAYG555@!#!##^&$'YDFODOA";
	int	value;

	value = ft_str_is_printable(&word[0]);
	printf("%d", value);
}
*/