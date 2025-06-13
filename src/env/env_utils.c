/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 00:00:00 by riel-fas          #+#    #+#             */
/*   Updated: 2025/06/13 20:56:53 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_shell.h"

static int	count_env_vars(t_env *env)
{
	t_env	*current;
	int		count;

	current = env;
	count = 0;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

static char	*create_env_string(t_env *node)
{
	char	*temp;
	char	*result;

	temp = ft_strjoin(node->key, "=");
	result = ft_strjoin(temp, node->value);
	free(temp);
	return (result);
}

char	**env_list_to_array(t_env *env)
{
	t_env	*current;
	char	**env_array;
	int		count;
	int		i;

	count = count_env_vars(env);
	env_array = (char **)malloc(sizeof(char *) * (count + 1));
	if (!env_array)
		return (NULL);
	current = env;
	i = 0;
	while (current)
	{
		env_array[i] = create_env_string(current);
		current = current->next;
		i++;
	}
	env_array[i] = NULL;
	return (env_array);
}
