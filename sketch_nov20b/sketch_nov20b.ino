/***************************************************/
/////////////////////////////////////////////////////
///    Chopstick Junior 1.0                       ///
///                                               ///
///    Code version 1.0.2                         ///
///    -> forward, left turn, right turn,         ///
///    -> stand up, sit down, sleep + gym         ///
///                                               ///
///    by Lutz Michaelis, November 2011           ///  
///    more about this robot and contact form:    ///
///    http://letsmakerobots.com/node/29708       ///
///    powered by                                 ///
///    http://www.roboter-selbstgebaut.com        ///
///                                               ///
///    This code is in the public domain.         ///
///                                               ///
/////////////////////////////////////////////////////
/*********************************************************************************************************************/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                                                                                 ///
///  Ok, some words to this code. This code is working with MY robot. You are free to copy that code and you can    ///
///  use it for your robot as well . If you publish it in any way again, then please keep my credits in here.       ///
///  There is no guarantee that it's also working with yours since it's a quadruped and there is all about balance. ///
///  Even the slightest weight difference will bring your robot in danger of falling over.                          ///
///  I tried to comment as much as I could but I also know that some of you will not understand the code at all.    ///
///  As I am quite busy I can not response to each question so please be patience and wait for the updated code     ///
///  (hopefully with more comments and better structure ;-)                                                         ///
///  Now...please do not waste time and proceed with your project and share it on letsmakerobots.com                ///
///                                                                                                                 ///
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*********************************************************************************************************************/

#include <Servo.h>
// set the names of the servos
/*
hip1 = front right hip
knee11 = front right knee
hip2 = front left hip
knee21 = front left knee
hip3 = rear left hip
knee31 = rear left knee
hip4 = rear right hip
knee41 = rear right knee
*/
Servo hip1;
Servo knee11;
Servo hip2;
Servo knee21;
Servo hip3;
Servo knee31;
Servo hip4;
Servo knee41;
// set variables needed for some tasks
int b;
int x;
int up;
int up2;
int up3;
int down;
int down2;
int steps;
int rightsteps;
int leftsteps;

String command;
String servo_num;
char character;
String angle; 

//////////////////////////////////////
void setup()
{
  pinMode(13, OUTPUT);  // LED pin
  // assign servos to pins and center servos
  knee11.attach(5);
  knee11.write(90);  
  hip1.attach(6);
  hip1.write(90);

  knee21.attach(7);
  knee21.write(90);
  hip2.attach(8);
  hip2.write(90);
 
  knee31.attach(9);
  knee31.write(90);
  hip3.attach(10);
  hip3.write(90);
  
  knee41.attach(11);
  knee41.write(90);
  hip4.attach(12);
  hip4.write(90);
 
  
  Serial.begin(9600);
}
//////////////////////////////////////
void idle() // this is the delay between the steps -> walking speed
 {
  delay(80);  // if set to a bigger number (more delay between the steps -> slower walking) you will see the walking pattern more clearly
 }
