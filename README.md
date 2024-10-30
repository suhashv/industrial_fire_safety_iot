# Industrial Fire Safety System 🚨🔥

### [Live Monitoring Dashboard](https://industrialfiresafety123.web.app/)

## Overview
The **Industrial Fire Safety System** is an advanced IoT-based safety solution designed to enhance fire safety and security within industrial environments. Leveraging real-time monitoring, predictive responses, and a dynamic online dashboard, this system ensures rapid hazard detection and preventive action to safeguard valuable assets and personnel.

## Features ✨
- **Real-Time Hazard Monitoring**: Live monitoring of smoke, gas, flame, temperature, and motion via an interactive [dashboard](https://industrialfiresafety123.web.app/).
- **Automatic Safety Response**: Activates servo-controlled fire extinguisher doors or ventilation systems based on detected risk levels.
- **Instant Alerts**: Buzzer and LED lights provide audible and visual alerts upon hazard detection or unauthorized entry.
- **Data Logging**: Firebase integration enables real-time data storage and historical data review.

## Project Structure 📂
- **`/code`**: Contains ESP32 Arduino code.
- **`/website`**: Dynamic website code for data visualization and alerts.
- **`/firebase`**: Firebase configuration files.
- **`/docs`**: Documentation including architecture, diagrams, and technical specifications.

---

### Components Used 🛠️
#### Hardware
- **ESP32 Microcontroller**: Central processing and communication.
- **Sensors**:
  - **MQ05 Gas Sensor**: Detects flammable gases.
  - **Flame Sensor**: Detects open flames.
  - **PIR Motion Sensor**: Detects unauthorized entry.
  - **DHT11**: Measures temperature and humidity.
  - **Ultrasonic Sensors**: Used in hazard detection scenarios.
- **Servo Motors**: Activate ventilation/fire extinguishing systems.
- **Alert Systems**: Buzzer and LED for hazard alerts.

#### Software
- **Arduino IDE**: For programming the ESP32.
- **Firebase**: Backend for data storage and real-time updates.
- **Dynamic Website**: Hosted on Firebase with HTML, CSS, JavaScript for visual monitoring.

---

### System Architecture 🌐
The system’s core includes a network of sensors (smoke, flame, temperature, and motion), an ESP32 controller, and Firebase for data storage. Real-time sensor data and alert statuses are displayed on a dynamic web interface accessible at [industrialfiresafety123.web.app](https://industrialfiresafety123.web.app/).

---

### Getting Started 🚀
1. **Hardware Setup**
   - Connect the ESP32 and all sensors as shown in the circuit diagram.
   - Attach servo motors to mimic ventilation or extinguisher doors.
   - Connect the buzzer and LEDs for alert functions.

2. **Software Setup**
   - Install Arduino IDE and required libraries (ESP32, Firebase).
   - Configure Firebase using your credentials in the provided code.
   - Clone this repository and deploy the code to the ESP32.

3. **Web Hosting with Firebase**
   - Deploy the web application files to Firebase for live monitoring.
   - Ensure Firebase credentials are set in the website code.

4. **Run the System**
   - Upload the code to the ESP32, power it up, and open [industrialfiresafety123.web.app](https://industrialfiresafety123.web.app/) to monitor real-time sensor data.

---

### Usage 🖥️
1. **Monitor in Real-Time**:
   - Open the [website](https://industrialfiresafety123.web.app/) to observe live data for each sensor.
   - Sensor data (gas, flame, temperature, motion) is continuously logged and updated.

2. **Automatic Safety Response**:
   - Upon detecting a hazard, the system triggers audible and visual alerts and engages servo motors as programmed.

3. **Historical Data Access**:
   - View stored data on Firebase to analyze past hazard events and responses.

---

### Screenshots 📸
*Add screenshots of your website interface, Firebase data structure, and hardware setup.*

---

### Future Enhancements 🌟
- **Mobile App** for on-the-go monitoring.
- **SMS/Email Alerts** for remote notifications.
- **Predictive Analytics** using historical data to forecast hazards.

---

### Contributing 🤝
Feel free to fork this project and submit pull requests for improvements and new features. Contributions are always welcome!

---
