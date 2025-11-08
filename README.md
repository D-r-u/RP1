# WMN Fault Tolerance Simulation

Enhancing Fault Tolerance in Wireless Mesh Networks through Adaptive and Resilient Routing Protocols.

This repository implements:
- Dynamic Fault Detection  
- Adaptive Routing using Improved Ant Colony Optimization (ACO)  
- Machine Learning-based Predictive Fault Tolerance (SVM)  
- NS-3 Simulation Framework for Wireless Mesh Networks  

## Repository Structure
ns3/ → NS-3 simulation and routing code
ml/ → ML models and feature scripts
scripts/ → Automation and fault injection
data/ → Datasets and logs
docs/ → Reports and methodology

## Setup
1. Install [NS-3](https://www.nsnam.org) with Python bindings  
2. Install Python dependencies:
   ```bash
   pip install scikit-learn numpy pandas matplotlib joblib```
3. Run the simulation:
```bash scripts/run_experiment.sh ```
4. Train and test ML model:
``` python ml/train.py ```
