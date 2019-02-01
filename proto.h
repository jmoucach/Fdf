/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:30:08 by jmoucach          #+#    #+#             */
/*   Updated: 2019/01/21 14:38:13 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

int create_image(t_data *data);
t_map	map_creation(char *name);

/*
**  Map
*/

t_map   map_creation(char *file_name);
int     **generate_map(int nbline, int nbword);
void    map_filler(t_map *map_data, char *file_name);
int     count_size_map(char *str, int *nbword);
int     word_count(char *str, char c);

/*
**  Hook deal
*/

int     deal_key(int key, t_data *data);
int     key_press(int key_code, t_data *data);
/*
**	Draw line
*/

void	dl_x_inc(t_dl dl_data, t_2Dpoint point, t_data *data);
void	dl_y_inc(t_dl dl_data, t_2Dpoint point, t_data *data);
int		draw_line(t_2Dpoint b_point, t_2Dpoint e_point, t_data *data);

/*
**	Info
*/

void	info(t_data data);
void	info_key(t_data data);
void	info_window(t_data data);

/*
**	Init
*/

void    init_image(t_data *data);
void	init_dl(t_dl *dl_data, t_2Dpoint b_point, t_2Dpoint e_point);
void	init(char *str, t_data *data);

#endif
