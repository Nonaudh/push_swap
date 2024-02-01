#include "../../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	data;

	if (argc == 2)
	{
		argc = count_arg(argv[1], ' ');
		if (!argc)
			exit(EXIT_FAILURE);
		data.tab = ft_split(argv[1], ' ');
		if (!data.tab)
			exit(EXIT_FAILURE);
		data.tab_to_free = true;
		init_data(&data, argc, data.tab);
		sort(&data);
		free_data(&data);
	}
	else if (argc > 2)
	{
		argc--;
		argv++;
		data.tab_to_free = false;
		init_data(&data, argc, argv);
		sort(&data);
		free_data(&data);
	}
	exit(EXIT_SUCCESS);
}
