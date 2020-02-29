/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/24 10:58:15 by ihering-       #+#    #+#                */
/*   Updated: 2019/12/10 15:24:42 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*res;

	if (!lst)
		return (NULL);
	list = f(lst);
	res = list;
	while (lst->next != NULL)
	{
		lst = lst->next;
		list->next = f(lst);
		if (f(list) == NULL)
			return (NULL);
		list = list->next;
	}
	return (res);
}
