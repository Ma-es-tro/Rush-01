/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtarasov <dtarasov@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 19:17:18 by dtarasov          #+#    #+#             */
/*   Updated: 2026/03/15 19:17:25 by dtarasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	visible(int arr_val[4]);

int	visible_row_left(int matr[4][4], int r_num)
{
	int	row_val_arr[4];
	int	counter;

	counter = 0;
	while (counter < 4)
	{
		row_val_arr[counter] = matr[r_num][counter];
		counter++;
	}
	return (visible(row_val_arr));
}

int	visible_row_right(int matr[4][4], int r_num)
{
	int	row_val_arr[4];
	int	counter;

	counter = 0;
	while (counter < 4)
	{
		row_val_arr[counter] = matr[r_num][3 - counter];
		counter++;
	}
	return (visible(row_val_arr));
}

int	visible_col_top(int matr[4][4], int c_num)
{
	int	col_val_arr[4];
	int	counter;

	counter = 0;
	while (counter < 4)
	{
		col_val_arr[counter] = matr[counter][c_num];
		counter++;
	}
	return (visible(col_val_arr));
}

int	visible_col_bottom(int matr[4][4], int c_num)
{
	int	col_val_arr[4];
	int	counter;

	counter = 0;
	while (counter < 4)
	{
		col_val_arr[counter] = matr[3 - counter][c_num];
		counter++;
	}
	return (visible(col_val_arr));
}
