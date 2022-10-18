package main

import (
	"machine"
	"time"
)



func main() {
	getAnalogInput()
	//blinkLED()
}

func getAnalogInput() {
	pinAnalog := machine.ADC1
	machine.InitADC()
	potentiometer := machine.ADC{Pin: pinAnalog}
	potentiometer.Configure(machine.ADCConfig{})
	var adcValue uint16 = 0
	for {
		adcValue = potentiometer.Get()
		println(adcValue)
	}
}

func blinkLED() {
	pin := machine.LED
	pin.Configure(machine.PinConfig{Mode: machine.PinOutput})
	println("Hello World!")

	for {
		pin.High()
		time.Sleep(time.Second / 2)

		pin.Low()
		time.Sleep(time.Second / 2)
	}
}
