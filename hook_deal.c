/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_deal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:11:05 by jmoucach          #+#    #+#             */
/*   Updated: 2019/01/23 15:11:07 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     deal_key(int key, t_data *data)
{
    if (key == ESC)
    {
        mlx_clear_window(data->mlx_ptr, data->win_ptr);
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        ft_putendl("Program closed successfully!");
        exit(EXIT_SUCCESS);
    }
    if (key == C)
    {
        mlx_clear_window(data->mlx_ptr, data->win_ptr);
        info(*data);
        ft_putendl("Screen cleared successfully!");
        return (1);
    }
    return (1);
}

int     key_press(int key_code, t_data *data)
{
    if (key_code == D)
    {
        mlx_clear_window(data->mlx_ptr, data->win_ptr);
        (*data).cam.x += 10;
    }
    if (key_code == A)
    {
        mlx_clear_window(data->mlx_ptr, data->win_ptr);
        (*data).cam.x -= 10;
    }
    if (key_code == W)
    {
        mlx_clear_window(data->mlx_ptr, data->win_ptr);
        (*data).cam.y -= 10;
    }
    if (key_code == S)
    {
        mlx_clear_window(data->mlx_ptr, data->win_ptr);
        (*data).cam.y += 10;
    }
    if (key_code == 78)
    {
        mlx_clear_window(data->mlx_ptr, data->win_ptr);
        (*data).cam.zoom += 5;
    }
    if (key_code == 69)
    {
        mlx_clear_window(data->mlx_ptr, data->win_ptr);
        (*data).cam.zoom -= 5;
    }
    create_image(data);
    info(*data);
    return (1);
}