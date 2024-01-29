#include "push_swap.h"

void	check_duplicate(p_s *data, int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (i != j && tab[i] == tab[j])
			{
				free(tab);
				error(data);
			}
			j++;
		}
	i++;
	}
}

void	check_valid_arg(p_s *data, char *arg, int *tab)
{
	int		i;
	long	nb;

	i = 0;
	nb = 0;
	while (arg[i] <= 32)
		i++;	
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
		{
			free(tab);
			error(data);
		}
		i++;
	}
	nb = ft_atol(arg);
	if (nb < INT_MIN || nb > INT_MAX)
		error(data);
}