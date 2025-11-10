# CMake configuration for the Mesh Fault Tolerance module

ns3_add_module(
  mesh-fault-tolerance
  SOURCE_FILES
    helper/mesh-fault-helper.cc
    model/adaptive-routing.cc
    model/resilient-topology.cc
    model/fault-detector.cc
    model/metrics-logger.cc
  HEADER_FILES
    helper/mesh-fault-helper.h
    model/adaptive-routing.h
    model/resilient-topology.h
    model/fault-detector.h
    model/metrics-logger.h
  LIBRARIES_TO_LINK
    ${libcore}
    ${libnetwork}
    ${libinternet}
    ${libwifi}
    ${libmesh}
)
