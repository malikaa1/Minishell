/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:04:27 by mrahmani          #+#    #+#             */
/*   Updated: 2021/10/31 17:09:42 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_env(t_env *env)
{
	if (env == NULL)
		return (-1);
	while (env && env->next != NULL)
	{
		printf("%s\n", env->var);
		env = env->next;
	}
	if (env)
		printf("%s\n", env->var);
	return (1);
}

void add_env(t_env **env, t_env *new, char *str)
{
	t_env *tmp;

	tmp = *env;
	if (*env == NULL)
	{
		*env = new;
		(*env)->next = NULL;
		(*env)->var = str;
		(*env)->value = get_value(str);
		(*env)->name = get_name_env(str);
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		tmp->next->var = str;
		tmp->next->value = get_value(str);
		tmp->next->name = get_name_env(str);
		tmp->next->next = NULL;
	}
}

void init_env(t_env **env_list, char **env)
{
	t_env *new;

	if (*env_list == NULL)
	{
		while (*env)
		{
			new = malloc(sizeof(t_env));
			if (new == NULL)
				return ;
			add_env(env_list, new, *env);
			*env++;
		}
	}
}

char *get_value(char *s)
{
    int i;
	int count;
    
    i = 0;
	count = 0;
	if (s != NULL)
	{
        while (s[i])
		{
			count++;
			if (s[i] == '=')
			{
				return (ft_substr(s, i + 1, ft_strlen(s) - count));
			}
			i++;
		}
	}
	return (s);
}

char *get_name_env(char *s)
{
	int i;

	i = 0;
	if (s == NULL)
		return (ft_strdup(" "));
	while (s[i])
	{
		if (s[i] == '=')
			return (ft_substr(s, 0, i));
		i++;
	}
    return (ft_strdup(s));
}
