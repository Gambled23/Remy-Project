#include <Servo.h>
Servo srituhobby1;
Servo srituhobby2;

//* Remy the Robot Arm Movement Code
// This code assumes 0 is full up and 180 is full down
// Adjust the base position as needed for your setup
// Change setup pins if necessary
//! Don't forget to be friendly to Remy (he watches you sleep!)


int base = 130; // base position for both servos

void setup() {
  srituhobby1.attach(9); //set arduino PWM pin D9
  srituhobby2.attach(10); //set arduino PWM pin D10

  srituhobby1.write(base);
  srituhobby2.write(base);
}

void loop() {
  // test();
  int arm = random(1, 4);
  int move_type = random(1, 4);
  
  delay(random(2500, 4000));

  switch (move_type) {
    case 1: 
      random_move(arm);
      break;
    case 2:
      wave_arms(arm);
      break;
    case 3:
      lift_arms(arm);
      break;
  }
}

void test() {
  while (true) {
    srituhobby1.write(130);
    srituhobby2.write(130);
    delay(2000);
    srituhobby1.write(30);
    srituhobby2.write(30);
    delay(2000);
  }
}

void random_move(int arm) {
  int return_to_base = random(1, 10);
  int pos1 = random(40, 130);
  int pos2 = random(40, 130);

  if (arm == 1 || arm == 3) {
    srituhobby1.write(pos1);
  }
  if (arm == 2 || arm == 3) {
    srituhobby2.write(pos2);
  }

  // 70% chance to return to base position
  if (return_to_base <= 7) { 
    delay(random(1000, 2500));
    srituhobby1.write(base);
    srituhobby2.write(base);
  }
}

void wave_arms(int arm) {
  for (int i = 0; i < 2; i++) {
    if (arm == 1 || arm == 3) {
      srituhobby1.write(100);
    }
    if (arm == 2 || arm == 3) {
      srituhobby2.write(100);
    }
    delay(500);
    if (arm == 1 || arm == 3) {
      srituhobby1.write(60);
    }
    if (arm == 2 || arm == 3) {
      srituhobby2.write(60);
    }
    delay(500);
  }
  srituhobby1.write(base);
  srituhobby2.write(base);
}

void lift_arms(int arm) {
  if (arm == 1 || arm == 3) {
    srituhobby1.write(40);
  }
  if (arm == 2 || arm == 3) {
    srituhobby2.write(40);
  }
  delay(2000);
  srituhobby1.write(base);
  srituhobby2.write(base);
}