/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netomm <netooff@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:46:51 by netomm            #+#    #+#             */
/*   Updated: 2025/01/07 14:07:41 by netomm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "hash_table.h"

static ht_item	*ht_new_item(char *k, char *v)
{
	ht_item	*item;

	item = malloc(sizeof(ht_item));
	item->key = ft_strdup(k);
	item->value = ft_strdup(v);
	return (item);
}

void	ht_delete_item(ht_item *ht)
{
	free(ht->key);
	free(ht->value);
	free(ht);
}

ht_hash_table	*ht_new(void)
{
	ht_hash_table	*ht;

	ht = malloc(sizeof(ht_hash_table));
	if (!ht)
		return (ht);
	ht->size = 10;
	ht->count = 0;
	ht->ht_items = calloc((size_t)ht->size, sizeof(ht_item *));
	return (ht);
}

void	ht_delete(ht_hash_table *ht)
{
	unsigned int	i;

	i = 0;
	while (i < ht->size)
	{
		if (!ht->ht_items[i])
			ht_delete_item(ht->ht_items[i]);
		i++;
	}
	free(ht->ht_items);
	free(ht);
}
