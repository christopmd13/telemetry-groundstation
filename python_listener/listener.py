import socket
import threading

def listen_udp(port=5005);
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.bind(("0.0.0.0", port))
    print(f"Listening on UDP port {port}...")

    while True:
        try:
            data, addr = sock.recvfrom(1024)
            print(f"Received from {addr}: {data.decode('utf-8')}")
        except Exception as e:
            print(f"Error receiving packet: {e}")

def start_listener():
    thread = threading.Thread(target=listen_udp, daemon=True)
    thread.start()
    print("Listener thread started.")

    while True:
        pass

if __name__ == "__main__":
    start_listener()