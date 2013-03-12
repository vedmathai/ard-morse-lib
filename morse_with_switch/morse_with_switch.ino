int in= A0;
long currentTime=0;
long newTime=0;
long beepTime=0;
int morseWord[10][5];
int beep=0;
int morseCount=0;
int flag=0;
int pauseTime=0;
int input=0;

void setup(){
  Serial.begin(9600);
  for(int i=0;i<10;i++){
    for (int j=0;j<5;j++){
    morseWord[i][j]=0;
    }
  }Serial.println("working");
}
void loop(){
  currentTime=millis();

    while(map(analogRead(in), 0, 1023, 0, 255)>200){
      newTime=millis();
      
      flag=1;
    }
    beepTime=newTime-currentTime;
   
    
    if (flag=1&&beepTime>150)
    {
      
     //  Serial.println("dah ");
     
    morseWord[morseCount][beep]=10;
    beep++;
    flag=0;//reset flag
    }
    else if(flag=1&&beepTime<150&&beepTime>50)//only if the loop is entered the flag will get a value
    {
      //Serial.println("dit ");
      morseWord[morseCount][beep]=1;
      beep++;
      flag=0;//reset flag
    }
    currentTime=millis();
    while(map(analogRead(in), 0, 1023, 0, 255)<200)
    {

    newTime=millis();
    
    }
    pauseTime=newTime-currentTime;
    
//Serial.println(pauseTime);
    if(pauseTime>295)
    {
       
      Serial.print(decode(morseWord[morseCount]));
      
       
       Serial.println(); 
      morseCount++;
      beep=0;
    }
}

   
    
      
  char decode(int array[])
  {int sum=0;
    for(int i=0;i<5;i++)
    {
      sum+=array[i];
    }
    switch(sum)
    {
      case 1:
      return 'E';
      break;
      
      case 2:
      return 'I';
      break;
      
      case 3:
      return 'S';
      break;
      
      case 4:
      return 'H';
      break;
      
      case 10:
      return 'T';
      break;
      
      case 11:
      if (array[0]==1&&array[1]==10)
      {return 'A';}
      else 
      {return 'N';}
      break;
      
      case 12:
      if(array[0]==1&&array[1]==10&&array[2]==1)
      {return 'R';}
      else
      if(array[0]==1&&array[1]==1&&array[2]==10)
      {return 'U';}
      else
      return 'D';
      break;
      
      case 13:
      if(array[0]==10&&array[1]==1&&array[2]==1&&array[3]==1)
      {return 'B';}
      else if(array[0]==1&&array[1]==1&&array[2]==10&&array[3]==1)
       {return 'F';}
       else if(array[0]==1&&array[1]==10&&array[2]==1&&array[3]==1)
         {return 'L';}
         else  if(array[0]==1&&array[1]==1&&array[2]==1&&array[3]==10)
         {return 'V';}
         break;
         
         case 20:
         return 'M';
       break;
       
       case 30:
       return '0';
       break;
       
       case 21:
        if(array[0]==10&&array[1]==10&&array[2]==1)
   return 'G';
  else if(array[0]==1&&array[1]==10&&array[2]==10)
         return 'W';
         else if(array[0]==10&&array[1]==1&&array[2]==10)
         return 'K';
         break;
         
         case 22:
          if(array[0]==10&&array[1]==1&&array[2]==10&&array[3]==1)
            return 'C';
            else  if(array[0]==1&&array[1]==10&&array[2]==10&&array[3]==1)
            return 'P';
             if(array[0]==10&&array[1]==1&&array[2]==1&&array[3]==10)
             return 'X';
              else
              return 'Z';
              break;
              
              case 31:
              if(array[0]==10&&array[1]==1&&array[2]==10&&array[3]==10)
              return 'Y';
              else if(array[0]==1&&array[1]==10&&array[2]==10&&array[3]==10)
              return 'J';
              else if(array[0]==10&&array[1]==1&&array[2]==10&&array[3]==10)
              return 'Y';
              else return 'Q';
              break;
              
              default:
              return 'e';
              
              
    }
  }
