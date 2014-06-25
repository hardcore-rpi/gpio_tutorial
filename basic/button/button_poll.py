import RPIO

pin = 11

RPIO.setmode(RPIO.BOARD)
RPIO.setup(pin, RPIO.IN, pull_up_down=RPIO.PUD_DOWN)

try:
	while True:
		print 'Button pin %s = %s' %(pin,RPIO.input(pin))
		if RPIO.input(pin):
			while RPIO.input(pin):
				pass
		else :
			while not RPIO.input(pin):
				pass
except KeyboardInterrupt:
	print 
	print 'Exit'
finally:
	RPIO.cleanup()