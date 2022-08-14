/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangjiho <gangjiho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 07:01:32 by gangjiho          #+#    #+#             */
/*   Updated: 2022/08/14 11:14:10 by gangjiho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include <fcntl.h>

typedef struct	s_wall
{
	int		ew;
	int		eh;
	int		ww;
	int		wh;
	int		sw;
	int		sh;
	int		nw;
	int		nh;
	void	*e_img;
	void	*w_img;
	void	*n_img;
	void	*s_img;
}t_wall;

void	set_img(void *mlx, t_wall *w)
{
	w->e_img = mlx_xpm_file_to_image(mlx, "./textures/wall_e.xpm", &w->ew, &w->eh);
	w->w_img = mlx_xpm_file_to_image(mlx, "./textures/wall_w.xpm", &w->ww, &w->wh);
	w->s_img = mlx_xpm_file_to_image(mlx, "./textures/wall_s.xpm", &w->sw, &w->sh);
	w->n_img = mlx_xpm_file_to_image(mlx, "./textures/wall_n.xpm", &w->nw, &w->nh);
}

t_wall	init(void *mlx, void *win)
{
	t_wall	w;
	int		i;

	i = 0;
	set_img(mlx, &w);
	return (w);
}

int	main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	void	*img;
	int		fd;
	t_wall  w;

	if (ac != 2)
		return 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (0);	
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 500, "HELLO");
	init(mlx, win);
	// mlx_put_image_to_windw mlx, win, img, screen-start-x, screen-start-y
	w = init(mlx, win);
	for (int i = 0; i < 10; i++)
	{
		mlx_put_image_to_window(mlx, win, w.n_img, w.nw * i + 50, w.nh);
		mlx_put_image_to_window(mlx, win, w.s_img, w.sw * i + 50, w.sh * 5);
	}
	for(int i = 0; i < 3; i++)
	{
		mlx_put_image_to_window(mlx, win, w.e_img, 50, w.eh * (i + 2));
		mlx_put_image_to_window(mlx, win, w.w_img, 50 + w.ww * 9, w.wh * (i + 2));
	}
	mlx_loop(mlx);
}