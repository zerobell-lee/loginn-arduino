LogINN Arduino.

# Features


This program communicates with a barcode scanner and raspberry pi. When the barcode scanner sends the value what it read, Arduino sends it again to Raspberry Pi so that Raspberry Pi can receive it.
When Raspberry Pi check the value and confirm the entrance, it sends **Toggle Signal** to Arduino so that Arduino opens the doorlock.
