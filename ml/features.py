import pandas as pd

def extract_features(csv_path):
    df = pd.read_csv(csv_path, names=['time', 'node', 'energy', 'pktLoss', 'rssi'])
    df['energy_drop'] = df['energy'].diff().fillna(0)
    df['loss_ratio'] = df['pktLoss'] / (df['pktLoss'].max() + 1)
    df['label'] = (df['energy'] < 80).astype(int)  # Simulated fault label
    df.to_csv("data/telemetry_dataset.csv", index=False)
    return df
