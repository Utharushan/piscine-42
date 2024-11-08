/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:13:20 by tuthayak          #+#    #+#             */
/*   Updated: 2024/07/01 11:13:22 by tuthayak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
char	*ft_strlowcase(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (64 < str[i] && str[i] < 91)
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	char	word[42] = "ABdda4654CDEFG@#$!@!$HIJKLMNOPQRSTUVWXYZ";
	int	i = 0;
	char    *result;

	result = ft_strlowcase(&word[0]);
	while (result[i] != '\0')
	{
		printf("%c", result[i]);
		i++;
	}
}
*/