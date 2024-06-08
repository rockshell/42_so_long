/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arch <arch@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:43:33 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/06/08 12:46:07 by arch             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	ft_putuns(unsigned int n, int *count)
{
	if (n >= 10)
	{
		ft_putuns(n / 10, count);
		ft_putchar((n % 10) + '0', count);
	}
	else
		ft_putchar(n + '0', count);
}
