/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtarasov <dtarasov@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 19:18:20 by dtarasov          #+#    #+#             */
/*   Updated: 2026/03/15 19:18:26 by dtarasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			digit_is_used_in_row(int digit_value, int r_num, int matr[4][4]);
int			digit_is_used_in_column(int digit_value, int c_num, int matr[4][4]);
int			check_current_val(int matr[4][4], int ent_val[16], int r_num,
				int c_num);
int			check_matr(int matr[4][4], int ent_val[16]);

static void	init_matr(int matr[4][4])
{
	int	r;
	int	c;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			matr[r][c] = 0;
			c++;
		}
		r++;
	}
}

static int	backtrack(int matr[4][4], int ent_val[16], int pos)
{
	int	r_num;
	int	c_num;
	int	val;

	if (pos == 16)
		return (check_matr(matr, ent_val));
	r_num = pos / 4;
	c_num = pos % 4;
	val = 1;
	while (val <= 4)
	{
		if (!digit_is_used_in_row(val, r_num, matr)
			&& !digit_is_used_in_column(val, c_num, matr))
		{
			matr[r_num][c_num] = val;
			if (check_current_val(matr, ent_val, r_num, c_num))
			{
				if (backtrack(matr, ent_val, pos + 1))
					return (1);
			}
			matr[r_num][c_num] = 0;
		}
		val++;
	}
	return (0);
}

int	solve(int matr[4][4], int ent_val[16])
{
	init_matr(matr);
	return (backtrack(matr, ent_val, 0));
}
