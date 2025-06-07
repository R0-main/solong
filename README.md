# Solong (Isometric Edition)

Solong is a small 2D adventure game built in C using the MinilibX (MLX) library. It features:
- Tile-based map rendering
- Player movement and animation
- Collectibles (coins)
- Enemies with simple AI
- Step counter displayed using texture-based digits

![screenshot](images/showcase.gif)

## Table of Contents

- [Features](#features)
- [Dependencies](#dependencies)
- [Building](#building)
- [Running](#running)
- [Project Structure](#project-structure)
- [Texture Management](#texture-management)
- [Animation Management](#animation-management)
- [Code Examples](#code-examples)
- [License](#license)

## Features

- Load `.ber` map files with walls, floor tiles, coins, enemies, exit
- Render map and entities using MLX textures
- Track and display player's steps as a score
- Simple enemy pathfinding and movement
- Clean resource loading and unloading

## Dependencies

- [MinilibX](https://github.com/42Paris/minilibx-linux)  
- Standard C libraries: `libft`, `ft_printf`, `get_next_line`

## Building

```bash
git clone https://github.com/R0-main/solong.git
cd solong
make
```

This compiles the executable `so_long`.

## Running

```bash
./so_long path/to/map.ber
```

- If no argument or too many arguments are given, the game will exit with an error.
- Map file must have the `.ber` extension.

## Project Structure

```
.
├── assets/                # XPM images for tiles, player, coins, fonts
├── includes/
│   ├── animations.h
│   ├── entities.h
│   ├── game.h
│   ├── rendering.h
│   ├── textures.h
│   └── utils.h
├── src/
│   ├── game/              # Game logic, map parsing, entities, score
│   ├── mlx_wrapper/       # MLX wrappers: textures & animations loaders
│   ├── dependencies/      # libft, ft_printf, get_next_line
│   └── main.c
└── Makefile
```

## Texture Management

All textures are stored in an atlas and referenced by enum IDs.  
In `includes/textures.h`:

```c
#define MAX_TEXTURES 256

typedef struct s_texture
{
    t_img      *img;
    t_img_data img_data;
} t_texture;

typedef enum e_textures
{
    PLAYER_TEXTURE_TOP,
    PLAYER_TEXTURE_BOTTOM,
    PLAYER_TEXTURE_LEFT,
    PLAYER_TEXTURE_RIGHT,
    TILE_TEXTURE,
    COIN_TEXTURE,
    ENEMY_TEXTURE,
    EXIT_OPEN_TEXTURE,
    EXIT_CLOSE_TEXTURE,
    FONT_ZERO_TEXTURE,
    // ...
    FONT_NINE_TEXTURE,
} t_textures_definition;

t_texture get_texture(int id);
void     load_assets(void *mlx);
void     unload_assets(void *mlx);
```

To load all assets at startup:

```c
void load_assets(void *mlx)
{
    load_texture(mlx, "assets/player-bottom.xpm", PLAYER_TEXTURE_BOTTOM);
    load_texture(mlx, "assets/player-up.xpm",     PLAYER_TEXTURE_TOP);
    load_texture(mlx, "assets/tile.xpm",          TILE_TEXTURE);
    load_texture(mlx, "assets/coin.xpm",          COIN_TEXTURE);
    // load font digits 0–9, exit flags, enemy...
}
```

Retrieve a texture during rendering:

```c
t_texture tile = get_texture(TILE_TEXTURE);
render_asset(game, tile, (t_vec2){x * TILE_X, y * TILE_Y});
```

## Animation Management

Animations use a similar atlas of frames. In `includes/animations.h`:

```c
typedef enum e_animations { COIN_ANIMATION } t_animation_id;

bool load_animation(void *mlx, const char *path, int id,
    t_animation_parameters params);
void load_animations(void *mlx);
void unload_animations(void *mlx);
```

Load the coin animation:

```c
void load_animations(void *mlx)
{
    load_animation(mlx,
        "./assets/coin.xpm",
        COIN_ANIMATION,
        (t_animation_parameters){ .frame_length = {25, 24},
                                 .speed        = 12,
                                 .frames_count = 8 });
}
```

Render frames in your game loop:

```c
render_animation(game,
    get_animation_first_frame(COIN_ANIMATION), position);
```

## Code Examples

### Main Loop (src/main.c)

```c
int main(int ac, char **av)
{
    if (ac != 2)
        exit_error("Usage: ./so_long map.ber");
    if (!endswith(av[1], ".ber"))
        exit_error("Map file must end with .ber");
    parse_map(av[1]);

    void   *mlx = mlx_init();
    t_mlx  *vars = get_mlx_vars();
    vars->mlx = mlx;
    vars->win = mlx_new_window(mlx, WIDTH, HEIGHT, "So Long");

    load_assets(vars);
    load_animations(vars);
    init_mlx_hooks(vars);
    mlx_loop(mlx);
}
```

### Rendering a Map Tile (src/rendering.c)

```c
void draw_map(t_game *game)
{
    for (int y = 0; y < game->map->height; y++)
        for (int x = 0; x < game->map->width; x++)
        {
            t_texture tile = get_texture(TILE_TEXTURE);
            render_asset(game,
                         tile,
                         (t_vec2){x * TILE_X, y * TILE_Y});
            // draw coins, walls, exit, etc.
        }
}
```

### Displaying Score (src/game/score/score.c)

```c
void write_score_on_screen(t_game *game)
{
    unsigned long score = game->steps_made;
    t_texture nums[10];
    set_numbers_textures(nums);  // maps 0–9 textures

    int offset = 0;
    if (score == 0)
        render_asset(game,
                     nums[0],
                     (t_vec2){WIDTH - nums[0].img->width,
                              HEIGHT - nums[0].img->height});
    while (score)
    {
        int digit = score % 10;
        render_asset(game,
                     nums[digit],
                     (t_vec2){WIDTH - nums[digit].img->width - offset,
                              HEIGHT - nums[digit].img->height});
        score /= 10;
        offset += nums[digit].img->width;
    }
}
```

## License

This project is released under [MIT](LICENSE).
