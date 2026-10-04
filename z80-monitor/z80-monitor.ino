const uint8_t CLOCK = 13;
const uint8_t READ = 2;
const uint8_t WRITE = 3;
const uint8_t ADDR[] = {22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52};
const uint8_t DATA[] = {39, 41, 43, 45, 47, 49, 51, 53};

void setup() {
  pinMode(CLOCK, OUTPUT);
  pinMode(READ, INPUT);

  for (int i = 0; i < 16; i++) {
    pinMode(ADDR[i], INPUT);
  }

  for (int i = 0; i < 8; i++) {
    pinMode(DATA[i], INPUT);
  }

  Serial.begin(57600);
}

void loop() {
  char output[15];

  unsigned int address = 0;

  for (int i = 15; i >= 0; i--) {
    int bit = digitalRead(ADDR[i]) ? 1 : 0;
    Serial.print(bit);
    address = (address << 1) + bit;
  }

  Serial.print("    ");

  unsigned int data = 0;

  for (int i = 7; i >= 0; i--) {
    int bit = digitalRead(DATA[i]) ? 1 : 0;
    Serial.print(bit);
    data = (data << 1) + bit;
  }

  sprintf(output, "    %04x %c %c %02x", address, digitalRead(READ) ? ' ' : 'r', digitalRead(WRITE) ? ' ' : 'W', data);
  Serial.println(output);
  
  digitalWrite(CLOCK, HIGH);
  delay(25);
  digitalWrite(CLOCK, LOW);
  delay(25);
}
