/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:26:01 by rguigneb          #+#    #+#             */
/*   Updated: 2024/11/07 10:33:39 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}

// #include <stdio.h>
// int	main()
// {
// 	char	*str = "Ffqffqfqwfq";
// 	char	*str2 = "2";
// 	t_list	*my_new_list = ft_lstnew(str2);
// 	t_list	*my_pile = ft_lstnew(str);

// 	ft_lstadd_front(&my_pile, my_new_list);
// 	printf("%s", (char *)my_pile->content);
// 	return (0);
// }
