#include <iostream>

#define POCO_STATIC
#include "Poco/Util/IniFileConfiguration.h"

int main()
{
	try
	{
		Poco::AutoPtr<Poco::Util::IniFileConfiguration> pZoneServerConf(new Poco::Util::IniFileConfiguration("test.ini"));
		auto nMaxChannelCount = pZoneServerConf->getInt("ZoneServer.CHANNEL_COUNT");
		auto nMaxChannelUserCount = pZoneServerConf->getInt("ZoneServer.CHANNEL_USER_COUNT");

		std::cout << "Success" << std::endl;
		std::cout << "ZoneServer.CHANNEL_COUNT: " << nMaxChannelCount << std::endl;
		std::cout << "ZoneServer.CHANNEL_USER_COUNT: " << nMaxChannelUserCount << std::endl;
	}
	catch (Poco::FileNotFoundException e) // ������ ���� ���
	{
		std::cout << e.displayText() << std::endl;
	}
	catch (Poco::NotFoundException& e)    // ���� Ű���尡 ���� ���
	{
		std::cout << e.displayText() << std::endl;
	}

	return 0;
}