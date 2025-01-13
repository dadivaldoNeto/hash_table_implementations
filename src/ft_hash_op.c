/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netomm <netooff@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:18:23 by netomm            #+#    #+#             */
/*   Updated: 2025/01/11 23:52:14 by netomm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_hash_table.h"
#include "ft_lib.h"

#define HT_DELE_ITEM {}

void	ft_ht_insert(t_hash_table *ht, char *key, char *value)
{
	t_ht_item	*ht_item;
	int			i;
	int			attempt;
	t_ht_item	*tmp;

	ht_item = ft_ht_new_item(key, value);
	if (!ht_item)
		return ;
	attempt = 0;
	i = ft_get_hash_code(ht_item->key, attempt, ht->size);
	tmp = ht->ht_items[i];
	while (tmp)
	{
		i = ft_get_hash_code(ht_item->key, attempt, ht->size);
		tmp = ht->ht_items[i];
	}
	ht->ht_items[i] = ht_item;
	ht->count++;
}

char	*ft_ht_search(t_hash_table *ht, char *key)
{
	t_ht_item	*tmp;
	int		i;
	int		index;

	i = 0;
	index = ft_get_hash_code(key, i++, ht->size);
	tmp = ht->ht_items[index];
	while (tmp)
	{
		if (!ft_strcmp(key, tmp->key))
			return (ht->ht_items[index]->value);
		index = ft_get_hash_code(key, i++, ht->size);
		tmp = ht->ht_items[index];
	}
	return (NULL);
}

void	ft_delete(t_hash_table *ht, char *key)
{
	int		index;
	int		i;
	t_ht_item	*item;

	i = 0;
	index = ft_get_hash_code(key, i++, ht->size);
	item = ht->ht_items[index];
	while (item)
	{
		if (!ft_strcmp(key, item->key))
		{
			ft_ht_delete_item(item);
			ht->ht_items[index] = NULL;
			ht->count--;
			return ;
		}
		index = ft_get_hash_code(key, i++, ht->size);	
		item = ht->ht_items[index];
	}
}
