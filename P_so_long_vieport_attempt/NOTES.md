MLX42 functions:

mlx_init()	Initialize and run a new window instance.
mlx_loop()	Keep the window open as long as a shutdown is not requested.
mlx_terminate()	Destroy and clean up all images and mlx resources.

```c
// Creates a whole new image.
mlx_image_t* mlx_new_image(mlx_t* mlx, uint16_t width, uint16_t height)
```

```c
// Creates a new instance/copy of an already existing image.
void mlx_image_to_window(mlx_image_t* img, int32_t x, int32_t y)
```

```c
// Deletes an image and removes it from the render queue.
void mlx_delete_image(mlx* mlx, mlx_image_t* image)
```

ALLOWED EXTERNAL FUNCTIONS:

open, close, read, write,
malloc, free, perror,
strerror, exit

When doing valgrind with .supp files:

valgrind --leak-check=full --track-origins=yes --suppressions=./mlx42.supp ./so_long 