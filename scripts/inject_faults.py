import random
import time
import os

def inject_random_faults(nodes=10, duration=60):
    failures = random.sample(range(nodes), 2)
    for node in failures:
        t = random.randint(10, duration-10)
        print(f"[FAULT] Node {node} will fail at {t}s")
        time.sleep(0.1)
        os.system(f"echo 'Node {node} failed at {t}s' >> fault_log.txt")

if __name__ == "__main__":
    inject_random_faults()
