/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:20:59 by jmoucach          #+#    #+#             */
/*   Updated: 2019/01/23 18:21:01 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     pt_is_inside_window(int index, int x, t_data *data)
{
    if (index < 0 || index > (data->win_width * 4 * data->win_height))
        return (0);
    if (4 * (x + (*data).cam.x) > (*data).win_width * 4 || 4 * (x + (*data).cam.x) < 0)
        return (0);
    return (1);
}
char    *fill_pixel(int x, int y, unsigned char *str, t_data *data)
{
    int i;
    int index;

    if ((*data).cam.zoom > 0)
    {
    x = x * (*data).win_width / (*data).cam.zoom;
    y = y * (*data).win_height / (*data).cam.zoom;
    i = 0;
    index = (4 * (x + (*data).cam.x)) + (4 * (*data).win_width * (y + (*data).cam.y));
    if (pt_is_inside_window(index + i, x, data) == 1)
    {
        while (i < 3)
        {
            str[index + i] = 255;
            i++;
        }
    }
    }
    return ((char*)str);
}

int create_image(t_data *data)
{
    init_image(data);

    t_3Dpoint p3;
    int x;
    int y;

    y = 0;
    while (y < (*data).map_data.nbline)
    {
        x = 0;
        while (x < (*data).map_data.nbword)
        {
            p3.x = x;
            p3.y = y;
            p3.z = data->map_data.map[y][x];
            (*data).img_data.img_str = fill_pixel(p3.x + p3.z, p3.y + p3.z, (unsigned char*)(*data).img_data.img_str, data); 
            x++;
        }
        y++;
    }
    mlx_put_image_to_window((*data).mlx_ptr, (*data).win_ptr, (*data).img_data.img_ptr, 0, 0);
    return (1);
}