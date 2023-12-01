```c
mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y)
```
- `void *mlx_ptr` - Address of `mlx_init()` 
- `void *win_ptr` - Address of a window
- `void *img_ptr` - Address of the image to be put in the window
- `int x` - X position where the image will be put on the  window
- `int y` - Y position where the image will be put on the  window



mlx_init();
mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
mlx_new_image(void *mlx_ptr, int width, int height);
mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
