import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.svm import SVC
from sklearn.metrics import classification_report, roc_auc_score
from joblib import dump
from features import extract_features

df = extract_features("data/telemetry_dataset.csv")
X = df[['energy', 'pktLoss', 'rssi', 'energy_drop', 'loss_ratio']]
y = df['label']

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2)
scaler = StandardScaler().fit(X_train)
svm = SVC(probability=True, kernel='rbf', C=1.0)
svm.fit(scaler.transform(X_train), y_train)

y_pred = svm.predict(scaler.transform(X_test))
print(classification_report(y_test, y_pred))
print("ROC AUC:", roc_auc_score(y_test, svm.predict_proba(scaler.transform(X_test))[:,1]))

dump((svm, scaler), "ml/models/svm_failure_predictor.joblib")
