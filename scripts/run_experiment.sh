#!/bin/bash
echo "[+] Running Wireless Mesh Network Simulation"
cd ns3/examples
python3 mesh_sim.py

echo "[+] Collecting Telemetry Data"
mv telemetry_log.csv ../../data/telemetry_dataset.csv 2>/dev/null

echo "[+] Training Machine Learning Model"
cd ../../ml
python3 train.py

echo "[+] Experiment Complete"
