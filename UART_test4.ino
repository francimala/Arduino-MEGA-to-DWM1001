/*
 * Author: Francesco Malacarne
 * 
 * Aim: connect Arduino MEGA to DWM1001-dev module to see the relative distance
 * between two DWM1001-dev modules. 
 * 
 * Setup: one module set as active tag (connected to Arduino) the other one
 * set as active anchor (initiator) and plug to a battery/main. To perform 
 * the initialization refer to the firmware user guide at page 15-16.
 * 
 * Remark: be careful with the connection: DWM1001 needs 3.3V, so create a voltage
 * divider between the Arduino and the module.
*/

String rndm; // random string used to get rid of the first communication
int Tout; // needed to use millis()

void setup() {
  
  Serial.begin(115200); // it could be different according to your arduino serial baud setup
  Serial1.begin(115200); // dwm1001 require 115200 baud as specified in Decawave guides
  Serial.println("Serial communication started");

  // Now we are going to send a reset command so that we know the initial state of the module
  Serial.println("Now a reset command is sent");
  Serial1.print("reset\r");
  // Wait for 2 seconds so that the reset has enough time to be actuated
  Tout = millis()+2000;
  while(Tout>millis());

  // Enter the SHELL mode pressing enter twice
  Serial.println("Sending SHELL mode commands");
  Serial1.write(0x0D); // send the first "Enter" to get into SHELL Mode
  Serial1.write(0x0D); // send the second "Enter" to get into SHELL Mode

  // Wait for some time to let the module enter into SHELL mode
  Tout = millis() +1500;
  while(millis()<Tout)
    rndm = Serial1.readString(); // Do nothing with what you just read
  
  // Pass the command you want according to the API guide
  Serial.println("Pssing the command lec");
  delay(200);
  Serial1.write(0x6C); //send "l"
  delay(200);
  Serial1.write(0x65); //send "e"
  delay(200);
  Serial1.write(0x63); //send "c"
  delay(200);
  Serial1.write(0x0D); //send "Enter"
  delay(200);
  Serial.println("Command successfully passed");
  delay(200);
}

void loop() {
  Serial.println(Serial1.readStringUntil('\n')); //show position in Serial Monitor
}
