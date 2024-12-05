/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:26:01 by rguigneb          #+#    #+#             */
/*   Updated: 2024/11/07 10:33:39 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

// #include <stdio.h>
// int	main()
// {
// 	char	*str = "Ffqffqfqwfq";
// 	char	*str2 = "2";
// 	char	*str3 = "3";
// 	char	*str4 = "4";
// 	t_list	*my_new_list = ft_lstnew(str2);
// 	t_list	*my_new_list2 = ft_lstnew(str3);
// 	t_list	*my_new_list3 = ft_lstnew(str4);
// 	t_list	*my_pile = ft_lstnew(str);

// 	ft_lstadd_front(&my_pile, my_new_list);
// 	ft_lstadd_front(&my_pile, my_new_list2);
// 	ft_lstadd_front(&my_pile, my_new_list3);

// 	t_list	*last = ft_lstlast(my_pile);
// 	//printf("%s", (char *)my_pile->content);
// 	printf("%s", (char *)last->content);
// 	return (0);
// }
