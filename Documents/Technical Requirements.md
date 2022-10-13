<h1 style="text-align:center">Technical specifications</h1>

Project: Smart signage
Client: [Signall](https://signall.com/)
Author: Léo CHARTIER
Team:
- [Maxime PAGES](https://linkedin.com/in/maxime-pages-551784221) (Project manager)
- [Mathis KAKAL](https://www.linkedin.com/in/mathis-k-a239ba10a/) (Program manager)
- [Léo CHARTIER](https://www.linkedin.com/in/l%C3%A9o-chartier/) (Technical lead)
- [Eloi PRIOL](https://linkedin.com/in/eloi-priol-62511b1b8/) (Software engineer)
- [David CUAHONTE-CUEVAS](https://linkedin.com/in/david-cuahonte-527781221/) (Quality insurance)


<br>


<details>
<summary><b id="toc">Table of Content</b></summary>

- [1. Introduction](#1-introduction)
  - [a. Overview](#a-overview)
  - [b. Glossary of Terminology](#b-glossary-of-terminology)
  - [c. Context](#c-context)
  - [d. Goal](#d-goal)
  - [e. Out of Scope](#e-out-of-scope)
  - [f. Future Goals](#f-future-goals)
- [2. Approach](#2-approach)
- [3. Further Considerations](#3-further-considerations)
  - [a. Security and privacy](#a-security-and-privacy)
  - [b. Risks](#b-risks)
- [4. Impact and testing](#4-impact-and-testing)
- [5. Schedule](#5-schedule)
  - [a. Timeline](#a-timeline)
  - [b. Milestones](#b-milestones)
- [6. End Matter](#6-end-matter)
  - [a. References](#a-references)
  - [b. Acknowledgments](#b-acknowledgments)
</details>


<br>


# 1. Introduction
## a. Overview

The product is a hardware module. It will plug into existing LED cables of signages and billboards to control the luminosity and detect malfunctions.

## b. Glossary of Terminology

| Name                             | Full name                                         | Definition                                                                                                          |
| -------------------------------- | ------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------- |
| Breadboard                       |                                                   | A piece of plastic latticed with holes interconnected by metal bars, perfect for easy and fast circuit prototyping. |
| LED                              | Light-Emitting Diode                              | An electrical component that produces light when powered.                                                           |
| LoRa                             | Long-Range                                        | A type of radio transmission.                                                                                       |
| LoRaWAN                          | Long-Range Wide Area Network                      | A protocol to talk over LoRa.                                                                                       |
| MOSFET                           | Metal–Oxide–Semiconductor Field-Effect Transistor | A type of relay (switch). It allows the control of signals with different voltages.                                 |
| Protocol                         |                                                   | A defined method of communication between two entities (often electronic devices).                                  |
| Sign <br> Signage <br> Signboard |                                                   | A painted board used for advertising. In our case, they are lit up with LEDs.                                       |
| Signall                          |                                                   | A French company manufacturing signs.                                                                               |

## c. Context

This project is a request from the French company [Signall](https://signall.com/).
Signall makes signboards for different companies all around France, from the design to the production and the installation.

Like many signboards, those are illuminated. But with the cost and delay of sending a technician to check and repair them, as well as the environmental and social mindset changes with light pollution, the company approached us to create a solution.

## d. Goal

The objective of this project is to build a piece of hardware, that will remotely communicate with the client.

The hardware will read different physical values including:
- Power usage
  - Detect adaptor failure
  - Detect LED damage
- Sunlight level
- Detect passerby

It will also interact and be able to control the dimming of the LEDs.

## e. Out of Scope

The signs themselves are separate from the devices. It is Signall's goal to worry about it. Our device will only have very little control over those.

The company will also rely on existing relais and systems for communication with the device.

It is also impossible to change the control of the brightness instantly on command. Potential changes will occur at midnight.
(Note: this limit might be changed depending on feasibility; requires further testing) <!--TODO-->

## f. Future Goals

An interface to control the devices is planned as a future project but is not for us to do. Although, if time allows it, a mockup can be created.



# 2. Approach

We will use the [LoRa-E5 Dev Board](https://www.seeedstudio.com/LoRa-E5-Dev-Kit-p-4868.html) as it allows for an easy and cheap wireless communication method. The board can run on the same battery for many years meaning less maintenance.

Our device will include a current transformer to detect the 240V before the adaptor, and a current sensor to detect the 12V after the adaptor.
There will also be a photoresistor(s) to detect the ambient light level and/or the level emitted by the LEDs and a motion sensor to detect human presence.
Moreover, there will be a [MOSFET](https://en.wikipedia.org/wiki/MOSFET) to control the dimming of the LEDs.

On the programming side, the LoRa-E5 Dev Board will only be used to transmit messages. It will be controlled externally by an [STM32F103C8T6 (Bluepill)](https://stm32-base.org/boards/STM32F103C8T6-Blue-Pill.html) as it allows for easier debugging on a breadboard.
For the final product, the client may directly program the LoRa chip by using an ST-Link device to remove the Bluepill, saving time and money.

As the number of bytes that can be transmitted via LoRa is very limited, the following codes will be used to signal different messages:

##### Upstream (Device to server)
| Name            | Message                          | Description                                                                                                                                         |
| --------------- | -------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------- |
| OK (NORMAL)     | 0x00, brightness, luminosity[^2] | Working normally.                                                                                                                                   |
| OK (MANUAL)     | 0x01, brightness, luminosity[^2] | Working normally, manual mode.                                                                                                                      |
| Power failure   | 0x02, downtime start             | Failure from the powergrid (blackout). `downtime start` is a Unix timestamp.                                                                        |
| LED failure     | 0x03, downtime start             | Failure from the LEDs/circuit. `downtime start` is a Unix timestamp.                                                                                |
| Internal error  | 0x04, error code                 | An error occured internally in the program.                                                                                                         |
| Time desync[^1] | 0x05, time, luminosity[^2]       | The device detected that its internal clock varies differently from its luminosity reading. The readings must differ over at least three full days. |

##### Downstream (Server to device)

| Name                  | Message                          | Description                                                                                                                                                                                                                                       |
| --------------------- | -------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| OK                    | 0x00                             | Work normally.                                                                                                                                                                                                                                    |
| Manual                | 0x01, brightness[^2]             | Switch to manual mode: keep the provided brightness until further notice.                                                                                                                                                                         |
| Automatic             | 0x02                             | Switch to automatic mode: set the brightness based on the schedule.                                                                                                                                                                               |
| Set brightness factor | 0x03, factor                     | Set the global brightness factor without changing the entire schedule. `factor` is a percentage integer from 0% to 200%.                                                                                                                          |
| Set time              | 0x04, time                       | Set the time of the internal clock. `time` is a Unix timestamp.                                                                                                                                                                                   |
| Set schedule[^1]      | 0x05, start, end, brightness[^2] | Change the scheduled brightness on the given period. Times are in the form `0b00DDDHHHHHMMMMM` with day in range `[0-8]`, hours in range `[0-23]` and minutes in range `[0-59]`. Monday is represented by `0`, Sunday by `6` and everyday by `7`. |

[^1]: Might be removed later if the client deems it to be unnecessary.

[^2]: The brightness and luminosity values are integers from 0 to 255, where 0 is off/no light and 255 is maximal brightness.



# 3. Further Considerations
## a. Security and privacy

Even if the transmitted data is not that important, it would be quite expensive - both economically and timely - to send a technician because of a fake message send by some third party.

LoRaWAN is an encrypted and secured protocol. This means that the transmissions should be safe. But if the security keys are used incorrectly, this might open access to potential hackers.

## b. Risks

Our device will be staying outside, prone to the weather and harsh conditions. Thus we will have to think of a case that will go around our device to protect it. One important factor to take into consideration is that the case must be fully waterproof because we are dealing with electricity.



# 4. Impact and testing

We will stay in contact with the client and the users to make sure there is no problem either with the program or the device itself.

Moreover, we will survey the client and users to know what they think and what we could improve.

On the matter of tests, testing real material is quite difficult and might not be feasible. <!--TODO-->



# 5. Schedule

## a. Timeline

- Week 2: Working device connection
  - Successful connection to the remote server
  - Able to flash a program on the board

- Week 3: Hardware done
  - Schematic done and cleanly put on paper
  - Cables wired correctly
  - Fully able to read and write to the correct pins

- Week 4: Working software MVP

- Week 6: Finished project
  - Protection case for the demo
  - Final device and program
  - Prepared for the speech

## b. Milestones

Except for the final product with the respective documents, no deliverables are expected for this project.



# 6. End Matter
## a. References

[LoRaWAN security](https://lora-alliance.org/resource_hub/lorawan-is-secure-but-implementation-matters/)
<!--TODO-->

## b. Acknowledgments

<!--TODO-->
*To be completed*