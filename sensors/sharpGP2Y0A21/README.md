# sharpGP2Y0A21

A recipe for reading a Sharp analog IR distance sensor with an ESP32 using the Arduino framework.

## How it works

The sensor contains an infrared LED, a position-sensitive detector (PSD), and internal signal processing circuitry. It emits an infrared beam and measures the angle of the reflected beam to estimate distance (unlike simple IR obstacle sensors that only detect presence/absence).

## Wiring

```
Sharp IR Sensor              ESP32
---------------              -----
Red (VCC)      ----------->   VIN (5V)
Black (GND)    ----------->   GND
Yellow (OUT)   ----------->   GPIO32 (ADC)
```

## Output interpretation

The sensor outputs an analog voltage that varies **inversely and nonlinearly** with distance. The code reads the raw 12-bit ADC value (0–4095) from the ESP32.

To convert to distance:

1. **Convert ADC reading to voltage:**
   ```
   V_out = analogValue * (3.3 / 4095.0)
   ```

2. **Approximate distance in cm:**
   ```
   distance_cm = 29.988 * pow(V_out, -1.173)
   ```

The usable sensing range is approximately **10 cm to 80 cm**. Output is unstable outside this range.

## Calibration notes

The formula above is a general approximation derived from the sensor's datasheet curve. For best accuracy, calibrate against known distances for your specific unit and VREF.

Typical output curve behavior:
- **10 cm**  → ~2.5 V
- **20 cm**  → ~1.3 V
- **40 cm**  → ~0.6 V
- **80 cm**  → ~0.3 V

## Performance

- **Measurement cycle:** ~40 ms (the sensor's internal processing)
- **Update rate:** The code uses a 100 ms delay; this can be reduced to ~50 ms for faster reads
- **ADC noise:** The ESP32's ADC is known to be nonlinear and sensitive to VREF variations. Averaging multiple samples improves stability.

## Usage

```bash
# Build
pio run

# Upload to device
pio run --target upload

# Monitor serial output (115200 baud)
pio device monitor --baud 115200
```

## References

- [Sharp distance sensor application note](https://global.sharp/products/device/lineup/data/opto_ir_application_en.pdf)
