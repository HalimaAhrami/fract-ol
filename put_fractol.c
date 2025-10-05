/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fractol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h-el-ahr <h-el-ahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:40:40 by h-el-ahr          #+#    #+#             */
/*   Updated: 2025/04/08 08:54:54 by h-el-ahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - 0) / (old_max - 0) + new_min);
}

static void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->pixel + (y * img->line_len + x * (img->bp / 8));
	*(unsigned int *) dst = color;
}

static void	mandel_vs_julia(t_complix *z, t_complix *c, t_fractal *f)
{	
	if (!ft_strncmp(f->name, "Julia", 5))
	{
		c->x = f->julia_x;
		c->y = f->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	handle_pixel(int x, int y, t_fractal *f)
{
	t_complix	z;
	t_complix	c;
	int			i;

	i = 0;
	z.x = (map(x, -2, 2, WIDTH) * f->zoom) + f->shift_x;
	z.y = (map(y, 2, -2, HIGHT) * f->zoom) + f->shift_y;
	mandel_vs_julia(&z, &c, f);
	while (i < f->iterations)
	{
		z = z_2_c(z, c);
		if ((z.x * z.x) + (z.y * z.y) > f->escape_value)
		{
			f->color = map(i, BLACK, WHITE, f->iterations);
			pixel_put(&f->img, x, y, f->color);
			return ;
		}
		i++;
	}
	pixel_put(&f->img, x, y, WHITE);
}

void	put_fractol(t_fractal *f)
{
	int	x;
	int	y;

	y = 0;
	while (y < HIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, f);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx_c, f->mlx_w, f->img.imgs, 0, 0);
}
