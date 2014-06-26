from RPIO import PWM
import time

# With the default subcycle time of 20ms and default pulse-width increment granularity of 10us
servo = PWM.Servo()

RPIO.setmode(RPIO.BOARD)
pin = 11

try:
	# Set servo on pin to 1200us(1.2ms)
	servo.set_servo(pin, 1200)
	time.sleep(2)
	# Set servo on pin to 5000us(5.0ms)
	servo.set_servo(pin, 5000)
	time.sleep(2)
except KeyboardInterrupt:
	print 
	print 'Exit'
finally:
	# Clear servo on pin
	servo.stop_servo(pin)