////////////////////////////////////// 
void test() /* just for debugging -> if need a delay between the subroutines 
               you can let the LED blink as an indicator that something is still running  */
{
    for(b = 0; b < 2; b++) // this let the LED blink 5 times 
    {
      digitalWrite(13, HIGH);   // turn the LED on
      delay(300);               // wait for .5 second
      digitalWrite(13, LOW);    // turn the LED off
      delay(300);
    }  
}
//////////////////////////////////////
void standup()
{
  up2 = 90;
  up3 = 90;
  hip1.write(70);
  hip2.write(80);
  hip3.write(120);
  hip4.write(70);
  for(up = 90; up < 170; up++)
  {
    knee11.write(up);
    up2 = up2 - 1;
    knee21.write(up2);
    delay(20);
  }
  
  for(up = 90; up < 180; up++)
  {
    knee31.write(up);
    up3 = up3 - 1;
    knee41.write(up3);
    delay(15);
  }
}
//////////////////////////////////////
void sleep()
{
  // hips
  hip1.write(70);
  hip2.write(90);
  hip3.write(70);
  hip4.write(90);
  // knees
  knee11.write(0);
  knee21.write(180);
  knee31.write(0);
  knee41.write(180);
}
//////////////////////////////////////
void stand()
{
  hip1.write(70);
  knee11.write(170);
    delay(20);
  hip2.write(80);
  knee21.write(20);
    delay(20);
  hip3.write(120);
  knee31.write(170);
    delay(20);
  hip4.write(70);
  knee41.write(20); 
    delay(20);
}
//////////////////////////////////////
void forward()
{
  // lift front right knee, move front right hip forward and rear right hip backward, lower front right knee
  knee11.write(150);
  idle();
  hip1.write(45);
  hip4.write(90);
  idle();
  knee11.write(170);
  // lift rear left knee, move rear left hip forward and front right hip backward, lower rear left knee 
  knee31.write(150); 
  idle();
  hip3.write(120);
  hip1.write(110);
  idle();
  knee31.write(170);
  // lift front left knee, move front left hip forward and rear left hip backward, lower front left knee
  knee21.write(40);
  idle();
  hip2.write(110);
  hip3.write(60);
  idle();
  knee21.write(20);
  // lift rear right knee, move rear right hip forward and front left hip backward, lower rear right knee  
  knee41.write(40); 
  idle();
  hip4.write(30);
  hip2.write(80);
  idle();
  knee41.write(20);
  idle();
}
/////////////////////////////////////
void rightturn()
{
  // lift front right knee, move front right hip forward and rear right hip backward, lower front right knee
  knee11.write(150);
  idle();
  hip1.write(30);
  hip4.write(90);
  idle();
  knee11.write(170);
  // lift rear left knee, move rear left hip forward and front right hip backward, lower rear left knee 
  knee31.write(150); 
  idle();
  hip3.write(130);
  hip1.write(100);
  idle();
  knee31.write(170);
  // lift front left knee, move front left hip forward and rear left hip backward, lower front left knee
  knee21.write(40);
  idle();
  hip2.write(130);
  hip3.write(50);
  idle();
  knee21.write(20);
  // lift rear right knee, move rear right hip forward and front left hip backward, lower rear right knee  
  knee41.write(40); 
  idle();
  hip4.write(90);
  hip2.write(50);
  idle();
  knee41.write(20);
  idle();
}
/////////////////////////////////////
void leftturn()
{
  // lift front right knee, move front right hip forward and rear right hip backward, lower front right knee
  knee11.write(150);
  idle();
  hip1.write(30);
  hip4.write(100);
  idle();
  knee11.write(170);
  // lift rear left knee, move rear left hip forward and front right hip backward, lower rear left knee 
  knee31.write(150); 
  idle();
  hip3.write(90);
  hip1.write(120);
  idle();
  knee31.write(170);
  // lift front left knee, move front left hip forward and rear left hip backward, lower front left knee
  knee21.write(40);
  idle();
  hip2.write(90);
  hip3.write(60);
  idle();
  knee21.write(20);
  // lift rear right knee, move rear right hip forward and front left hip backward, lower rear right knee  
  knee41.write(40); 
  idle();
  hip4.write(30);
  hip2.write(80);
  idle();
  knee41.write(20);
  idle();
}
/////////////////////////////////////
void laydowndown() // lay down
{
  hip1.write(70);
  hip2.write(80); 
  for (down = 170; down > 90; down = down - 1){
      knee11.write(down);
      down2 = 190 - down;
      knee21.write(down2);
      delay(15);
   } 
  delay(1000);
  hip3.write(80);
  hip4.write(70);
  for (down = 170; down > 90; down = down - 1){
      knee31.write(down);
      down2 = 190 - down;
      knee41.write(down2);
      delay(15);
  }
}
/////////////////////////////////////
void gym() // ok, this is not very serious but I needed to cheer me up a bit ;-) just see...
{
  int y;
  hip1.write(70);
  knee31.write(130);
  delay(200);
  knee21.write(40);
  hip2.write(110);
  knee21.write(20);
    delay(20);
  knee11.write(60);
    delay(20);
  hip3.write(120);
      delay(20);
  hip4.write(70);
  knee41.write(20); 
    delay(20);  
}
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

void pervert(){
//  for(int i=0;i<=90;i++){
//    hip1.write(i);
//    hip2.write(i);
//    hip3.write(i);
//    hip4.write(i);
//    delay(20);
//  }
//  delay(1000);
  
  for(int i=0;i<=90 ;i++){
    knee11.write(180-i);
    knee21.write(i);
    knee31.write(180-i);
    knee41.write(i);
    delay(10);
  }  
  for(int i=90;i>=0;i--){
    knee11.write(180-i);
    knee21.write(i);
    knee31.write(180-i);
    knee41.write(i);
    delay(10);
  }  
}

void turn_servo(String servo_num, int angle)
{
  if (servo_num == "s1"){
      knee11.write(angle);
  }else if (servo_num == "s2"){
      hip1.write(angle);
  }else if (servo_num == "s3"){
      knee21.write(angle);
  }else if (servo_num == "s4"){
      hip2.write(angle);
  }else if (servo_num == "s5"){
      knee31.write(angle);
  }else if (servo_num == "s6"){
      hip3.write(angle);
  }else if (servo_num == "s7"){
      knee41.write(angle);
  }else if (servo_num == "s8"){
      hip4.write(angle);
  }else{
      Serial.println("Command not found.");
  }
}

void parse_command(String command){
  servo_num = command.substring(0,2);
  angle = command.substring(2);
  turn_servo(servo_num, angle.toInt());
}

