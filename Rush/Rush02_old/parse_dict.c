#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	ft_strlen(char *src);
char	*ft_strdup(char *src);
char *crop_space(char *str);
char *read_line(int fd);

typedef struct
{
	char	*number;
	char	*word;
	struct	DictEntry	*next;
} DictEntry;

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_puterror(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

char	*ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

DictEntry *parse_dict(char *filename)
{
	int fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_puterror("Dict Error\n");
		return (NULL);
	}

	DictEntry *head;
	DictEntry *tail;

	head = NULL;
	tail = NULL;
	char	*line;
	while ((line = read_line(fd)) != NULL)
	{
		char	*colon;
		char	*number;
		char	*word;
		DictEntry *entry;

		colon = ft_strchr(line, ':');
		if (!colon)
		{
			free(line);
			continue ;
		}
		*colon = '\0';
		number = crop_space(line);
		word = crop_space(colon + 1);
		entry = (DictEntry *)malloc(sizeof(DictEntry));
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
	}
	close(fd);
	return (head);
}

int	ft_strcmp(char *s1, char *s2)
{
		int	i;

		i = 0;
		while (s1[i] && s1[i] == s2[i])
				i++;
		return (s1[i] - s2[i]);
}


char	*find_word(DictEntry *dict, char *number)
{
	while (dict)
	{
		if (ft_strcmp(dict->number, number) == 0)
			return dict->word;
		dict = dict->next;
	}
	return (NULL);
}

void free_dict(DictEntry *dict)
{
	while (dict)
	{
		DictEntry *temp;
		
		temp = dict;
		dict = dict->next;
		free(temp->number);
		free(temp->word);
		free(temp);
	}
}

int	main(int argc, char **argv)
{
	char *dict_file;
	char *number;

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

	DictEntry *dict;
	
	dict = parse_dict(dict_file);

	char *result;

	result = find_word(dict, number);
	if (result)
	{
		ft_putstr(result);
		ft_putstr("\n");
	}
	else
		ft_puterror("Dict Error\n");
	free_dict(dict);
	return (0);
}
