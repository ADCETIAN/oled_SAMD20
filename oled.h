/*
 * oled.h
 *
 * Created: 12/2/2020 12:41:52 AM
 *  Author: Kiran
 */ 


#ifndef OLED_H_
#define OLED_H_





 

#define SSD1306_MEMORYMODE 0x20          ///< See datasheet
#define SSD1306_COLUMNADDR 0x21          ///< See datasheet
#define SSD1306_PAGEADDR 0x22            ///< See datasheet
#define SSD1306_SETCONTRAST 0x81         ///< See datasheet
#define SSD1306_CHARGEPUMP 0x8D          ///< See datasheet
#define SSD1306_SEGREMAP 0xA0            ///< See datasheet
#define SSD1306_DISPLAYALLON_RESUME 0xA4 ///< See datasheet
#define SSD1306_DISPLAYALLON 0xA5        ///< Not currently used
#define SSD1306_NORMALDISPLAY 0xA6       ///< See datasheet
#define SSD1306_INVERTDISPLAY 0xA7       ///< See datasheet
#define SSD1306_SETMULTIPLEX 0xA8        ///< See datasheet
#define SSD1306_DISPLAYOFF 0xAE          ///< See datasheet
#define SSD1306_DISPLAYON 0xAF           ///< See datasheet
#define SSD1306_COMSCANINC 0xC0          ///< Not currently used
#define SSD1306_COMSCANDEC 0xC8          ///< See datasheet
#define SSD1306_SETDISPLAYOFFSET 0xD3    ///< See datasheet
#define SSD1306_SETDISPLAYCLOCKDIV 0xD5  ///< See datasheet
#define SSD1306_SETPRECHARGE 0xD9        ///< See datasheet
#define SSD1306_SETCOMPINS 0xDA          ///< See datasheet
#define SSD1306_SETVCOMDETECT 0xDB       ///< See datasheet

#define SSD1306_SETLOWCOLUMN 0x00  ///< Not currently used
#define SSD1306_SETHIGHCOLUMN 0x10 ///< Not currently used
#define SSD1306_SETSTARTLINE 0x40  ///< See datasheet

#define SSD1306_EXTERNALVCC 0x01  ///< External display voltage source
#define SSD1306_SWITCHCAPVCC 0x02 ///< Gen. display voltage from 3.3V

#define SSD1306_RIGHT_HORIZONTAL_SCROLL 0x26              ///< Init rt scroll
#define SSD1306_LEFT_HORIZONTAL_SCROLL 0x27               ///< Init left scroll
#define SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL 0x29 ///< Init diag scroll
#define SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL 0x2A  ///< Init diag scroll
#define SSD1306_DEACTIVATE_SCROLL 0x2E                    ///< Stop scroll
#define SSD1306_ACTIVATE_SCROLL 0x2F                      ///< Start scroll
#define SSD1306_SET_VERTICAL_SCROLL_AREA 0xA3             ///< Set scroll range

// Definiting new data structure
typedef struct State{
	unsigned short h; // height
	unsigned short w; //width
	const unsigned char *image[30];
	unsigned short x_pos; // x prosition
	unsigned short y_pos; //
}ImgType;
 
