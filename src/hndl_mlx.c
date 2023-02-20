/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hndl_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:15:13 by otait-ta          #+#    #+#             */
/*   Updated: 2023/02/20 09:30:51 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_mlx(t_info *info)
{
	info->width = 400;
	info->height = 400;
	info->max_iterations = 50;
	info->mlx.mlx_ptr = mlx_init();
	info->mlx.win_ptr = mlx_new_window(info->mlx.mlx_ptr, info->width,
			info->height, "Fractol");
	info->img_data.img = mlx_new_image(info->mlx.mlx_ptr, info->width,
			info->height);
	info->img_data.addr = mlx_get_data_addr(info->img_data.img,
											&info->img_data.bpp,
											&info->img_data.size_line,
											&info->img_data.endian);
	info->move.x = 1;
	info->move.y = 1;
}

void	my_mlx_hook(t_info *info)
{
	mlx_mouse_hook(info->mlx.win_ptr, mouse_hook, info);
	mlx_key_hook(info->mlx.win_ptr, key_hook, info);
	mlx_hook(info->mlx.win_ptr, 17, 0, exit_handler, info);
	mlx_put_image_to_window(info->mlx.mlx_ptr, info->mlx.win_ptr,
			info->img_data.img, 0, 0);
	mlx_loop(info->mlx.mlx_ptr);
}
