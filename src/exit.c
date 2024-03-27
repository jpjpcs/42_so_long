/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:45:24 by joaosilva         #+#    #+#             */
/*   Updated: 2024/03/27 16:32:48 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	free_textures(t_game *game)
{
	if (game->img_walls.img)
		mlx_destroy_image(game->mlx, game->img_walls.img);
	if (game->img_space.img)
		mlx_destroy_image(game->mlx, game->img_space.img);
	if (game->img_exit.img)
		mlx_destroy_image(game->mlx, game->img_exit.img);
	if (game->img_collect.img)
		mlx_destroy_image(game->mlx, game->img_collect.img);
	if (game->img_player.img)
		mlx_destroy_image(game->mlx, game->img_player.img);
}

static void	free_game(t_game *game)
{
	if (game)
	{
		if (game->map.grid)
			ft_free_array(game->map.grid);
		free_textures(game);
		if (game->mlx && game->win)
			mlx_destroy_window(game->mlx, game->win);
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
	}
}

int	exit_esc(t_game *game)
{
	ft_putendl_fd("You gave up! Nice. More 🧀 🧀 🧀 cheese left for me!", 1);
	free_game(game);
	exit(EXIT_SUCCESS);
}

int	exit_game(t_game *game, char *msg)
{
	ft_putendl_fd(msg, 1);
	free_game(game);
	exit(EXIT_SUCCESS);
}

int	exit_error(t_game *game, char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	free_game(game);
	exit(EXIT_FAILURE);
}
