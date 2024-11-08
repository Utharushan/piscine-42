/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_word_and_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:26:15 by mabaran           #+#    #+#             */
/*   Updated: 2024/07/06 21:50:09 by mabaran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	nb_word_and_value(char *str)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (!(str[i] >= '1' && str[i] <= '4') && str[i] != ' ')
			return (0);
		if (i % 2 == 0)
		{
			if (!(str[i] >= '1' && str[i] <= '4'))
				return (0);
			n++;
		}
		else if (str[i] != ' ')
			return (0);//verifie la presence de l'espace
		i++;
	}
	return (n);
}
