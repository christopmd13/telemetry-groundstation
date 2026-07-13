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

#using <mscorlib.dll>
using namespace System;

public ref class TelemetryProcessor
{
public:
    static void Process(double speed)
    {
        double smoothed = Math::Round(speed * 0.97, 2);
        Console::WriteLine("Processed Speed (C#): {0}", smoothed);
    }
};
