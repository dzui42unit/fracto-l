# fracto-l

This project is to create a small fractal exploration program. Start by seeing what a fractal is.

This project includes a realization of Mandelbrot and Julia set and a Ships fractal.

* It is possible to vary the mouse (without clicking) the parameter of the Julia
set.
* The mouse wheel zooms in and out on the current mouse position, and this in a
quasi infinite way (modulo the limits of the machine). This is the same principle of
fractals.
* There must be a minimum play of color to feel the depth of each fractal.
* A parameter is passed on the command line to define what type of fractal is to
view. If there is no parameter provided, or if the parameter is invalid, the program
displays a list of available parameters and exits.
* Multithreading is used to improve the performance of the program.

How to compile: gcc *.c -lmlx -lXext -lX11 -L ./libmlx/ -I ./libmlx/ -lm -pthread

# Mandelbrot set:

![mandelbrot](https://user-images.githubusercontent.com/28359156/30073918-3ad47adc-9278-11e7-9fae-6af17dbb54f0.png)

![mandel_zoom](https://user-images.githubusercontent.com/28359156/30073924-3c4b37a2-9278-11e7-9112-fab3c3be88f8.png)

![mande_zoom_2](https://user-images.githubusercontent.com/28359156/30073926-3d623230-9278-11e7-963a-e9baa222e783.png)

# Julia set:

![julia](https://user-images.githubusercontent.com/28359156/30074078-c1394134-9278-11e7-8574-0692ef41f724.png)

![julia_2](https://user-images.githubusercontent.com/28359156/30074081-c1e59c9a-9278-11e7-8855-3ef8144161a4.png)

![julia_3](https://user-images.githubusercontent.com/28359156/30074082-c2aaefcc-9278-11e7-880b-e08e0bd7690d.png)

# Ships

![ships](https://user-images.githubusercontent.com/28359156/30074197-4653ec66-9279-11e7-915c-ca40e6aa719f.png)

![ships_2](https://user-images.githubusercontent.com/28359156/30074200-492cd376-9279-11e7-9552-b66d348a5b17.png)
