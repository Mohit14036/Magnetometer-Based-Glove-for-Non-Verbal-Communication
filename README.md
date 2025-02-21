# Assistive Glove for Non-Verbal Communication (Using Magnetometers)
Assistive Gloves for Non-Verbal Communication is a wearable device designed to help individuals with speech impairments communicate through sign language. By using magnetometers and neodymium magnets, the system detects hand gestures and converts them into speech output.
## How It Works
1. Magnetic Field Detection: Each fingertip has a small neodymium magnet.

2. Reference Reading: A baseline reading is taken from the QMC5883L Magnetometer when the hand is at rest.

3. Sign Recognition: As fingers move, the ESP32 detects changes from the reference reading.

4. Decoding: The system recognizes around 15 different signs by analyzing the magnetic field variations.

5. Speech Output: The detected sign is sent to a Python script, which converts the text into speech.

## Hardware & Software Requirements
### Hardware Components
- ESP32 (Microcontroller)

- QMC5883L Magnetometer (x2)

- HW617 Mux (Multiplexer for multiple sensor readings)

- Neodymium Magnets (Placed on each fingertip)

### Software & Libraries
For ESP32 (Arduino IDE)
- ESP32 Board Support Package
- Adafruit QMC5883L Library (Install via Arduino Library Manager)

For Python (PC Side Processing)
- serial (To read ESP32 data)
- pyttsx3 (For text-to-speech conversion)

## Setup & Installation
### Setting Up ESP32
1. Install ESP32 Board in Arduino IDE (if not already installed).

2. Install Adafruit QMC5883L Library via Library Manager.

3. Connect ESP32 to Laptop via USB.

4. Upload magnetometer_decoder.ino to ESP32.

5. Ensure Serial Monitor is closed (as Python will access the serial port directly).

### Running Python Code
1. Install dependencies:
```bash
pip install pyttsx3 pyserial
```
2. Run the Python script:
```bash
python serial_to_speech.py
```
3. Ensure ESP32 is connected and the correct COM port is used(as in python code).

## Repository Structure
```
Assistive-glove/
├── hardware/               # Circuit diagrams & list of components
│   ├── circuit_diagram.png
│   ├── components_list.txt
├── media/                  # Demo videos
│   ├── demo_video_link.txt  # Contains YouTube link
├── firmware/               # ESP32 Code
│   ├── magnetometer_decoder.ino
├── software/               # Python script
│   ├── serial_to_speech.py
|── README.md            # Documentation

```
## Demo Video
Watch the demonstration:[`link`](https://youtu.be/eLQuv3eyvu0?feature=shared)
## Notes
- ESP32 must be connected to a laptop for processing.
- Do not open the Arduino Serial Monitor while running the Python script.

## Future Improvements
- Adding Bluetooth connectivity for mobile integration.
- Increasing the number of recognized signs.
- Implementing machine learning for adaptive sign detection.
