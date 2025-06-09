/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerste <jukerste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:15:12 by jukerste          #+#    #+#             */
/*   Updated: 2025/06/09 19:58:03 by jukerste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
        error_exit("Usage: ./so_long <map_file.ber>");
    game.map = parse_map(argv[1]);
    if (game.map == NULL)
        error_exit("Failed to load map");
    validate_map(game.map);
    game_init(&game);
    load_images(&game);
    render_map(&game);
    mlx_key_hook(game.mlx, &key_handler, &game);
    mlx_loop(game.mlx);
    if (game.has_won)
        ft_printf("The ghost found it's way home!\n");
    free_map(game.map);
    mlx_terminate(game.mlx);
    return (0);
}
