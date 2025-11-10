import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("../data/metrics.csv")

plt.bar(df["metric"], df["value"])
plt.title("Performance Metrics")
plt.xlabel("Metric")
plt.ylabel("Value")
plt.savefig("../data/metrics_plot.png")
plt.show()
