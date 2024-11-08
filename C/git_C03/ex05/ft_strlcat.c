/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:13:37 by tuthayak          #+#    #+#             */
/*   Updated: 2024/07/03 09:13:39 by tuthayak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	init_size_dest;
	unsigned int	init_size_src;

	i = 0;
	init_size_dest = ft_strlen(dest);
	init_size_src = ft_strlen(src);
	if (size <= init_size_dest)
		return (size + init_size_src);
	while (src[i] != '\0' && i < size - init_size_dest - 1)
	{
		dest[init_size_dest + i] = src[i];
		i++;
	}
	dest[init_size_dest + i] = '\0';
	return (init_size_src + init_size_dest);
}
