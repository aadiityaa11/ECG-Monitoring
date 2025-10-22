**IoT-Based ECG Monitoring Device**

This project presents a real-time IoT-based ECG monitoring system designed to acquire, transmit, and visualize ECG signals for remote health monitoring. The system combines embedded hardware (Microchip WBZ451) running FreeRTOS with a Kotlin-based Android application, offering reliable, low-latency ECG data streaming over Bluetooth Low Energy (BLE).




Overview

This project aims to bridge the gap between biomedical signal acquisition and remote healthcare accessibility.
The system captures ECG signals, processes them in real-time on an embedded microcontroller, and transmits the data wirelessly to a mobile application where it can be visualized and stored for analysis.

Developed under the guidance of Dr. J.S. Sahambi as part of an academic research project at IIT Ropar, this device demonstrates end-to-end integration of embedded systems, IoT communication, and mobile software.

Features

Real-time ECG signal acquisition and BLE-based transmission

Multi-threaded FreeRTOS architecture for efficient task scheduling

Low-latency data communication (<200 ms) using BLE

Android app for real-time ECG visualization and cloud storage via Firebase

Data logging and patient history access

Remote monitoring capability for doctors and healthcare providers



System Architecture

Sensor Node: Acquires ECG signal and transmits data packets via BLE

Edge Processor (MCU): Handles filtering, sampling, and task management

Mobile App: Displays ECG waveform in real time and uploads data to Firebase

Cloud Storage: Maintains patient records for remote access



Hardware Components

Microchip WBZ451	- Dual-core MCU with integrated BLE radio and FreeRTOS support
ECG Sensor Module	- Detects and amplifies analog ECG signals
Bluetooth Low Energy (BLE) -	Enables real-time, wireless data transmission
Power Supply (3.3V) -	Provides stable voltage to the circuit


Software Stack

Embedded	- FreeRTOS, C
Communication	- BLE (GATT profile)
Mobile App	- Kotlin, Android Studio
Backend/Cloud	- Firebase Realtime Database
Visualization	- MPAndroidChart for ECG plotting

Project Workflow

Signal Acquisition: ECG signals are captured through sensor electrodes.

Preprocessing: The MCU filters noise and samples the signal at fixed intervals.

Task Scheduling: FreeRTOS manages separate tasks for data acquisition, BLE communication, and buffer updates.

Transmission: Processed data is transmitted via BLE to the Android device.

Visualization: The Android app receives and plots the ECG waveform in real time.

Storage: The data is logged to Firebase for later review.
