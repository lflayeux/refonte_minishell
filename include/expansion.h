/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 22:13:21 by pandemonium       #+#    #+#             */
/*   Updated: 2025/07/13 11:34:47 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

typedef struct s_expand
{
	char	*word;
	char	*new;
	int		quotes;
	int		i;
}			t_expand;

void		dollar_expand(t_expand *expand, t_shell *shell);
void		quotes_expand(t_expand *expand, char sep, t_shell *shell);
void		expanded_one(t_expand *expand, t_shell *shell);
void		expanded_two(t_expand *expand, t_shell *shell);

// =============================
// ========= UTILS =============
// =============================

char		*ft_getenv(char **env, char *word, t_expand *expand,
				t_shell *shell);
void		pid_expand(t_expand *expand, t_shell *shell);
void		error_expand(t_expand *expand, t_shell *shell);
void		base_expand(t_expand *expand, t_shell *shell);
void		var_expand(t_expand *expand, t_shell *shell);
char		*ft_strjoin_free(char const *s1, char const *s2, t_shell *shell);

#endif