/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdarko <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/30 16:17:43 by jdarko       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/02 15:09:32 by jdarko      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		ft_check_open(int fd, char **argv)
{
	char	buff[1];

	errno = 0;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr("error\n");
		exit(1);
	}
	read(fd, buff, 1);
	if (errno != 0)
	{
		perror("fdf ");
		exit(1);
	}
	return (fd);
}

int		main(int argc, char **argv)
{
	int				fd;
	int				i;
	char			*line;
	t_env			mlx;

	fd = 0;
	i = 0;
	line = NULL;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1600, 1200, "fdf");
	if (argc < 2 && argc > 5)
	{
		ft_putstr("usage: ./Fdf source_file\n");
		return (0);
	}
	fd = ft_check_open(fd, argv);
	read_and_stock(fd, line, argv, &mlx);
	mlx_key_hook(mlx.win, bonus_key, (void *)&mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
