 /*
 * main.c
 *
 * Created: 11-12-2020 12:30:21
 * Author: kiran Ukarande
 * Company: thingTronics Innovations Pvt. Ltd.
 */
        #include "main.h"
	
	i2cConfig();
	begin_oled();
	oled_blank();
	oled_print(1, 2, "hello World");
	vTaskDelay(2000); 

	ImgType weew_pic = {.h = weew_stack_rows, .w = weew_stack_cols, .x_pos = 0, .y_pos = 0};
	weew_pic.image[0] = weew_stack;
 
	oled_blank();
	clear_buffer(oled_buffer);
	update_buffer(weew_pic, 0, oled_buffer);
  	print_buffer(oled_buffer);
	
	while(1)
	{
 	
	}