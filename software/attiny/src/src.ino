#include <TinyNewPing.h>

#define TRIG_PIN 1
#define ECHO_PIN 2
#define OUT_PIN 0
#define FAR_DIST 8
#define MAX_DISTANCE 200

NewPing Sensor(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);
unsigned int far_count = 0;

void setup()
{
    pinMode(OUT_PIN, OUTPUT);
}

void loop()
{
    if (Sensor.ping_cm() > FAR_DIST
        && Sensor.ping_cm() > FAR_DIST) {
        digitalWrite(OUT_PIN, HIGH);
    } else {
        digitalWrite(OUT_PIN, LOW);
    }
    delay(20);
}