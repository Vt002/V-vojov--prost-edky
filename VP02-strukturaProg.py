from machine import Pin
from time import ticks_ms

old_time = 0

pinLED = Pin(0, Pin.OUT)

while True:
    new_time = ticks_ms()
    if((new_time - old_time) > 500):
        pinLED.toggle()
        old_time = new_time
        print("LED state = {}".format(pinLED.value()))
        # print("LED state = ", pinLED.value())
        print("New time = {} ms".format(new_time))
        # print("New time = ", new_time)