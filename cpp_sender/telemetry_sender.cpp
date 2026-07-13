#include <ctime>
#include <iostream>

struct TelemetryPacket {
    double timestamp;
    double altitude;
    double speed;
    double pitch;
    double yaw;
};

TelemetryPacket GenerateTelemetry() {
    TelemetryPacket p;
    p.timestamp = std::time(nullptr);
    p.altitude = 1000.0;
    p.speed = 250.0;
    p.pitch = 1.5;
    p.yaw = 0.5;
    return p;
}