bool begin_oled(void);
void oled_command(char* data); 
void oled_blank();
void oled_pos(int Ypos, int Xpos);
void oled_print(int Ypos, int Xpos, char str[]);
void oled_data(char* data);
void clear_buffer(unsigned char screen_buffer[][128]);
void update_buffer(ImgType img, unsigned short img_num, unsigned char screen_buffer[][128]);
void update_str_buffer(short Ypos, short Xpos,char str[], unsigned char screen_buffer[][128]);
void print_buffer(unsigned char screen_buffer[][128])
;
static const char ASCII[][6] =
{
	 {0x40, 0x00, 0x00, 0x00, 0x00, 0x00} // 20
	,{0x40, 0x00, 0x00, 0x5f, 0x00, 0x00} // 21 !
	,{0x40, 0x00, 0x07, 0x00, 0x07, 0x00} // 22 "
	,{0x40, 0x14, 0x7f, 0x14, 0x7f, 0x14} // 23 #
	,{0x40, 0x24, 0x2a, 0x7f, 0x2a, 0x12} // 24 $
	,{0x40, 0x23, 0x13, 0x08, 0x64, 0x62} // 25 %
	,{0x40, 0x36, 0x49, 0x55, 0x22, 0x50} // 26 &
	,{0x40, 0x00, 0x05, 0x03, 0x00, 0x00} // 27 '
	,{0x40, 0x00, 0x1c, 0x22, 0x41, 0x00} // 28 (
	,{0x40, 0x00, 0x41, 0x22, 0x1c, 0x00} // 29 )
	,{0x40, 0x14, 0x08, 0x3e, 0x08, 0x14} // 2a *
	,{0x40, 0x08, 0x08, 0x3e, 0x08, 0x08} // 2b +
	,{0x40, 0x00, 0x50, 0x30, 0x00, 0x00} // 2c ,
	,{0x40, 0x08, 0x08, 0x08, 0x08, 0x08} // 2d -
	,{0x40, 0x00, 0x60, 0x60, 0x00, 0x00} // 2e .
	,{0x40, 0x20, 0x10, 0x08, 0x04, 0x02} // 2f /
	,{0x40, 0x3e, 0x51, 0x49, 0x45, 0x3e} // 30 0
	,{0x40, 0x00, 0x42, 0x7f, 0x40, 0x00} // 31 1
	,{0x40, 0x42, 0x61, 0x51, 0x49, 0x46} // 32 2
	,{0x40, 0x21, 0x41, 0x45, 0x4b, 0x31} // 33 3
	,{0x40, 0x18, 0x14, 0x12, 0x7f, 0x10} // 34 4
	,{0x40, 0x27, 0x45, 0x45, 0x45, 0x39} // 35 5
	,{0x40, 0x3c, 0x4a, 0x49, 0x49, 0x30} // 36 6
	,{0x40, 0x01, 0x71, 0x09, 0x05, 0x03} // 37 7
	,{0x40, 0x36, 0x49, 0x49, 0x49, 0x36} // 38 8
	,{0x40, 0x06, 0x49, 0x49, 0x29, 0x1e} // 39 9
	,{0x40, 0x00, 0x36, 0x36, 0x00, 0x00} // 3a :
	,{0x40, 0x00, 0x56, 0x36, 0x00, 0x00} // 3b ;
	,{0x40, 0x08, 0x14, 0x22, 0x41, 0x00} // 3c <
	,{0x40, 0x14, 0x14, 0x14, 0x14, 0x14} // 3d =
	,{0x40, 0x00, 0x41, 0x22, 0x14, 0x08} // 3e >
	,{0x40, 0x02, 0x01, 0x51, 0x09, 0x06} // 3f ?
	,{0x40, 0x32, 0x49, 0x79, 0x41, 0x3e} // 40 @
	,{0x40, 0x7e, 0x11, 0x11, 0x11, 0x7e} // 41 A
	,{0x40, 0x7f, 0x49, 0x49, 0x49, 0x36} // 42 B
	,{0x40, 0x3e, 0x41, 0x41, 0x41, 0x22} // 43 C
	,{0x40, 0x7f, 0x41, 0x41, 0x22, 0x1c} // 44 D
	,{0x40, 0x7f, 0x49, 0x49, 0x49, 0x41} // 45 E
	,{0x40, 0x7f, 0x09, 0x09, 0x09, 0x01} // 46 F
	,{0x40, 0x3e, 0x41, 0x49, 0x49, 0x7a} // 47 G
	,{0x40, 0x7f, 0x08, 0x08, 0x08, 0x7f} // 48 H
	,{0x40, 0x00, 0x41, 0x7f, 0x41, 0x00} // 49 I
	,{0x40, 0x20, 0x40, 0x41, 0x3f, 0x01} // 4a J
	,{0x40, 0x7f, 0x08, 0x14, 0x22, 0x41} // 4b K
	,{0x40, 0x7f, 0x40, 0x40, 0x40, 0x40} // 4c L
	,{0x40, 0x7f, 0x02, 0x0c, 0x02, 0x7f} // 4d M
	,{0x40, 0x7f, 0x04, 0x08, 0x10, 0x7f} // 4e N
	,{0x40, 0x3e, 0x41, 0x41, 0x41, 0x3e} // 4f O
	,{0x40, 0x7f, 0x09, 0x09, 0x09, 0x06} // 50 P
	,{0x40, 0x3e, 0x41, 0x51, 0x21, 0x5e} // 51 Q
	,{0x40, 0x7f, 0x09, 0x19, 0x29, 0x46} // 52 R
	,{0x40, 0x46, 0x49, 0x49, 0x49, 0x31} // 53 S
	,{0x40, 0x01, 0x01, 0x7f, 0x01, 0x01} // 54 T
	,{0x40, 0x3f, 0x40, 0x40, 0x40, 0x3f} // 55 U
	,{0x40, 0x1f, 0x20, 0x40, 0x20, 0x1f} // 56 V
	,{0x40, 0x3f, 0x40, 0x38, 0x40, 0x3f} // 57 W
	,{0x40, 0x63, 0x14, 0x08, 0x14, 0x63} // 58 X
	,{0x40, 0x07, 0x08, 0x70, 0x08, 0x07} // 59 Y
	,{0x40, 0x61, 0x51, 0x49, 0x45, 0x43} // 5a Z
	,{0x40, 0x00, 0x7f, 0x41, 0x41, 0x00} // 5b [
	,{0x40, 0x02, 0x04, 0x08, 0x10, 0x20} // 5c �
	,{0x40, 0x00, 0x41, 0x41, 0x7f, 0x00} // 5d ]
	,{0x40, 0x04, 0x02, 0x01, 0x02, 0x04} // 5e ^
	,{0x40, 0x40, 0x40, 0x40, 0x40, 0x40} // 5f _
	,{0x40, 0x00, 0x01, 0x02, 0x04, 0x00} // 60 `
	,{0x40, 0x20, 0x54, 0x54, 0x54, 0x78} // 61 a
	,{0x40, 0x7f, 0x48, 0x44, 0x44, 0x38} // 62 b
	,{0x40, 0x38, 0x44, 0x44, 0x44, 0x20} // 63 c
	,{0x40, 0x38, 0x44, 0x44, 0x48, 0x7f} // 64 d
	,{0x40, 0x38, 0x54, 0x54, 0x54, 0x18} // 65 e
	,{0x40, 0x08, 0x7e, 0x09, 0x01, 0x02} // 66 f
	,{0x40, 0x0c, 0x52, 0x52, 0x52, 0x3e} // 67 g
	,{0x40, 0x7f, 0x08, 0x04, 0x04, 0x78} // 68 h
	,{0x40, 0x00, 0x44, 0x7d, 0x40, 0x00} // 69 i
	,{0x40, 0x20, 0x40, 0x44, 0x3d, 0x00} // 6a j
	,{0x40, 0x7f, 0x10, 0x28, 0x44, 0x00} // 6b k
	,{0x40, 0x00, 0x41, 0x7f, 0x40, 0x00} // 6c l
	,{0x40, 0x7c, 0x04, 0x18, 0x04, 0x78} // 6d m
	,{0x40, 0x7c, 0x08, 0x04, 0x04, 0x78} // 6e n
	,{0x40, 0x38, 0x44, 0x44, 0x44, 0x38} // 6f o
	,{0x40, 0x7c, 0x14, 0x14, 0x14, 0x08} // 70 p
	,{0x40, 0x08, 0x14, 0x14, 0x18, 0x7c} // 71 q
	,{0x40, 0x7c, 0x08, 0x04, 0x04, 0x08} // 72 r
	,{0x40, 0x48, 0x54, 0x54, 0x54, 0x20} // 73 s
	,{0x40, 0x04, 0x3f, 0x44, 0x40, 0x20} // 74 t
	,{0x40, 0x3c, 0x40, 0x40, 0x20, 0x7c} // 75 u
	,{0x40, 0x1c, 0x20, 0x40, 0x20, 0x1c} // 76 v
	,{0x40, 0x3c, 0x40, 0x30, 0x40, 0x3c} // 77 w
	,{0x40, 0x44, 0x28, 0x10, 0x28, 0x44} // 78 x
	,{0x40, 0x0c, 0x50, 0x50, 0x50, 0x3c} // 79 y
	,{0x40, 0x44, 0x64, 0x54, 0x4c, 0x44} // 7a z
	,{0x40, 0x00, 0x08, 0x36, 0x41, 0x00} // 7b {
	,{0x40, 0x00, 0x00, 0x7f, 0x00, 0x00} // 7c |
	,{0x40, 0x00, 0x41, 0x36, 0x08, 0x00} // 7d }
	,{0x40, 0x10, 0x08, 0x08, 0x10, 0x08} // 7e ?
	,{0x40, 0x78, 0x46, 0x41, 0x46, 0x78} // 7f ?
};


