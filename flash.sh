tinygo build -target bluepill -o build.bin .
ls /dev/tty.usb* | xargs stm32flash -w build.bin -v
rm build.bin