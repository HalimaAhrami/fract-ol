/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h-el-ahr <h-el-ahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:40:45 by h-el-ahr          #+#    #+#             */
/*   Updated: 2025/04/08 08:54:03 by h-el-ahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	data_init(t_fractal *f)
{
	f->escape_value = 4;
	f->iterations = 37;
	f->shift_x = 0.0;
	f->shift_y = 0.0;
	f->zoom = 1.0;
}

void	init_fractol(t_fractal *f)
{
	f->mlx_c = mlx_init();
	if (f->mlx_c == NULL)
		exit((ft_putstr_fd("error\n", 2), 1));
	f->mlx_w = mlx_new_window(f->mlx_c, WIDTH, HIGHT, f->name);
	if (f->mlx_w == NULL)
	{
		mlx_destroy_display(f->mlx_c);
		free(f->mlx_c);
		exit((ft_putstr_fd("error\n", 2), 1));
	}
	f->img.imgs = mlx_new_image(f->mlx_c, WIDTH, HIGHT);
	if (f->img.imgs == NULL)
	{
		mlx_destroy_window(f->mlx_c, f->mlx_w);
		mlx_destroy_display(f->mlx_c);
		free(f->mlx_c);
		exit((ft_putstr_fd("error\n", 2), 1));
	}
	f->img.pixel = mlx_get_data_addr(f->img.imgs, &f->img.bp, &f->img.line_len,
			&f->img.endian);
	data_init(f);
}

static int	ft_mouse_hook(int key, int x, int y, t_fractal *f)
{
	if (key == 4 && x)
		f->zoom *= 1.01;
	else if (key == 5 && y)
		f->zoom /= 1.01;
	put_fractol(f);
	return (0);
}

static int	ft_key(int key, t_fractal *f)
{
	if (key == 65307)
		ft_close(f);
	put_fractol(f);
	return (0);
}

void	ft_evant(t_fractal *f)
{
	mlx_key_hook(f->mlx_w, ft_key, f);
	mlx_mouse_hook(f->mlx_w, ft_mouse_hook, f);
	mlx_hook(f->mlx_w, 17, 0, ft_close, f);
}
