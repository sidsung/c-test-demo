#include "/home/sidsung/esp/idftest/HomeKitTest/components/esp_common/include/esp_err.h"

/**
  * @brief  Generate and display QR Code on the console
  *         Encodes the given string into a QR Code & displays it on the console
  *
  * @attention 1. Can successfully encode a UTF-8 string of up to 2953 bytes or an alphanumeric
  *               string of up to 4296 characters or any digit string of up to 7089 characters
  *
  * @param  text  string to encode into a QR Code.
  *
  * @return
  *    - ESP_OK: succeed
  *    - ESP_FAIL: Failed to encode string into a QR Code
  *    - ESP_ERR_NO_MEM: Failed to allocate buffer for given MAX_QRCODE_VERSION
  */
esp_err_t qrcode_display(const char *text);