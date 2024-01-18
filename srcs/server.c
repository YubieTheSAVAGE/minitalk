/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudiba <aboudiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 21:58:09 by aboudiba          #+#    #+#             */
/*   Updated: 2023/12/27 22:24:27 by aboudiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static int	bin_to_char(int *ptr)
{
	int	i;
	int	res;
	int	bit_index;

	i = 0;
	res = 0;
	bit_index = 7;
	while (bit_index >= 0)
	{
		res += ptr[i] << bit_index;
		bit_index--;
		i++;
	}
	return (res);
}

static void	ft_signal_handler(int sig)
{
	static int	*ptr;
	static int	bit_index;

	if (!ptr)
	{
		ptr = ft_calloc(8, sizeof(int));
		if (!ptr)
			return ;
	}
	if (!ptr)
		return ;
	if (sig == SIGUSR1)
		ptr[bit_index] = 1;
	else if (sig == SIGUSR2)
		ptr[bit_index] = 0;
	bit_index++;
	if (bit_index == 8)
	{
		if (bin_to_char(ptr) == '\0')
			ft_putchar_fd('\n', 1);
		else
			ft_putchar_fd(bin_to_char(ptr), 1);
		bit_index = 0;
	}
}

int	main(void)
{
	ft_putstr_fd("\033[1;32mServer's PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\033[1;0m\n", 1);
	signal(SIGUSR1, ft_signal_handler);
	signal(SIGUSR2, ft_signal_handler);
	while (1)
	{
		pause();
	}
	return (0);
}
