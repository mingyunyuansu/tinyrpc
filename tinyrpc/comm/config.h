#ifndef TINYRPC_COMM_CONFIG_H
#define TINYRPC_COMM_CONFIG_H

#include <tinyxml/tinyxml.h>
#include <string>
#include <memory>
#include <map>
#include "tinyrpc/comm/mysql_instase.h"

namespace tinyrpc {

enum LogLevel {
	DEBUG = 1,
	INFO = 2,
	WARN = 3,
	ERROR = 4
};

class Config {

 public:
  typedef std::shared_ptr<Config> ptr;
  Config(const char* file_path);

  ~Config();

  void readConf();

  void readDBConfig(TiXmlElement* node);

 public:

  // log params
  std::string m_log_path;
  int m_log_max_size {0};
  LogLevel m_log_level {LogLevel::DEBUG};
  int m_log_sync_inteval {1000};

  // coroutine params
  int m_cor_stack_size {0};
  int m_cor_pool_size {0};

  int m_msg_req_len {0};

  int m_max_connect_timeout {0};    // ms
  int m_iothread_num {0};

  int m_timewheel_bucket_num {0};
  int m_timewheel_inteval {0};

  std::map<std::string, MySQLOption> m_mysql_options;

 private:
  std::string m_file_path;
  TiXmlDocument* m_xml_file;

};


}

#endif // TINYRPC_COMM_CONFIG_H