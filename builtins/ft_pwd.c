#include "../minishell.h"

/*
** Ecrire directement le $PWD renvoyé par la fonction getcwd.
** Si $PWD plus long que buffer, l'écrire manuellement après l'avoir 
** récupéré grace à la fonction var_env.
*/

int		ft_pwd(t_cmds cmds)
{
	char	buf[256];
	char	*tmp;

	ft_memset(buf, 0, 256);
	getcwd(buf, 256);
	if (!buf[0] && (tmp = var_env("$PWD")))
		ft_putendl_fd(tmp, 1);
	else
		ft_putendl_fd(buf, 1);
	g_shell.status = 0;
	return (1);
}