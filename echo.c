/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:47:03 by mrahmani          #+#    #+#             */
/*   Updated: 2021/11/06 21:01:36 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_echo(char **arg)
{
    int i;
    int has_option;

    has_option = 0;
    i = 1;
    if (ft_strncmp(arg[i], "-n", 2) == 0 && i == 1)
    {
        i++;
        has_option = 1;
    }
    while (arg && arg[i])
    {
        ft_putstr_fd(arg[i], 1);
        if (arg[i + 1] != NULL)
            ft_putstr_fd(" ", 1);
        i++;
    }
    if (has_option == 0)
          ft_putstr_fd("\n", 1);
    return (1);
}