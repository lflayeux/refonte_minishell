/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflayeux <lflayeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:22:33 by lflayeux          #+#    #+#             */
/*   Updated: 2025/07/13 16:19:54 by lflayeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	exec_exit(t_exec *exec, int i, int flag, t_shell *shell)
{
	int	error;

	printf("exit\n");
	if (exec->cmd[i + 1] && exec->cmd[i + 2])
		return (printf("minishell: exit: too many arguments\n"), GEN_ERR);
	else if (exec->cmd[i + 1])
	{
		error = ft_atoi(exec->cmd[1]);
		error = error & 0xFF;
		if (error > 255 && flag == 0)
			return (GEN_ERR);
		else if (error > 255 && flag == 1)
			return (free_all(shell), exit(1), GEN_ERR);
		else if (flag == 0)
			return (error);
		else
			return (free_all(shell), exit(error), GEN_ERR);
	}
	else if (flag == 1)
		return (free_all(shell), exit(0), SUCCESS);
	return (SUCCESS);
}
