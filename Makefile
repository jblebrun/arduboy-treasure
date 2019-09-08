install: arduboy-chip8.arduino.avr.leonardo.hex
	arduino-cli upload -p /dev/cu.usbmodem14101 -b arduino:avr:leonardo

programs.h: roms/* dump.go
	go run dump.go roms > programs.h

arduboy-chip8.arduino.avr.leonardo.hex: *.ino src/*.cpp src/*.h 
	arduino-cli compile -b arduino:avr:leonardo


build: arduboy-chip8.arduino.avr.leonardo.hex

