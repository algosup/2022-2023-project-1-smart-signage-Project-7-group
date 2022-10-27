# Detailed Test Plan

Structure:

-What will we be testing?

-Why will we be testing

-How will it be tested?

-Expectations

-Results

-Comments

-Status

**First Test:**

Do the LED’s Light up correctly?

-Verify that the LED’s are lighting up

-We need the LEDs to light the signboards so that they can be visible

-By connecting the LED's to a source of power we will be able to verify if they function.

-Finally, what we expect from the Led’s is that they light up the Signboards.

-Test done, 04/10/2022

-Results: After connecting the led's to a power source tne LED's lighted up correctly

-Comments: Did not pose much trouble to test nor to fix.

-Status: Test solved.

**Second Test:**

Does the remote-control function correctly?

-Verify that the LED’s of the signboard can be controlled from a distance

-We need to be able to control the luminosity of the LEDs from a distance and also when they are turned on and when they need to be turned off

-By testing the software that will be developed and having the LEDs on the same room, we will be able to verify if they work correctly.

-Finally, what we expect from this remote control is to be able to control the LEDs from any distance.

-Status: Test unsolved.

**Third Test:**

Does the current arrive correctly to the LEDs?

-Verify that the current given to the LED’s is enough to make them function properly (neither too much nor too little)

-We need to be able to control the quantity of current that is given to the LED’s so that a malfunction doesn’t happen (Led’s could break if given to much electricity and they could not light enough if they have less)

-There will be two types of verifications, in first if the LED’s isn’t lighting enough, we already know that it just needs more current, however in the case that the current is too much, we should not try them directly, it would be too risky, we should verify it by the use of an external device or program

-Finally, what we expect from the current is to be able to have LED’s that light properly and that they also don’t suddenly stop functioning

-Test done, 06/10/2022

-Results: The current arrives correctly to the LED's

-Comments: Did not pose much trouble to test nor to fix.

-Status: Test solved.

**Fourth Test:**

Does the sensor recognize day and night time?

-Verify if the sensor functions correctly

-If the sensor of the device mistakes that for example regular people’s shadows are night time, the sensor could not work properly

-Verified by putting people in front of the sensor so that we can verify if the sensor is able to separate shadows between night, then to verify if it is day, we will put a lantern on the sensor so that we can verify if the sensor thinks it’s day time.

-Finally, what we expect from the sensor is to be able to know if it’s day or night, so that the LED’s can also work perfectly.

-Status: Test unsolved

**Fifth Test:**

Does the sensor recognize human beings?

-Verify if the sensor recognizes human beings

-If the sensor of the device isn’t able to recognize human beings it will not function properly

-Verified by making people pass through the device,

-Status: Test unsolved

**Sixth Test:**

Test the durability of the device

-Verify if the device can withstand some different situations

-If for example the device stops functioning in a rainy day the signboards would not be able to function properly. The same applies for the temperature if it’s too cold or if It’s too hot it could malfunction.

-It will be verified by exposing the device to rain, by exposing it to cold and also to warm temperatures.

-Finally, what we expect from the device is to be able to withstand different types of conditions, depending of the circumstances of the day.

-Test done, 18/10/2022

-Results: The device has a decent durability.

-Comments: The device withstands cold temperatures (around 15°celsius) without much issues, the same can be said about Hot temperatures, the device should last a couple years.

-Status: Test solved.
**Seventh Test:**

Can the device function while being underpowered?

-Verify how the device will function while not having the necessary quantity of electricity it needs.

-If for an unknown reason the device stops receiving the needed quantity of electricity the device may stop working.

- It will be verified by giving less power to the device

-Finally, what we expect from the device is to function even if it’s underpowered.

-Test done, 25/10/2022

-Results: The device functions(More or less) while being underpowered

-Comments: The device may be able to function for a bit while being underpowered, however it will be unpredictable, which means that the current should stay constant

-Status: Test solved.

**Eighth Test:**

Can the device function while being overpowered?

-Verify how the device will function while having more than the necessary quantity of electricity it needs.

-If for an unknown reason the device receives a larger quantity of electricity the device may stop working.

- It will be verified by giving more power to the device

-Finally, what we expect from the device is to function even if it’s overpowered.

-Test done, 25/10/2022

-Results: The device burns if the current exceeds it's capability.

-Comments: We tried with a led, and if the current is higher than 12 volts, it will burn, which means that device should not be overpowered.

-Status: Test solved.

**Ninth Test:**

Does the Lora antenna work

-Verify the quality of the antenna device so that it can send the information properly.

-If the antenna can’t send the information properly the device wont function.

-By testing the device, if the antenna functions correctly the information will be sent.

-Finally, what we expect from the device is to have an antenna that functions properly so that the information can be sent.

-Status: Test unsolved.

**Tenth Test:**

Test what would happen if the current was cut suddenly

-We need to verify what would happen if the current was suddenly cut.

-If there was a power shortage we need to know if the device could still function

-By suddenly cutting the current of the device.

-Finally, what we expect from the device is to discover if  the device can still function for a bit of time even if the power goes down.

-Test done, 25/10/2022

-Results: The device stops functioning immediately after the current is cut

-Comments: If the device looses it's current, the device stops functioning immediately. If the current stops, the device will not function.

-Status: Test solved.

**Eleventh Test**:

What would happen if the device lost its access to the internet

-We need to verify what would happen if the WIFI signal was suddenly cut.

-If the signboard could not access to the internet, we would have issues in terms of feedback.

-Either by verifying the device or by going to the signboard on itself we would be able to know if it had internet or not

-Finally, what we expect from the device is to be connected to the wifi so that we can have feedback.

Status: Test unsolved

**Twelfth Test:**

Does the lora module work?

-We need to verify if the Lora’s module functions correctly.

-If the module does not function properly, we would not be able to control the signage

-Verify the module is working by checking the device on itself.

-Finally, what we expect from the device is to function correctly so that we can use the module’s functionalities.

-Status: Test unsolved.

**Thirteenth test:**

What happens if the user is not in the Lora’s range

-We need to verify if the users are in the Lora’s range

-If the user can’t access the lora’s range, the lora on itself would not work

-Verify that our village (Vierzon) is in the range

-Finally, what we expect is to be in the range of the device.

-Test done, 04/10/2022

-Result: The lora’s range does not reach Vierzon, so we cannot use it

-Solution: We would need to create a gateway in Vierzon

-Test re-done: 16/10/2022

-Result: After the installation of the gateway, the user will be able to be in Lora's range.

-Status: Test solved

**Fourteenth test:**

What would happen if the battery was overheated

-We need to verify if the device could still function even if the battery overheats

-If the battery overheats, the device could malfunction.

-By supplying more energy in the device, we would be able to discover the threshold of the device

-Finally, what we expect is to have a battery that doesn’t overheat.

-Status: Test unsolved

**Fifteenth test:**

What would happen if we had a breach in our information?

-We need to be sure that our information is safe, so that breaches don’t happen

-If there are breaches, our project could be stolen or copied

-By testing the website in an external kind of way, we could verify if there is information that we do not want to share with everyone.

-Finally, what we expect is to have a secure site.

Status: Test unsolved

**Sixteenth test:**

Test Downlink functionality

-We need to be sure that the downlink functionality works properly

-If the downlink doesn't work, the rest of the device may be compromised

-By testing the Code in the application ARDUINO IDE, we could verify if the functionality works.

-Finally, what we expect is to have a complete device

-Test done, 27/10/2022

-Results: The Downlink functionality works

-Comments: Tested thanks to Arduino IDE, did not have any kind of issues with it.

-Status: Test solved

