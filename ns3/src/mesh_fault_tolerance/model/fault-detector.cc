#include "fault-detector.h"
#include "ns3/log.h"

namespace ns3 {

NS_LOG_COMPONENT_DEFINE("FaultDetector");

void FaultDetector::StartMonitoring(NodeContainer nodes) {
  NS_LOG_INFO("Starting fault monitoring...");
}

void FaultDetector::CheckHealth() {
  NS_LOG_INFO("Checking node/link health...");
}

} // namespace ns3
