#!/bin/bash
echo "[+] Running NS-3 Simulation..."
cd ns3
./ns3 run examples/mesh_fault_sim
echo "[+] Simulation Completed."