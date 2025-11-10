#!/bin/bash
python3 -m venv myenv
source myenv/bin/activate
pip install cppyy numpy pandas scikit-learn matplotlib joblib
echo "[+] Environment setup completed."