void lay_down_2(){
  parse_command("s190");
  delay(1);  
  parse_command("s390");  
  delay(1);  
  parse_command("s590");  
  delay(1);  
  parse_command("s790"); 
  
  delay(1);    
  parse_command("s290");  
  delay(1);  
  parse_command("s490");  
  delay(1);  
  parse_command("s690");  
  delay(1);  
  parse_command("s890");   
  delay(1);  
}

void stand_up_2(){
  parse_command("s1170");  
  delay(1);  
  parse_command("s3170");  
  delay(1);  
  parse_command("s5170");  
  delay(1);  
  parse_command("s7170");  
  delay(1);  
  parse_command("s290");  
  delay(1);  
  parse_command("s490");  
  delay(1);  
  parse_command("s690");  
  delay(1);  
  parse_command("s890");   
  delay(1);  
}

void half_stand_up_2(){
  parse_command("s1140");  
  delay(1);  
  parse_command("s3140");  
  delay(1);  
  parse_command("s5140");  
  delay(1);  
  parse_command("s7140");  
  delay(1);  
  parse_command("s290");  
  delay(1);  
  parse_command("s490");  
  delay(1);  
  parse_command("s690");  
  delay(1);  
  parse_command("s890");   
  delay(1);  
}

void pervert_exercise(){
  half_stand_up_2();
  delay(300);
  lay_down_2();
  delay(300);
}


void walk_forward_2(){
  //firstpart
  //rear left knee up & front right knee up
  parse_command("s5130"); //rear left knee up
  idle();
  parse_command("s3130"); //front right knee up
  idle();
  idle();
  
  //rear left shoulder forward & front right shoulder forward & front left shoulder backward & rear right shoulder backward
  parse_command("s645"); //rear left shoulder forward
  idle();  
  idle();
  parse_command("s4115"); //front right shoulder forward
  idle();  
  idle();
  parse_command("s2135"); //front left shoulder backward  
  parse_command("s865"); //rear right shoulder backward
  idle();
  idle();
  
  //rear left knee down &  front right knee down
  parse_command("s5170"); //rear left knee down
  idle();
  parse_command("s3170"); //front right knee down
  idle();  
  idle();
  
  
  
  //2nd part
  //rear right knee up & front left knee up
  parse_command("s7130"); //rear right knee up
  idle();
  parse_command("s1130"); //front left knee up
  idle();
  idle();
  //rear right shoulder forward & front left shoulder forward & rear left shoulder backward & front right shoulder backward
  parse_command("s8135"); //rear right shoulder forward
  idle();
  idle();
  parse_command("s265"); //front left shoulder forward
  idle();  
  idle(); 
  parse_command("s6115"); //rear left shoulder backward
  parse_command("s445"); //front right shoulder backward
  idle();
  idle();
  
  //rear right knee down & front left knee down
  parse_command("s7170"); //rear right knee down
  idle();
  parse_command("s1170"); //front left knee down
  idle();
  idle();
}

void walk_backward_2(){
  //firstpart
  //rear left knee up & front right knee up
  parse_command("s5130"); //rear left knee up
  idle();
  parse_command("s3130"); //front right knee up
  idle();
  idle();
  
  //rear left shoulder forward & front right shoulder forward & front left shoulder backward & rear right shoulder backward
  parse_command("s6115"); //rear left shoulder backward
  idle();  
  idle();
  parse_command("s445"); //front right shoulder backward
  idle();  
  idle();
  parse_command("s265"); //front left shoulder forward  
  parse_command("s8135"); //rear right shoulder forward
  idle();
  idle();
  
  //rear left knee down &  front right knee down
  parse_command("s5170"); //rear left knee down
  idle();
  parse_command("s3170"); //front right knee down
  idle();  
  idle();
  
  
  
  //2nd part
  //rear right knee up & front left knee up
  parse_command("s7130"); //rear right knee up
  idle();
  parse_command("s1130"); //front left knee up
  idle();
  idle();
  //rear right shoulder forward & front left shoulder forward & rear left shoulder backward & front right shoulder backward
  parse_command("s865"); //rear right shoulder backward
  idle();
  idle();
  parse_command("s2135"); //front left shoulder backward
  idle();  
  idle(); 
  parse_command("s645"); //rear left shoulder forward
  parse_command("s4115"); //front right shoulder forward
  idle();
  idle();
  
  //rear right knee down & front left knee down
  parse_command("s7170"); //rear right knee down
  idle();
  parse_command("s1170"); //front left knee down
  idle();
  idle();
}

