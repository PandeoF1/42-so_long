#include <mlx.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int test(int a);

typedef struct so_long
{
    int     max_x;
    int     max_y;
	int		player_x;
	int		player_y;
	int		picture_size;
	void	*border;
	void	*player;
	void	*exit;
	void	*mlx;
	void	*mlx_win;
}				so_long;

typedef struct map_check
{
    int     max_x;
    int     max_y;
	int		count_x;
	int		x;
	int		y;
}				map_check;
