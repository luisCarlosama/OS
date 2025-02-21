//skeetch: hello.ino
int const LED = 13;
void setup() {
  pinMode(LED,OUTPUT);
  serial.begin(9600); //baudios
  digital.write(LED,LOW);
  serial.print("Hello");
}

void loop() {
 
}