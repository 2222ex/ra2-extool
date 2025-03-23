#include "http_server.h"

#include "../base/logger.h"
#include "../client_module.h"

#include <MinHook.h>
#include <httplib.h>
#include <nlohmann/json.hpp>

#include "../yrpp.h"

#include "../client_module.h"
#include "../quick.h"

void Detach();

bool TaskHandlerHttpServer::InitHttpServer()
{
    Logger::Log()->info("InitHttpServer");
    httplib::Server svr;

    svr.Get(
        "/f1",
        [](const httplib::Request &req, httplib::Response &res)
        {
            res.set_content("call f1", "text/plain"); // appliation/json
        });

    svr.Get(
        "/Detach",
        [&](const httplib::Request &req, httplib::Response &res)
        {
            Detach();
            res.set_content("call Detach", "text/plain");
            svr.stop();
        });

    svr.Post(
        kEnterMenuRequestPath,
        [](const httplib::Request &req, httplib::Response &res)
        {
            auto &client = ClientModuleSingleton::instance();

            client.EnterMenu(reinterpret_cast<uintptr_t>(InputManagerClass::Instance.get()), 0x1b, 0);

            res.set_content("call enter menu", "text/plain");
        });
    svr.Post(
        kQuickSave,
        [](const httplib::Request &req, httplib::Response &res)
        {
            try
            {
                auto &quick = QuickSingleton::instance();
                Response response = {true, "", {}};
                std::string err_msg;
                if (quick.save(err_msg) == false)
                {
                    response.success = false;
                    response.err_msg = err_msg;
                }

                nlohmann::json json_response = response;
                res.set_content(json_response.dump(), "text/plain");
            }
            catch (const std::exception &e)
            {
                Logger::Log()->error("{} throw std::exception: {}", kQuickSave, e.what());
                res.set_content(fmt::format("{} throw std::exception: {}", kQuickSave, e.what()), "text/plain");
            }
        });

    bool res = svr.listen("localhost", kPort);
    Logger::Log()->info("svr.listen return value: {}", res);
    return res;
}