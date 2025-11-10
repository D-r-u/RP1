#ifndef METRICS_LOGGER_H
#define METRICS_LOGGER_H

#include <fstream>
#include <string>

namespace ns3 {

/**
 * MetricsLogger: Logs performance metrics to CSV for Python analysis.
 */
class MetricsLogger {
public:
  MetricsLogger(std::string file);
  void LogMetric(std::string key, double value);
  void Close();
private:
  std::ofstream m_file;
};

} // namespace ns3

#endif // METRICS_LOGGER_H
