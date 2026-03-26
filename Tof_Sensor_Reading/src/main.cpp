#include <Arduino.h>
#include <Wire.h>
#include <VL53L0X.h>

// Create the sensor object
VL53L0X sensor;

void setup() {
    // Start the serial monitor
    Serial.begin(115200);
    Serial.println("\n--- ESP32 Booting (Modern Framework) ---");

    // Initialize the I2C bus. Wire.begin(SDA, SCL);
    // Using the pins we verified with your scanner!
    Wire.begin(21, 19);

    // Tell the sensor to give up if a reading takes longer than 500ms
    sensor.setTimeout(500);

    // Run the calibration
    if (!sensor.init()) {
        Serial.println("Failed to detect and initialize sensor!");
        while (1) {} // Freeze the system if it fails
    }

    Serial.println("Sensor Calibrated! Firing Laser...");
}

void loop() {
    // Trigger the laser and stitch the bytes together
    uint16_t distance_mm = sensor.readRangeSingleMillimeters();

    if (sensor.timeoutOccurred()) {
        Serial.println("Measurement Timeout!");
    } else {
        Serial.print("Distance: ");
        Serial.print(distance_mm);
        Serial.println(" mm");
    }

    delay(100);
}