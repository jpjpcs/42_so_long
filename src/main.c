/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:43:50 by joaosilva         #+#    #+#             */
/*   Updated: 2024/02/23 19:43:53 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void check_file_open(char *file)
{
    int fd;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        exit_error(NULL, "The requested file couldn´t be open. Please insert a corrected file.");
    close (fd);
}

static void check_file_extension(char *filename, int len)
{
    if (len > 4)
    {
        if (!ft_strnstr (filename + len - 4, ".ber", len)) //qual a diferença entre usar strstr ou strnstr para o efeito? não há!
            exit_error(NULL, "Invalid file extension.");
    }
}

static void check_file_name(int len)
{
    if (len <= 4)
        exit_error (NULL, "Invalid file name.");
}

static void check_args_num (int ac)
{
    if (ac != 2)
        exit_error(NULL, "Wrong number of arguments");
}

int main (int ac, char **av)
{
    size_t len;
    //t_game *game;


    check_args_num (ac); // changed the main, putting the checkers.c with the check functions: 1. check num args, 2. check_file name, 3. check file extension
    len = ft_strlen (av[1]); //LIBFT - o len está dps do check_args_num pq senão poderia dar segmentation fault se não existisse nenhum argumento. ao não existir, o strlen não iria ler ficheiro nenhum, mas iria tentar aceder causando segmentation fault.
    check_file_name (len); // file name was changed from filename to file_name. acrescentei a len que retirei da check_file_name. isto pq separei a check_file_name da check_file_extension
    check_file_extension (av[1], len); //also separeted check_file_extension from check_file_name
    check_file_open(av[1]);
    so_long(av[1]);
    return (0);
}

