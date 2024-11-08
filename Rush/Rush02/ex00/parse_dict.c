/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:36:33 by tuthayak          #+#    #+#             */
/*   Updated: 2024/07/14 15:36:35 by tuthayak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int		ft_strlen(char *src);
char	*ft_strdup(char *src);
char	*crop_space(char *str);
char	*read_line(int fd);
void	print_hundreds(char	*number, char *dict_file);
char	*ft_strcat(char *dest, char *src);
void	print_doubles(char	*number, char *dict_file);
void	ft_putstr(char *str);
void	ft_puterror(char *str);
char	*ft_strchr(char *str, char c);
int		ft_strcmp(char *s1, char *s2);
void	print_solo(char *dict, char *units, char *number, char *res_units);

typedef struct s_DictEntry
{
	char				*number;
	char				*word;
	struct s_DictEntry	*next;
}	t_DictEntry;

t_DictEntry	*parse_dict(char *filename)
{
	int			fd;
	char		*line;
	t_DictEntry	*head;
	t_DictEntry	*tail;
	char		*colon;
	char		*number;
	char		*word;
	t_DictEntry	*entry;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_puterror("Dict Error\n");
		return (NULL);
	}
	head = NULL;
	tail = NULL;
	line = read_line(fd);
	while (line != NULL)
	{
		colon = ft_strchr(line, ':');
		if (!colon)
		{
			free(line);
			continue ;
		}
		*colon = '\0';
		number = crop_space(line);
		word = crop_space(colon + 1);
		entry = (t_DictEntry *)malloc(sizeof(t_DictEntry));
		if (!entry)
		{
			ft_puterror("Dict Error\n");
			return (NULL);
		}
		entry->number = ft_strdup(number);
		entry->word = ft_strdup(word);
		entry->next = NULL;
		if (!head)
			head = entry;
		else
			tail->next = entry;
		tail = entry;
		free(line);
		line = read_line(fd);
	}
	close(fd);
	return (head);
}

char	*find_word(t_DictEntry *dict, char *number)
{
	while (dict)
	{
		if (ft_strcmp(dict->number, number) == 0)
			return (dict->word);
		dict = dict->next;
	}
	return (NULL);
}

void	free_dict(t_DictEntry *dict)
{
	t_DictEntry	*temp;

	while (dict)
	{	
		temp = dict;
		dict = dict->next;
		free(temp->number);
		free(temp->word);
		free(temp);
	}
}

int	main(int argc, char **argv)
{
	char	*dict_file;
	char	*number;

	dict_file = "numbers.dict";
	number = argv[1];
	if (argc < 2 || argc > 3)
	{
		ft_puterror("Error\n");
		return (1);
	}
	if (argc == 3)
	{
		dict_file = argv[1];
		number = argv[2];
	}
	print_hundreds(number, dict_file);
	return (0);
}
