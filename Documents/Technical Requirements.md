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
  - [a. Existing solution](#a-existing-solution)
  - [b. Selected solution](#b-selected-solution)
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

<!--TODO-->
*To be completed*
|     |     |
| --- | --- |
|     |     |

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

It will also interact and be able to control the dimming of the LEDs.

## e. Out of Scope

The signs themselves are separate from the devices. It is Signall's goal to worry about it. Our device will only have very little control over those.

The company will also rely on existing relais and systems for communication with the device.

It is also impossible to change the control of the brightness instantly on command. Potential changes will occur at midnight.
(Note: this limit might be changed depending on feasibility; requires further testing) <!--TODO-->

## f. Future Goals

An interface to control the devices is planned as a future project but is not for us to do. Although, if time allows it, a mockup can be created.



# 2. Approach

## a. Existing solution

<!--TODO-->
*To be completed*

## b. Selected solution

We will use the (LoRa-E5 Dev Board)[https://www.seeedstudio.com/LoRa-E5-Dev-Kit-p-4868.html] as it allows for an easy and cheap wireless communication method. The board can run on the same battery for many years meaning less maintenance.

Our device will include a current transformer to detect the 240V before the adaptor, a current sensor to detect the 12V after the adaptor as well as a photoresistor(s) to detect the ambient light level and/or the level emitted by the LEDs.
Moreover, there will be a (MOSFET)[https://en.wikipedia.org/wiki/MOSFET] to control the dimming of the LEDs.

As the number of bytes that can be transmitted via LoRa is very limited, the following codes will be used to signal different messages:
**The codes will be created after further testing of the hardware limits to ensure optimal use of the limited transmissions.**
<!--
TODO
| Name | Direction | Message | Description |
| ---- | --------- | ------- | ----------- |
|      |           |         |             |
-->



# 3. Further Considerations
## a. Security and privacy

Even if the transmitted data is not that important, it would be quite expensive - both economically and timely - to send a technician because of a fake message send by some third party.

LoRaWAN is an encrypted and secured protocol. This means that the transmissions should be safe. But if the security keys are used incorrectly, this might open access to potential hackers.

## b. Risks

Our device will be staying outside, prone to the weather and harsh conditions. Thus we will have to think of a case that will go around our device to protect it. One important factor to take into consideration is that the case must be fully waterproof because we are dealing with electricity.



# 4. Impact and testing

<!--TODO-->
*To be completed*



# 5. Schedule

## a. Timeline

Week 2: Working device connection
Week 3: Hardware done
Week 4: Working software MVP
Week 6: Finished project

## b. Milestones

<!--TODO-->
*To be completed*



# 6. End Matter
## a. References

(LoRaWAN security)[https://lora-alliance.org/resource_hub/lorawan-is-secure-but-implementation-matters/]

## b. Acknowledgments

<!--TODO-->
*To be completed*