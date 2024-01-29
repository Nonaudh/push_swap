#include "push_swap.h"

void	error(p_s *data)
{
	free_data(data);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	free_data(p_s *data)
{
	if (data->tab_to_free)
		free_the_tab(data->tab, (data->a.size));
	free(data->a.values);
	free(data->b.values);
}

void	free_the_tab(char **tab, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}