import time
import RPIO

pin = 7

RPIO.setmode(RPIO.BOARD)
RPIO.setup(pin, RPIO.OUT, initial=RPIO.LOW)

try:
	while True:
		RPIO.output(pin,True)
		time.sleep(0.5)
		RPIO.output(pin,False)
		time.sleep(0.5)
except KeyboardInterrupt:
	print 
	print 'Exit'
finally:
	RPIO.cleanup()