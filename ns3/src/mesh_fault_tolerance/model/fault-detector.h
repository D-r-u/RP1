#ifndef FAULT_DETECTOR_H
#define FAULT_DETECTOR_H

#include "ns3/event-id.h"
#include "ns3/node-container.h"

namespace ns3 {

/**
 * FaultDetector: Monitors link and node health periodically.
 */
class FaultDetector {
public:
  void StartMonitoring(NodeContainer nodes);
  void CheckHealth();
};

} // namespace ns3

#endif // FAULT_DETECTOR_H
