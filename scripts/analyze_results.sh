#!/bin/bash
echo "[+] Analyzing results with Python..."
cd ../ml
python3 performance_plots.py
python3 fault_prediction.py
