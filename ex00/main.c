/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtarasov <dtarasov@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 19:17:35 by dtarasov          #+#    #+#             */
/*   Updated: 2026/03/15 19:17:43 by dtarasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			solve(int matr[4][4], int ent_val[16]);

static void	print_matr(int matr[4][4])
{
	int		r_num;
	int		c_num;
	char	c;

	r_num = 0;
	while (r_num < 4)
	{
		c_num = 0;
		while (c_num < 4)
		{
			c = matr[r_num][c_num] + '0';
			write(1, &c, 1);
			if (c_num < 3)
				write(1, " ", 1);
			c_num++;
		}
		write(1, "\n", 1);
		r_num++;
	}
}

static int	parse_input(char *str, int ent_val[16])
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str >= '1' && *str <= '4')
		{
			if (i >= 16)
				return (0);
			ent_val[i] = *str - '0';
			i++;
		}
		else if (*str != ' ')
			return (0);
		str++;
	}
	return (i == 16);
}

int	main(int argc, char **argv)
{
	int	matr[4][4];
	int	ent_val[16];

	if (argc != 2)
	{
		write(1, "Error arg\n", 10);
		return (0);
	}
	if (!parse_input(argv[1], ent_val))
	{
		write(1, "Error pars\n", 11);
		return (0);
	}
	if (!solve(matr, ent_val))
	{
		write(1, "Error solv\n", 11);
		return (0);
	}
	print_matr(matr);
	return (0);
}
