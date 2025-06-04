/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandemonium <pandemonium@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 23:30:08 by pandemonium       #+#    #+#             */
/*   Updated: 2025/06/04 23:38:32 by pandemonium      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Creates a new token node.
 *
 * @param type The type of the token.
 * @param word The string value of the token.
 * @param shell Pointer to the shell context (used for error handling).
 * @return Pointer to the newly created token node, or NULL on failure.
 */
t_tok	*ft_lstnew_tok(TOK_TYPE type, char *word, t_shell *shell)
{
	t_tok	*new;

	new = malloc(sizeof(t_tok));
	if (new == NULL)
		free_exit(shell);
	new->type = type;
	new->word = word;
	new->next = NULL;
	return (new);
}
/**
 * @brief Returns the last node of a token list.
 *
 * @param lst Pointer to the head of the token list.
 * @return Pointer to the last token in the list, or NULL if the list is empty.
 */
t_tok	*ft_lstlast_tok(t_tok *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/**
 * @brief Adds a new token node at the end of the list.
 *
 * @param token Address of the pointer to the first element of the list.
 * @param new Pointer to the new token node to add.
 */
void	ft_lstadd_back_tok(t_tok **token, t_tok *new)
{
	t_tok	*last;

	if (token == NULL)
		return ;
	if (*token == NULL)
	{
		*token = new;
		return ;
	}
	last = ft_lstlast_tok(*token);
	last->next = new;
}
/**
 * @brief Frees all nodes in a token list and their associated memory.
 *
 * @param lst Pointer to the head of the token list.
 */
void	ft_lstclear_tok(t_tok *lst)
{
	t_tok	*current;
	t_tok	*tmp;

	if (!lst)
		return;
	current = lst;
	while (current)
	{
		tmp = current;
		current = current->next;
		if (tmp->word)
			free(tmp->word);
		free(tmp);
	}
	lst = NULL;
}