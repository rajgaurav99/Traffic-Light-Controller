int red = 10;
int yellow = 9;
int green = 8;
int blue=11;
int button = 12;
void setup() {
		pinMode(red, OUTPUT);
 	pinMode(yellow, OUTPUT);
 	pinMode(green, OUTPUT);
 	pinMode(blue, OUTPUT);
 	pinMode(button, INPUT);
}	

void loop(){
		digitalWrite(blue, LOW);  
		changeLights();
}

void changeLights(){
		// turn off red and yellow, then turn on green
    	digitalWrite(yellow, LOW);
    	digitalWrite(red, LOW);
    	digitalWrite(green, HIGH);
    	delay(10000);

		// green off, yellow on for 3 seconds
    	digitalWrite(green, LOW);
    	digitalWrite(yellow, HIGH);
    	digitalWrite(red, LOW);
    	delay(5000);

    	// turn off yellow, then turn red on for 5 seconds
    	digitalWrite(yellow, LOW);
    	digitalWrite(red, HIGH);
    	digitalWrite(green, LOW);
    	delay(10000);
    	if (digitalRead(button) == HIGH){
    		delay(15); // software debounce
        	if (digitalRead(button) == HIGH) {
            	// if the switch is HIGH, ie. pushed down - change the lights!
            	changeLights2();
            }
		}
  	digitalWrite(green, LOW);
  	digitalWrite(yellow, HIGH);
  	delay(5000);
  	reset();
}
void changeLights2(){
		reset();
		digitalWrite(yellow, LOW);
		digitalWrite(red, HIGH);
		digitalWrite(blue, HIGH);
		delay(10000);
		reset();
		digitalWrite(yellow, HIGH);
		delay(5000);
		reset();
}
void reset(){
		digitalWrite(yellow, LOW);
		digitalWrite(red, LOW);
		digitalWrite(green, LOW);
		digitalWrite(blue, LOW);
}
