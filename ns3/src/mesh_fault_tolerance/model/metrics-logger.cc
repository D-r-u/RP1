#include "metrics-logger.h"
#include "ns3/log.h"

namespace ns3 {

NS_LOG_COMPONENT_DEFINE("MetricsLogger");

MetricsLogger::MetricsLogger(std::string file) {
  m_file.open(file, std::ios::out);
  m_file << "metric,value\n";
}

void MetricsLogger::LogMetric(std::string key, double value) {
  m_file << key << "," << value << "\n";
}

void MetricsLogger::Close() { m_file.close(); }

} // namespace ns3
