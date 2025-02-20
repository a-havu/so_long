/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:43:41 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/13 16:40:19 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_plus.h"

void ft_lstadd_back(t_list **lst, t_list *new_node)
{
    t_list  *last;

    if (!new_node)
        return ;
    if (!*lst)
    {
        *lst = new_node;
        return ;
    }
    last = ft_lstlast(*lst);
    last->next = new_node;
}