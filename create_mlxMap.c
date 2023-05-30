/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mlxMap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:33:21 by gansard           #+#    #+#             */
/*   Updated: 2023/02/21 16:54:50 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_display_cells_util(void *cell, int y, int x, t_data *data)
{
	mlx_put_image_to_window(
		data->mlx_ptr, data->win_ptr, cell, y * 64, x * 64);
}

void	ft_display_cells(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == 'P')
				ft_display_cells_util(data->player, y, x, data);
			else if (data->map[x][y] == '0')
				ft_display_cells_util(data->field, y, x, data);
			else if (data->map[x][y] == '1')
				ft_display_cells_util(data->wall, y, x, data);
			else if (data->map[x][y] == 'C')
				ft_display_cells_util(data->c, y, x, data);
			else
				ft_display_cells_util(data->exit, y, x, data);
			y++;
		}
		x++;
	}
}

int	handle_keypress(int keysym, t_data *data)
{
	static int	i = 0;

	if (keysym == XK_Escape)
		mlx_loop_end(data->mlx_ptr);
	else if (keysym == XK_d)
		i += move_right(data, i);
	else if (keysym == XK_s)
		i += move_down(data, i);
	else if (keysym == XK_a)
		i += move_left(data, i);
	else if (keysym == XK_w)
		i += move_up(data, i);
	ft_display_cells(data);
	return (0);
}

int	ft_create_img(t_data *data)
{
	int		s;

	data->player = NULL;
	data->field = NULL;
	data->wall = NULL;
	data->c = NULL;
	data->exit = NULL;
	data->player = mlx_xpm_file_to_image(data->mlx_ptr, "Assets/j.xpm", &s, &s);
	if (!data->player)
		return (0);
	data->field = mlx_xpm_file_to_image(data->mlx_ptr, "Assets/v.xpm", &s, &s);
	if (!data->field)
		return (0);
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr, "Assets/m.xpm", &s, &s);
	if (!data->wall)
		return (0);
	data->c = mlx_xpm_file_to_image(data->mlx_ptr, "Assets/b.xpm", &s, &s);
	if (!data->c)
		return (0);
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr, "Assets/w.xpm", &s, &s);
	if (!data->exit)
		return (0);
	return (1);
	if (!data->exit)
		return (0);
}

int	ft_create_mlxmap(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (0);
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			ft_strlen(data->map[0]) * 64,
			ft__height(data->map) * 64, "So_long");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (0);
	}
	if (ft_create_img(data) == 0)
	{
		ft_printf("Error\nProblemme de lecture sur une image.\n");
		return (ft_free_img(data), 0);
	}
	ft_display_cells(data);
	mlx_key_hook(data->win_ptr, &handle_keypress, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, mlx_loop_end, data->mlx_ptr);
	mlx_loop(data->mlx_ptr);
	ft_free_img(data);
	return (1);
}
