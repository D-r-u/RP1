#include "ns3/core-module.h"
#include "ns3/internet-module.h"
#include "ns3/mesh-module.h"
#include "ns3/mobility-module.h"
#include "ns3/yans-wifi-helper.h"
#include "../src/mesh_fault_tolerance/helper/mesh-fault-helper.h"
#include "../src/mesh_fault_tolerance/model/metrics-logger.h"

using namespace ns3;

NS_LOG_COMPONENT_DEFINE("MeshFaultSimulation");

int main(int argc, char *argv[]) {
  Time::SetResolution(Time::NS);
  LogComponentEnable("MeshFaultSimulation", LOG_LEVEL_INFO);

  NodeContainer nodes;
  nodes.Create(9);

  MeshFaultHelper meshHelper;
  meshHelper.SetRoutingType("adaptive");
  meshHelper.EnableLogging(true);
  meshHelper.Install(nodes);

  InternetStackHelper internet;
  internet.Install(nodes);

  MobilityHelper mobility;
  mobility.SetMobilityModel("ns3::GridPositionAllocator");
  mobility.Install(nodes);

  MetricsLogger logger("../../../data/metrics.csv");
  logger.LogMetric("PDR", 95.0);
  logger.LogMetric("Delay", 15.0);
  logger.Close();

  Simulator::Run();
  Simulator::Destroy();

  return 0;
}
