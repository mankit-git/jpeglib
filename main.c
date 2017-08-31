
#include "jpeg.h"

int main(int argc, char *argv[]) // ./show_jpeg  xxx.jpg/xxx.jpeg
{	
	if(argc != 2)
	{
		printf("Usage: %s <jpeg>\n", argv[0]);
		exit(0);
	}
	int fd = lcd_fd();

	struct image_info *image_info = calloc(1, sizeof(struct image_info));
	char *rgb_buf = load_jpg(argv[1], image_info);

	struct fb_var_screeninfo vinfo;
	char *fbmemy = init_lcd(fd, &vinfo);

	write_lcd(fbmemy, &vinfo, rgb_buf, image_info);

	//munmap(fbmemy, vinfo.xres * vinfo.yres * bpp/8);
	close(fd);

	return 0;
}