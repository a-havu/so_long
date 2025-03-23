<h2>FEED THE VAMP</h2>

This is a very simple top-down 2D game built with C, utilising MLX42 library. The program takes a .ber map as argument, and the player has to collect all collectibles on the map before they can exit - but look out for enemies! 😈🧄

In my game, the player is a vampire on the prowl in a castle garden. The vampire is hungry and needs to eat all the noblemen who are casually hanging out in the garden, before it can go to its coffin and slumber for the day.

I have made all the graphics myself in collage style with Photoshop, using royalty-free images from image banks.

<h3>🦇Mandatory part🦇</h3>
  ☆  <strong>map validation:</strong>  map can only be a .ber file, has to be a rectangle, can only contain characters P, 0, 1, E and C, needs to have a certain amount of E/P/C's etc.<br><br>
  
  ☆ <strong>player movement:</strong> up, down, left & right, can't move through or into walls etc.

  ☆ <strong>graphic management:</strong> window opens and stays open, closes when ``ESC`` is pressed or window cross clicked.
<h3>🦇Bonus part🦇</h3>
  ☆ Add some animation<br><br>
  ☆ Player loses if they touch an enemy

  
<h2>How to play</h2>

My so_long works for both Linux and MacOS, feel free to try it out if you're using either of those systems!

```shell
git clone https://github.com/a-havu/so_long.git
cd so_long
make
./so_long maps/minimap.ber
```
In the ``maps/`` directory, there are some example maps that you can try out!<br>
Move the player with WASD or arrow keys and destroy enemies (garlic) with SPACE.🦇😈🧄
