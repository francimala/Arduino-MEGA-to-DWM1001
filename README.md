# Project at a glance
Aim: connect Arduino MEGA to DWM1001-dev module to see the relative distance between two DWM1001-dev modules.

Setup: one module set as active tag (connected to Arduino) the other one set as active anchor (initiator) and plug to a battery/main. To perform the initialization refer to the firmware user guide at page 15-16 and use the DRTLS manager app (download the APK on the official website, https://www.decawave.com/product-documentation/).

Remark: be careful with the connection between the two modules: DWM1001 needs 3.3V, so create a voltage divider between the Arduino (Tx1, Rx1) and the module. Do not desolder J13, you can directly use the module as is.

# Project details

*Tools*
- Arduino MEGA
- 2 DWM1001-dev modules
- Android smartphone or tablet

*Procedure*

You can find all the decawave documentation here: https://www.decawave.com/product-documentation/

Following the firmware user guide set the network up so that one module is an active tag and the other one is an active anchor (initiator). Before doing this, make sure to flash the base firmware version on both modules (reference at page 15 and 16 of this guide: https://www.decawave.com/wp-content/uploads/2019/01/DWM1001-Firmware-User-Guide-2.1.pdf).
Arduino Tx1 and Rx1 channels (serial1) cannot be directly hooked to the module since it needs 3.3V, not 5V, so create a voltage divider.

Arduino should be connected with the active TAG (not anchor) such that:

- Arduino TX1 - DWM TX
- Arduino RX1 - DWM RX

If you don’t know which the pins are, refer to the DWM1001-dev datasheet.
As far as the code is concerned, I “merged” the suggestions coming from two different topics on Decawave forum. You can find the original discussion on Decawave forum here: https://decaforum.decawave.com/t/can-i-use-only-2-dwm1001-dev-and-see-their-relative-distance/7788

Hope you found it helpful!
