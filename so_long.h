/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:05:37 by gansard           #+#    #+#             */
/*   Updated: 2023/02/21 16:54:50 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "libft/ft_printf.h"
# include <fcntl.h>
# include "./minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_data {
	char	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
	int		width;
	int		count_c;
	void	*player;
	void	*wall;
	void	*field;
	void	*c;
	void	*exit;
}	t_data;

int		ft_check_exit(char **map);
int		ft__height(char **map);
int		ft_create_img(t_data *data);
char	*ft_get_map(char *src_map);
int		move_right(t_data *data, int i);
int		move_down(t_data *data, int i);
int		move_left(t_data *data, int i);
int		move_up(t_data *data, int i);
void	ft_display_cells(t_data *data);
void	ft_free_map(char **map);
void	ft_free_data(t_data *data);
int		ft_check_map(char **map, int *count_c);
int		ft_check_format(char *map_str, int *count_c);
int		ft_check_name(char *src_map);
char	**ft_dup_map(char **map);
void	ft_moveup(char **map, int *x, int *y, int *c_tofound);
void	ft_moveright(char **map, int *x, int *y, int *c_tofound);
void	ft_moveleft(char **map, int *x, int *y, int *c_tofound);
void	ft_movedown(char **map, int *x, int *y, int *c_tofound);
int		ft_check_items(char **map, int *count_c);
int		ft_create_mlxmap(t_data *data);
void	ft_free_img(t_data *data);

#endif
