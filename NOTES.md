MLX42 functions:

mlx_init()	Initialize and run a new window instance.
mlx_loop()	Keep the window open as long as a shutdown is not requested.
mlx_terminate()	Destroy and clean up all images and mlx resources.



ALLOWED EXTERNAL FUNCTIONS:

open, close, read, write,
malloc, free, perror,
strerror, exit


Loading Textures
Before loading your textures, you may notice you don’t have any. Here is a quick way to get some basic graphical assets, and make them ready for MLX:

You first need to go to itch.io, and choose some assets for your game (you can also make your own in Photoshop, just make sure you export them as PNG).
Export each texture into a PNG image.
Go to Convertio, which will take your images and transform them into an XPM file format.
With these newly created XPM images, I recommend defining both your tile size and the paths for each of your assets in a header file. This will lead to more readable code, and your future self/evaluator will thank you for it.