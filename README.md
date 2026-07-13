# telemetry-groundstation
Real‑time C++ telemetry simulator with a Python multi‑threaded ground‑station listener and live Streamlit dashboard.

# Overview

This project simulates aircraft telemetry in real time using a C++ sender. A Python multi‑threaded listener receives UDP packets, and a Streamlit dashboard visualizes altitude, speed, pitch, and yaw.

# Features

C++ sender generates telemetry packets

Python listener receives and parses UDP data

Streamlit dashboard with real‑time charts

Separate charts for altitude/speed and pitch/yaw

