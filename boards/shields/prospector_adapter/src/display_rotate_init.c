#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/display.h>

int disp_set_orientation(void)
{
	// Set the orientation
	const struct device *display = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));
	if (!device_is_ready(display))
	{
		return -EIO;
	}

#ifdef CONFIG_PROSPECTOR_ROTATE_DISPLAY
	if ( CONFIG_PROSPECTOR_ROTATE_DISPLAY == 0)
		int ret = display_set_orientation(display, DISPLAY_ORIENTATION_NORMAL);
	else if ( CONFIG_PROSPECTOR_ROTATE_DISPLAY == 1)
		int ret = display_set_orientation(display, DISPLAY_ORIENTATION_ROTATED_90);
	else if ( CONFIG_PROSPECTOR_ROTATE_DISPLAY == 2)
		int ret = display_set_orientation(display, DISPLAY_ORIENTATION_ROTATED_180);
	else ( CONFIG_PROSPECTOR_ROTATE_DISPLAY == 3)
		int ret = display_set_orientation(display, DISPLAY_ORIENTATION_ROTATED_270);
#endif
	if (ret < 0)
	{
		return ret;
	}

	return 0;
}

SYS_INIT(disp_set_orientation, APPLICATION, 60);
