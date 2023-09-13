#include <mlx.h>
#include <stdio.h>

typedef struct s_ptrs
{
    void    *mlx_ptr;
    void    *win_ptr;
} t_game;

int color(int keycode, t_game *add)
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
            mlx_pixel_put(add->mlx_ptr, add->win_ptr, x, y, colors[0]);
            i = 20;
            printf("rd\n");
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
                mlx_pixel_put(add->mlx_ptr, add->win_ptr, x, y, colors[1]);
                i = 30;
            printf("gr\n");
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
                mlx_pixel_put(add->mlx_ptr, add->win_ptr, x, y, colors[2]);
                i = 40;
            printf("bl\n");
                y++;
                }
            y = 350;
            x++;
            }
        }
    return(0);
    }

int main()
{
    t_game  add;
    add.mlx_ptr = mlx_init();
    add.win_ptr = mlx_new_window(add.mlx_ptr, 800, 800, "TEST");
    mlx_hook(add.win_ptr,2,0,color, &add);
    mlx_loop(add.mlx_ptr);
    return(0);
}