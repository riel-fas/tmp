/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:45:00 by riel-fas          #+#    #+#             */
/*   Updated: 2025/06/13 20:52:38 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static char	*generate_prompt(t_shell *shell)
{
	(void)shell;
	return (ft_strdup("minishell~> "));
}

static int	process_input(t_shell *shell, char *input)
{
	t_parse_result	result;
	int				exit_status;

	if (!input || !*input || is_only_whitespace(input))
		return (1);
	if (*input)
		add_history(input);
	if (!process_exit_check(input))
		return (0);
	shell->tokens = tokenize(input);
	if (handle_tokenize_error(shell, input))
		return (1);
	print_tokens(shell->tokens);
	result = parse_tokens(shell->tokens);
	if (handle_parse_error(shell, result))
		return (1);
	print_commands(shell->commands);
	exit_status = execute_commands(shell, shell->commands);
	shell->exit_status = exit_status;
	free_tokens(shell->tokens);
	shell->tokens = NULL;
	free_commands(shell->commands);
	shell->commands = NULL;
	return (1);
}

//The main shell loop
int	minishell_loop(t_shell *shell)
{
	char	*input;
	char	*prompt;
	int		status;

	status = 1;
	while (status)
	{
		// Generate and display prompt
		prompt = generate_prompt(shell);
		input = readline(prompt);
		free(prompt);
		// Handle EOF (Ctrl+D)
		if (!input)
		{
			printf("exit\n");
			break;
		}
		// Process the input
		status = process_input(shell, input);
		free(input);
	}
	return (shell->exit_status);
}
