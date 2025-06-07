/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflayeux <lflayeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:41:38 by pandemonium       #+#    #+#             */
/*   Updated: 2025/06/07 18:28:12 by lflayeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// ==============================================
// ================== LIBRARIES =================
// ==============================================

# include "../libft/libft.h"
# include "struct.h"
# include "error.h"
# include "signals.h"
# include "tokenization.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <fcntl.h>

// ==============================================
// ================== PROMPT ====================
// ==============================================

# define PROMPT GOLD "🦾 miniboss 🦾 > " RST

// ==============================================
// ================== COLORS ====================
// ==============================================

# define RED "\033[31m"
# define CYAN "\033[36m"
# define RST "\033[0m"
# define YLW "\033[33m"
# define GRN "\033[32m"
# define GOLD "\033[38;5;220m"

// ==============================================
// =================  EXPAND ====================
// ==============================================

void	expand(t_shell *shell);

// ==============================================
// ==================  UTILS ====================
// ==============================================

void	init_shell(t_shell *shell, char **envp);
int		ft_get_env(char **env, char *to_check);
void	reset_shell(t_shell *shell);
void	free_all(t_shell *shell);

#endif