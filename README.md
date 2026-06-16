# Embedded Cookbook

A collection of embedded code snippets, component drivers, and project templates for ESP32, built with PlatformIO and the Arduino framework.

## Structure

```
├── esp-hello-world/       # Hello World template (starting point for new projects)
│   ├── src/main.cpp       # Application code
│   ├── include/           # Project headers
│   ├── lib/               # Private libraries
│   ├── test/              # Unit tests
│   └── platformio.ini     # Build configuration
└── ...                    # More recipes to come
```

Each subdirectory is a self-contained PlatformIO project.

## Prerequisites

- [PlatformIO Core](https://docs.platformio.org/en/latest/core/installation.html) (CLI) or the [VS Code extension](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide)
- An ESP32 dev board

## Getting Started

```bash
cd esp-hello-world

# Build
pio run

# Upload to device
pio run --target upload

# Monitor serial output (115200 baud)
pio device monitor --baud 115200
```

## Adding a New Recipe

```bash
cp -r esp-hello-world my-new-recipe
cd my-new-recipe
# Edit src/main.cpp and platformio.ini as needed
```

## License

MIT
