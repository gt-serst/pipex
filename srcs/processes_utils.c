#include "../includes/pipex.h"

char	*ft_check_if_path_exists(char *command)
{
	if (access(command, 0) == 0)
		return (command);
	return (NULL);
}
