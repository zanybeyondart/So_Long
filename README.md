![DINO WARS](https://github.com/zanybeyondart/ReadMeEditor/assets/124681155/c7f8cbe5-66b0-41c0-8a3e-ed38c4e23a23)

### Table of Contents

#### [Dino Wars](https://github.com/zanybeyondart/So_Long#dino-wars-1)
- [Gameplay and Graphics](https://github.com/zanybeyondart/So_Long#gameplay-and-graphics)
- [Game Logic](https://github.com/zanybeyondart/So_Long#game-logic)
- [Updates and Development](https://github.com/zanybeyondart/So_Long#updates-and-development)
- [Installing](https://github.com/zanybeyondart/So_Long#installing)

#### [So_Long](https://github.com/zanybeyondart/So_Long#so_long-guide)
- [Understanding MiniLibX](https://github.com/zanybeyondart/So_Long#understanding-minilibx)
  - [Getting Started](https://github.com/zanybeyondart/So_Long#getting-started)
    - [Pixel Put Project](https://github.com/zanybeyondart/So_Long#pixelput-project-understanding-graphics)
  - [Loops and Hooks](https://github.com/zanybeyondart/So_Long#loops-hooks-and-events)
    - [Loop](https://github.com/zanybeyondart/So_Long#loops)
    - [Hook](https://github.com/zanybeyondart/So_Long#hooks)
    - [Events](https://github.com/zanybeyondart/So_Long#events)
  - [Integrating Inputs](https://github.com/zanybeyondart/So_Long#integrating-inputs)
    - [Mlx_Hook](https://github.com/zanybeyondart/So_Long#mlx_hook-mlx-win-key-mask-function-parameter)
  - [Examples](https://github.com/zanybeyondart/So_Long#examples)
    - [Quitting the Program](https://github.com/zanybeyondart/So_Long#quitting-the-program)
    - [Moving Box with Arrow Key](https://github.com/zanybeyondart/So_Long#moving-box-using-keys)
  - [mlx_clear_window() & mlx_do_sync()](https://github.com/zanybeyondart/So_Long#mlx_clear_window--mlx_do_sync)
  - [Concluding Your First Program](https://github.com/zanybeyondart/So_Long#concluding-your-first-program)
- [Understanding Textures and Sprites](https://github.com/zanybeyondart/So_Long#understanding-textures--sprites)
  - [How to Create Perfect Textures and Sprites](https://github.com/zanybeyondart/So_Long#how-to-create-perfect-textures-and-sprites)
- [Importing and Rendering Textures in MLX](https://github.com/zanybeyondart/So_Long#importing-and-rendering-textures-in-mlx)
  - [Program 2.0](https://github.com/zanybeyondart/So_Long#program-20)
- [Collision and Hit Boxes](https://github.com/zanybeyondart/So_Long#collisions-and-hit-boxes)
  - [Understanding Your Resources](https://github.com/zanybeyondart/So_Long#understanding-your-resources)
  - [Tips and Tricks](https://github.com/zanybeyondart/So_Long#tips-and-tricks)
- [Animation](https://github.com/zanybeyondart/So_Long#animation)
  - [Pseudo Code](https://github.com/zanybeyondart/So_Long#pseudo-code)

#### [Conclusion](https://github.com/zanybeyondart/So_Long#conclusion-1)


# Dino Wars
Dino Wars is a game produced by me for my So_Long project at 42, Abu Dhabi. This project is a very small 2D game.
Its purpose is to make you work with textures, sprites,
and some other very basic gameplay elements.


![Main Menu](https://github.com/zanybeyondart/So_Long/blob/main/README/MainMenu.gif)
![Tutorial Screen](https://github.com/zanybeyondart/So_Long/blob/main/README/Tutorial.gif)
![Win Gameplay](https://github.com/zanybeyondart/So_Long/blob/main/README/WinSeq.gif)
![Lose Gameplay](https://github.com/zanybeyondart/So_Long/blob/main/README/LoseSeq.gif)
![Easter Egg](https://github.com/zanybeyondart/So_Long/blob/main/README/EasterEggSeq.gif)

### Gameplay and Graphics

https://github.com/zanybeyondart/ReadMeEditor/assets/124681155/865f49e6-871e-4500-aafb-df2e4c83bfdd

![ezgif com-video-to-gif](https://github.com/zanybeyondart/ReadMeEditor/assets/124681155/4384493e-fee9-4787-9a2a-91a0ba3a86a2)

### Game Logic
[Figma Mind Map](https://www.figma.com/file/Rq69CTnHRQ8VZoos8HVUzj/Untitled?type=whiteboard&node-id=0%3A1&t=cnrDCpPZuBIyaW4a-1)

You can have a look into how the game logic works and also contribute to make it more efficient but leaving sticky notes


### Updates and Development

[Dino Wars Repository](), will be the main repo for this games development and updates. This repository is specifically for the project So_long.

### Installing

Clone the repository, make a bonus, and then run the executable file with the choice of your map in /map folder.




```bash
  cd so_long
  make bonus
  ./so_long_bonus ./map/map1_bonus.ber
```

# So_Long Guide
In this guide, I will be mainly focusing on creating the game logic, animations and how you can achieve anything using MiniLibX

## Understanding MiniLibX
The best place to start would be [MiniLibX Docs](https://harm-smits.github.io/42docs/libs/minilibx), It can be very intimidating at first, but believe me, this tool is a wonder!

Refer to the following sections while going through the **MiniLibX Docs**


 

### Getting Started

* Create a new C program and try initializing MLX and a window

* The part where you create a new image using **mlx_new_image()** is not necessary, as per my experience you will never be using it. Instead use **mlx_pixel_put()** to understand how you have control over the MLX window

* Concepts of **colors, little endian, and big-endian** were also not used in my project, only initial testing and understanding of MLX involved **colors**.

* Your key takeaway from the Getting Started page of MiniLibX would be to successfully understand the initialization of MLX and how you can control the graphics

#### Pixelput Project (Understanding Graphics)
This project will give you a very simple and easy idea about how you render images onto the MLX Window

The MLX window assigns the position of each pixel using the X and Y positions starting from the top left corner

![ACCESSING_PIXELS](https://github.com/zanybeyondart/ReadMeEditor/assets/124681155/d27d2864-e593-43fe-9bd7-a8ceac5a68b8)


    void render_square(void)
    {
	    int x;
	    int y;

        x = 350;
        y = 350;
        while (x < 450)
        {
            while(y < 450)
            {
            mlx_pixel_put(mlx, win, x, y, color);
            y++;
            }
        y = 350;
        x++;
        }
    }

The above code simply goes through a loop and renders 1 pixel every time with different X and Y positions, resulting in a simple square in your Window 

![Render_Square](https://github.com/zanybeyondart/ReadMeEditor/assets/124681155/7b7512d9-6dfe-4ae4-8caa-9bfe489ff486)


Now that you're aware of how you have access to each and every pixel in your window let's go ahead and see how you can interact with your window

*The next section in the MiniLibX Docs about color will not be used, however it's your choice to experiment on that, but I would suggest not spending a lot of time on that section*


### Loops, Hooks and Events

#### Loops
Loop refers to the infinite loop that goes on infinitely throughout your program. **mlx_loop()** is the perfect example, it keeps your program running infinitely unless **exit()** is initiated  

#### Hooks 
Hooks look for the input that you pass through the program, through your mouse or keyboard. MiniLibx has different functions for each input device. However, the best way would be to use **mlx_hook()** and then assign events as per the prototype. You'll learn about this more in a while.

#### Events

Events are just the input event that happens, refer to the table below for more information

### Integrating inputs

Integrating inputs are little tricky, there are certain rules you have to go through

#### mlx_hook (mlx, win, key, mask, function, parameter)

The above is a simplified prototype of **mlx_hook**
* **Mlx and win** refer to the pointers

* **Key** refers to the input key that you want your program to be looking for (refer to the table below)

* **Mask** refers to the key mask (not important, you can learn about this in the end)

* **Function** refers to the function you want to call when the key is pressed, **your function prototype should match the prototype of the corresponding key** (refer to the table below)

* **Parameter** is the parameter you will be passing to the **Function** that is called.

If you notice the prototype column in the table below, the ***param** is the same parameter that is passed from **mlx_hook** to the function that is called.


| Key | Event      | Prototype |
| :--:| :-------:  | :---: |
| 2   | Key press   | int (*f)(int keycode, void *param) |
| 3   | Key release | 	int (*f)(int keycode, void *param) |
|4||Mouse Click| int (*f)(int button, int x, int y, void *param)|
|5| Mouse Release |int (*f)(int button, int x, int y, void *param)|
|6| Moving Mouse |int (*f)(int x, int y, void *param)|

This table is a mini version of the one you see on MinilibX, these are the ones that are good to start with and then you can progress with more advanced keys depending on your project

### Examples

#### Quitting the program

This example elaborates on how you can integrate **ESC** to quit your program 

The header defines the keycode that your function will be looking for to quit the game

It's important to use a struct that has all the variables that you use in your program as you can only pass one parameter through your functions


    #define ESC = 53     (Defining the keycode of ESC)

    typedef struct s_vars{
        void    *mlx;
        void    *win;
    }t_vars;
_________________________________________________

The main function starts with initializing mlx and a window, we set the **mlx_hook()** to look for buttons pressed by passing the key as **2** (refer to the event table) and mask 0 as we won't be needing that

We pass the **quit()** function as per the **prototype** (refer event table) with the parameter as **vars**

It's very important to dynamically allocate memory using **malloc** and initializing all your variables regardless of memory allocation as you are working with **structs** and **lists**, you'll learn about it as we go ahead


    
    int main()
    {
        t_vars  *vars;

        vars = NULL;
        vars = malloc(sizeof(t_vars));

	    vars->mlx = mlx_init();
	    vars->win = mlx_new_window(vars->mlx, 1920 , 1080 , "HELLO");

        mlx_hook(vars->win, 2, 0, quit, vars);
        mlx_loop(vars->mlx);
    }


___
When any button is pressed quit function initiates, but unless the key is **ESC** it won't quit

    int quit(int keycode, t_vars *vars)
        {
            if (keycode == ESC)
            {
                mlx_destroy_window(vars->mlx, vars->win);
                free(vars);
                exit();
            }
        }


The above code should stop the program and exit whenever **ESC** is pressed

#### Moving box using keys

Remember how we created a square box using **mlx_pixel_put()**, lets move the box using the same logic of keys


Let's add some more variables for the position of our square into our struct, and define some more macros for movement buttons

    #define ESC     53
    #define W       13
    #define A	    0
    #define S	    1
    #define D	    2

    typedef struct s_vars{
        void    *mlx;
        void    *win;
        int     box_x;
        int     box_y;
    }t_vars;
___

Let's use the render function for square, but this time with **x + vars->box_x** and **y + vars->box_y** in x and y for **mlx_pixel_put()**

    int render_square(t_vars *vars)
    {
	    int x;
	    int y;

        x = 350;
        y = 350;
        while(x < 450)
        {
            while(y < 450)
            {
            mlx_pixel_put(vars->mlx, vars->win, x + vars->box_x, y + vars->box_y, 0xFFDDFF);
            y++;
            }
        y = 350;
        x++;
        }
	    return(1);
    }

___

Let's change our quit function to a keys function and add movement keys to it too, every time you press any movement keys, it changes its position by 10 pixels

    int keys(int keycode, t_vars *vars)
        {
            if (keycode == ESC)
            {
                mlx_destroy_window(vars->mlx, vars->win);
                free(vars);
                exit();
            }
            if (keycode == W)
                vars->box_y -= 10;
            if (keycode == A)
                vars->box_x -= 10;
            if (keycode == S)
                vars->box_y += 10;
            if (keycode == D)
                vars->box_x += 10;
        }

___

We'll add **mlx_loop_hook()** for our render function, it will infinitely call our render function, while at the same time keeping in account the position of our box using **box_x** and **box_y**

    int main()
    {
        t_vars  *vars;

        vars = NULL;
        vars = malloc(sizeof(t_vars));

        vars->box_x = 0;
        vars->box_y = 0;

	    vars->mlx = mlx_init();
	    vars->win = mlx_new_window(vars->mlx, 1920 , 1080 , "HELLO");

        mlx_loop_hook(vars->mlx, render_square, vars);
        mlx_hook(vars->win, 2, 0, keys, vars);
        mlx_loop(vars->mlx);
    }
___


Now when you run your program you should be able to move the box, but you'll see a very weird result where the box leaves a trail, and it looks like you're just painting your screen 

![TRAIL PROBLEM](https://github.com/zanybeyondart/ReadMeEditor/assets/124681155/7b1a61ab-f6ad-42b5-83f5-9dffd9ea9b2b)


In fact what we want this

![FIXED](https://github.com/zanybeyondart/ReadMeEditor/assets/124681155/fb0e8f44-2364-425c-8e7a-799656909403)


### mlx_clear_window() & mlx_do_sync()

To fix the trial effect, we simply use these two functions which literally do what they say

**mlx_clear_window()**: Clears the window back to nothing, just a black screen.

**mlx_do_sync()**: Syncs all the new rendered pixels that are put after rendering, like a refresh button

Just adding **mlx_clear_window()** before we start to render the pixels and then **mlx_do_sync()** after we finish the render should fix it for us 

    int render_square(d_vars *vars)
    {
	    int x;
	    int y;

        x = 350;
        y = 350;
	    mlx_clear_window(vars->mlx, vars->win);
        while(x < 450)
        {
            while(y < 450)
            {
            mlx_pixel_put(vars->mlx, vars->win, x + vars->x, y + vars->y, 0xFFDDFF);
            y++;
        }
        y = 350;
        x++;
        }
	    mlx_do_sync(vars->mlx);
	    return(1);
    }



### Concluding your first program
Congratulations, you successfully have a functional mini-game. Just with these concepts, you can create a full-fledged game like **Dino Wars**.

Furthermore, in this guide, I will be going through how to work with your own textures and then how you can master animation

**Some key points to remember from this exercise**
* It is important to work with structures when it comes to MLX or Game as it gives you too much flexibility

* Keep track of each and every memory, and initialize every variable in your structures, further on in this guide you will see how we will be connecting different structs and linked lists to each other, in this case, its really important to start the habit of this concept from the base itself

## Understanding Textures & Sprites

A key feature of a dope game is graphics, it's really important to understand how graphics work and how you can use it to your advantage creatively and make **GAME OF THE YEAR!!!!!**

**Textures** are basically images that you use for your game, **Sprites** are a set of textures that together when sequentially displayed look like a video or animation

| Texture | Sprite (set of textures) |
| :----: | :----: |
|![2](https://github.com/zanybeyondart/ReadMeEditor/assets/124681155/3bdb48af-2571-4d70-a891-9799a5db90b9) | ![ALL](https://github.com/zanybeyondart/ReadMeEditor/assets/124681155/672db2c1-0039-429c-8840-59e638d5c617)|

### How to create perfect textures and Sprites?

You can find textures online from websites such as [itch.io](https://www.itch.io), you can download textures that you like and then use softwares such as Photoshop or [Photopea](https://www.photopea.com/) (Free and Online alternative for Photoshop) to edit your textures 

Ideally, we would be going for creating PNGs so that we can convert them to XPM later on and use them in our game

#### Make sure your texture size does not have white spaces: 

| Right | Wrong |
| :----: | :----: |
|<img width="200" alt="Screenshot_1" src="https://github.com/zanybeyondart/ReadMeEditor/assets/124681155/3a2677db-5ce7-4007-9f78-94f67399bded">|<img width="200" alt="Screenshot_2" src="https://github.com/zanybeyondart/ReadMeEditor/assets/124681155/0ce2d99b-0757-476d-8f21-b3b4aa74d7b5">|

It's important to make sure that your texture size does not have extra white spaces as it will mess around with the hitbox/collision boundary of your object

#### Proper organization for Sprites

When creating sprites it is important that each of your textures is aligned and organized properly with numbering starting from 0

I personally organize it as **/player_idle_r/0.png** 

This might look intimidating and time-consuming but it is very important, better to do it the right way or not do it at all

#### Preparing your textures for MLX

MLX takes in **PNG** as well as **XPM** as input format for texture input. However, using PNG is unstable in MiniLibX, so we convert out textures from PNG to XPM. Use [ImageMagick](https://imagemagick.org/index.php) for this, it is a opensource and perfect tool for this project
## Importing and Rendering Textures in MLX

Now that you have prepared your texture in **XPM** format for MLX, let's go ahead and import it to your program and then render it in your window 


### Program 2.0

We add another **struct** and link it to our **main struct**, you'll see further why we link it to the main struct

**void** ***img**: is the pointer to the image that is passed to render on the screen

**int w & int h**: refers to the  width and height of the image that we pass. This is used to calculate the hitbox or collision boundary of your objects

**int x & int y**: refers to the x and y position of the object that you will be working on width

**struct s_obj** ***next**: is a linked list for linking your sprite and animating 

    #define ESC     53
    #define W       13
    #define A	    0
    #define S	    1
    #define D	    2

    typedef struct s_obj{
        void *img;
        int w;
        int h;
        int x;
        int y;
        struct s_obj *next;
    }t_obj;

    typedef struct s_vars{
        void    *mlx;
        void    *win;
        t_obj   *car;
    }t_vars;



___


We allocate memory for our **Car** and then load the texture to its ***img** using **mlx_xpm_file_to_image()**

**mlx_xpm_file_to_image()** take ***mlx**, path to your texture, address to store w and h of your image, car->w & car->h in our case 



    int main()
    {
        t_vars  *vars;

        vars = NULL;
        vars = malloc(sizeof(t_vars));

        vars->car = malloc(sizeof(t_obj));
        vars->car->x = 0;
        vars->car->y = 0;
        vars->car->next = NULL;
        vars->car->img = mlx_xpm_file_to_image(vars->mlx, "./texture.xpm", &vars->car->w, &vars->car->h);


	    vars->mlx = mlx_init();
	    vars->win = mlx_new_window(vars->mlx, 1920 , 1080 , "HELLO");

        mlx_loop_hook(vars->mlx, render_car, vars);
        mlx_hook(vars->win, 2, 0, keys, vars);
        mlx_loop(vars->mlx);
    }

____

We change our function to **render_car** and use the ***img** along with the **X** and **Y** position from the object 

    int render_car(b_vars *vars)
    {
	    int x;
	    int y;

        x = 350;
        y = 350;
	    mlx_clear_window(vars->mlx, vars->win);
        while(x < 450)
        {
            while(y < 450)
            {
            mlx_put_image_to_window(vars->mlx, vars->win, vars->car->img, vars->car->x, vars->car->y);
            }
            y++;
            }
        y = 350;
        x++;
        }
	    mlx_do_sync(vars->mlx);
	    return(1);
    }




## Collisions and Hit Boxes

Now that you are successfully able to put an object inside your game and control it, it is time to understand how you can make it interact with other objects inside your game

### Understanding your resources

The object struct that we created has everything you need to make it interact with other things

Let's assume we have two objects **Car** and **Wall** and you don't want the car to move right through the Wall

![ezgif com-video-to-gif (7)](https://github.com/zanybeyondart/ReadMeEditor/assets/124681155/98d3c6a0-1e9d-489a-9e19-e522a037203b)


You have to calculate that the next move is only valid if the Car does not overlap with the Wall

To calculate need to see that the start and the end of the **Car** i.e **car->x** and **car->x + car->w** do not fall under the range of **wall->x** and **wall->x + wall->w**. 

**BUT** the above condition should only be valid when **car->y** and **car->y + car->h** does not fall in the range of **wall->y and wall->y + wall->h**

<img src="https://github.com/zanybeyondart/ReadMeEditor/assets/124681155/e7ea41f0-f928-4a3c-b232-499a8806eeb7" width="600"/>


This was a simple way of how just using these 4 variables you can control any collision, event, or automated movements

### Tips and tricks 

* Refer to **lim()**, **wall_bound()**, and similar functions in **/src** to see how you can efficiently with the same pattern handle different types of interactions between objects

* I have created a separate struct in my game which runs through a function and returns the boundaries that need to be calculated 


This is how it looks

    typedef struct s_box
    {
	    int	m_min; \\ Moving axis of the object || Start point of the Object
	    int	m_max; \\ m_min + (w || h) || End point of the object
	    int	m_bd; \\ Boundry of the collision object (col->w || col->h)
	    int	bd; \\ Inverted bd
	    int	min; \\ Inverted m_min [Constant Min]
	    int	max; \\ Inverted m_max [Constant Max]
    }t_box;

The **m_** is for the axis that is moving, everything in that will be correlated. If the moving axis is **X** then we go for the **W**, similarly if **Y** we go for **H**

Inverted is the other axis which will be constant. This is quite a complicated algorithm that I came up with, try coming up with your own efficient way, that way you will be able to have full control over everything


## Animation

Now comes the part that makes your game look alive, animation is fairly a easy concept but can be very tricky

Let's say your sprite has 4 textures, you load the animation to a linked list which has all the textures on individual nodes linked ending at **NULL**

Every time you call **mlx_put_image_to_window()** you just keep returning the next node's image and it keeps the animation happening

You will have to use **usleep()** in order to give a slight delay in between every animated frame to make the animation visible 

### Pseudo Code

    Main render function
    {
        animation node temp = next_node(frame, linkedlist_sprite)
        mlx_put_image_to_window(temp->image)
    }

    next_node function 
    {
        static int i;
        sprite temp;

        temp = linkedlist_sprite

        if(i >= frames)
        i = 0
        
        else
        i++;

        return(helperfunction(i, temp))
    }

    Helper function
    {
       while (i < frame)
       {
		temp = temp->next;
		i++;
       }

       return(temp); 
    }


Now every time you render this in **mlx_loop_hook()** it will give you a new and different animation

## Conclusion

This guide should get you ready to produce a perfectly fine game, take your time, enjoy the project, and push your creative limits !!!

You can reach out to me if you need any help at zvakil@student.42abudhabi.ae

Thank you for going through the guide, don't forget to give it a star if you liked it! and All the best with your project!
