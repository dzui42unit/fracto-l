/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:42:50 by dzui              #+#    #+#             */
/*   Updated: 2016/11/28 20:42:51 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	if (lst)
	{
		new = f(ft_lstnew(lst->content, lst->content_size));
		if (lst->next)
			new->next = ft_lstmap(lst->next, f);
		return (new);
	}
	return (NULL);
}
