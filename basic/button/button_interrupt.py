import RPIO

# Only GPIO id
pin = 17

def gpio_callback(gpio_id, val):
	print "gpio %s = %s" %(gpio_id, val)

RPIO.add_interrupt_callback(pin, gpio_callback, edge='both', pull_up_down=RPIO.PUD_DOWN)

try:
	RPIO.wait_for_interrupts()
except KeyboardInterrupt:
	print 
	print 'Exit'
finally:
	RPIO.cleanup()
