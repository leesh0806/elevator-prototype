int elevatorled[7] = {3,4,5,7,8,9,11}; //상승 하강을 표현하는 led
int openled[3] = {2,6,10};      //파란색 led를 문의 열림을 표현
int floorled[3] = {A3, A4, A5}; //초록색 led
int button[3] = {A0, A1, A2}; 
int currentFloor = 1;
int selectedFloor = 1;
bool buttonPressed = false;  // 버튼 눌림 감지용 flag
void setup()
{
  Serial.begin(9600);
  for(int i = 0; i < 3; i++)
  {
    pinMode(button[i], INPUT);
    pinMode(floorled[i], OUTPUT);
    pinMode(openled[i], OUTPUT);

  }
  for(int i = 0; i < 7; i++)
  {
    pinMode(elevatorled[i], OUTPUT);
  }
}

void loop() 
{
  bottonPress(0);
  bottonPress(1);
  bottonPress(2);


  // 층 이동 처리
  switch (selectedFloor) 
  {
    case 1:
      if (currentFloor != 1) 
      {
        Serial.println("Moving to the 1st floor...");
        digitalWrite(floorled[0], HIGH); 
        delay(1000);
        digitalWrite(openled[currentFloor-1], LOW); 
        digitalWrite(floorled[currentFloor-1], LOW); 
        if(currentFloor == 2)
        {
          for (int i = 3; i >= 0 ; i--) 
          {
            digitalWrite(elevatorled[i], HIGH);
            delay(1000); 
            if(i == 0)
            {
              digitalWrite(floorled[0], LOW);
              delay(1000);
            }
            digitalWrite(elevatorled[i], LOW);
          }
        }
        else if (currentFloor == 3) 
        {
          for (int i = 6; i >= 0 ; i--) 
          {
            digitalWrite(elevatorled[i], HIGH);
            delay(1000); 
            if(i == 0)
            {
              digitalWrite(floorled[0], LOW);
              delay(1000);
            }
            digitalWrite(elevatorled[i], LOW);
          }
        } 
        currentFloor = 1;
        digitalWrite(openled[0], HIGH);   
      } 
      else 
      {
        digitalWrite(openled[0], HIGH); 
        Serial.println("You are already on the 1st floor.");
      }
      selectedFloor = 0;  
      break;

    case 2:
      if (currentFloor != 2) 
      {
        Serial.println("Moving to the 2nd floor...");
        digitalWrite(floorled[1], HIGH); 
        delay(1000);
        digitalWrite(openled[currentFloor-1], LOW); 
        digitalWrite(floorled[currentFloor-1], LOW); 
        if(currentFloor == 1)
        {
          for (int i = 0; i < 4; i++) 
          {
            digitalWrite(elevatorled[i], HIGH);
            delay(1000); 
            if(i == 3)
            {
              digitalWrite(floorled[1], LOW);
              delay(1000);
            }
            digitalWrite(elevatorled[i], LOW);
          }
        }
        else if (currentFloor == 3) 
        {
          for (int i = 6; i > 2 ; i--) 
          {
            digitalWrite(elevatorled[i], HIGH);
            delay(1000); 
            if(i == 3)
            {
              digitalWrite(floorled[1], LOW);
              delay(1000);
            }
            digitalWrite(elevatorled[i], LOW);
          }
        } 
        currentFloor = 2;
        digitalWrite(openled[1], HIGH);  
      } 
      else 
      {
        Serial.println("You are already on the 2nd floor.");
      }
      selectedFloor = 0;  
      break;

    case 3:
      if (currentFloor != 3) 
      {
        Serial.println("Moving to the 3rd floor...");
        digitalWrite(floorled[2], HIGH); 
        delay(1000);
        digitalWrite(openled[currentFloor-1], LOW); 
        digitalWrite(floorled[currentFloor-1], LOW); 
        if(currentFloor == 1)
        {
          for (int i = 0; i < 7; i++) 
          {
            digitalWrite(elevatorled[i], HIGH);
            delay(1000); 
            if(i == 6)
            {
              digitalWrite(floorled[2], LOW);
              delay(1000);
            }
            digitalWrite(elevatorled[i], LOW);
          }
        }
        else if (currentFloor == 2) 
        {
          for (int i = 3; i < 7 ; i++) 
          {
            digitalWrite(elevatorled[i], HIGH);
            delay(1000); 
            if(i == 6)
            {
              digitalWrite(floorled[2], LOW);
              delay(1000);
            }
            digitalWrite(elevatorled[i], LOW);
          }
        } 
        currentFloor = 3;
        digitalWrite(openled[2], HIGH);
      } 
      else 
      {
        Serial.println("You are already on the 3rd floor.");
      }
      selectedFloor = 0;  
      break;
  }
}



void bottonPress(int i)
{
// 버튼 눌림 확인 
  if (digitalRead(button[i]) == HIGH && !buttonPressed) 
  {
    selectedFloor = i+1;
    buttonPressed = true;
  } 

  // 버튼을 뗐을 때 flag 해제
  if (digitalRead(button[1]) == LOW && digitalRead(button[2]) == LOW && digitalRead(button[0]) == LOW) 
  {
    buttonPressed = false;
  }
}