/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:18:46 by tuthayak          #+#    #+#             */
/*   Updated: 2024/07/01 11:18:48 by tuthayak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <unistd.h>
*/
int	is_alphanumeric(char c)
{
	if ((64 < c && c < 91) || (96 < c && c < 123) || (47 < c && c < 58))
		return (1);
	return (0);
}

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

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	ft_strlowcase(str);
	if (96 < str[0] && str[0] < 123)
		str[0] -= 32;
	i++;
	while (str[i])
	{
		if (is_alphanumeric(str[i - 1]))
			i++;
		else if (96 < str[i] && str[i] < 123)
		{
			str[i] -= 32;
			i++;
		}
		else
			i++;
	}
	return (str);
}
/*
void	ft_putstr(char *str)
{
	int	l;

	l = 0;
	while (str[l])
	{
		l++;
	}
	write(1, str, l);
}

int	main(void)
{
	char	c[] = "salut, coMMent tu vAs ? 42mOts quArAnTe-dEux; cinQuante+et+un";

	ft_putstr("Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un:");
	ft_putstr(ft_strcapitalize(c));
	ft_putstr(":");
	ft_putstr(c);
}
*/
