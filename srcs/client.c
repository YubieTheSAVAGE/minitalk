/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudiba <aboudiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:02:24 by aboudiba          #+#    #+#             */
/*   Updated: 2023/12/28 20:14:31 by aboudiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	ft_check_arg(int ac, char **av)
{
	if (ac != 3)
	{
		ft_putstr_fd("\033[1;31mError: Wrong number of arguments\n\n", 1);
		ft_putstr_fd("\033[1;33mPrototype:\n\t", 1);
		ft_putstr_fd("./client <PID> <Message>\033[1;0\n", 1);
		exit(EXIT_FAILURE);
	}
	if (!ft_isalldigit(av[1]))
	{
		ft_putstr_fd("\033[1;31mError: PID must be a number\n\033[1;0m", 1);
		exit(EXIT_FAILURE);
	}
}

static int	**ft_char_to_bin(char *str)
{
	int	**ptr;
	int	byte_index;
	int	bit_index;
	int	i;

	byte_index = 0;
	ptr = ft_calloc(ft_strlen(str) + 2, sizeof(int *));
	if (!ptr)
		return (NULL);
	while (str[byte_index])
	{
		ptr[byte_index] = ft_calloc(8, sizeof(int));
		if (!ptr[byte_index])
			return (NULL);
		bit_index = 7;
		i = 0;
		while (bit_index >= 0)
		{
			ptr[byte_index][i++] = (str[byte_index] >> bit_index) & 1;
			bit_index--;
		}
		byte_index++;
	}
	ft_addnullterminator(ptr, byte_index);
	return (ptr);
}

static void	ft_send_signals(int **ptr, int pid)
{
	int	byte_index;
	int	bit_index;

	byte_index = 0;
	while (ptr[byte_index])
	{
		bit_index = 0;
		while (bit_index < 8)
		{
			if (ptr[byte_index][bit_index] == 1)
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_invalid_pid();
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					ft_invalid_pid();
			}
			bit_index++;
			usleep(100);
		}
		byte_index++;
	}
}

int	main(int ac, char **av)
{
	ft_check_arg(ac, av);
	if (av[2][0] == '\0')
		ft_invalid_message();
	ft_send_signals(ft_char_to_bin(av[2]), ft_atoi(av[1]));
	return (0);
}
