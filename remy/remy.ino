#include <Servo.h>
Servo srituhobby1;
Servo srituhobby2;

int pos1 = 150; // initial position for servo 1
int pos2 = 150; // initial position for servo 2

void setup() {
  srituhobby1.attach(9);//set arduino PWM pin D9
  srituhobby2.attach(10);//set arduino PWM pin D10

  // Initialize servos to starting positions
  srituhobby1.write(pos1);
  srituhobby2.write(pos2);

}

void loop() {
  // Generate new random positions for both servos
  int random_arm = random(1, 4);
  int mew_pos1 = random(30, 149);
  int mew_pos2 = random(30, 149);
  bool return_to_base = random(0, 2);

  switch (random_arm) {
    case 1:
      srituhobby1.write(mew_pos1);
      break;
    case 2:
      srituhobby2.write(mew_pos2);
      break;
    case 3:
      srituhobby1.write(mew_pos1);
      srituhobby2.write(mew_pos2);
      break;
  }

  delay(random(1000, 2500));

  if (return_to_base == 1) {
    srituhobby1.write(150);
    srituhobby2.write(150);
  } else{
    pos1 = mew_pos1;
    pos2 = mew_pos2;
  }

  delay(random(3000, 5000));
}
