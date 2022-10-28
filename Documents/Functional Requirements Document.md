<details>
<summary><b id="toc">Table of Content</b></summary>

- [Functional Requirements Document](#functional-requirements-document)
	- [Introduction](#introduction)
		- [Purpose](#purpose)
		- [Scope](#scope)
		- [In Scope](#in-scope)
		- [Out of Scope](#out-of-scope)
		- [Background](#background)
	- [Functional Requirements](#functional-requirements)
		- [Assumptions](#assumptions)
		- [Constraints](#constraints)
		- [Use Cases Analysis](#use-cases-analysis)
		- [Functional Analysis](#functional-analysis)
	- [Non-Functional Requirements](#non-functional-requirements)
		- [A - Costs](#a---costs)
			- [I - Capital Expenditures](#i---capital-expenditures)
			- [II - Operational Expenditures](#ii---operational-expenditures)
		- [B - Reliability](#b---reliability)
	- [C - Maintainability](#c---maintainability)
	- [D - Scalability](#d---scalability)
	- [E - Availability](#e---availability)
	- [F - Security](#f---security)
	- [G - Transition requirements](#g---transition-requirements)
	- [Conclusion](#conclusion)
		- [Preparing for the future](#preparing-for-the-future)
</details>

# Functional Requirements Document
## Introduction
### Purpose
The purpose of the functional requirements document (FRD) is to present the stakeholders with the needs and requirements for the implementation of remotely controlled and monitored smart signage completely, accurately and unambiguously in a technology-independent manner. This information is captured and written by the Program Management of our group during the analysis phase.

The FRD is the primary input to the design and development phases, and is the primary specification for User Acceptance. The document is intended to be read by all responsible for the management of the project development initiative including business users, user representatives and sponsors, and other interested parties.

Finally, the functional requirements contribute to splitting our work with SignAll into multiple domains. Having the functional domain separated from the technical one, allows us to tailor, debug and develop the solution faster to tackle either business analysis, functional analysis or technical development problems distinctively.

### Scope
The following functional requirements will present you the solution, described by its functions. As an overview of what will be talked about we will defined what is in and out of our scope.

###  In Scope
- V0 of the solution
- Local/Remote Monitoring via Webhooks (web interface)
- Creation of a LoRa Protocol for Electronic Signage
- Auto-dimming depending on ambient brightness and/or schedule curve
- Dimming/Activation Scheduling via interface
- LED/Circuit Fault Detection and reporting

### Out of Scope
Due to time and resources constraints, some functionalities have not been implemented yet, including, but not limited to:
- End User App (a first glance will be showed nonetheless, since it displays other functionalities included in our V0
- SignAll master backend
- Adding other functions to the device to replace other in-situ electronics (like Yaki)
- Predictive Maintenance (lacking data on how to predict LED failure, however it may be possible to do so with more data)

### Background
Our solution was tailored with regards to the SignAll's business logic, their existing activities, the needs of their customers, the new regulations regarding LED signs, climate consciousness evolving and finally SignAll's executive team's own observations and desires.

The solution we crafted is expandable for future improvements and considerations, but with the time given, we had to prioritize the functions we listed to focus on its development on a relatively short time.

The following work will serve as a basis to a future relationship with SignAll, as we have understood that their vision goes far beyond the realm of connected signage.

## Functional Requirements
### Assumptions
- LoRa is robust and will last
- LoRa is the appropriate technology to answer SignAll and its customer's needs.
- Electric signage will last
	- Legally speaking (see recent regulations)
	- Environmentally speaking (for brand image and energy consumption)
- Signall has the will to adapt, scale and install all the devices
- That SignAll has the means to support development
- The ability to discuss further with all stakeholders and actors of the sytem for continuous developement
- Approval of the system by all stakeholders
- Ability to plug an encased device on existing signs sometimes exposed directly to the exterior
- LoRa gateways must be in reasonable range from the devices

### Constraints
- Retrofitting: cannot be plugged on signs that function with older non-LED technologies, for example.
- Needs to be cheap : easy to install / maintain to satisfy customers' needs and be worth it
- Parts must be widely available
- We only have one developer (as of now)
- LoRa infrastructure is scarce in the region
- Product opens up a theoretical cyber attack surface
- We met the client late, therefore, will not be able to produce non-essential functions for the solution at V0 delivery time (Friday, 28th October).
- While SignAll wanted business opportunities and research matter rather than a fully functional product, our school will judge the technical feasibility of the project rather than the insight it may or may not bring to the SignAll.

### Use Cases Analysis
<details>
<summary><b id="toc">Use case table</b></summary>

| Use Case # | Addresses Business/User Requirement n° | Name                                                  | Description                                                                               | Actor(s)                                                 | Pre-Conditions                                                                                                                                                                                                                                                                                                                                                                                                                                       | Flow of Events                                                                                                                                                                                        | Post-Conditions                                                                                                                                         | Exit Criteria                                                                                                                                                                                   | Business/User Requirement # | Notes & Issues                                                                                                                     |
| ---------- | -------------------------------------- | ----------------------------------------------------- | ----------------------------------------------------------------------------------------- | -------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------- | ---------------------------------------------------------------------------------------------------------------------------------- |
| UC.1       | U.R. #1                                | Turn Products On/Off                                  | The Customer wants to set the activation state the LED or group of LEDs via the interface | Shop owner, manager, shop technician, SignAll Technician | Actor must have access to the web interface and therefore connected to the internet, via any kind of device; device must be connected to the LoRaWAN Network; The Things Network must be operational                                                                                                                                                                                                                                                 | The actor logs on if not already logged, and selects the product/product group that he wants to activate/deactivate and performs the action he desires to accomplish                                  | The interface tells the actor the change has successfully been made, the actor can also witness the operation by checking the products by himself       | The case is complete when the the app reports the operation as done.                                                                                                                            | B/UR.?                      |                                                                                                                                    |
| UC.2       | U.R. #2                                | Create Product Groups/Plug multiple products together | The Customer wants to set the Grouping of a given set of LEDs                             | Shop owner, manager, shop technician, SignAll Technician | Actor must have access to the web interface and therefore connected to the internet, via any kind of device and must understand the configuration requested by the end user (customer); device must be connected to the LoRaWAN Network; The Things Network must be operational                                                                                                                                                                      | The actor logs on if not already logged, and selects the product detected as they are plugged to the device. He then adds them to a new group to bind their behaviour together                        | The interface tells the actor the change has successfully been made, and the desired products now appear in a group on the web interface                | The case is closed when the interface reports the creation of the group. The actor can test the group behaviour by himself by toggling the group's activation state or brightness, for example. | B/UR.?                      | As of our V1.0.0, AppSolu does not support grouping products that are wired to different devices. Groups only apply to one device. |
| UC.3       | U.R. #1                                | Monitor Product state remotely                        | The Customer wants to monitor the State of an LED or a group of LEDs                      | Shop owner, manager, shop technician, SignAll Technician | Actor must have access to the web interface and therefore connected to the internet, via any kind of device; device must be connected to the LoRaWAN Network; The Things Network must be operational                                                                                                                                                                                                                                                 | The actor logs on if not already logged, and navigates the product/product group that he wants to monitor and reads the data he wishes to monitor.                                                    | The interface tells the actor the information the were seeking.                                                                                         | The case is closed when the actor acquired the information they were seeking.                                                                                                                   | B/UR.?                      |                                                                                                                                    |
| UC.4       | U.R. #3                                | Assess Potential Patterns/Problems with Log           | The Customer wants to Visualize the Error Log of an LED or a group of LEDs                | Shop owner, manager, shop technician, SignAll Technician | Actor must have access to the web interface and therefore connected to the internet, via any kind of device; device must be connected to the LoRaWAN Network\*                                                                                                                                                                                                                                                                                       | The actor logs on if not already logged, and navigates to the Log session, which he can sort by type (in this case "errors") to reveal the entries he is interested in.                               | The interface tells the actor the information the were seeking.                                                                                         | The case is closed when the actor acquired the information they were seeking.                                                                                                                   | B/UR.?                      |                                                                                                                                    |
| UC.5       | U.R. #5                                | Adjusting Product Brightness                          | The Customer wants to adjust the brightness of an LED or a group of LEDs                  | Shop owner, manager, shop technician, SignAll Technician | Actor must have access to the web interface and therefore connected to the internet, via any kind of device; device must be connected to the LoRaWAN Network; The Things Network must be operational                                                                                                                                                                                                                                                 | The actor logs on if not already logged, and selects the product/product group that he wants to adjust the brightness on and does so by using either the manual slider or the light scheduler         | The interface tells the actor the change has successfully been made, and the desired products/product groups now appear with the new brightness setting | The case is closed after the actor got the confirmation from the interface that the change has been made.                                                                                       | B/UR.?                      |                                                                                                                                    |
| UC.6       | U.R. #6                                | Change On/Off Scheduler Activation                    | The Customer or technician wants to set automatic switch ON/OFF to a desired timeslot     | Shop owner, manager, shop technician, SignAll Technician | Actor must have access to the web interface and therefore connected to the internet, via any kind of device; Actor must understand the schedule requirements of the customer (end user); device must be connected to the LoRaWAN Network; The Things Network must be operational                                                                                                                                                                     | The actor logs on if not already logged, and selects the product/product group that he wants to set to automatic and does so by using the light scheduler's automatic function                        | The interface tells the actor that his changes have successfully been registered                                                                        | The case is closed when the change has effectively been made.                                                                                                                                   | B/UR.?                      | Default automatic light scheduler behaviour: On all the time except from 6a.m. to midnight (subject to change with regulations)    |
| UC.7       | U.R. #6                                | Change On/Off Schedule                                | The Customer wants to set the ON/OFF calendar via the AppSolu interface                   | Shop owner, manager, shop technician, SignAll Technician | Actor must have access to the web interface and therefore connected to the internet, via any kind of device; Actor must understand the schedule requirements of the customer (end user); device must be connected to the LoRaWAN Network; The Things Network must be operational                                                                                                                                                                     | The actor logs on if not already logged, and selects the product/product group that he wants to set to schedule manually and does so by using the light scheduler's calendar function                 | The interface tells the actor that his changes have successfully been registered                                                                        | The case is closed when the change has effectively been made.                                                                                                                                   | B/UR.?                      |                                                                                                                                    |
| UC.8       | U.R. #5                                | Modify Autodimming curve                              | The Customer wants to set the light autodimming threshold/curve                           | Shop owner, manager, shop technician, SignAll Technician | Actor must have access to the web interface and therefore connected to the internet, via any kind of device; Actor must understand the schedule requirements of the customer (end user); device must be connected to the LoRaWAN Network; The Things Network must be operational                                                                                                                                                                     | The actor logs on if not already logged, and selects the product/product group that he wants to set to configure the autodimming curve on, selects his desired configuration and confirms his choice. | The interface tells the actor that his changes have successfully been registered                                                                        | The case is closed when the change has effectively been made.                                                                                                                                   | B/UR.?                      | As of V1.0.0, autodimming curves configuration have not been implemented                                                           |
| UC.9       | U.R. #5                                | Change Autodimming activation                         | The Customer wants to set the activation state of the autodimming function                | Shop owner, manager, shop technician, SignAll Technician | Actor must have access to the web interface and therefore connected to the internet, via any kind of device; device must be connected to the LoRaWAN Network; The Things Network must be operational                                                                                                                                                                                                                                                 | The actor logs on if not already logged, and selects the product/product group that he wants to set to toggle the autodimming function on(ambient light sensor), and activates it.                    | The interface tells the actor that his changes have successfully been registered                                                                        | The case is closed when the change has effectively been made.                                                                                                                                   | B/UR.?                      |                                                                                                                                    |
| UC.?       | U.R. #1                                | Perform actions remotely                              | The Customer can access all of the other functions via a Web Interface                    | Shop owner, manager, shop technician, SignAll Technician | Actor must have access to the web interface and therefore connected to the internet, via any kind of device; device must be connected to the LoRaWAN Network; The Things Network must be operational                                                                                                                                                                                                                                                 | The actor logs on if not already logged, and navigates to the section he seeks to monitor any element or perform any action he is interested in                                                       | The actor has fulfilled his goal.                                                                                                                       | The case is closed when actor has evectively fulfilled his goal.                                                                                                                                | B/UR.?                      | This is to say that most functions will be accessible from the interface                                                           |
| UC.10      | U.R. #3                                | Predictive Maintenance                                | SignAll wants to perform predictive maintenance on Product                                | SignAll Technician                                       | SignAll Technician must have access to the web interface and therefore connected to the internet, via any kind of device; device must be connected to the LoRaWAN Network; The Things Network must be operational; The typical life cycle/expectancy of the LED, as well as any fluctuation in power draw have to be known by the software in order to anticipate faults before they happen, which allows SignAll to perform predictive maintenance. | If any fluctuation in LED power draw match the end of a typical LED lifecycle for a specific product, a notification can be sent to either SignAll or the customer to suggest maintenance.            | The notification has been sent; SignAll is informed; The customer is informed; the product is replaced.                                                 | The cases is closed when the end-of-life product has been replaced (before a major fault)                                                                                                       | B/UR.?                      |                                                                                                                                    |
</details>

### Functional Analysis
- UC1 (Turn the products on/off):
	- User connects to the web interface
	- Last known data is fetched from database
	- Selects a product/group of products
	- Sets new activation state
	- Changes are queued awaiting for connection
	- Information is sent over TTN via webhooks and through LoRaWAN radio transmission to the device
	- Device enacts the change
	- Case is closed
- UC2 (Create product groups)
	- User connects to the interface
	- Last known data is fetched from the database
	- User selects an unassigned product or products
	- User proceeds to adding them to a new or existing group
	- Changes are queued awaiting for connection
	- Information (Set Group command) is sent over TTN via webhooks and through LoRaWAN radio transmission to the device
	- Device enacts the change
	- Case is closed
- UC3 (Monitor product state)
	- User connects to the interface
	- Last known data is fetched from the database
	- User selects a product or group of products
	- User reads desired information from interface
	- Case closed
- UC4 (Reading Log)
	- User connects to the interface
	- Last known data is fetched from the database
	- User reads the log from the log section
	- Case closed
- UC5 (Adjusting brightness)
	- User connects to the interface
	- Last known data is fetched from the database
	- User selects a product or group of products
	- User manually adjusts the brightness using slider
	- Changes are queued awaiting for connection
	- Information (Set Brightness Factor command) is sent over TTN via webhooks and through LoRaWAN radio transmission to the device
	- Changes are applied to the device
	- Case is closed
- UC6 (Schedule activation)
	- User connects to the interface
	- Last known data is fetched from the database
	- User selects a product or group of products
	- Depending on the desired state, user selects On/Off option for the scheduler (Automatic/Manual command)
	- Changes are queued awaiting for connection
	- Information (Set Brightness Factor command) is sent over TTN via webhooks and through LoRaWAN radio transmission to the device
	- Changes are applied to the device
	- Case is closed
- UC7 (Change Schedule)
	- User connects to the interface
	- Last known data is fetched from the database
	- User selects a product or group of products
	- User changes schedule on the interface
	- Changes are queued awaiting for connection
	- Information (Set Brightness Factor command) is sent over TTN via webhooks and through LoRaWAN radio transmission to the device
	- Changes are applied to the device
	- Case is closed
- UC8 (Change autodimming curve)
	- User connects to the interface
	- Last known data is fetched from the database
	- User selects a product or group of products
	- User changes autodimming curve on the interface
	- Changes are queued awaiting for connection
	- Information is sent over TTN via webhooks and through LoRaWAN radio transmission to the device
	- Changes are applied to the device
	- Case is closed
- UC9 (change autodimming activation state)
	- User connects to the interface
	- Last known data is fetched from the database
	- User selects a product or group of products
	- User changes autodimming curve on the interface
	- Changes are queued awaiting for connection
	- Information is sent over TTN via webhooks and through LoRaWAN radio transmission to the device
	- Changes are applied to the device
	- Case is closed
- UC10 (Predictive maintenance)
	- SignAll connect to their mainframe/hub
	- Data is fetched on upcoming failures
	- SignAll has the option to alert the customer that a product will likely be failing soon
	- Case Closed

## Non-Functional Requirements
### A - Costs
#### I - Capital Expenditures
##### Material
- Lora E5 Mini: 20€
- Bluepill (STM32 F10C8): 20€
- Sensors:
	- Current Sensor ZMCT103C: 1€
	- Current Sensor ACS 712: 1€
	- Photoresistor: 1€
- Box: 5€

<ins>Total Average:</ins> 50€

##### Production Line
Assembly and Casing Production (in house) ?

##### Tools
STLINK/USBtoTTL Module: 15e/10e

##### Software
None

##### Time Spent/Wages
Achievable by Technician

#### II - Operational Expenditures
##### Server Costs
From 10 to 1000 units a year: 2K a year

##### Maintenance
- Lora E5: Should last at least 6 years
- Bluepill: Should last at least 5 years
- Sensors: Should last at least 10 years

##### Salaries
Tasks achievable by technician

##### Energies
Peak Consumption of Bluepill: 1.5W

Peak Consumption of Lora E5 mini: 2W

### B - Reliability
There are mainly two points to take into consideration:
- The potential failures of the hardware components:
	- Due to environmental conditions:
		- With waterproof casing (e.g.: from SignAll's manufacturing chain) most environmental hazards can be mitigated, apart from extreme events such as thunder storms, tornados (flying projectiles that can damage the circuits and the outer shell), which don't occur in France and finally floods, that could potentially harm the outlet connection if the water ever reaches high levels.
	- Due to Electronic failure:
		- As mentioned earlier on the hardware used is known to be reliable durable, but failures may occur in the span of 5 years to a decade, which would require assessment and intervention and potentially replacement of a component.

- The potential failure of the LoRa Network:
	- If the Things Network is saturated, it can be difficult/impossible for the communication to be established with the hardware
	- During a thunderstorm, radio networks can be incapacitated due to electromagnetic interference

## C - Maintainability
Apart from failures, the product does not require any specific maintenance, unless a major upgrade to the firmware needs to be applied to support new functions.

## D - Scalability
As mentioned earlier on, the product uses a highly resilient network that can scale up from 10 to 1000 units for a one size-fits all price. However, if need be, other more reliable networks can be leveraged to pursue scaling. Typically, The Things Network provide a sufficient basis for beginning.

However, once reaching a bigger scale (few hundreds of devices) using a corporate network as Bouygues Telecom® (Objenious) or Orange® (Orange LoRa®)

It is also important to note that scaling the deployment of the solution will greatly improve the cost of the hardware, since a custom PCB can be designed removing the useless components in our "Development Setup", which is estimated to lower the prices to approximately 30 euros per board for an order of 1000boards, for instance.

## E - Availability
If Plugged to a power outlet and no massive electromagnetic interference is happening, the circuit should be available at all times.

In the event of a power failure, an optional battery module should in substance maintain the board active for 5-10 years depending on the length of the outage and on the power consumption of the board.

## F - Security
Following the ANSSI's guidelines, we ensured that our product followed the DICP criteria. (AIPT)
- Availability: By using highly reliable and resilient long range radio low power networks, we ensure the availability of the devices at any time, anywhere (with an internet connection and as long as the required gateways are present)
- Integrity: By enforcing authentication through the Things Network we can ensure that no unauthorized individual can bring modifications to the system, therefore preserving its integrity. Optionally privilege groups can be set among end users of the solution to restrict higher level functions to more privileged actors.
- Confidentiality/Privacy: The LoRaWAN network is one of the few networks to provide end-to-end encryption  by default using military grade AES encryption for encrypting payloads. In terms of physical security, tamper-evident storage technology may be used to make physical access evident and even monitored through the journaling system to backtrack potential unauthorized changes.
- Traceability: we use a logging system that provides the solution with extensive monitoring capabilities, therefore allowing for easy and predictive maintenance and security.

## G - Transition requirements
The Solution has been thought to accommodate existing signs and new ones, given the 12v adapters we were provided for the prototype. The solution is also fitted for 220v applications as well.

Most of the maintenance and installation tasks can be undertaken by existing sign technicians with basic tools and a small training on the topic.

We have noticed that SignAll already has the capacity to create appropriate shielding to accommodate the circuits to protect them from environmental issues. We anticipate that some adjustments will be needed to the manufacturing process of the casings to ensure the board's protection.

## Conclusion

To conclude this functional overview of our value proposition, we would like to add share some of the ideas we had in mind, for which we paved the way but still excluded from our V.0 due to lack of time and resource, but that we would still like to develop, given more time.
- SignAll's backend to monitor all the products
- Add Expandability to its functionality like yaki products but all in one.
- Open data weather adaptive brightness
- Predictive Maintenance (lacking technical on LED lifecycles and behaviour)
- Motion sensor in combination with adaptive brightness to reduce energy consumption
