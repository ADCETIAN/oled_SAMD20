/*
 * oled.c
 *
 * Created: 12/2/2020 12:41:25 AM
 * Author: Kiran
 */ 

#include "main.h"

#define PROGMEM

bool begin_oled(){  
 
 // For all command check datasheet.
 static uint8_t write_buffer_1[2] = {0xA8, 0x3F};
 oled_command(write_buffer_1);
 
 static uint8_t write_buffer_2[2] = {0xD3, 0x00};
 oled_command(write_buffer_2);
 
 static uint8_t write_buffer_3[1] = {0x40};
 oled_command(write_buffer_3);
 
 static uint8_t write_buffer_4[1] = {0xA1};
 oled_command(write_buffer_4);
 
 static uint8_t write_buffer_5[2] = {0xC8};
 oled_command(write_buffer_5);
 
 static uint8_t write_buffer_6[2] = {0xDA, 0x12};
 oled_command(write_buffer_6);
 
 static uint8_t write_buffer_7[2] = {0x81, 0x7F};
 oled_command(write_buffer_7);
 
 static uint8_t write_buffer_8[1] = {0xA4};
 oled_command(write_buffer_8);
 
 static uint8_t write_buffer_9[1] = {0xA6};
 oled_command(write_buffer_9);
 
 static uint8_t write_buffer_10[2] = {0xD5, 0x80};
 oled_command(write_buffer_10);
 
 static uint8_t write_buffer_11[2] = {0x8D, 0x14};
 oled_command(write_buffer_11);
 
 static uint8_t write_buffer_13[1] = {0xAF};
 oled_command(write_buffer_13);
 
 static uint8_t write_buffer_14[2] = {0x20, 0x10};
 oled_command(write_buffer_14);
 return true; 
}

void oled_command(char* data){
	static uint8_t write_buffer_12[1] = {0x00};
	uint8_t buf[(sizeof(data) + sizeof(write_buffer_12))];
	memcpy(buf, write_buffer_12, sizeof(write_buffer_12));
	memcpy(buf + sizeof(write_buffer_12), data, sizeof(data));
	i2cWriteToSlave(SLAVE_ADDRESS, sizeof ( buf	) , &buf);
}
/*
	 @param data
			Pointer to an data which will contains data has to print.
*/
void oled_data(char* data){
	static uint8_t write_buffer_12[1] = {0x40};
	uint8_t buf[(sizeof(data) + sizeof(write_buffer_12))];
	memcpy(buf, write_buffer_12, sizeof(write_buffer_12));
	memcpy(buf + sizeof(write_buffer_12), data, sizeof(data));
	i2cWriteToSlave(SLAVE_ADDRESS, sizeof ( buf	) , &buf);
}
 /*   @brief  Constructor for I2C SSD1306 displays.
	  @param Ypos
			 Set the page start address of the target display location.
	
	  @param Xpos
	         Set X position of the data has to be started to print.
*/
	          
void oled_pos(int Ypos, int Xpos){
	char ypos[] = {0xB0 + Xpos};         //Set the page start address of the target display location by command B0h to B7h.
 	char xpos[] = {0x10 + Xpos};         //Set the upper start column address of pointer by command
	static uint8_t	cmd[1] = {0x00};     //Set the lower start column address of pointer by command
	oled_command(ypos);
	oled_command(cmd);
	oled_command(xpos);
}

//to clear the screen
void oled_blank(){
	int i, j;
	oled_pos(0, 0);
	static uint8_t buf[1] = {0x00};
	for (i=0; i<8; i++)
	{
		for(j=0; j<128; j++)
		{
			oled_data(buf);
		}
		i++;
	}
	oled_pos(0, 0);
}
 
/*
	 @param str
			Pointer to an data which will contains data has to print.
			
	@param Ypos
	       Set the page start address of the target display location.
	
	@param Xpos
	      Set X position of the data has to be started to print.
*/
void oled_print(int Ypos, int Xpos, char str[])
{
	int i=0;
	oled_pos(Ypos, Xpos);
	while(str[i])
	{		
 		i2cWriteToSlave(SLAVE_ADDRESS, 6, &ASCII[(str[i]-32)]);
		i++;
 	}
}
/*
	 @param screen_buffer
	        buffer to an data which will contains data has to print.
			
*/
void clear_buffer(unsigned char screen_buffer[][128])
{
	int i, j;
	for (i=0; i<8; i++)
	{
		for(j=0; j<128; j++)
		screen_buffer[i][j] = 0;

	}
}
/*
	 @param img
	        image which has to copy in to buffer.	
			
	 @param img_num
	       Number of images to be printed on screen.
		   
	@param screen_buffer
		  data buffer which has to update.			
*/
void update_buffer(ImgType img, unsigned short img_num, unsigned char screen_buffer[][128])
{
	int x_dir, y_dir, endx, endy, cnt;
	if((img.w+img.x_pos)>128)
	{
		endx = 127;
	}
	else
	{
		endx = img.w+img.x_pos-1;
	}
	if((img.h+ img.y_pos)>8)
	{
		endy = 8;
	}
	else
	{
		endy = img.h+img.y_pos-1;
	}
	cnt = 0;
	for(y_dir = img.y_pos;y_dir<=endy;y_dir++)
	{
		for (x_dir= img.x_pos;x_dir <= endx; x_dir ++)
		{
			cnt =(y_dir-img.y_pos)*img.w +x_dir-img.x_pos;
			screen_buffer[y_dir][x_dir] = img.image[img_num][cnt];
			
		}
	}
}
//update str buffer
void update_str_buffer(short Ypos, short Xpos,char str[], unsigned char screen_buffer[][128])
{
	int i, j, cnt_col, cnt_row;
 	cnt_col = Xpos;
	cnt_row = Ypos;
	i = 0;
	while(str[i])
	{
		 
		for(j=0; j<8; j++)
		{
			screen_buffer[cnt_row][cnt_col] = ASCII[str[i]-32][j];
			if((cnt_col+1)>128)
			{
				if((cnt_row+1)>8)
				{
					break;
				}
				else{
					cnt_row ++;
					cnt_col = Xpos;
				}
			}
			else
			{
				cnt_col ++;
			}
		}
		i++;
	}

}
/*
	 @param screen_buffer
	        image screen_buffer which has to print on to Screen.	
			
 */		
void print_buffer(unsigned char screen_buffer[][128])
{
  	int i, j;
 	for (i=0; i<8; i++)	 
	{		 
		static uint8_t write_buffer_12[1] = {0x40};
		uint8_t buf[(sizeof(screen_buffer[i]) + sizeof(write_buffer_12))];
		memcpy(buf, write_buffer_12, sizeof(write_buffer_12));
		memcpy(buf + sizeof(write_buffer_12), screen_buffer[i], sizeof(screen_buffer[i]));
		i2cWriteToSlave(SLAVE_ADDRESS, sizeof ( buf	) , &buf);
	}
 
}