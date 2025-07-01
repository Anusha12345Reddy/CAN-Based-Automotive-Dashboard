# CAN-Based-Automotive-Dashboard

📘 CAN-based Automotive Dashboard – Explanation

This project simulates a real-time automotive dashboard using the CAN (Controller Area Network) protocol. Implemented in embedded C, it involves three Electronic Control Units (ECUs) communicating over a virtual CAN bus to display key vehicle parameters like speed, RPM, engine temperature, gear position, and indicator status. The goal of this project is to demonstrate inter-ECU communication and real-time data sharing using a standardized automotive communication protocol.

Each ECU performs a specific role:

- ECU1: Collects and transmits speed, gear position, and engine temperature data
- ECU2: Sends RPM and indicator signal status
- ECU3: Acts as the receiver unit, aggregating all the data and displaying it on a simulated dashboard

The project uses SocketCAN interfaces (or similar emulation) to replicate CAN messaging on Linux systems. Messages are encoded and decoded using CAN frame structures, and precise timing is used to simulate real-time updates. The dashboard display is terminal-based, updating live based on incoming CAN packets.

Key capabilities include:

- Multi-ECU simulation using separate processes
- CAN frame construction and filtering
- Live dashboard output with real-time updates
- Graceful error handling and message validation
- Strong modularity separating ECU logic and CAN layer

This project required deep understanding of communication protocols, inter-process signaling, and embedded data formatting. It showcases real-time systems thinking, protocol implementation, and embedded diagnostics — all essential skills for automotive and embedded software engineering.

🔹 What This Project Showcases:

- Practical implementation of CAN protocol in a simulated environment
- Real-time data handling and multi-process communication
- Embedded systems design principles with protocol layering
- Automotive industry relevance and protocol-level debugging experience
