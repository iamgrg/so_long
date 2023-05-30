/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:41:49 by gansard           #+#    #+#             */
/*   Updated: 2023/02/21 16:04:54 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_exit(char **map)
{
	int	x;
	int	y;

	x = 1;
	while (map[x])
	{
		y = 1;
		while (map[x][y])
		{
			if (map[x][y] == 'E')
				return (1);
			y++;
		}	
		x++;
	}
	return (0);
}

char	**ft_so_long(t_data *data, char *src_map)
{
	char	**map;
	char	*map_str;
	int		count_c;
	int		pos;

	count_c = 0;
	map_str = ft_get_map(src_map);
	if (!map_str || !ft_check_format(map_str, &count_c))
		return (free(map_str), NULL);
	pos = (int)(ft_strchr(map_str, 'P') - map_str);
	map = ft_split(map_str, '\n');
	free(map_str);
	if (!map)
		return (NULL);
	data->count_c = count_c;
	if (!ft_check_map(map, &count_c))
	{
		ft_free_map(map);
		return (NULL);
	}
	data->width = ft_strlen(map[0]);
	data->x = pos / data->width;
	data->y = ((pos - 1) % data->width);
	return (map);
}

int	main(int ac, char **av, char **env)
{
	char	*src_map;
	int		boolean;
	t_data	data;

	if (!*env)
		return (ft_printf("Error \nPas d'environnement.\n"), 0);
	if (ac != 2)
		return (ft_printf("Error \nNombre d'arguments incorrect.\n"), 0);
	src_map = av[1];
	if (!ft_check_name(src_map))
		return (0);
	data.map = ft_so_long(&data, src_map);
	if (!data.map)
		return (0);
	if (!ft_create_mlxmap(&data))
		return (ft_free_data(&data), 0);
	ft_free_data(&data);
	return (0);
}
