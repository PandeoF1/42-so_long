#include "../minilibx/mlx.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

# define event_w 119
# define event_a 97
# define event_s 115
# define event_d 100

int test(int a);
char *ft_strrchr(const char *s, int c);
unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);
int	ft_strcmp(char *s1, char *s2);
int	ft_strlen(char *str);
typedef struct so_long
{
	char	**str;
	int		mult;
	int		max_x;
	int		max_y;
	int		player_x;
	int		player_y;
	int		picture_size;
	int		coin_count;
	int		player_mouv;
	void	*border;
	void	*player;
	void	*exit;
	void	*coin;
	void	*background;
	int		*background_data;
	int		background_bpp;
	int		background_endian;
	void	*mlx;
	void	*mlx_win;
}				so_long;

typedef struct map_check
{
	int		max_x;
	int		max_y;
	int		count_x;
	int		x;
	int		y;
}				map_check;
