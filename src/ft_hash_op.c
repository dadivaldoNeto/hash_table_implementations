/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netomm <netooff@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:18:23 by netomm            #+#    #+#             */
/*   Updated: 2025/01/09 23:12:58 by netomm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_hash_table.h"
#include "ft_lib.h"

int	ft_ht_insert(t_hash_table *ht, char *key, char *value)
{
	t_ht_item	*ht_item;
	int			i;
	int			attempt;
	t_ht_item	*tmp;

	ht_item = ft_ht_new_item(key, value);
	if (!ht_item)
		return (0);
	attempt = 0;
	i = ft_get_hash_code(ht_item->key, attempt, ht->size);
	tmp = ht->ht_items[i];
	while (tmp && ++attempt < ht->size)
	{
		i = ft_get_hash_code(ht_item->key, attempt, ht->size);
		tmp = ht->ht_items[i];
	}
	ht->ht_items[i] = ht_item;
	ht->count++;
	return (1);
}
