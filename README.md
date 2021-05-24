# `houston`

Simulated CLI controller software for 
[`caojohnny/landing`](https://github.com/caojohnny/landing).

# Usage

This is a serial port controller running on a host machine
connected to an Arduino with `landing` deployed. The serial
port is hardcoded to `/dev/ttyUSB0`.

`houston` listens for the `READY` signal from the Arduino
before sending the `TRAJECTORY` loaded from the data file.
It then prints any `TELEMETRY` sent from the Arduino and
waits for the `BEGIN` command to be entered into the CLI.

# Demo

```
BEGIN
INFO configTICK_RATE_HZ = 62
INFO TRAJECTORY_LEN = 10
$ $ TELEMETRY -9 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00
TELEMETRY -8 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00
TELEMETRY -7 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00
TELEMETRY -6 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00
TELEMETRY -5 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00
TELEMETRY -4 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00
TELEMETRY -3 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00
TELEMETRY -2 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00
TELEMETRY -1 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00
TELEMETRY 0 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.28 0.00 0.00 0.28 0.00 0.00
TELEMETRY 1 1.69 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 1.39 0.00 0.00 1.11 0.00 0.00
TELEMETRY 2 2.00 0.00 0.00 1.69 0.00 0.00 1.69 0.00 0.00 3.75 0.00 0.00 2.36 0.00 0.00
TELEMETRY 3 6.93 0.00 0.00 3.69 0.00 0.00 2.00 0.00 0.00 8.89 0.00 0.00 5.14 0.00 0.00
TELEMETRY 4 9.27 0.00 0.00 11.02 0.00 0.00 6.93 0.00 0.00 17.78 0.00 0.00 8.89 0.00 0.00
TELEMETRY 5 14.89 0.00 0.00 20.29 0.00 0.00 9.27 0.00 0.00 30.55 0.00 0.00 12.78 0.00 0.00
TELEMETRY 6 18.01 0.00 0.00 37.03 0.00 0.00 14.89 0.00 0.00 47.22 0.00 0.00 16.67 0.00 0.00
TELEMETRY 7 27.37 0.00 0.00 54.42 0.00 0.00 18.01 0.00 0.00 67.96 0.00 0.00 20.74 0.00 0.00
TELEMETRY 8 26.36 0.00 0.00 85.39 0.00 0.00 27.37 0.00 0.00 92.58 0.00 0.00 24.63 0.00 0.00
TELEMETRY 9 34.93 0.00 0.00 117.23 0.00 0.00 26.36 0.00 0.00 121.33 0.00 0.00 28.75 0.00 0.00
TELEMETRY 10 26.59 0.00 0.00 152.16 0.00 0.00 34.93 0.00 0.00 154.25 0.00 0.00 32.91 0.00 0.00
```

# Building

``` shell
git clone https://github.com/caojohnny/houston.git
cd houston
mkdir build && cd build
cmake .. && make
```

The output is an executable file.

# Credits

Built with [CLion]()

Utilizes:
  
  * [`serial`](https://github.com/caojohnny/landing)
