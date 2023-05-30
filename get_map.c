/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:35:02 by gansard           #+#    #+#             */
/*   Updated: 2023/02/21 15:55:58 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_name(char *src_map)
{
	if (ft_strncmp((src_map + ft_strlen(src_map) - 4), ".ber", 4) != 0)
	{
		ft_printf("Error \nLa fichier de la carte ne fini pas par \".ber\".\n");
		return (0);
	}
	return (1);
}

int	ft_test_format(char *map_str, int *count_c)
{
	int		i;
	char	*pos_p;
	char	*pos_e;

	i = 0;
	pos_p = ft_strchr(map_str, 'P');
	pos_e = ft_strchr(map_str, 'E');
	if (!(pos_p && pos_e && ft_strchr(map_str, 'C')))
		return (1);
	while (map_str[i])
	{
		if (!ft_strchr("01PEC\n", map_str[i]))
			return (2);
		if (map_str[i] == 'C')
			(*count_c)++;
		if ((map_str[i] == '\n' && ((map_str[i + 1] == '\n')
					|| map_str[i + 1] == '\0')) || map_str[0] == '\n')
			return (4);
		i++;
	}
	if (ft_strchr((pos_p + 1), 'P') || ft_strchr((pos_e + 1), 'E'))
		return (3);
	return (0);
}

int	ft_check_format(char *map_str, int	*count_c)
{
	int	res;

	res = ft_test_format(map_str, count_c);
	if (res == 1)
	{
		ft_printf("Error \nNe contient pas tous les caractères nécessaires.\n");
		return (0);
	}
	if (res == 2)
	{
		ft_printf("Error \nLa carte contient des caractères interdit.\n");
		return (0);
	}
	if (res == 3)
	{
		ft_printf("Error \nLa carte contient des doublons.\n");
		return (0);
	}
	if (res == 4)
	{
		ft_printf("Error \nLa carte contient des lignes vides.\n");
		return (0);
	}
	return (1);
}

char	*ft_read_file(char *str, char *buf, int fd)
{
	char	*temp;
	int		rd_bytes;

	rd_bytes = 1;
	while (rd_bytes != 0)
	{
		rd_bytes = read(fd, buf, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			ft_printf("Error \nProblème de lecture.\n");
			return (free(buf), free(str), NULL);
		}
		buf[rd_bytes] = '\0';
		temp = str;
		str = ft_strjoin(str, buf);
		if (!str)
		{
			free(temp);
			return (free(buf), NULL);
		}
		free(temp);
	}
	return (str);
}

char	*ft_get_map(char *src_map)
{
	int		fd;
	char	*buf;
	char	*str;

	str = ft_strdup("");
	if (!str)
		return (NULL);
	fd = open(src_map, O_RDONLY);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	str = ft_read_file(str, buf, fd);
	if (!str)
		return (NULL);
	close(fd);
	return (free(buf), str);
}
