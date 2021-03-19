#include "include.h"

void	print_split_l(char **line_s)
{
	int	y;

	y = 0;
	while (line_s[y])
	{
		printf("%s\n", line_s[y]);
		y++;
	}
}
