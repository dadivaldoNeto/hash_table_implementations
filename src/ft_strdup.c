/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netomm <netooff@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:28:31 by netomm            #+#    #+#             */
/*   Updated: 2025/01/07 21:44:49 by netomm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * This function copy an string into a chunk of memory in heap
**/
#include "ft_lib.h"

char	*ft_strdup(char	*s)
{
	char	*buffer;
	int		i;
	int		len;

	len = ft_strlen(s) + 1;
	i = -1;
	buffer = (char *) malloc(sizeof(char) * len);
	while (buffer && ++i < len)
		buffer[i] = s[i];
	return (buffer);
}
