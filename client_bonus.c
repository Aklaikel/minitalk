/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:44:15 by aklaikel          #+#    #+#             */
/*   Updated: 2021/12/18 17:48:00 by aklaikel         ###   ########.fr       */
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

void	handler(int sig)
{
	write(1, "Server: successfully recieved\n", 29);
	exit(0);
}

int	main(int ac, char **av)
{
	int		pid;
	char	*s;
	int		i;

	i = 0;
	if (ac != 3)
	{
		write(2, "false arguments", 15);
		return (0);
	}
	signal(SIGUSR1, handler);
	pid = ft_atoi(av[1]);
	s = av[2];
	while (s[i])
	{
		send_char(s[i], pid);
		i++;
	}
	send_char(0, pid);
	pause ();
}
