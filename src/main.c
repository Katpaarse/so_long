/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerste <jukerste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:15:12 by jukerste          #+#    #+#             */
/*   Updated: 2025/05/26 16:25:07 by jukerste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
        error_exit("Usage: ./so_long <map_file.ber>");

    // Parse the map file
    game.map = parse_map(argv[1]);
    if (!game.map)
        error_exit("Failed to load map");

    // Validate the map
    validate_map(game.map);

    // Initialize the MLX42 window
    game_initializer(&game);

    // Load all necessary images
    load_images(&game);

    // Render the initial map
    render_map(&game);

    // Show the window and start the loop
    mlx_loop(game.mlx);

    // Cleanup (won't be reached until window closed)
    free_map(game.map);
    mlx_terminate(game.mlx);

    return (0);
}
