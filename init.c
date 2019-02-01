/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:25:30 by jmoucach          #+#    #+#             */
/*   Updated: 2019/01/21 14:37:59 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_dl(t_dl *dl_data, t_2Dpoint b_point, t_2Dpoint e_point)
{
	(*dl_data).x_inc = (e_point.x - b_point.x > 0) ? 1 : -1;
	(*dl_data).y_inc = (e_point.y - b_point.y > 0) ? 1 : -1;
	(*dl_data).dx = abs(e_point.x - b_point.x);
	(*dl_data).dy = abs(e_point.y - b_point.y);
}

void	init_cam(t_data *data)
{
	(*data).cam.x = 0;
	(*data).cam.y = 0;
	(*data).cam.z = 0;
	(*data).cam.rx = 0;
	(*data).cam.ry = 0;
	(*data).cam.rz = 0;
	(*data).cam.zoom = 50;
}
void	init_image(t_data *data)
{
	data->img_data.img_ptr = mlx_new_image(data->mlx_ptr, data->win_width,
		data->win_height);
	data->img_data.img_str = mlx_get_data_addr(data->img_data.img_ptr,
		&(data->img_data.bpp), &(data->img_data.sl), &(data->img_data.endian));
}
void	init(char *str, t_data *data)
{
	(*data).mlx_ptr = mlx_init();
	ft_putendl("t1");
	(*data).win_width = WIDTH;
	(*data).win_height = HEIGHT;
	ft_putendl("t2");
	(*data).win_ptr = mlx_new_window((*data).mlx_ptr, (*data).win_width,
			(*data).win_height, "Fdf");
	ft_putendl("t3");
	(*data).map_data = map_creation(str);
	ft_putendl("t4");
	init_cam(data);
	ft_putendl("t5");
}
