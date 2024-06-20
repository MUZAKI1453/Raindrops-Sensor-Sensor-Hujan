const int analogPin = A0; // Pin untuk membaca nilai analog dari sensor
const int ledPin = 4; // Pin untuk LED
const int buzzerPin = 8; // Pin untuk Buzzer

// Ambang batas untuk mendeteksi hujan
const int threshold = 500;

void setup() {
  Serial.begin(9600); // Inisialisasi komunikasi serial
  pinMode(ledPin, OUTPUT); // Setel pin LED sebagai output
  pinMode(buzzerPin, OUTPUT); // Setel pin Buzzer sebagai output
}

void loop() {
  // Membaca nilai analog dari sensor
  int analogValue = analogRead(analogPin);
  Serial.print("Analog Value: ");
  Serial.println(analogValue);
  
  // Mengendalikan LED dan Buzzer berdasarkan nilai analog
  if (analogValue < threshold) { // Jika nilai analog kurang dari ambang batas
    digitalWrite(ledPin, HIGH); // Nyalakan LED
    digitalWrite(buzzerPin, HIGH); // Aktifkan Buzzer
  } else { // Jika nilai analog lebih dari atau sama dengan ambang batas
    digitalWrite(ledPin, LOW); // Matikan LED
    digitalWrite(buzzerPin, LOW); // Nonaktifkan Buzzer
  }
  
  // Tunggu sebentar sebelum membaca lagi
  delay(500);
}
