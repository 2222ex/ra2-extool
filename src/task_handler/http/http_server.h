#ifndef TASK_HANDLER_HTTP_SERVER_H
#define TASK_HANDLER_HTTP_SERVER_H

#include "../common/http/http_server.h"

namespace TaskHandlerHttpServer
{
const std::string kEnterMenuRequestPath = "/enter_menu";
const std::string kQuickSave = "/quick_save";
const int kPort = 24960;
bool InitHttpServer();
};

#endif