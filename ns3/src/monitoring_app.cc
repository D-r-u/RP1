#include "ns3/application.h"
#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/simulator.h"
#include "ns3/log.h"
#include <fstream>

using namespace ns3;

NS_LOG_COMPONENT_DEFINE("MonitoringApp");

class MonitoringApp : public Application {
public:
  void StartApplication() override {
    m_timer = Simulator::Schedule(Seconds(0.0), &MonitoringApp::Sample, this);
  }

  void StopApplication() override {
    if (m_timer.IsRunning())
      m_timer.Cancel();
  }

  void Sample() {
    double time = Simulator::Now().GetSeconds();
    double energy = 100.0 - (rand() % 10); // placeholder for energy model
    double pktLoss = (rand() % 5);
    double rssi = -60.0 + (rand() % 10);

    std::ofstream file;
    file.open("telemetry_log.csv", std::ios_base::app);
    file << time << "," << GetNode()->GetId() << "," << energy
         << "," << pktLoss << "," << rssi << std::endl;
    file.close();

    m_timer = Simulator::Schedule(Seconds(5.0), &MonitoringApp::Sample, this);
  }

private:
  EventId m_timer;
};

int main(int argc, char *argv[]) {
  NodeContainer nodes;
  nodes.Create(10);

  for (uint32_t i = 0; i < nodes.GetN(); ++i) {
    Ptr<MonitoringApp> app = CreateObject<MonitoringApp>();
    nodes.Get(i)->AddApplication(app);
    app->SetStartTime(Seconds(0.0));
  }

  Simulator::Stop(Seconds(60.0));
  Simulator::Run();
  Simulator::Destroy();
  return 0;
}