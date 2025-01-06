/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netomm <netooff@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:41:09 by netomm            #+#    #+#             */
/*   Updated: 2025/01/06 01:29:47 by netomm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef HASH_TABLE_H
# define HASH_TABLE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct
{
	char	*key;
	char	*value;
} ht_item;

typedef struct
{
	unsigned int	size;
	unsigned int	count;
	ht_item	**ht_items;
} ht_hash_table;

ht_hash_table	*ht_new(void);
void	ht_delete(ht_hash_table *ht);

#endif
