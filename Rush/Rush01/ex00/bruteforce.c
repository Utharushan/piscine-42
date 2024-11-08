char	**fill_sequence_column(char **grid, int i)
{
	char a;

	a = '0';
	if (i < 4)
	{
		while (a < '4')
		{
			grid[a - 48][i] = a - 47;
			a++;
		}
	}
	else
		while 
}

char	**prefill(char **grid, char *to_solve, int row, int column)
{
	int	i;

	while (to_solve[i])
	{
		if (to_solve[i] == 4)
		{
			if (i < 8)
				fill_sequence_column(grid, i)
			else 
				fill_sequence_row()
		}
	}
}