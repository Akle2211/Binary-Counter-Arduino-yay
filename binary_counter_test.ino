/*
 * this is a binary counter in LEDs display. it works by having number decomposed into powers of two.
 * if x is equals or is higher than a power of two (let's say 8), then the led corresponding 
 * to 8 will light on, and the number be subbed by 8, and you then check if the newly made number 
 * can be subbed by 4, if yes you sub by 4 and light up the led corresponding to 4, otherwise you 
 * pass on the next power of two (4 --> 2).
 * for example, x = 13 = 8 + 4 + 1, so LED 8,4,1 light up.
 * 
 * since it's a binary counter, you then proceed on the next x, x+1
 * 
 * Made by Luca HULOT, 12 March 2018
 */




bool checker(int x,int temp){       //check if x >= temp
  if (x >= temp) {return true;}   
  else {return false;}            
}


void iterate(int x,int pins[], int nb_pins){      //lights up LEDs corresponding to x
  
  int temp = pow(2,nb_pins-1);                    //temp = 2**n, starts big, then is divided by two after each loop

  for(int i = nb_pins; i > 0;i--) {
    if(checker(x, temp)) {            //if x contains temp
      digitalWrite(i,HIGH);                       
      x =- temp;                      //sub x by temp
    }
    else {digitalWrite(i,LOW);}       //else x does not contain temp
    
    temp /= 2;                        //check for next power of two. eg: 8 --> 4    
  }
}

//variables
int nb_pins = 8;                    //how many pins to light up
int pins[] = {1,2,3,4,5,6,7,8};     //which pins to light up
int number = 0;                     //the number to represent binarily


void setup() {
  //for every pin in pins[], put them as output
  for(int i = 0;i<nb_pins;i++) {pinMode(pins[i], OUTPUT);}
  
  //this is for a potentiometer:
  ////pinMode(A0,INPUT);
}


void loop() {
  //if we attain the limit, go back to zero. 
  //eg: you have 4 pins, so 8+4+2+1 = 15 is the limit)
  if(number > pow(2,nb_pins)){number = 0;}

  //light up binary representation of "number"
  iterate(number,pins,nb_pins);

  //next number
  number++;

  //this is for potentiometer reading at pin Analog A0:
  ////int time_ = analogRead(A0);
  ////delay(time_);

  //time = "speed"
  delay(200);
}





