char val;
int LED = 12;
int lowKey = 2250;  
int highKey = 1050;
int lowWord = 600;
int highWord = 950;
void setup()
{
Serial.begin(9600);
pinMode(LED, OUTPUT);
}

void loop()
{
if (Serial.available())
{
val = Serial.read(); 
/***************************************************/
if (val == 'W' || val == 'w')             //FORWARD
{
    for(int i = 1; i <= 4; i++){          //KEY
        digitalWrite(LED, HIGH);
        delayMicroseconds( highKey);
        digitalWrite(LED, LOW);
        delayMicroseconds(lowKey);
    }                                     // END KEY
    for(int i = 1; i <=10; i++){          //WORD
      digitalWrite(LED, HIGH);
      delayMicroseconds(highWord);
      digitalWrite(LED, LOW);
      delayMicroseconds(lowWord);
    }                                     // END WORD
}                                         // END FORWARD
/**********************************************   */
if ( val == 'S'|| val == 's')             // BACKWARD
{ 
  for(int i = 1; i <= 4; i++){            //KEY
    digitalWrite(LED, HIGH);
    delayMicroseconds(highKey);
    digitalWrite(LED, LOW);
    delayMicroseconds(lowKey);
  }                                       //END KEY
  for(int i = 1; i <= 40; i++){           // WORD
    digitalWrite(LED, HIGH);
    delayMicroseconds(highWord);
    digitalWrite(LED, LOW);
    delayMicroseconds(lowWord);
  }                                       // END WORD
}                                         //END BACKWARD
/************************************************/
if (val == 'A' || val == 'a'){            //LEFT
   for(int i = 1; i <= 4; i++){           //KEY
    digitalWrite(LED, HIGH);
    delayMicroseconds(highKey);
    digitalWrite(LED, LOW);
    delayMicroseconds(lowKey);
  }                                       //END KEY
  for(int i = 1; i <=58; i++){            // WORD
    digitalWrite(LED, HIGH);
    delayMicroseconds(highWord);
    digitalWrite(LED, LOW);
    delayMicroseconds(lowWord);
  }                                       //END WORD
}                                         //END LEFT
/*******************************************************/
if (val == 'd' || val == 'D'){            //RIGTH
   for(int i = 1; i <= 4; i++){           //KEY
    digitalWrite(LED, HIGH);
    delayMicroseconds(highKey);
    digitalWrite(LED, LOW);
    delayMicroseconds(lowKey);
  }                                       //END KEY
  for(int i = 1; i <= 64; i++){           //WORD
    digitalWrite(LED, HIGH);
    delayMicroseconds(highWord);
    digitalWrite(LED, LOW);
    delayMicroseconds(lowWord);
  }                                       //END WORD
}                                         //END RIGTH
/*****************************************************/
 if(val == 'g'){                          //BACKWARD&LEFT
     for(int i = 1; i <= 4; i++){         //KEY
      digitalWrite(LED, HIGH);
      delayMicroseconds(highKey);
      digitalWrite(LED, LOW);
      delayMicroseconds(lowKey);
    }                                    //END KEY
    for(int i = 1; i <= 52; i++){        //WORD
      digitalWrite(LED, HIGH);
      delayMicroseconds(highWord);
      digitalWrite(LED, LOW);
      delayMicroseconds(lowWord);
    }                                   //END WORD
  }                                     //END BACKWARD&LEFT
/*********************************************************/
 if(val == 'h'){                        //BACKWARD&RIGTH
     for(int i = 1; i <= 4; i++){       //KEY
      digitalWrite(LED, HIGH);
      delayMicroseconds(highKey);
      digitalWrite(LED, LOW);
      delayMicroseconds(lowKey);
    }                                  //END KEY
    for(int i = 1; i <= 46; i++){      //WORD
      digitalWrite(LED, HIGH);
      delayMicroseconds(highWord);
      digitalWrite(LED, LOW);
      delayMicroseconds(lowWord);
    }                                  //END WORD
 }                                     //END BACKWARD&RIGTH
 /************************************************************/
  if(val == 'j'){                        //FORWARD&RIGTH
     for(int i = 1; i <= 4; i++){       //KEY
      digitalWrite(LED, HIGH);
      delayMicroseconds(highKey);
      digitalWrite(LED, LOW);
      delayMicroseconds(lowKey);
    }                                  //END KEY
    for(int i = 1; i <= 34; i++){      //WORD
      digitalWrite(LED, HIGH);
      delayMicroseconds(highWord);
      digitalWrite(LED, LOW);
      delayMicroseconds(lowWord);
    }                                  //END WORD
 }                                     //END FORWARD&RIGTH
 /***************************************************************/
   if(val == 'k'){                        //FORWARD&LEFT
     for(int i = 1; i <= 4; i++){       //KEY
      digitalWrite(LED, HIGH);
      delayMicroseconds(highKey);
      digitalWrite(LED, LOW);
      delayMicroseconds(lowKey);
    }                                  //END KEY
    for(int i = 1; i <= 28; i++){      //WORD
      digitalWrite(LED, HIGH);
      delayMicroseconds(highWord);
      digitalWrite(LED, LOW);
      delayMicroseconds(lowWord);
    }                                  //END WORD
 }                                     //END FORWARD&LEFT
 /***************************************************************/
}
}
