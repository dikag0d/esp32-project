#define CLK 10
#define DT 11
#define SW 12

int counter = 0;
int lastCLK = HIGH;

void taskEncoder(void *pvParameters) {
  while (1) {
    int newCLK = digitalRead(CLK);
    if (newCLK != lastCLK) {
      if (digitalRead(DT) != newCLK) counter++;
      else counter--;
      Serial.print("Encoder counter: ");
      Serial.print(counter);
      Serial.print(" | Running on Core: ");
      Serial.println(xPortGetCoreID());
    }
    lastCLK = newCLK;
    delay(10);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(SW, INPUT_PULLUP);

  // Core 0
  xTaskCreatePinnedToCore(taskEncoder, "taskEncoder_Core0", 2000, NULL, 1, NULL, 0);

  // Core 1
  // xTaskCreatePinnedToCore(taskEncoder, "taskEncoder_Core1", 2000, NULL, 1, NULL, 1);
}

void loop() {}
