
#include <unity.h>
#include "wifi_adapter_mock.h"

#ifdef UNIT_TEST

void test_creoUnWifi_adapterYTieneSSID() {
    //wifi_adapter_mock miwifi;
    //std::string ssid;// = "test";
	
	wifi_adapter_mock miwifi; 
    std::string ssidmocka = miwifi.getSSID();
	
	//ssid = "test"; 
	//ssid = miwifi->getSSID();
	
	TEST_ASSERT_TRUE(ssidmocka.length() != 0);
	//TEST_ASSERT_EQUAL(1,1);
}

int main( int argc, char **argv) {
	UNITY_BEGIN();


	RUN_TEST(test_creoUnWifi_adapterYTieneSSID);

	UNITY_END();
}

#endif
