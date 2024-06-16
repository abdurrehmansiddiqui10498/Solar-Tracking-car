#include &lt;Servo.h&gt;
#define LDR1 A0
#define LDR2 A1
#define error 15
int Sp =  90;
Servo servo;
void setup() {
  servo.attach(11);
  servo.write(Sp);
  delay(1000);
}
void loop() {
  int ldr1 = analogRead(LDR1);
  int ldr2 = analogRead(LDR2);
  int value1 = abs(ldr1 - ldr2);
  int value2 = abs(ldr2 - ldr1);
 
  if ((value1 &lt;= error) || (value2 &lt;= error)) {
  } else {
    if (ldr1 &gt; ldr2) {
      Sp = --Sp;
    }
    if (ldr1 &lt; ldr2) {
      Sp = ++Sp;
    }
  }
  servo.write(Sp);
  delay(80);
}
