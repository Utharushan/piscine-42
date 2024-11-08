/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hundreds.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:36:41 by tuthayak          #+#    #+#             */
/*   Updated: 2024/07/14 15:36:42 by tuthayak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_DictEntry
{
	char				*number;
	char				*word;
	struct s_DictEntry	*next;
}	t_DictEntry;

void		ft_putstr(char *str);
void		ft_puterror(char *str);
t_DictEntry	*parse_dict(char *filename);
char		*find_word(t_DictEntry *dict, char *number);
int			ft_strcmp(char *s1, char *s2);
int			ft_strlen(char *str);
char		*ft_strcat(char *dest, char *src);

void	print_solo(t_DictEntry *dict, char *units, char *number, char *res)
{
	units[0] = number[0];
	if (units[0] != '0')
	{
		res = find_word(dict, units);
		if (res)
			ft_putstr(res);
		else
			ft_puterror("Dict Error\n");
	}
	else
		ft_putstr(find_word(dict, "0"));
	return ;
}

void	print_number(t_DictEntry *dict, char *number, char *res)
{
	res = find_word(dict, number);
	if (res)
		ft_putstr(res);
	else
		ft_puterror("Dict Error\n");
}

int	sub_print_doubles(t_DictEntry *dict, char *units, char *number, char *res)
{
	if (ft_strcmp(number, "00") == 0)
		return (1);
	if (ft_strlen(number) == 1)
	{
		print_solo(dict, units, number, res);
		return (1);
	}
	if (number[0] == '1')
	{
		print_number(dict, number, res);
		return (1);
	}
	return (0);
}

void	print_doubles(char	*number, char *dict_file)
{
	char		*units;
	char		*tens;
	char		*res;
	t_DictEntry	*dict;

	tens = malloc(2 * sizeof(char));
	units = malloc(sizeof(char));
	dict = parse_dict(dict_file);
	res = NULL;
	if (sub_print_doubles(dict, units, number, res))
		return ;
	tens[0] = number[0];
	tens[1] = '0';
	units[0] = number[1];
	if (tens[0] != '0')
	{
		print_number(dict, tens, res);
		if (units[0] != '0')
			ft_putstr(" ");
	}
	if (units[0] != '0')
		print_number(dict, units, res);
	free(tens);
	free(units);
}

void	print_hundreds(char *number, char *dict_file)
{
	char		*hundreds;
	char		*res_hundreds;
	int			len;
	t_DictEntry	*dict;

	dict = parse_dict(dict_file);
	len = ft_strlen(number);
	if (len < 3)
		return (print_doubles(number, dict_file));
	hundreds = malloc(sizeof(char));
	hundreds[0] = number[0];
	if (hundreds[0] != '0')
	{
		res_hundreds = find_word(dict, hundreds);
		if (res_hundreds)
			ft_putstr(res_hundreds);
		else
			ft_puterror("Dict Error\n");
		ft_putstr(" ");
		free(hundreds);
		ft_putstr(find_word(dict, "100"));
		if (ft_strcmp(&number[1], "00") != 0)
			ft_putstr(" ");
	}
	return (print_doubles(&number[1], dict_file));
}
