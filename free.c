/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:04:18 by gansard           #+#    #+#             */
/*   Updated: 2023/02/21 16:54:50 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_free_data(t_data *data)
{
	if (data != NULL)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		ft_free_map(data->map);
	}
}

void	ft_free_img(t_data *data)
{
	if (data->player)
		mlx_destroy_image(data->mlx_ptr, data->player);
	if (data->c)
		mlx_destroy_image(data->mlx_ptr, data->c);
	if (data->exit)
		mlx_destroy_image(data->mlx_ptr, data->exit);
	if (data->wall)
		mlx_destroy_image(data->mlx_ptr, data->wall);
	if (data->field)
		mlx_destroy_image(data->mlx_ptr, data->field);
}

int	ft__height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
