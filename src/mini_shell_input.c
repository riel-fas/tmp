/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 00:00:00 by riel-fas          #+#    #+#             */
/*   Updated: 2025/06/13 20:54:01 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_shell.h"

int	process_exit_check(char *input)
{
	if (ft_strcmp(input, "exit") == 0)
		return (0);
	return (1);
}

int	handle_tokenize_error(t_shell *shell, char *input)
{
	if (!shell->tokens && *input)
	{
		printf("Error: Failed to tokenize input\n");
		return (1);
	}
	return (0);
}

int	handle_parse_error(t_shell *shell, t_parse_result result)
{
	if (result == PARSE_ERROR_SYNTAX)
	{
		printf("Syntax error\n");
		free_tokens(shell->tokens);
		shell->tokens = NULL;
		return (1);
	}
	else if (result == PARSE_ERROR_MEMORY)
	{
		printf("Memory allocation error\n");
		free_tokens(shell->tokens);
		shell->tokens = NULL;
		return (1);
	}
	return (0);
}
