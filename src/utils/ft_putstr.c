/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arch <arch@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:10:29 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/06/08 12:46:07 by arch             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	ft_putstr(char *s, int *count)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		ft_putstr("(null)", count);
		return ;
	}
	while (s[i] != '\0')
	{
		ft_putchar(s[i], count);
		i++;
	}
}
