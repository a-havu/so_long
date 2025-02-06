MLX42 functions:

mlx_init()	Initialize and run a new window instance.
mlx_loop()	Keep the window open as long as a shutdown is not requested.
mlx_terminate()	Destroy and clean up all images and mlx resources.
mlx_img_to_window 

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


You first need to go to itch.io, and choose some assets for your game (you can also make your own in Photoshop, just make sure you export them as PNG).
Export each texture into a PNG image.
Go to Convertio, which will take your images and transform them into an XPM file format.
With these newly created XPM images, I recommend defining both your tile size and the paths for each of your assets in a header file. This will lead to more readable code, and your future self/evaluator will thank you for it.

When doing valgrind with .supp files: valgrind --leak-check=full --suppressions=./mlx42.supp ./so_long 