import ns.network
import ns.internet
import ns.mesh
import ns.mobility
import ns.applications
import ns.core

nodes = ns.network.NodeContainer()
nodes.Create(10)

mobility = ns.mobility.MobilityHelper()
mobility.SetMobilityModel("ns3::ConstantPositionMobilityModel")
mobility.Install(nodes)

stack = ns.internet.InternetStackHelper()
stack.Install(nodes)

mesh = ns.mesh.MeshHelper()
mesh.SetStackInstaller("ns3::Dot11sStack")
mesh.SetSpreadInterfaceChannels(ns.mesh.MeshHelper.SPREAD_CHANNELS)
mesh.Install(nodes)

# Fault injection
def Fault(node):
    print(f"Simulated failure: Node {node.GetId()}")
    node.GetDevice(0).SetReceiveCallback(None)

ns.core.Simulator.Schedule(ns.core.Seconds(30.0), Fault, nodes.Get(3))
ns.core.Simulator.Stop(ns.core.Seconds(60.0))
ns.core.Simulator.Run()
ns.core.Simulator.Destroy()
