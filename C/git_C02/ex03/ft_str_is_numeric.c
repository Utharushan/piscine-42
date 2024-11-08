/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:31:56 by tuthayak          #+#    #+#             */
/*   Updated: 2024/07/01 10:31:57 by tuthayak         ###   ########.fr       */
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

int	ft_str_is_numeric(char *str)
{
	unsigned int	i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (1);
	while (str[i] != '\0')
	{
		if (!(47 < str[i] && str[i] < 58))
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
	char	word[25] = "0123456789";
	int	value;

	value = ft_str_is_numeric(&word[0]);
	printf("%d", value);
}
*/