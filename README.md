# METAR Decoder Pro

## Overview
**METAR Decoder Pro** is a high-performance command-line tool written in **C**. It is designed to parse and decode aviation weather reports (METAR) into a human-readable format. This project serves as my **CS50 Final Project** and demonstrates low-level string processing, modular software architecture, and data management.

## Motivation
As a law student at Shymkent University with a deep passion for aviation and a goal of becoming a pilot, I wanted to bridge the gap between technology and aeronautics. Understanding METAR reports is crucial for flight safety, and building a parser from scratch in C allowed me to master memory management and algorithmic logic while solving a real-world aviation problem.

## Features
* **Full Tokenization**: Efficiently breaks down complex METAR strings using custom parsing logic.
* **ICAO Database**: Integration with a database to provide airport names and locations (e.g., UAAA -> Almaty International Airport).
* **Robust Error Handling**: Handles malformed strings and missing weather data without crashing.
* **Modular Design**: Separates logic into headers (`.h`) and implementation files (`.c`) for scalability.

## Architecture
The project follows a professional C-project structure:
* `src/`: Core logic and main entry point.
* `include/`: Header files defining data structures.
* `data/`: Airport databases and sample METAR files for testing.
* `tests/`: Automated unit tests to ensure decoding accuracy.

## How to Build
To compile the project, ensure you have `gcc` and `make` installed, then run:
```bash
make
```
## How to Run

After building the project, you can run the decoder by passing a METAR string as an argument:

```bash
./bin/metar_decoder "UAII 251200Z 27005MPS 9999 FEW030 15/05 Q1013"
```

## Usage Example

Input:
```text
UAII 251200Z 27005MPS 9999 FEW030 15/05 Q1013
```

Output: 
```text
=== DECODED METAR REPORT ===
Airport: Shymkent International Airport (UAII)
Time: Day 25 at 12:00 UTC
Wind: 270 degrees at 5 MPS
Temperature: 15°C / Dew point: 5°C
Pressure: 1013 hPa
============================
```

## Future Roadmap

    [ ] Integration with a live Weather API using libcurl.

    [ ] Support for TAF (Terminal Aerodrome Forecast) decoding.

    [ ] SQLite integration for faster airport metadata lookups.

    [ ] Web interface using a C-based micro-webserver.

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Author
**Timur Ussenov**
Law Student at Shymkent University 
 Aspiring Pilot | CS50 Student
