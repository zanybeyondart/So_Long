#include <mlx.h>
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	whynots(int keycode)
{
    printf("Key Pressed! : %d \n", keycode);
    return (0);
}

int color(int keycode, t_vars *add)
{
    int x = 0;
    int y = 0;
    static int px;
    static int py;
    static int i;

    if (keycode == 13)
    py -= 10;
    if (keycode == 1)
    py += 10;
    if (keycode == 0)
    px -= 10; 
    if (keycode == 2)
    px += 10;  
    int colors[3] = {0xFF0000, 0x00FF00, 0x0000FF};
    if (keycode == 15 || (i == 20 && (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)))
    {
		mlx_clear_window(add->mlx, add->win);
        x = 350 + px;
        y = 350 + py;
        while(x < 450 + px)
        {
            while(y < 450 + py)
            {
            mlx_pixel_put(add->mlx, add->win, x, y, colors[0]);
            i = 20;
            y++;
            }
        y = 350 + py;
        x++;
        }
    }
      if (keycode == 5 || (i == 30 && (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)))
        {
		mlx_clear_window(add->mlx, add->win);
        x = 350 + px;
        y = 350 + py;

        while(x < 450 + px)
            {
            while(y < 450 + py)
            {
                mlx_pixel_put(add->mlx, add->win, x, y, colors[1]);
                i = 30;
                y++;
            }
            y = 350 + py;
            x++;
            }
        }

        if (keycode == 11 || (i == 40 && (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)))
        {
				mlx_clear_window(add->mlx, add->win);
                x = 350 + px;
                y = 350 + py;
            while(x < 450 + px)
            {
                while(y < 450 + py)
                {
                mlx_pixel_put(add->mlx, add->win, x, y, colors[2]);
                i = 40;
                y++;
                }
            y = 350 + py;
            x++;
            }
        }
    }

int main(void)
{
    t_vars  vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 640, 480, "HELLO");
    mlx_key_hook(vars.win, whynots, &vars);
    mlx_hook(vars.win,2,0,color, &vars);
    mlx_loop(vars.mlx);
}