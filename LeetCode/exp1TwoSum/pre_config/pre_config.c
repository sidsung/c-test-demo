#include "pre_config.h"

log_level_e g_hlLogLevel = LOG_DEBUG;

hl_result_e pre_config_set_log_level(log_level_e logLevel)
{
    g_hlLogLevel = logLevel;
    return HL_OK;
}

log_level_e pre_config_get_log_level(void)
{
    return g_hlLogLevel;
}