/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 09:57:12 by tuthayak          #+#    #+#             */
/*   Updated: 2024/07/01 09:57:13 by tuthayak         ###   ########.fr       */
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

int	ft_str_is_alpha(char *str)
{
	unsigned int	i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (1);
	while (str[i] != '\0')
	{
		if (!(64 < str[i] && str[i] < 91) && !(96 < str[i] && str[i] < 123))
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
	char	word[25] = "sfadfaFtyTYDTYuyf";
	int	value;

	value = ft_str_is_alpha(&word[0]);
	printf("%d", value);
}
*/