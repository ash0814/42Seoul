#include "header.h"

int	input_map_info(char *entries, t_info *info)
{
	if (entries[0] < 4) 
		return (-1);
	info.empty = entries[0][len - 3];
	info.obstacle = entries[0][len - 2];
	info.fill = entries[0][len - 1];
	info.height = ft_n_atoi(entries[0][0], len - 3)
	return (validate(entries, info));
}

int valiadate(char *entries, t_info *info)
{
	if (is_printable(info.empty) != 0 ||
		is_printable(info.obstacle) != 0) ||
		is_printable(info.fill) != 0)
		return (-1);
	else if (info.empty == info.obstacle ||
			info.obstacle == info.fill ||
			info.fill == info.empty)
		return (-1);
	else if (info.height - 1 != sizeof(entries))
		return (-1);
	else if (info.height == 0)
		return (-1);
	return (0);
}