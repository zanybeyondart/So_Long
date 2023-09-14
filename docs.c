#include <mlx.h>
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	whynots(int keycode, t_vars *vars)
{
	printf("Hello from key_hook! brooooo\n");
	return (0);
}

int color(int keycode, t_vars *add)
{
    int x = 0;
    int y = 0;
    static int i;
    int colors[3] = {0xFF0000, 0x00FF00, 0x0000FF};
    if (keycode == 15 && i != 20)
    {
        x = 350;
        y = 350;
        while(x < 450)
        {
            while(y < 450)
            {
            mlx_pixel_put(add->mlx, add->win, x, y, colors[0]);
            i = 20;
            y++;
            }
        y = 350;
        x++;
        }
    }
      if (keycode == 5 && i != 30)
        {
        x = 350;
        y = 350;

        while(x < 450)
            {
            while(y < 450)
            {
                mlx_pixel_put(add->mlx, add->win, x, y, colors[1]);
                i = 30;
                y++;
            }
            y = 350;
            x++;
            }
        }

        if (keycode == 11 && i != 40)
        {
                x = 350;
                y = 350;
            while(x < 450)
            {
                while(y < 450)
                {
                mlx_pixel_put(add->mlx, add->win, x, y, colors[2]);
                i = 40;
                y++;
                }
            y = 350;
            x++;
            }
        }
    return(0);
    }

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_key_hook(vars.win, whynots, &vars);
    mlx_hook(vars.win,2,0,color, &vars);
	mlx_loop(vars.mlx);
}