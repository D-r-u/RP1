#include "mesh-fault-helper.h"
#include "ns3/log.h"

namespace ns3 {

NS_LOG_COMPONENT_DEFINE("MeshFaultHelper");

MeshFaultHelper::MeshFaultHelper()
    : m_routingType("adaptive"), m_enableLogging(false) {}

NetDeviceContainer MeshFaultHelper::Install(NodeContainer nodes) {
  NS_LOG_INFO("Installing MeshFaultHelper with routing type: " << m_routingType);
  MeshHelper mesh;
  mesh.SetStackInstaller("ns3::Dot11sStack");
  return mesh.Install(nodes);
}

void MeshFaultHelper::SetRoutingType(std::string type) { m_routingType = type; }
void MeshFaultHelper::EnableLogging(bool enable) { m_enableLogging = enable; }

} // namespace ns3
