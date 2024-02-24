/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:45:24 by joaosilva         #+#    #+#             */
/*   Updated: 2024/02/23 19:45:26 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void free_game(t_game *game)
{   
    if (game)
    {
        free(game->mlx);
    }    
}


int exit_error(t_game *game, char *msg)
{
    ft_putendl_fd ("Error", 2);
    ft_putendl_fd (msg, 2);
    free_game (game);
    exit (EXIT_FAILURE);
}