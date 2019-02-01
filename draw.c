/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:00:58 by jmoucach          #+#    #+#             */
/*   Updated: 2019/01/23 15:01:02 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dl_x_inc(t_dl dl_data, t_2Dpoint point, t_data *data)
{
	int		error;
	int		i;

	i = 1;
	error = dl_data.dx / 2;
	ft_putnbr(dl_data.dx);
	ft_putchar('\n');
	while (i <= dl_data.dx)
	{
		point.x += dl_data.x_inc;
		error += dl_data.dy;

		if (error >= dl_data.dx)
		{
			error -= dl_data.dx;
			point.y += dl_data.y_inc;
		}
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, point.x, point.y, WHITE);
		i++;
	}
}

void	dl_y_inc(t_dl dl_data, t_2Dpoint point, t_data *data)
{
	int		error;
	int		i;

	i = 1;
	error = dl_data.dy / 2;
	while (i <= dl_data.dy)
	{
		point.y += dl_data.y_inc;
		error += dl_data.dx;

		if (error >= dl_data.dy)
		{
			error -= dl_data.dy;
			point.x += dl_data.x_inc;
		}
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, point.x, point.y, WHITE);
		i++;
	}
}

int		draw_line(t_2Dpoint b_point, t_2Dpoint e_point, t_data *data)
{
	t_dl	dl_data;
	t_2Dpoint	here;

	init_dl(&dl_data, b_point, e_point);
	here.x = b_point.x;
	here.y = b_point.y;
	if (dl_data.dx > dl_data.dy)
	{
		dl_x_inc(dl_data, here, data);
		return (1);
	}
	else
	{
		dl_y_inc(dl_data, here, data);
		return (1);
	}
}
