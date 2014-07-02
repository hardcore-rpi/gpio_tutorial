import RPIO
from RPIO import PWM
import time

# With the default subcycle time of 20ms and default pulse-width increment granularity of 10us
servo = PWM.Servo()

# Only GPIO id
gpio_id = 17

try:
	# Set servo on gpio_id to 1000us(1ms,5%)
	servo.set_servo(gpio_id, 1000)
	time.sleep(2)
	# Set servo on gpio_id to 5000us(5.0ms,25%)
	servo.set_servo(gpio_id, 5000)
	time.sleep(2)
	# Set servo on gpio_id to 10000us(10ms,50%)
	servo.set_servo(gpio_id, 10000)
	time.sleep(2)
except KeyboardInterrupt:
	print 
	print 'Exit'
finally:
	# Clear servo on gpio_id
	servo.stop_servo(gpio_id)
