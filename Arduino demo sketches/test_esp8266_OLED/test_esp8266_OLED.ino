#include <U8g2lib.h>

//U8g2 Contructor
U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ 16, /* clock=*/ 5, /* data=*/ 4);

u8g2_uint_t offset;     // current offset for the scrolling text
u8g2_uint_t width;      // pixel width of the scrolling text (must be lesser than 128 unless U8G2_16BIT is defined
const char *text = "ROB01 "; // scroll this text from right to left


void setup(void) {
  u8g2.begin();

  u8g2.setFont(u8g2_font_logisoso32_tf); // set the target font to calculate the pixel width
  u8g2.enableUTF8Print();
  u8g2.setFontMode(0);    // enable transparent mode, which is faster
}


void loop(void) {
  u8g2.clearBuffer();
  u8g2.setCursor(0, 32);                   //text position (left botom corner)
  u8g2.setFont(u8g2_font_logisoso16_tf); //first font             
  u8g2.print("wizzx.tech");                //main text 
  u8g2.sendBuffer();
  
  /*
  u8g2_uint_t x;

  u8g2.firstPage();
  do {

    // draw the scrolling text at current offset
    x = offset;
    u8g2.setFont(u8g2_font_logisoso32_tf);   // set the target font
    do {                // repeated drawing of the scrolling text...
      u8g2.drawUTF8(x, 32, text);     // draw the scolling text
      x += width;           // add the pixel width of the scrolling text
    } while ( x < u8g2.getDisplayWidth() );   // draw again until the complete display is filled

    u8g2.setFont(u8g2_font_logisoso32_tf);   // draw the current pixel width
    u8g2.setCursor(0, 64);
    u8g2.print(width);          // this value must be lesser than 128 unless U8G2_16BIT is set

  } while ( u8g2.nextPage() );

  offset -= 1;            // scroll by one pixel
  if ( (u8g2_uint_t)offset < (u8g2_uint_t) - width )
    offset = 0;             // start over again

    */
}
