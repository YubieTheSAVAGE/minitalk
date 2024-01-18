/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudiba <aboudiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:01:54 by aboudiba          #+#    #+#             */
/*   Updated: 2023/12/27 22:45:53 by aboudiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>

void	ft_invalid_pid(void);
void	ft_invalid_message(void);
void	ft_addnullterminator(int **ptr, int byte_index);
int		ft_isalldigit(char *str);

#endif // !MINITALK_H
