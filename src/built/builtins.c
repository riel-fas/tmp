/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:15:00 by riel-fas          #+#    #+#             */
/*   Updated: 2025/06/13 20:43:22 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	return (ft_strcmp(cmd, "cd") == 0
		|| ft_strcmp(cmd, "echo") == 0
		|| ft_strcmp(cmd, "pwd") == 0
		|| ft_strcmp(cmd, "export") == 0
		|| ft_strcmp(cmd, "unset") == 0
		|| ft_strcmp(cmd, "env") == 0
		|| ft_strcmp(cmd, "exit") == 0);
}

t_builtin_func	get_builtin(char *cmd)
{
	if (!cmd)
		return (NULL);
	if (ft_strcmp(cmd, "cd") == 0)
		return (&builtin_cd);
	else if (ft_strcmp(cmd, "echo") == 0)
		return (&builtin_echo);
	else if (ft_strcmp(cmd, "pwd") == 0)
		return (&builtin_pwd);
	else if (ft_strcmp(cmd, "export") == 0)
		return (&builtin_export);
	else if (ft_strcmp(cmd, "unset") == 0)
		return (&builtin_unset);
	else if (ft_strcmp(cmd, "env") == 0)
		return (&builtin_env);
	else if (ft_strcmp(cmd, "exit") == 0)
		return (&builtin_exit);
	return (NULL);
}
