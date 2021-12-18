/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylibrary.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:44:58 by aklaikel          #+#    #+#             */
/*   Updated: 2021/12/18 16:24:04 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLIBRARY_H
# define MYLIBRARY_H
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

struct	s_recieved
{
	int		n;
	char	c;
	int		pid;
}		t_recieved;
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);

#endif