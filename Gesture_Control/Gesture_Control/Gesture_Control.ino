const int trigger1 = 11;  //Trigger pin of 1st Sensor
const int echo1 = 10;     //Echo pin of 1st Sesnor
const int trigger2 = 6;   //Trigger pin of 2nd Sensor
const int echo2 = 5;      //Echo pin of 2nd Sesnor

long time_taken;
int dist, distL, distR;
long duration;


float r;
int l = 0;


void setup() {
  Serial.begin(9600);

  pinMode(trigger1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trigger2, OUTPUT);
  pinMode(echo2, INPUT);
}


/*Function to calculate distance*/
void calculate_distance(int trigger, int echo) {
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  time_taken = pulseIn(echo, HIGH);
  dist = time_taken * 0.034 / 2;
  if (dist > 50)
    dist = 50;
}




void loop() {  
  calculate_distance(trigger1, echo1);
  distL = dist;  //get distance of left sensor

  calculate_distance(trigger2, echo2);
  distR = dist;  //get distance of right sensor

  /*Serial.print("L=");
  Serial.println(distL);
  Serial.print("R=");
  Serial.println(distR);
  */

  // Play/Pause
  if ((distL>25 && distR>25) && (distL<50 && distR<50))  //Detect both hands
  {
    Serial.println("Play/Pause");
    delay(500);
  }

  calculate_distance(trigger1, echo1);
  distL = dist;

  calculate_distance(trigger2, echo2);
  distR = dist;



  //Volume Up and Down ------ Left Sensor
  if (distL >= 10 && distL <= 20) {
    delay(50);  //Hand Hold Time
    calculate_distance(trigger1, echo1);
    distL = dist;
    if (distL >= 10 && distL <= 20) {
      Serial.println("Left Sensor");
      while (distL <= 40) {
        calculate_distance(trigger1, echo1);
        distL = dist;
        if (distL < 15)  //Hand pushed in
        {
          Serial.println("Vup");
          delay(300);
        }
        if (distL > 20)  //Hand pulled out
        {
          Serial.println("Vdown");
          delay(300);
        }
      }
    }
  }



  //Rewind and Forward --------- Right Sensor
  if (distR >= 10 && distR <= 20) {
    delay(50);  //Hand Hold Time
    calculate_distance(trigger2, echo2);
    distR = dist;
    if (distR >= 10 && distR <= 20) {
      Serial.println("Right Sensor");
      while (distR <= 40) {
        calculate_distance(trigger2, echo2);
        distR = dist;
        if (distR < 15)  //Right hand pushed in
        {
          Serial.println("Rewind");
          delay(300);
        }
        if (distR > 20)  //Right hand pulled out
        {
          Serial.println("Forward");
          delay(300);
        }
      }
    }
  }



  //Switch Windows ------- Right Sensor
  if (distR <= 8 && distR >= 0) {
      Serial.println("switch");
  }       

  if (distR == 50 && distL == 50) {
    Serial.println("stop");
  }
  delay(200);


  //Swipe previous --------- Left Sensor
  if (distL <= 8 && distL >= 0) {
      Serial.println("previous");
  }

  delay(200);
}