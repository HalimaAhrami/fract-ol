/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h-el-ahr <h-el-ahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 08:49:59 by h-el-ahr          #+#    #+#             */
/*   Updated: 2025/04/10 20:13:02 by h-el-ahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complix	z__2_c(t_complix z, t_complix c)
{
	t_complix	r;

	r.x = z.x * z.x - z.y * z.y + c.x;
	r.y = -2 * z.x * z.y + c.y;
	return (r);
}

int	ft_close(t_fractal *f)
{
	mlx_destroy_image(f->mlx_c, f->img.imgs);
	mlx_destroy_window(f->mlx_c, f->mlx_w);
	mlx_destroy_display(f->mlx_c);
	free(f->mlx_c);
	exit (0);
}

int	main(int ac, char **av)
{
	t_fractal	f;

	if ((ac == 2 && ft_strncmp(av[1], "Tricorn", ft_strlen(av[1])) == 0))
	{
		f.name = "Tricorn";
		init_fractol(&f);
		put_fractol(&f);
		ft_evant(&f);
		mlx_loop(f.mlx_c);
	}
	else
		exit((ft_putstr_fd("./fracol Tricorn", 2), 1));
	return (0);
}
