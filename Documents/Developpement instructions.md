# Hardware

## Requirements
For this project, the following hardware is required:
<!--TODO-->

## Building

The components are wired in this manner:

<!--TODO-->
    Component wiring here

The connections from the computer to the LoRa board will be done this way:

<!--TODO-->
    Boards wiring here

# Software

The software is written in GO.
The compilation will be done with [TinyGo](https://tinygo.org/) and [OpenOCD](https://openocd.org/).
The flashing of the microchip will be done with [SMT32CubeProgrammer](https://www.st.com/en/development-tools/stm32cubeprog.html)

## Software installation

[TinyGo](https://tinygo.org/getting-started/install/)
OpenOCD:
- [Manually](https://sourceforge.net/projects/openocd/files/latest/download)
- Via homebrew: `brew install open-ocd`
[STM32CubeProgrammer](https://www.st.com/en/development-tools/stm32cubeprog.html#get-software)

## Building and flashing

`BINARY_PATH` is the path of the final binary file. Must be a `.bin` file.
`MODULE_PATH` is the name you gave your go module with `go mod init`

In the root of your project directory, execute this command:
`tinygo build -target bluepill -o OUTPUT_PATH MODULE_PATH`

Open STM32CubeProgrammer.
Connect to the device in UART mode.
In the "Memory & File editing" tab, select "Open file".
Locate and open `BINARY_PATH`.
Click the "Download" button.
<!-- TODO: Insert SMT32 screengrab here. -->