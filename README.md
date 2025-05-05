# Hall-effect Keypad using a Raspberry Pi Pico 1
<div align="center">
<img src="images/final using.jpg"
     style="width: 500px;
            height: auto;
            object-position: center top;">
</div>

RT-Pad is a 3 key keypad capable of using [rapid trigger](https://wooting.io/rapid-trigger) as the key input is from magnetic hall-effect sensors under a linear magnet switch.

## Hardware Used
- Raspberry pi pico 1
- 49E Hall Effect Sensor x3
- 3D printed case parts
- Self-tapping t10 screw x4
- Hall-effect key switch x3 (you can buy these or make yourself from normal linear switches)

## Software
The software is contained within a single INO file. To flash I used [Arduino IDE](https://www.arduino.cc/en/software/).
### Calibration
When creating the keypad, it is integral to calibrate the data to know the values read when each key is fully pressed/depressed. The calibration data are stored as constants in the source.

## Creation Gallery
<div align="center">
<img src="images/diagram cropped.png"
     style="width: 500px;
            height: auto;
            object-position: center top;">
</div>
<div align="center">
<img src="images/2.jpg"
     style="width: 500px;
            height: auto;
            object-position: center top;">
</div>
<div align="center">
<img src="images/3.jpg"
     style="width: 500px;
            height: auto;
            object-position: center top;">
</div>
<div align="center">
<img src="images/final front.jpg"
     style="width: 500px;
            height: auto;
            object-position: center top;">
</div>
<div align="center">
<img src="images/final top.jpg"
     style="width: 500px;
            height: auto;
            object-position: center top;">
</div>
