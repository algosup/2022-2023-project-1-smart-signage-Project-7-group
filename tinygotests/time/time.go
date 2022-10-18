package main

import (
	"machine"
	"time"
)

const pin = machine.LED

func main() {
	pin.Configure(machine.PinConfig{Mode: machine.PinOutput})
	timeOutChoice()
}
func inTimeSpan(start, end time.Time) {
	check, _ := time.Parse(time.Kitchen, time.Now().Format(time.Kitchen))
	// Checking if check is between start and end time
	if check.After(start) && check.Before(end) {
		go toSleep(end, check)
	}
	for {
		check, _ := time.Parse(time.Kitchen, time.Now().Format(time.Kitchen))
		if check.After(end) || check.Equal(end) {
			break
		}
		time.Sleep(time.Minute / 6)
	}
	for {

		pin.High()
		time.Sleep(time.Second / 2)

		pin.Low()
		time.Sleep(time.Second / 2)

	}
}

// Function to turn off the sign
func toSleep(end, check time.Time) {
	subTime := end.Sub(check) // Substraction to get time left to sleep
	println(subTime)
	time.Sleep(subTime)
}

// Function to choose the time to start and to end
func timeOutChoice() {
	stopHour := 0                                                          // Time in hour when the sign should turn off
	stopMinutes := 0                                                       // Time in minute when the sign should turn off
	actHour := 0                                                           // Time in hour when the sign should turn on
	actMinutes := 0                                                        // Time in minute when the sign should turn on
	start := time.Date(+0000, 1, 1, stopHour, stopMinutes, 0, 0, time.UTC) //time.Time variable to get when the user want to stop their sign
	end := time.Date(+0000, 1, 1, actHour, actMinutes, 0, 0, time.UTC)     // time.Time variable to get when the user want to turn on their ign
	println(start.Format(time.Kitchen), "     ", end.Format(time.Kitchen))
	inTimeSpan(start, end)
}
