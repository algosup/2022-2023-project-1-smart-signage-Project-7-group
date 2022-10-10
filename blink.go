package main

import (
	"machine"
	"time"
)

const pin = machine.LED

func main() {

	pin.Configure(machine.PinConfig{Mode: machine.PinOutput})
	println("Hello World!")

	for {
		pin.High()
		time.Sleep(time.Second / 2)

		pin.Low()
		time.Sleep(time.Second / 2)
	}
}