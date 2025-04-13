#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/display.h>

int disp_set_orientation(void)
{
	int ret = 0;
	// Set the orientation
	const struct device *display = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));
	if (!device_is_ready(display))
	{
		return -EIO;
	}

#ifdef CONFIG_PROSPECTOR_ROTATE_DISPLAY
	switch (CONFIG_PROSPECTOR_ROTATE_DISPLAY) {
  		case 1:
			ret = display_set_orientation(display, DISPLAY_ORIENTATION_ROTATED_90);
    		break;
  		case 2:
			ret = display_set_orientation(display, DISPLAY_ORIENTATION_ROTATED_180);
    		break;
		case 3:
			ret = display_set_orientation(display, DISPLAY_ORIENTATION_ROTATED_270);
		break;
		default:
			ret = display_set_orientation(display, DISPLAY_ORIENTATION_NORMAL);
		break;
	}
#endif
	if (ret < 0)
	{
		return ret;
	}

	return 0;
}

SYS_INIT(disp_set_orientation, APPLICATION, 60);