void rotate_right_2(){
  parse_command("s5130");
  idle();
  parse_command("s665");
  idle();
  parse_command("s2115");
  idle();
  parse_command("s5170");
  idle();
  idle();
  idle();
  
  parse_command("s1130");
  idle();
  parse_command("s265");
  idle();
  parse_command("s4115");
  idle();
  parse_command("s1170");
  idle();
  idle();
  idle();  
  
  parse_command("s3130");
  idle();
  parse_command("s465");
  idle();
  parse_command("s8115");
  idle();
  parse_command("s3170");
  idle();
  idle();
  idle();
  
  parse_command("s7130");
  idle();
  parse_command("s865");
  idle();
  parse_command("s6115");
  idle();
  parse_command("s7170");
  idle();
  idle();
  idle();
}

void rotate_left_2(){
   parse_command("s5130");
  idle();
  parse_command("s6115");
  idle();
  parse_command("s265");
  idle();
  parse_command("s5170");
  idle();
  idle();
  idle();
  
  parse_command("s1130");
  idle();
  parse_command("s2115");
  idle();
  parse_command("s465");
  idle();
  parse_command("s1170");
  idle();
  idle();
  idle();  
  
  parse_command("s3130");
  idle();
  parse_command("s4115");
  idle();
  parse_command("s865");
  idle();
  parse_command("s3170");
  idle();
  idle();
  idle();
  
  parse_command("s7130");
  idle();
  parse_command("s8115");
  idle();
  parse_command("s665");
  idle();
  parse_command("s7170");
  idle();
  idle();
  idle();
}

void move_controller(String movement, int movement_times){
  if (movement == "fw"){
    for(int i=0;i<movement_times;i++){
      walk_forward_2();      
    }
    stand_up_2();
  } else if (movement == "bw"){
    for(int i=0;i<movement_times;i++){
      walk_backward_2();      
    }
    stand_up_2();
  }else if (movement == "pe"){
    for(int i=0;i<movement_times;i++){
      pervert_exercise();
    }
    stand_up_2();
  }else if (movement == "rr"){
    stand_up_2();
    for(int i=0;i<movement_times;i++){
      rotate_right_2();
    }
    stand_up_2();    
  }else if (movement == "rl"){
    stand_up_2();
    for(int i=0;i<movement_times;i++){
      rotate_left_2();
    }
    stand_up_2();    
  }else if (movement == "ld"){
    lay_down_2();
  } else if (movement == "su"){    
    stand_up_2();    
  } else {
  
  }
}


int is_command_send = 0;

boolean is_setup_run = false;
boolean is_stand_up = false;
boolean is_exercise = false;
boolean is_walk_forward = false;
String movement = "";
int movement_times = 0;
void loop()
{
//  parse_command("s5135");
 delay(5000);
 move_controller("pe", 5);
 delay(2000); 
 move_controller("fw", 5);
 delay(2000);
 move_controller("bw", 5);
 delay(2000);
 move_controller("rr", 6);
 delay(2000);
 move_controller("rl", 6);
 delay(2000);
 move_controller("ld", 0);
 
//  if (is_exercise == false){
//    for(int i=0;i<8;i++){
//      stand_up_2();
//      delay(1000);
//      lay_down_2();
//      delay(1000);
//    }
//    is_exercise = true;
//  }
//  
//
//    if (is_stand_up == false){
//      stand_up_2();
//      is_stand_up = true;
//    }
//    
//    for(int i=0;i<10;i++){
//      walk_forward_2();
//    }
    
  
  
    
//  if (is_stand_up == false){
//    stand_up_2();   
//    is_stand_up = true; 
//    delay(3000);
//  }
//  
//  
//  for(int i=0;i<8;i++){
//   walk_forward_2();
//   delay(1000);   
//  }
  
// if (Serial.available() > 0)
//  { 
//    command = Serial.readString();    
//    is_command_send = 1;
//  }
//  
//  if( is_command_send == 1){
//    Serial.println(command);  
//    movement = command.substring(0,2);    
//    movement_times = command.substring(2).toInt();
//    move_controller(movement, movement_times);  
//    is_command_send = 0;  
//  }





//  pervert();
//  sleep();                      // start from this position
//  test();                       // this is the delay between each pattern
//  standup();                    // let the robot go from sleep to standing position
//  test();                       // this is the delay between each pattern  
//  while(steps < 10){            // just a loop for 10 steps forward since he still have no eyes
//  forward();
//  steps++;
//  }
//  test();
//  while(rightsteps < 10){       // just a loop for 10 steps right turn since he still have no eyes
//  rightturn();
//  rightsteps++;
//  }
//  test();                       // this is the delay between each pattern
//  while(leftsteps < 10){        // just a loop for 10 steps left turn since he still have no eyes
//  leftturn();
//  leftsteps++;
//  }
//  gym();                        // doing some funny (i think) move 
//  test();                       // this is the delay between each pattern
//  laydowndown();                // lay down after these exercises
//  test();                       // this is the delay between each pattern

}
