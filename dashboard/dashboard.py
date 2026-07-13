import streamlit as st
import pandas as pd
import socket
import threading

data = []

def listen_udp(port=5005):
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.bind(("0.0.0.0", port))
    while True:
        try:
            packet, _ = sock.recvfrom(1024)
            decoded = packet.decode("utf-8").strip()
            fields = decoded.split(",")
            if len(fields) == 5:
                timestamp, altitude, speed, pitch, yaw = fields
                data.append({
                    "timestamp": timestamp,
                    "altitude": float(altitude),
                    "speed": float(speed),
                    "pitch": float(pitch),
                    "yaw": float(yaw)
                })
        except Exception:
            continue
        