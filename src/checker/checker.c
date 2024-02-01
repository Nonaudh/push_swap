#include "../../inc/checker.h"

void	check_operation(void)
{
	// to do
}

void	execute_operation(t_ps *data, char *op)
{
	if (op[0] == 's' && op[1] == 'a' && op[2] == '\n')
		swap(&data->a);
	if (op[0] == 's' && op[1] == 'b' && op[2] == '\n')
		swap(&data->b);
	if (op[0] == 's' && op[1] == 's' && op[2] == '\n')
	{
		swap(&data->a);
		swap(&data->b);
	}
	if (op[0] == 'p' && op[1] == 'a' && op[2] == '\n')
		push(&data->b, &data->a);
	if (op[0] == 'p' && op[1] == 'b' && op[2] == '\n')
		push(&data->a, &data->b);
	if (op[0] == 'r' && op[1] == 'a' && op[2] == '\n')
		rotate(&data->a);
	if (op[0] == 'r' && op[1] == 'b' && op[2] == '\n')
		rotate(&data->b);
	if (op[0] == 'r' && op[1] == 'r' && op[2] == '\n')
	{
		rotate(&data->a);
		rotate(&data->b);
	}
	if (op[0] == 'r' && op[1] == 'r' && op[2] == 'a' && op[3] == '\n')
		reverse_rotate(&data->a);
	if (op[0] == 'r' && op[1] == 'r' && op[2] == 'b' && op[3] == '\n')
		reverse_rotate(&data->b);
	if (op[0] == 'r' && op[1] == 'r' && op[2] == 'r' && op[3] == '\n')
	{
		reverse_rotate(&data->a);
		reverse_rotate(&data->b);
	}
}

void    checker(t_ps *data)
{
	char	*op;

	op = get_next_line(0);
	while (op && op[0] != '\n')
	{
		execute_operation(data, op);
		free (op);
		op = get_next_line(0);
	}
	free (op);
	if(is_stack_sorted(&data->a) && stack_empty(&data->b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

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
		checker(&data);
		free_data(&data);
	}
	else if (argc > 2)
	{
		argc--;
		argv++;
		data.tab_to_free = false;
		init_data(&data, argc, argv);
		checker(&data);
		free_data(&data);
	}
	exit(EXIT_SUCCESS);
}