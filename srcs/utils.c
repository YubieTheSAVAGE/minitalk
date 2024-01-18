/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudiba <aboudiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 22:00:44 by aboudiba          #+#    #+#             */
/*   Updated: 2023/12/27 22:44:35 by aboudiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_invalid_pid(void)
{
	ft_putstr_fd("\033[1;31mError: Invalid PID\n\033[1;0m", 1);
	exit(EXIT_FAILURE);
}

void	ft_invalid_message(void)
{
	ft_putstr_fd("\033[1;31mError: Invalid message\n\033[1;0m", 1);
	exit(EXIT_FAILURE);
}

void	ft_addnullterminator(int **ptr, int byte_index)
{
	int	i;

	i = 0;
	ptr[byte_index] = ft_calloc(8, sizeof(int));
	while (i < 8)
	{
		ptr[byte_index][i] = 0;
		i++;
	}
}

int	ft_isalldigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
