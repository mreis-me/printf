/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:54:33 by mreis-me          #+#    #+#             */
/*   Updated: 2022/06/15 23:17:00 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list args;
	int count;
	int index;
	char *str;

	count = 0;
	index = 0;
	str = ft_strdup(format);
	if (!str)
		return (0);

	va_start(args, format);

	while (str[index])
	{
		if (str[index] == '%')
		{
			index++;
			if(is_args(str[index]))
				count += scan_args(str[index], args);
		}
		else if (str[index])
			count += print_char(str[index]);
		index++;
	}
	va_end(args);
	free((void *)str);
	return (count);
}
