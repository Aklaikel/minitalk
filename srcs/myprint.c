/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myprint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:38:36 by aklaikel          #+#    #+#             */
/*   Updated: 2021/12/18 16:13:23 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mylibrary.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 10)
	{
		ft_putchar(nb + '0');
		return ;
	}
	ft_putnbr(nb / 10);
	ft_putnbr(nb % 10);
}
