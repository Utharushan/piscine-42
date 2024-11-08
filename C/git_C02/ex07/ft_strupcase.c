/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:02:12 by tuthayak          #+#    #+#             */
/*   Updated: 2024/07/01 11:02:14 by tuthayak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
char	*ft_strupcase(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (96 < str[i] && str[i] < 123)
		{
			str[i] -= 32;
		}
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	char	word[42] = "abDDA4654cdefg@#$!@!$hijklmnopqrstuvwxyz";
	int	i = 0;
	char    *result;

	result = ft_strupcase(&word[0]);
	while (result[i] != '\0')
	{
		printf("%c", result[i]);
		i++;
	}
}
*/