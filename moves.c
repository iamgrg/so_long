/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:05:39 by gansard           #+#    #+#             */
/*   Updated: 2023/02/20 21:50:16 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_right(t_data *data, int i)
{
	if (data->map[data->x][data->y + 1] == 'E' && data->count_c == 0)
	{
		data->map[data->x][data->y] = '0';
		ft_printf ("Moves: %d\n", ++i);
		mlx_loop_end (data->mlx_ptr);
		return (1);
	}
	if (data->map[data->x][data->y + 1] != '1'
		&& data->map[data->x][data->y + 1] != 'E')
	{
		if (data->map[data->x][data->y + 1] == 'C')
			data->count_c--;
		data->map[data->x][data->y + 1] = 'P';
		data->map[data->x][data->y] = '0';
		data->y++;
		ft_printf ("Moves: %d\n", ++i);
		return (1);
	}
	return (0);
}

int	move_down(t_data *data, int i)
{
	if (data->map[data->x + 1][data->y] == 'E' && data->count_c == 0)
	{
		data->map[data->x + 1][data->y] = '0';
		ft_printf ("Moves: %d\n", ++i);
		mlx_loop_end (data->mlx_ptr);
		return (1);
	}
	if (data->map[data->x + 1][data->y] != '1'
		&& data->map[data->x + 1][data->y] != 'E')
	{
		if (data->map[data->x + 1][data->y] == 'C')
			data->count_c--;
		data->map[data->x + 1][data->y] = 'P';
		data->map[data->x][data->y] = '0';
		data->x++;
		ft_printf ("Moves: %d\n", ++i);
		return (1);
	}
	return (0);
}

int	move_up(t_data *data, int i)
{
	if (data->map[data->x - 1][data->y] == 'E' && data->count_c == 0)
	{
		data->map[data->x - 1][data->y] = '0';
		ft_printf ("Moves: %d\n", ++i);
		mlx_loop_end (data->mlx_ptr);
		return (1);
	}
	if (data->map[data->x - 1][data->y] != '1'
		&& data->map[data->x - 1][data->y] != 'E')
	{
		if (data->map[data->x - 1][data->y] == 'C')
			data->count_c--;
		data->map[data->x - 1][data->y] = 'P';
		data->map[data->x][data->y] = '0';
		data->x--;
		ft_printf ("Moves: %d\n", ++i);
		return (1);
	}
	return (0);
}

int	move_left(t_data *data, int i)
{
	if (data->map[data->x][data->y - 1] == 'E' && data->count_c == 0)
	{
		data->map[data->x][data->y] = '0';
		ft_printf ("Moves: %d\n", ++i);
		mlx_loop_end (data->mlx_ptr);
		return (1);
	}
	if (data->map[data->x][data->y - 1] != '1'
		&& data->map[data->x][data->y - 1] != 'E')
	{
		if (data->map[data->x][data->y - 1] == 'C')
			data->count_c--;
		data->map[data->x][data->y - 1] = 'P';
		data->map[data->x][data->y] = '0';
		data->y--;
		ft_printf ("Moves: %d\n", ++i);
		return (1);
	}
	return (0);
}
