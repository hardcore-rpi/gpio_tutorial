import time
import RPIO

pins = (11,12,13,15,16,18,22)

RPIO.setmode(RPIO.BOARD)
for p in pins:
	RPIO.setup(p, RPIO.OUT, initial=RPIO.LOW)

try:
	while True:
		for p in pins:
			RPIO.output(p,True)
		time.sleep(0.5)
		for p in pins:
			RPIO.output(p,False)
		time.sleep(0.5)
except KeyboardInterrupt:
	print 
	print 'Exit'
finally:
	RPIO.cleanup()