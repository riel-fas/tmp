/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:19:54 by riel-fas          #+#    #+#             */
/*   Updated: 2025/06/13 20:50:26 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_shell.h"
#include <string.h>


extern int rl_catch_signals; // kat9olo ana variable ja mn library 3la bara


// void ll()
// {
// 	system("leaks -q minishell");
// }

int	main(int argc, char **argv, char **env)
{
	t_shell	*shell;
	int		exit_status;

	(void)argc;
	(void)argv;

	// atexit(ll);
	// Set up signal handling
	signal(SIGINT, handler);  // CTRL+C
	signal(SIGQUIT, SIG_IGN);
	// rl_catch_signals = 0;
	// Initialize the shell
	shell = shell_init(env);
	if (!shell)
	{
		printf("Error: Failed to initialize shell.\n");
		return (1);
	}

	// Run the main shell loop
	exit_status = minishell_loop(shell);

	// Clean up and exit
	cleanup(shell);
	return (exit_status);
}