// Adding img data
static unsigned short weew_stack_rows = 128;
static unsigned short weew_stack_cols = 128;
static unsigned char weew_stack[] =
{
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0x7F,
	0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0x7F,
	0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
	0x7F, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0x7F, 0x7F, 0x7F, 0x7F,
	0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0x7F, 0xFF, 0xFF,
	0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
	0x7F, 0xFF, 0x7F, 0x7F, 0xFF, 0xFF, 0x7F, 0x7F, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0x7F, 0xFF, 0xFF, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F,
	0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
	0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFE, 0xFE, 0x06,
	0x06, 0x06, 0x06, 0x06, 0xFE, 0xFE, 0x00, 0xFF, 0xFF, 0x0F,
	0x0F, 0xC9, 0xC9, 0xC0, 0x00, 0x00, 0xCC, 0xC8, 0x0D, 0xC9,
	0xC0, 0x33, 0x33, 0xCF, 0xCF, 0xC8, 0xDC, 0xFE, 0x1E, 0x0E,
	0xFC, 0xF8, 0x30, 0x30, 0xF0, 0x3E, 0x3E, 0x00, 0x00, 0x07,
	0x03, 0xF0, 0xF1, 0xF1, 0xFC, 0xFC, 0xF6, 0xF6, 0x06, 0x31,
	0x31, 0x3F, 0x3F, 0x08, 0x1C, 0x3E, 0x31, 0x31, 0x3E, 0x3E,
	0x32, 0x36, 0x3E, 0xC0, 0xC0, 0x0C, 0x0C, 0x00, 0x00, 0x31,
	0xDE, 0xCE, 0xCF, 0xCF, 0xC8, 0xDC, 0xFF, 0xFF, 0xFF, 0x07,
	0x07, 0x00, 0x00, 0x0E, 0xCD, 0xCD, 0xC0, 0xC0, 0x0F, 0x0F,
	0xC3, 0xCF, 0xCE, 0x31, 0x31, 0xFF, 0xFF, 0x00, 0xFE, 0xFE,
	0x06, 0x06, 0x06, 0x06, 0x06, 0xFE, 0xFE, 0x00, 0x00, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0x98, 0x98, 0x1B, 0x9B, 0xFB, 0x7B, 0x7B,
	0x7B, 0x7B, 0x1B, 0x99, 0x98, 0x9F, 0x9F, 0xFB, 0xFB, 0x07,
	0x07, 0x00, 0x9C, 0x9E, 0x60, 0x60, 0x87, 0xE7, 0x60, 0xFF,
	0xFF, 0x83, 0x83, 0xFC, 0xFC, 0x78, 0x7C, 0x7C, 0x7B, 0x7B,
	0xFC, 0xFE, 0x83, 0x1F, 0x1F, 0xE0, 0xE0, 0x9E, 0x9E, 0x83,
	0xE7, 0xE7, 0xE0, 0xE0, 0x66, 0x64, 0x00, 0x9F, 0x9F, 0x1B,
	0x1B, 0x1F, 0x1F, 0x00, 0x07, 0x07, 0x9B, 0x9B, 0x1F, 0x1F,
	0x18, 0x8C, 0x84, 0x63, 0x63, 0xFF, 0xFF, 0x78, 0xEC, 0xE4,
	0xE3, 0xE3, 0x9F, 0x9F, 0x00, 0x7C, 0x7C, 0x9B, 0x9B, 0x67,
	0x67, 0x18, 0x7F, 0x7F, 0xFB, 0xFB, 0x87, 0x87, 0x60, 0xE7,
	0xE7, 0x7B, 0x7B, 0xFF, 0xFF, 0xF8, 0xF9, 0xFB, 0x9B, 0x9B,
	0x9B, 0x9B, 0x7B, 0x7B, 0x7B, 0xF8, 0xF8, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0x3F, 0xBF, 0xC0, 0xEF, 0x3F, 0xCF, 0xCF, 0x3C, 0x3C,
	0x3C, 0x3C, 0xCD, 0x81, 0x81, 0x0D, 0x0D, 0xC2, 0xCE, 0x0C,
	0xF3, 0xF3, 0xFC, 0xFC, 0x33, 0x33, 0x00, 0x30, 0xB1, 0x31,
	0x31, 0x3F, 0xBF, 0xC0, 0x00, 0x00, 0x0C, 0x0C, 0xFF, 0xFF,
	0x01, 0x03, 0x02, 0x03, 0x83, 0xF3, 0xF7, 0x0F, 0x31, 0x31,
	0x0F, 0x8F, 0xF2, 0xF2, 0xC0, 0x3C, 0x3D, 0xCC, 0xCC, 0xFC,
	0xFC, 0xFF, 0x8E, 0x0E, 0xFD, 0xFD, 0x30, 0x30, 0xF0, 0xF0,
	0xF1, 0xB3, 0x33, 0x3D, 0x3D, 0x0E, 0x07, 0x03, 0x33, 0x33,
	0x01, 0x00, 0x0C, 0xF0, 0xF0, 0xFD, 0xFD, 0x02, 0x86, 0xCE,
	0xCE, 0xCE, 0xCF, 0xCF, 0x0D, 0x0D, 0x32, 0x3D, 0x3D, 0xFF,
	0xFF, 0xCD, 0xCD, 0xCF, 0xFD, 0xFD, 0xCD, 0xCD, 0xF3, 0xF3,
	0x0E, 0x3C, 0x3C, 0x03, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF9,
	0xF9, 0xF8, 0xF9, 0x79, 0xE0, 0xE0, 0x01, 0x01, 0x66, 0x66,
	0x66, 0xC7, 0x87, 0x78, 0x78, 0x66, 0x7E, 0x79, 0x1E, 0x1E,
	0xF9, 0xF9, 0x1E, 0x1E, 0x80, 0xE1, 0xE1, 0x06, 0x06, 0x67,
	0x77, 0x9F, 0x60, 0x60, 0xE6, 0xE6, 0x66, 0x26, 0x01, 0xF9,
	0xF9, 0x79, 0x79, 0x7F, 0x7F, 0x98, 0x86, 0xC6, 0x07, 0x07,
	0x00, 0x00, 0x87, 0x66, 0x66, 0x1F, 0x1F, 0x66, 0x66, 0x80,
	0x19, 0x19, 0xF8, 0xF8, 0x78, 0x78, 0x07, 0x83, 0x81, 0xF9,
	0xF9, 0x81, 0x81, 0x00, 0x07, 0x07, 0x99, 0x99, 0x87, 0xC7,
	0x67, 0x24, 0x00, 0xF8, 0xF8, 0xFF, 0xFF, 0x66, 0x64, 0x60,
	0x79, 0x79, 0x7F, 0x7F, 0x01, 0x19, 0x18, 0x86, 0xC6, 0x18,
	0x18, 0xE1, 0xE1, 0xE1, 0x7E, 0x7E, 0xE1, 0xE1, 0x60, 0x39,
	0x19, 0x99, 0x99, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x40, 0x60, 0xFC,
	0xED, 0x0F, 0x80, 0x80, 0x40, 0x60, 0x30, 0x32, 0xB3, 0x8D,
	0x8C, 0x3F, 0x3F, 0x4C, 0x4C, 0x0F, 0xC0, 0xC0, 0xC0, 0xC0,
	0x00, 0x00, 0x3F, 0xFD, 0xFC, 0xCC, 0xEC, 0xBC, 0xBC, 0xBC,
	0xEF, 0x4F, 0x00, 0x00, 0x73, 0x73, 0x40, 0xBF, 0xBF, 0xCC,
	0xEC, 0xB0, 0xB8, 0x4C, 0x83, 0x83, 0xCC, 0xEC, 0xB0, 0xB0,
	0x3F, 0x03, 0x03, 0xCF, 0xEF, 0x73, 0xF3, 0xC0, 0xF0, 0x70,
	0xBC, 0xBC, 0xBC, 0xBC, 0xF3, 0x8D, 0x8C, 0x3F, 0x3F, 0xFC,
	0xFC, 0xBC, 0x3B, 0x33, 0xBF, 0xBF, 0x70, 0xF1, 0xC3, 0x3F,
	0x3F, 0x3C, 0x3C, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0xBC, 0xBC,
	0xB0, 0xB0, 0x73, 0x7C, 0x7C, 0x8F, 0x8F, 0x8F, 0x8F, 0x8F,
	0x07, 0x03, 0x40, 0x60, 0x8C, 0x8C, 0x8F, 0x9F, 0xB3, 0x70,
	0x70, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE6, 0xF6, 0xFF, 0xFE, 0xFE,
	0x7F, 0x3F, 0x1E, 0x1E, 0xE6, 0xF6, 0xD9, 0xD9, 0xD9, 0x1E,
	0x1E, 0xC0, 0x82, 0x06, 0x27, 0x27, 0xF9, 0xF9, 0x3E, 0x3E,
	0x20, 0xC1, 0xC1, 0xD9, 0xD9, 0x01, 0x01, 0x07, 0xD8, 0xD8,
	0x06, 0x06, 0x00, 0x20, 0x20, 0x3F, 0x3F, 0x39, 0x39, 0x1F,
	0x1F, 0xE6, 0xD9, 0xD9, 0x19, 0x19, 0x21, 0x61, 0xC6, 0xC0,
	0xC0, 0xD9, 0xD9, 0xD8, 0xD8, 0x27, 0xC6, 0xC6, 0xF9, 0xF9,
	0xE1, 0xF1, 0x1F, 0xF9, 0xF9, 0xD8, 0xD8, 0xDF, 0xDF, 0x27,
	0x1E, 0x1E, 0xF9, 0xF9, 0x18, 0x18, 0x39, 0xD9, 0xD8, 0xFE,
	0xFE, 0xE1, 0xE1, 0x07, 0xFF, 0xFF, 0x3F, 0x3F, 0x39, 0x39,
	0x06, 0x8E, 0xDE, 0x07, 0x07, 0xC7, 0xC7, 0x3F, 0xFD, 0xF8,
	0x06, 0x06, 0x3F, 0x3F, 0x1F, 0x87, 0xC7, 0xDE, 0xDE, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFC, 0xFC, 0x10, 0x30, 0xF0, 0xEF, 0xEF,
	0x0C, 0x0C, 0xE3, 0xE3, 0x6C, 0xE0, 0xE0, 0x03, 0x03, 0xF0,
	0xF8, 0x9C, 0x00, 0x00, 0xE3, 0xE3, 0x9F, 0xBF, 0xF3, 0x00,
	0x00, 0x93, 0x93, 0x00, 0x04, 0x8C, 0x78, 0x70, 0x9F, 0x9F,
	0xE3, 0xE3, 0xF3, 0x60, 0x60, 0x00, 0x00, 0xEC, 0xEE, 0xE3,
	0x7F, 0x7F, 0x13, 0x13, 0x1F, 0x1F, 0x0C, 0xEF, 0xEF, 0x6C,
	0x6C, 0xE0, 0xE0, 0x0F, 0x7C, 0x7C, 0x83, 0x83, 0x63, 0x63,
	0x0C, 0x18, 0x10, 0xE3, 0xE3, 0x8C, 0x8C, 0x00, 0x13, 0x13,
	0x63, 0x63, 0x6C, 0x6C, 0x8F, 0x9F, 0x9C, 0x8F, 0x8F, 0xE0,
	0xE0, 0x1F, 0x8F, 0x8F, 0x6F, 0x6F, 0x1C, 0x3C, 0xF0, 0xE3,
	0x63, 0x0C, 0x0C, 0xEC, 0xEC, 0x6F, 0xE5, 0xE0, 0x0C, 0x0C,
	0x6F, 0x6F, 0x90, 0x93, 0x93, 0x93, 0x93, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xC9, 0xCD, 0x0E, 0x3F, 0x37, 0xC9, 0xC9, 0xC0, 0xC0,
	0xF7, 0xF7, 0x36, 0xC7, 0xC7, 0xC0, 0xC0, 0xF1, 0xF1, 0xF9,
	0xF8, 0xF8, 0xFF, 0xFF, 0x07, 0x07, 0x0F, 0x36, 0x36, 0xC1,
	0xC1, 0x38, 0x38, 0x09, 0x30, 0x30, 0xFF, 0xFF, 0x31, 0x31,
	0x31, 0x1E, 0x0E, 0x0E, 0x0E, 0xC9, 0xC9, 0xC1, 0x36, 0x36,
	0xCE, 0xCE, 0xFE, 0xFE, 0xF0, 0xF7, 0xF7, 0xF6, 0xF6, 0x07,
	0x07, 0x30, 0xF0, 0xF0, 0x39, 0x39, 0x08, 0x1C, 0xFE, 0x1C,
	0x08, 0x01, 0x01, 0x07, 0x07, 0xC6, 0xFC, 0xF8, 0x36, 0x36,
	0xC8, 0xDC, 0xFF, 0x77, 0x37, 0x19, 0x09, 0x01, 0x01, 0x38,
	0xF1, 0xF1, 0x06, 0x06, 0x00, 0x00, 0x01, 0xC0, 0xC0, 0x00,
	0x00, 0xC7, 0xC7, 0x36, 0x37, 0x37, 0xF0, 0xF0, 0xC6, 0xC6,
	0xF1, 0x99, 0x09, 0x31, 0x31, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC,
	0xFE, 0x87, 0x87, 0x04, 0x9F, 0x9F, 0xE4, 0xE4, 0xE3, 0xE3,
	0x9B, 0x98, 0x98, 0x9F, 0x9F, 0x67, 0x67, 0x07, 0xFB, 0xFB,
	0x78, 0x78, 0x9B, 0xFB, 0x7F, 0x8E, 0x84, 0x9F, 0x9F, 0x9B,
	0xBB, 0xF8, 0x18, 0x18, 0x87, 0x87, 0x9B, 0x9B, 0x07, 0x7E,
	0x7C, 0x00, 0x00, 0x1B, 0x1B, 0x1F, 0xFF, 0xFF, 0x9F, 0x9F,
	0xF8, 0xF8, 0x04, 0x18, 0x18, 0x9F, 0x9F, 0x9F, 0x9F, 0x04,
	0x98, 0x98, 0x9C, 0x9C, 0xE3, 0xE3, 0xE3, 0x3F, 0x1F, 0xFB,
	0xFB, 0x9B, 0x9B, 0x7B, 0x3E, 0x1C, 0xE3, 0xE3, 0x18, 0x18,
	0xE7, 0xFF, 0xFF, 0x78, 0x78, 0xFC, 0xFC, 0x60, 0xF1, 0x9B,
	0x6C, 0x64, 0x87, 0x87, 0x04, 0xE4, 0xE4, 0x98, 0x98, 0xE3,
	0xE3, 0x04, 0x64, 0x64, 0x07, 0x07, 0x7F, 0x7F, 0x63, 0xC7,
	0x87, 0x06, 0x04, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03,
	0x33, 0x30, 0xFF, 0xFF, 0x31, 0x31, 0x03, 0x4F, 0xCD, 0x3F,
	0x3F, 0xC1, 0xC1, 0xCE, 0x4E, 0x0C, 0x0D, 0x0D, 0x3E, 0x3E,
	0xC3, 0xC3, 0xF0, 0xC3, 0xC3, 0x3F, 0x3F, 0xCD, 0xCD, 0xCD,
	0xB0, 0x30, 0xCD, 0xCD, 0xFD, 0xF9, 0xF0, 0xC2, 0xC2, 0x02,
	0x02, 0x00, 0x00, 0xFC, 0x07, 0x03, 0xFF, 0xFF, 0x0D, 0x0D,
	0xCE, 0x00, 0x00, 0xFF, 0xFF, 0xF3, 0xF7, 0xFC, 0xCD, 0xCD,
	0x0D, 0x0D, 0xCD, 0xCD, 0x03, 0x3F, 0x3E, 0x3D, 0x3D, 0x3D,
	0x3D, 0x3E, 0xDC, 0xCC, 0xC1, 0xC1, 0xCE, 0xCF, 0x3D, 0xDF,
	0xCF, 0xFC, 0xFC, 0x0D, 0x0D, 0x02, 0xFD, 0xFD, 0x3C, 0x3C,
	0x0D, 0x0D, 0x3C, 0x3C, 0x0D, 0x3F, 0x3F, 0x0F, 0x0F, 0x00,
	0x72, 0xF2, 0x02, 0x02, 0xF2, 0xF6, 0x0E, 0xFF, 0xFF, 0xF6,
	0xF2, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x07,
	0xE6, 0xE6, 0x79, 0x79, 0x00, 0x24, 0x66, 0xE6, 0xE6, 0x79,
	0x79, 0xE0, 0xE0, 0xF8, 0xFF, 0xFF, 0x7E, 0x7E, 0xE6, 0xEC,
	0x78, 0x00, 0x00, 0x7F, 0x7F, 0x9F, 0x9F, 0x00, 0x81, 0x81,
	0x7F, 0x7F, 0xE6, 0xEE, 0x99, 0x86, 0x86, 0xE0, 0xE0, 0xF8,
	0xF8, 0x9F, 0x60, 0x60, 0x99, 0x99, 0xF8, 0xF8, 0x86, 0x9E,
	0x9E, 0xE3, 0xE1, 0x80, 0x80, 0x86, 0x18, 0x18, 0x98, 0x98,
	0x1E, 0x1E, 0x98, 0x61, 0x61, 0x07, 0x07, 0xFE, 0xFE, 0x18,
	0xF8, 0xF8, 0x7F, 0x7F, 0x01, 0x01, 0x81, 0x80, 0x00, 0x80,
	0x80, 0x7F, 0x7F, 0x98, 0x91, 0x01, 0x7E, 0x7E, 0x07, 0x07,
	0x1E, 0xF3, 0xE1, 0x79, 0x79, 0x67, 0x67, 0x60, 0xFC, 0xFE,
	0x1E, 0x1E, 0xF9, 0xFB, 0x06, 0xE7, 0xE1, 0x87, 0x87, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0x4C, 0xCC, 0xFF, 0xBF, 0xB0, 0x30, 0x30,
	0xC3, 0xC3, 0x83, 0x93, 0xB3, 0xC1, 0xC1, 0x80, 0x80, 0xBF,
	0xBF, 0x7F, 0x81, 0x80, 0xFC, 0xFC, 0x40, 0xE1, 0xF3, 0x83,
	0x83, 0xBF, 0xBF, 0xFF, 0xFF, 0x80, 0xCF, 0xCF, 0x33, 0x33,
	0xF3, 0xF3, 0x80, 0x3F, 0x3F, 0x8C, 0x8D, 0x4F, 0x6F, 0x33,
	0xE3, 0xC3, 0xB1, 0xB1, 0x83, 0x87, 0x8F, 0x8F, 0x8F, 0x31,
	0x31, 0xB3, 0xB3, 0xBF, 0x3F, 0x3F, 0x81, 0x80, 0xF0, 0xF0,
	0xF0, 0xEF, 0x4F, 0x3C, 0x3C, 0x8D, 0x8C, 0x7C, 0x87, 0x83,
	0xCC, 0xCC, 0x70, 0xF0, 0x81, 0x0C, 0x0C, 0x70, 0xF1, 0xB3,
	0xB3, 0xC0, 0x8C, 0x8C, 0xBF, 0xBF, 0x0F, 0x0F, 0xC3, 0xC3,
	0x83, 0x8C, 0x8C, 0xCF, 0xCF, 0x8F, 0x0D, 0x0C, 0x7C, 0x7C,
	0x81, 0x81, 0x33, 0x73, 0x73, 0x83, 0x83, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0x1E, 0x1E, 0xD9, 0xD9, 0xD9, 0xDE, 0xDE, 0xD9, 0xD9,
	0xDF, 0x9F, 0x19, 0xFF, 0xFF, 0x01, 0x01, 0x07, 0x27, 0xE6,
	0xE7, 0xE7, 0xFF, 0xFF, 0x1E, 0x1E, 0x79, 0x31, 0x21, 0xE7,
	0xE7, 0x21, 0x39, 0x19, 0x1F, 0x1F, 0xE0, 0xE0, 0x07, 0x07,
	0xF9, 0x78, 0x38, 0x21, 0x61, 0xF8, 0xF8, 0x3E, 0x1F, 0x1F,
	0xC1, 0xC1, 0xC7, 0x87, 0x01, 0xF9, 0xF9, 0xD8, 0xD8, 0xF9,
	0xF9, 0x01, 0xE0, 0xE0, 0xD9, 0xD9, 0xE7, 0xE7, 0x27, 0x20,
	0x00, 0x26, 0x66, 0x19, 0x19, 0x66, 0x3B, 0x79, 0x1F, 0x1F,
	0xDE, 0xDE, 0xE7, 0x78, 0x78, 0x06, 0x06, 0xFF, 0xFF, 0xE1,
	0xE7, 0xE7, 0x7F, 0x3F, 0xE0, 0xE0, 0xE6, 0xDF, 0xDF, 0x01,
	0x01, 0xF9, 0xF9, 0xD9, 0xF9, 0xF8, 0x00, 0x00, 0x19, 0x19,
	0xE6, 0xE4, 0xE0, 0x1F, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
	0x00, 0x7F, 0x7F, 0x60, 0x60, 0x60, 0x60, 0x60, 0x7F, 0x7F,
	0x00, 0xFF, 0xFF, 0x1F, 0x3F, 0x7F, 0xFF, 0x80, 0x13, 0x13,
	0xFC, 0xFC, 0x9C, 0xBC, 0xE0, 0x6F, 0x6F, 0x0C, 0x0C, 0xFC,
	0xFC, 0x4C, 0xF3, 0xF3, 0x70, 0x70, 0x43, 0xE3, 0xF0, 0x7F,
	0x7F, 0x0C, 0x0C, 0xFC, 0xFC, 0x10, 0x63, 0x43, 0xF0, 0xF0,
	0xFF, 0xFF, 0x6C, 0x6C, 0x6C, 0xE0, 0xE0, 0xFC, 0xFC, 0xE0,
	0x3C, 0x3C, 0x83, 0x83, 0x3F, 0x3F, 0xEF, 0x3F, 0x1F, 0x10,
	0x10, 0x90, 0xB0, 0xE0, 0x8F, 0x8F, 0x13, 0x33, 0xFC, 0xFC,
	0x6C, 0x4C, 0x0C, 0x83, 0x83, 0x6F, 0x6F, 0xEC, 0x3C, 0x3C,
	0x00, 0x00, 0x73, 0x73, 0xF3, 0xF3, 0x70, 0xE0, 0xE0, 0x30,
	0x10, 0x0C, 0x44, 0x60, 0xEC, 0xEC, 0x0C, 0x0C, 0xF3, 0xEB,
	0x4F, 0xFC, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE,
	0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFF,
	0xFF, 0xFE, 0xFE, 0xFE, 0xFE, 0xFF, 0xFE, 0xFE, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFE,
	0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFE, 0xFF, 0xFE, 0xFE, 0xFE,
	0xFE, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE,
	0xFF, 0xFF, 0xFE, 0xFE, 0xFF, 0xFE, 0xFE, 0xFE, 0xFE, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFF, 0xFF, 0xFE, 0xFE,
	0xFE, 0xFF, 0xFF, 0xFE, 0xFE, 0xFF, 0xFE, 0xFE, 0xFE, 0xFE,
	0xFE, 0xFE, 0xFF, 0xFE, 0xFE, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE,
	0xFE, 0xFE, 0xFF, 0xFF, 0xFE, 0xFE, 0xFF, 0xFE, 0xFE, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

#endif /* OLED_H_ */