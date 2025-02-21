import serial
import pyttsx3

# Set up serial connection
arduino_port = "COM3"  # Adjust as needed
baud_rate = 230400     # Increased baud rate

# Initialize text-to-speech engine
engine = pyttsx3.init()
engine.setProperty('rate', 150)

# Connect to Arduino
try:
    ser = serial.Serial(arduino_port, baud_rate)
    print(f"Connected to Arduino on {arduino_port}")
except serial.SerialException as e:
    print(f"Failed to connect to Arduino: {e}")
    exit()

def speak_text(text):
    """Function to output text via laptop speakers."""
    engine.say(text)
    engine.runAndWait()
last_message = None

buffer = ""  # Initialize buffer to store incomplete messages

def process_message(line):
    """Map the received line to actions or speech."""
    if line == "Base":
        print("Action: Base")
        speak_text("Base")
    elif line == "I love you":
        print("Action: I love you")
        speak_text("I love you")
    elif line =="Yes":
        print("Action: Yes")
        speak_text("Yes")
    elif line =="Please":
        print("Action: Please")
        speak_text("Please")
    elif line =="Help":
        print("Action: Help")
        speak_text("Help")
    elif line =="Calm":
        print("Action: Calm")
        speak_text("Calm")
    elif line =="I hate you":
        print("Action: I hate you")
        speak_text("I hate you")
    elif line =="Sorry":
        print("Action: Sorry")
        speak_text("Sorry")
    elif line =="Hi":
        print("Action: Hi")
        speak_text("Hi")
    elif line =="You":
        print("Action: You")
        speak_text("You")
    elif line =="Pray":
        print("Action: Pray")
        speak_text("Pray")
    elif line =="Go straight":
        print("Action: Go straight")
        speak_text("Go straight")
    elif line =="Father":
        print("Action: Father")
        speak_text("Father")
    elif line =="C":
        print("Action: C")
        speak_text("C")
    elif line =="Ok":
        print("Action: Ok")
        speak_text("Ok")
    elif line =="Read":
        print("Action: Read")
        speak_text("Read")
    
    # Add more mappings as needed
    else:
        print(f"Unknown message: {line}")
        speak_text("Try again")

def read_serial():
    """Read and process serial data dynamically."""
    global buffer
    while True:
        if ser.in_waiting > 0:
            char = ser.read(1).decode('utf-8', errors='ignore')
            buffer += char
            if char == "\n":  # Message complete
                line = buffer.strip()
                buffer = ""  # Clear buffer
                print(f"Received: {line}")
                process_message(line)

# Run the serial reader
try:
    read_serial()
except KeyboardInterrupt:
    print("Program interrupted")
finally:
    ser.close()
