/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:22:22 by tuthayak          #+#    #+#             */
/*   Updated: 2024/07/06 16:54:51 by tuthayak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
char	*input_array(char *input)
{
	char	*input_array;
	char	c[16];
	int		i;
	int		j;

	input_array = &c[0];
	i = 0;
	j = 0;
	while (input[j])
	{
		if (j % 2 == 0)
		{
			input_array[i] = input[j];
			i++;
		}
		j++;
	}
	return (input_array);
}
/*
int main(int argc, char **argv)
{
	char *array;
	int i;
	(void)argc;

	i = 0;
	array = input_array(argv[1]);
	while (array[i])
	{
		printf("%c", array[i]);
		i++;
	}
	printf("\n");
}
*/
