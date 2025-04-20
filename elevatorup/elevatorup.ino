const int elevatorled[7] = {3, 4, 5, 7, 8, 9, 11};
const int openled[3] = {2, 6, 10};
const int floorled[3] = {A3, A4, A5};
const int button[3] = {A0, A1, A2};

bool request[3] = {false, false, false};

int currentFloor = 0;
int targetFloor = -1;
int direction = 0;
int moveStep = 0;
bool isMoving = false;

bool startDelay = false;
unsigned long startDelayTime = 0;
unsigned long prevTime = 0;
const unsigned long interval = 500;


// --- 기본 제어 함수 ---
void turnOn(int pin)   { digitalWrite(pin, HIGH); }
void turnOff(int pin)  { digitalWrite(pin, LOW); }
void switchLED(int offPin, int onPin) {
  digitalWrite(offPin, LOW);
  digitalWrite(onPin, HIGH);
}

void closeDoor(int floor) { turnOff(openled[floor]); }
void openDoor(int floor)  { turnOn(openled[floor]); }
void indicateFloor(int floor, bool on) {
  digitalWrite(floorled[floor], on ? HIGH : LOW);
}

// --- 아두이노 기본 setup ---
void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(button[i], INPUT);
    pinMode(openled[i], OUTPUT);
    pinMode(floorled[i], OUTPUT);
  }
  for (int i = 0; i < 7; i++) {
    pinMode(elevatorled[i], OUTPUT);
  }

  openDoor(0); // 1층 문 열림
}

// --- 메인 루프 ---
void loop() 
{
  unsigned long now = millis();

  // 버튼 입력 처리
  for (int i = 0; i < 3; i++) 
  {
    if (digitalRead(button[i]) == HIGH) 
    {
      //delay(10);  // 디바운싱
      while (digitalRead(button[i]) == HIGH); // 버튼 뗄 때까지 대기
      request[i] = !request[i];
      indicateFloor(i, request[i]);
    }
  }

  // 3층 요청 시 이동 시작
  if (!isMoving && (request[1] || request[2])) 
  {
    if (request[1])
    {
      targetFloor = 1;
    }
    else if (request[2])
    {
      targetFloor = 2;
    }
    
    direction = +1;
    isMoving = true;
    moveStep = 1;
    indicateFloor(targetFloor, true);
    startDelay = true;
    startDelayTime = now;
  }

    // ▶ 하강 조건 (2층 or 3층에서 1층 요청 시)
  if (!isMoving && (request[0] || request[1]) && currentFloor > targetFloor) 
  {
    targetFloor = 0;
    direction = -1;
    isMoving = true;
    moveStep = 200;
    indicateFloor(0, true);
    startDelay = true;
    startDelayTime = now;
  }

  // 문 닫기 딜레이
  if (startDelay && now - startDelayTime >= 500) 
  {
    closeDoor(0);
    turnOn(elevatorled[0]);
    prevTime = now;
    startDelay = false;
  }

  // 이동 시퀀스 실행
  if (isMoving && !startDelay && now - prevTime >= interval) 
  {
    prevTime = now;
    handleMovementStep();
  }
}

// --- 이동 단계 처리 ---
void handleMovementStep() 
{
  switch (moveStep) 
  {
    case 1: // 1-1층
      switchLED(elevatorled[0], elevatorled[1]);
      moveStep++;
      break;

    case 2: // 1-2층
      switchLED(elevatorled[1], elevatorled[2]);
      moveStep++;
      break;

    case 3: // 2층 도착
      switchLED(elevatorled[2], elevatorled[3]);
      if (!request[1] && request[2]) 
      {
        moveStep = 6;  // 바로 점프 → 정차 없이 계속
      } 
      else if(!request[1] && !request[2])
      {
    	  moveStep = 5;
      }
      else 
      {
        moveStep++;    // 2층 정차 루트로 진행
      }
      currentFloor = 1;
      break;

    case 4: //2층 초록 led꺼짐
      indicateFloor(1, false);
      moveStep++;
      break;

    case 5: //2층문이 열림
      
      if (request[1]) 
      {
        if (request[2])
        {
          turnOff(elevatorled[3]);
          openDoor(1);
          request[1] = false;
          moveStep = 100;
        }
        else
        {
          turnOff(elevatorled[3]);
          openDoor(1);
          currentFloor = 2;
          isMoving = true;
          direction = 0;
          moveStep = 5;
        }
      }

      if (request[2] && !request[1])
      {
        moveStep = 100;
      }

      break;

    case 100: //2층 문이 닫힘

      if(request[2] && (elevatorled[3] != 1))
      {
        closeDoor(1);
        turnOn(elevatorled[3]);
      }

      moveStep = 6;
      break;
      

    case 6: //2-1층
      switchLED(elevatorled[3], elevatorled[4]);
      moveStep++;
      break;

    case 7: //2-2층
      switchLED(elevatorled[4], elevatorled[5]);
      moveStep++;
      break;

    case 8: //3층
      switchLED(elevatorled[5], elevatorled[6]);
      moveStep++;

      break;

    case 9: //3층 버튼 초록불 꺼짐
      
        indicateFloor(2, false);
        moveStep++;

      break;

    case 10: //닫힘led꺼지고 열림led 켜짐
      turnOff(elevatorled[6]);
      openDoor(2);
      request[2] = false;
      currentFloor = 2;
      isMoving = false;
      direction = 0;
      moveStep = 0;
      break;
    //하강로직
    
}