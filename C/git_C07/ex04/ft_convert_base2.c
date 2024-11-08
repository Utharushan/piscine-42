/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:46:05 by tuthayak          #+#    #+#             */
/*   Updated: 2024/07/15 11:46:07 by tuthayak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	size_dest;
	unsigned int	i;

	i = 0;
	size_dest = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[size_dest + i] = src[i];
		i++;
	}
	dest[size_dest + i] = '\0';
	return (dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*sub_ft_putnbr_base(int i, char *base, int nb_final[64], char *str)
{
	int		j;
	int		len_str;

	j = 0;
	len_str = ft_strlen(str);
	j = 0;
	while (--i >= 0)
	{
		str[len_str + j] = base[nb_final[i]];
		j++;
	}
	return (str);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	int		len_base;
	int		nb_final[64];
	long	nb;
	int		i;
	char	*str;

	len_base = 0;
	nb = nbr;
	str = malloc(sizeof(char) * 64);
	i = 0;
	if (nb < 0)
	{
		ft_strcat(str, "-");
		nb *= -1;
	}
	len_base = ft_strlen(base);
	while (nb)
	{
		nb_final[i] = nb % len_base;
		nb = nb / len_base;
		i++;
	}
	return (sub_ft_putnbr_base(i, base, nb_final, str));
}
