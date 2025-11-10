#ifndef ADAPTIVE_ROUTING_H
#define ADAPTIVE_ROUTING_H

#include "ns3/node.h"
#include "ns3/ipv4-routing-protocol.h"

namespace ns3 {

/**
 * AdaptiveRouting: Implements an ACO-inspired adaptive routing logic.
 */
class AdaptiveRouting : public Ipv4RoutingProtocol {
public:
  static TypeId GetTypeId(void);
  AdaptiveRouting();
  virtual Ptr<Ipv4Route> RouteOutput(Ptr<Packet> p, const Ipv4Header &header,
                                     Ptr<NetDevice> oif, Socket::SocketErrno &sockerr);
  virtual bool RouteInput(Ptr<const Packet> p, const Ipv4Header &header,
                          Ptr<const NetDevice> idev,
                          UnicastForwardCallback ucb,
                          MulticastForwardCallback mcb,
                          LocalDeliverCallback lcb, ErrorCallback ecb);

private:
  void UpdatePheromone();
  void DetectLinkFailure();
};

} // namespace ns3

#endif // ADAPTIVE_ROUTING_H
