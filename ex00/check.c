/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtarasov <dtarasov@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 19:16:56 by dtarasov          #+#    #+#             */
/*   Updated: 2026/03/15 19:17:08 by dtarasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	visible_row_left(int matr[4][4], int r_num);
int	visible_row_right(int matr[4][4], int r_num);
int	visible_col_top(int matr[4][4], int c_num);
int	visible_col_bottom(int matr[4][4], int c_num);

int	digit_is_used_in_row(int digit_value, int r_num, int matr[4][4])
{
	int	counter;

	counter = 0;
	while (counter < 4)
	{
		if (matr[r_num][counter] == digit_value)
			return (1);
		counter++;
	}
	return (0);
}

int	digit_is_used_in_column(int digit_value, int c_num, int matr[4][4])
{
	int	counter;

	counter = 0;
	while (counter < 4)
	{
		if (matr[counter][c_num] == digit_value)
			return (1);
		counter++;
	}
	return (0);
}

int	visible(int arr_val[4])
{
	int	max;
	int	visible_count;
	int	counter;

	max = 0;
	visible_count = 0;
	counter = 0;
	while (counter < 4)
	{
		if (arr_val[counter] > max)
		{
			max = arr_val[counter];
			visible_count++;
		}
		counter++;
	}
	return (visible_count);
}

int	check_current_val(int matr[4][4], int ent_val[16], int r_num, int c_num)
{
	if (c_num == 3)
	{
		if (visible_row_left(matr, r_num) != ent_val[8 + r_num])
			return (0);
		if (visible_row_right(matr, r_num) != ent_val[12 + r_num])
			return (0);
	}
	if (r_num == 3)
	{
		if (visible_col_top(matr, c_num) != ent_val[c_num])
			return (0);
		if (visible_col_bottom(matr, c_num) != ent_val[4 + c_num])
			return (0);
	}
	return (1);
}

int	check_matr(int matr[4][4], int ent_val[16])
{
	int	counter;

	counter = 0;
	while (counter < 4)
	{
		if (visible_col_top(matr, counter) != ent_val[counter])
			return (0);
		if (visible_col_bottom(matr, counter) != ent_val[4 + counter])
			return (0);
		if (visible_row_left(matr, counter) != ent_val[8 + counter])
			return (0);
		if (visible_row_right(matr, counter) != ent_val[12 + counter])
			return (0);
		counter++;
	}
	return (1);
}
