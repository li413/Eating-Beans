/*
// Name: Chenyang Li Username:li413
// Partner's name: Ke Zhao Partner's username: zhaok
*/



#include <stm32f30x.h> // Pull in include files for F30x standard drivers
#include <f3d_uart.h>
#include <f3d_user_btn.h>
#include <f3d_lcd_sd.h>
#include <f3d_i2c.h>
#include <f3d_accel.h>
#include <f3d_mag.h>
#include <f3d_delay.h>
#include <f3d_nunchuk.h>
#include <f3d_led.h>
#include <f3d_gyro.h>
#include <math.h>
#include <stdio.h>
#include <f3d_rtc.h>
#include <f3d_systick.h>
#include <ff.h>
#include <diskio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "audio.h"
#define TIMER 20000


//food
typedef struct foods{
   int x;
   int y;
   int visited;
}food;


int main(void) {


  
  //f_mount(0, &Fatfs);/* Register volume work area */
  struct foods food[100];

 char x[100];


  // Set up your inits before you go ahead
  f3d_uart_init();
  delay(10);
  f3d_delay_init();
  f3d_i2c1_init();
  delay(10);
  f3d_accel_init();
  delay(10);
  f3d_mag_init();
  delay(10);
  f3d_user_btn_init();
  delay(10);
  f3d_led_init();
  delay(10);
  f3d_lcd_init();
  delay(10);
  f3d_nunchuk_init(); // new_added
  delay(10);
  f3d_timer2_init();
  delay(10);
  f3d_dac_init();
  delay(10);
  f3d_rtc_init();
  delay(10);
  f3d_systick_init();
  delay(10);

  setvbuf(stdin, NULL, _IONBF, 0);
  setvbuf(stdout, NULL, _IONBF, 0);
  setvbuf(stderr, NULL, _IONBF, 0);

  f3d_lcd_fillScreen(BLUE);
 




 int j,i;
  for(i =3; i<125; i++){
    for(j=1; j<159;j++){
   f3d_lcd_drawPixel(i,j, BLACK);
}
}

// draw box 1
for(i=20; i<40;i++){
 f3d_lcd_drawPixel(20,i, BLUE);
}

for(i=20; i<40;i++){
 f3d_lcd_drawPixel(i,20, BLUE);
}

for(i=20; i<40;i++){
 f3d_lcd_drawPixel(40,i, BLUE);
}

for(i=20; i<40;i++){
 f3d_lcd_drawPixel(i,40, BLUE);
}


for(i=20; i<40;i++){
 f3d_lcd_drawPixel(i,20, BLUE);
}

for(i=60; i<105;i++){
 f3d_lcd_drawPixel(i,20, BLUE);
}

for(i=20; i<40;i++){
//  f3d_lcd_fillScreen(BLACK);
//}



 f3d_lcd_drawPixel(60,i, BLUE);
}

for(i=20; i<40;i++){
 f3d_lcd_drawPixel(105,i, BLUE);
}

for(i=60; i<105;i++){
 f3d_lcd_drawPixel(i,40, BLUE);
}


//draw box 3

for(i=60; i<140;i++){
 f3d_lcd_drawPixel(20,i, BLUE);
}



for(i=20; i<75;i++){
 f3d_lcd_drawPixel(i,60, BLUE);
}
for(i=20; i<75;i++){
 f3d_lcd_drawPixel(i,140, BLUE);
}



for(i=60; i<140;i++){
 f3d_lcd_drawPixel(75,i, BLUE);
}





// draw box  4

for(i=60; i<140;i++){
 f3d_lcd_drawPixel(95,i, BLUE);
}

for(i=60; i<140;i++){
 f3d_lcd_drawPixel(105,i, BLUE);
}





for(i=95; i<105;i++){
 f3d_lcd_drawPixel(i,60, BLUE);
}
for(i=95; i<105;i++){
 f3d_lcd_drawPixel(i,140, BLUE);
}




int xval=7,yval=7;
int index=0;
// draw beans in the graph

for(index=0;index<45;index++){
 food[index].visited=0;

}

//bottom foods
food[0].x=7;
food[0].y=144;

food[1].x=22;
food[1].y=144;

food[2].x=37;
food[2].y=144;

food[3].x=52;
food[3].y=144;

food[4].x=67;
food[4].y=144;

food[5].x=82;
food[5].y=144;

food[6].x=97;
food[6].y=144;

food[7].x=112;
food[7].y=144;






  for (i=7; i<120;i= i+15){
 f3d_lcd_drawString(i,144,".",YELLOW,BLACK);
 
  
}






//left foods
food[8].x=7;
food[8].y=22;

food[9].x=7;
food[9].y=37;

food[10].x=7;
food[10].y=52;

food[11].x=7;
food[11].y=67;

food[12].x=7;
food[12].y=82;

food[13].x=7;
food[13].y=97;

food[14].x=7;
food[14].y=112;

food[15].x=7;
food[15].y=127;





  for (i=22; i<140;i= i+15){
   f3d_lcd_drawString(7,i,".",YELLOW,BLACK);
   
  
}

//right foods

food[16].x=113;
food[16].y=22;

food[17].x=113;
food[17].y=37;

food[18].x=113;
food[18].y=52;

food[19].x=113;
food[19].y=67;

food[20].x=113;
food[20].y=82;

food[21].x=113;
food[21].y=97;

food[22].x=113;
food[22].y=112;

food[23].x=113;
food[23].y=127;



	for (i=22; i<140;i= i+15){
         f3d_lcd_drawString(113,i,".",YELLOW,BLACK);
         
 
}

// middle foods lower

food[24].x=82;
food[24].y=60;

food[25].x=82;
food[25].y=75;

food[26].x=82;
food[26].y=90;

food[27].x=82;
food[27].y=105;

food[28].x=82;
food[28].y=120;

food[29].x=82;
food[29].y=135;


  for (i=60; i<140;i= i+15){
    f3d_lcd_drawString(82,i,".",YELLOW,BLACK);
    
 
}

//middle foods upper


food[30].x=45;
food[30].y=15;

food[31].x=45;
food[31].y=30;



   for (i=15; i<45;i= i+15){
    f3d_lcd_drawString(47,i,".",YELLOW,BLACK);
    

}

//upper foods


food[32].x=22;
food[32].y=7;

food[33].x=37;
food[33].y=7;

food[34].x=52;
food[34].y=7;

food[35].x=67;
food[35].y=7;

food[36].x=82;
food[36].y=7;

food[37].x=97;
food[37].y=7;


food[38].x=112;
food[38].y=7;


  for(i=22;i<120;i= i+15){
   f3d_lcd_drawString(i,7,".",YELLOW,BLACK);
 
  
}

// second upper foods




food[39].x=22;
food[39].y=47;

food[40].x=37;
food[40].y=47;

food[41].x=52;
food[41].y=47;

food[42].x=67;
food[42].y=47;

food[43].x=82;
food[43].y=47;

food[44].x=97;
food[44].y=47;

  for(i=22;i<100;i= i+15){
   f3d_lcd_drawString(i,47,".",YELLOW,BLACK);
  
  
}

int count,z,k;
int sum=0;


nunchuk_t data;
//play_selected_file("pacman.wav");


  while(1){


f3d_nunchuk_read(&data);
//delay(10);   
if(data.jx >=250){
xval= xval +1;
}

if(data.jx <=5){
xval= xval -1;
}
if(data.jy <=5){
yval= yval +1;
}
if(data.jy >=250){
yval= yval -1;
}

f3d_lcd_drawString(xval-1,yval,"o",BLACK,BLACK);
f3d_lcd_drawString(xval+1,yval,"o",BLACK,BLACK);
f3d_lcd_drawString(xval,yval,"o",YELLOW,BLACK);



// the bound
if(xval<7) {
 xval=7;

}

if(yval<7){

yval=7;
}
if(xval>113 ){
xval=113;
}

if(yval>144 ){
//  f3d_lcd_fillScreen(BLACK);
//}



yval=144;
}

if(xval>8 && xval < 16 && yval>16 && yval<40){
xval=7;
}

if(xval>8 && xval < 16 && yval > 55 && yval < 140){
xval=7;

}

if (yval>8 && yval < 16 && xval > 16 && xval < 40){
yval=7;
}

if (yval>8 && yval < 16 && xval > 55 && xval < 105){
yval=7;
}

if (yval>8 && yval < 16 && xval > 55 && xval < 105){
yval=7;
}
//1 box right
if (xval >=  40 && xval <= 60 && yval > 7 && yval <= 40) {
xval =45;
}


//1 box bottom
if (xval >= 20 && xval <= 40 && yval >= 40 && yval <= 60) {
yval =47;
}

//2 box right
if (xval > 112 && yval >= 20 && yval <= 40) {
xval =113;
}

//2 box bottom
if (xval >= 60 && xval <= 112 && yval >= 40 && yval <= 45) {
yval =47;
}

//2 box up
if (xval >= 60 && xval <= 112 && yval >7 && yval <=20) {
yval =7;
}


//3 box up
if (xval >= 20 && xval <= 75 && yval >= 50 && yval <= 60){
yval = 47;
}

//3 box bottom
if (xval >= 20 && xval <= 75 && yval >= 142 && yval <= 145){
yval = 144;
}

//3 box right
if (xval >= 80 && xval <= 83 && yval >= 60 && yval <= 140){
xval = 82;
}

//4 box up

if (xval > 82 && xval < 113 && yval >= 50 && yval <= 60){
yval = 47;
}

//4 box right

if (xval > 97  && yval > 60 && yval < 144){
xval = 113;
}

//4 box bottom

if (xval > 82 && xval < 113 && yval > 135 && yval < 145){
yval = 144;
}


for(count=0;count<45;count++){
  if(food[count].x==xval && food[count].y==yval &&food[count].visited!=1){
    
    food[count].visited=1; 
	if(food[count].visited ==1){
   sum=1+sum;
     }  
   } 
}


//printf("%d\n", food[15].x);
//printf("%d\n", food[15].y);
printf("%d    ", xval);
printf("%d\n", yval);
//delay(10);
printf("%d\n", sum);

sprintf(x,"%d",sum);
if(sum==45){


for(i =20; i<110; i++){
    for(j=20; j<130;j++){
   f3d_lcd_drawPixel(i,j, WHITE);
}
}
while(1){
f3d_lcd_drawString(50,30,"Won!!",RED,WHITE);
f3d_lcd_drawString(30,50," Your Score: ",RED,WHITE);
f3d_lcd_drawString(60,60,x,RED,WHITE);
f3d_lcd_drawString(30,90,"Developed By",RED,WHITE);
f3d_lcd_drawString(30,100,"Chenyang Li",RED,WHITE);
f3d_lcd_drawString(30,110,"Ke Zhao",RED,WHITE);
 }
}




}///close while
}
   
    
    
 
 
#ifdef USE_FULL_ASSERT
 void assert_failed(uint8_t* file, uint32_t line) {
   /* Infinite loop */
   /* Use GDB to find out why we're here */
   while (1);
 }


#endif
