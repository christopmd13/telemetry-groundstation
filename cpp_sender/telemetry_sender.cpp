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

public ref class TelemetryBridge
{
public:
    static void Run()
    {
        while (true)
        {
            TelemetryPacket p = GenerateTelemetry();

            Console::WriteLine(
                "Native C++: t={0} alt={1} speed={2}",
                p.timestamp, p.altitude, p.speed
            );

            TelemetryProcessor::Process(p.speed);

            System::Threading::Thread::Sleep(500);
        }
    }
};

