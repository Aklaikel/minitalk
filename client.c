/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 22:13:37 by aklaikel          #+#    #+#             */
/*   Updated: 2021/12/18 18:08:53 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"mylibrary.h"

void	send_char(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		usleep(500);
		kill(pid, (c >> i & 1) + SIGUSR1);
		i--;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*s;
	int		i;

	i = 0;
	if (ac != 3)
	{
		write(2, "not enough arguments", 20);
		return (0);
	}
	pid = ft_atoi(av[1]);
	s = av[2];
	while (s[i])
	{
		send_char(s[i], pid);
		i++;
	}
	send_char(0, pid);
}
