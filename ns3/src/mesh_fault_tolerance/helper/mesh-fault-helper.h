#ifndef MESH_FAULT_HELPER_H
#define MESH_FAULT_HELPER_H

#include "ns3/mesh-helper.h"
#include "ns3/node-container.h"
#include "ns3/net-device-container.h"

namespace ns3 {

/**
 * MeshFaultHelper: Initializes a mesh network with fault-tolerant parameters.
 * Helps configure adaptive routing, topology, and logging systems.
 */
class MeshFaultHelper {
public:
  MeshFaultHelper();
  NetDeviceContainer Install(NodeContainer nodes);
  void SetRoutingType(std::string type);
  void EnableLogging(bool enable);
private:
  std::string m_routingType;
  bool m_enableLogging;
};

} // namespace ns3

#endif // MESH_FAULT_HELPER_H
